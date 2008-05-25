/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2008 Ciaran McCreesh
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

#ifndef PALUDIS_GUARD_PALUDIS_REPOSITORIES_FAKE_DEP_PARSER_HH
#define PALUDIS_GUARD_PALUDIS_REPOSITORIES_FAKE_DEP_PARSER_HH 1

#include <paludis/util/exception.hh>
#include <paludis/dep_tree.hh>
#include <paludis/package_id-fwd.hh>
#include <paludis/environment-fwd.hh>
#include <string>
#include <tr1/functional>

namespace paludis
{
    namespace fakerepository
    {
        class PALUDIS_VISIBLE FakeDepParseError :
            public Exception
        {
            public:
                /**
                 * Constructor.
                 */
                FakeDepParseError(const std::string & dep_string,
                        const std::string & message) throw ();
        };

        /**
         * Parse a dependency heirarchy.
         */
        std::tr1::shared_ptr<DependencySpecTree::ConstItem> parse_depend(const std::string & s,
                const Environment * const, const std::tr1::shared_ptr<const PackageID> &) PALUDIS_VISIBLE;

        /**
         * Parse a provide heirarchy.
         */
        std::tr1::shared_ptr<ProvideSpecTree::ConstItem> parse_provide(const std::string & s,
                const Environment * const, const std::tr1::shared_ptr<const PackageID> &) PALUDIS_VISIBLE;

        /**
         * Parse a fetchable uri heirarchy.
         */
        std::tr1::shared_ptr<FetchableURISpecTree::ConstItem> parse_fetchable_uri(const std::string & s,
                const Environment * const, const std::tr1::shared_ptr<const PackageID> &) PALUDIS_VISIBLE;

        /**
         * Parse a simple uri heirarchy.
         */
        std::tr1::shared_ptr<SimpleURISpecTree::ConstItem> parse_simple_uri(const std::string & s,
                const Environment * const, const std::tr1::shared_ptr<const PackageID> &) PALUDIS_VISIBLE;

        /**
         * Parse a license heirarchy.
         */
        std::tr1::shared_ptr<LicenseSpecTree::ConstItem> parse_license(const std::string & s,
                const Environment * const, const std::tr1::shared_ptr<const PackageID> &) PALUDIS_VISIBLE;
    }
}

#endif