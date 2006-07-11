/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2006 Ciaran McCreesh <ciaran.mccreesh@blueyonder.co.uk>
 *
 * This file is part of the Paludis package manager. Paludis is free software;
 * you can redistribute it and/or modify it under the terms of the GNU General
 * Public License version 2, as published by the Free Software Foundation.
 *
 * Paludis is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <paludis/qa/deps_visible_check.hh>

#include <paludis/portage_dep_parser.hh>
#include <paludis/dep_atom.hh>

using namespace paludis;
using namespace paludis::qa;

namespace
{
    struct Checker :
        DepAtomVisitorTypes::ConstVisitor
    {
        CheckResult & result;
        const std::string role;
        const Environment * env;

        Checker(CheckResult & rr, const std::string & r, const Environment * e) :
            result(rr),
            role(r),
            env(e)
        {
        }

        void visit(const PackageDepAtom * const p)
        {
            bool found(false);
            PackageDatabaseEntryCollection::Pointer matches(env->package_database()->query(p,
                        is_either));
            for (PackageDatabaseEntryCollection::ReverseIterator m(matches->rbegin()),
                    m_end(matches->rend()) ; m != m_end ; ++m)
            {
                if (env->mask_reasons(*m).any())
                    continue;

                found = true;
                break;
            }

            if (! found)
                result << Message(qal_major, "No visible provider for " + role + " entry '"
                        + stringify(*p) + "'");
        }

        void visit(const AllDepAtom * const a)
        {
            std::for_each(a->begin(), a->end(), accept_visitor(this));
        }

        void visit(const AnyDepAtom * const)
        {
        }

        void visit(const UseDepAtom * const)
        {
        }

        void visit(const BlockDepAtom * const)
        {
        }

        void visit(const PlainTextDepAtom * const)
        {
        }
    };
}

DepsVisibleCheck::DepsVisibleCheck()
{
}

CheckResult
DepsVisibleCheck::operator() (const EbuildCheckData & e) const
{
    CheckResult result(stringify(e.get<ecd_name>()) + "-" + stringify(e.get<ecd_version>()),
            identifier());

    try
    {
        PackageDatabaseEntry ee(e.get<ecd_name>(), e.get<ecd_version>(),
                e.get<ecd_environment>()->package_database()->favourite_repository());
        VersionMetadata::ConstPointer metadata(
                e.get<ecd_environment>()->package_database()->fetch_repository(
                        ee.get<pde_repository>())->version_metadata(ee.get<pde_name>(), ee.get<pde_version>()));

        if (e.get<ecd_environment>()->mask_reasons(ee).any())
            result << Message(qal_skip, "Masked, so skipping checks");
        else
        {
            Checker depend_checker(result, "DEPEND", e.get<ecd_environment>());
            std::string depend(metadata->get<vm_deps>().get<vmd_build_depend_string>());
            PortageDepParser::parse(depend)->accept(&depend_checker);

            Checker rdepend_checker(result, "RDEPEND", e.get<ecd_environment>());
            std::string rdepend(metadata->get<vm_deps>().get<vmd_run_depend_string>());
            PortageDepParser::parse(rdepend)->accept(&rdepend_checker);

            Checker pdepend_checker(result, "PDEPEND", e.get<ecd_environment>());
            std::string pdepend(metadata->get<vm_deps>().get<vmd_post_depend_string>());
            PortageDepParser::parse(pdepend)->accept(&pdepend_checker);
        }
    }
    catch (const InternalError &)
    {
        throw;
    }
    catch (const Exception & e)
    {
        result << Message(qal_fatal, "Caught Exception '" + e.message() + "' ("
                + e.what() + ")");
    }

    return result;
}

const std::string &
DepsVisibleCheck::identifier()
{
    static const std::string id("deps visible");
    return id;
}

