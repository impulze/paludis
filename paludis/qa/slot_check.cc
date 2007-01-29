/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2006, 2007 Ciaran McCreesh <ciaranm@ciaranm.org>
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

#include <paludis/qa/slot_check.hh>
#include <paludis/package_database_entry.hh>
#include <paludis/environment.hh>

using namespace paludis;
using namespace paludis::qa;

SlotCheck::SlotCheck()
{
}

CheckResult
SlotCheck::operator() (const EbuildCheckData & e) const
{
    CheckResult result(stringify(e.name) + "-" + stringify(e.version),
            identifier());

    try
    {
        PackageDatabaseEntry ee(e.name, e.version,
                e.environment->package_database()->favourite_repository());
        std::tr1::shared_ptr<const VersionMetadata> metadata(
                e.environment->package_database()->fetch_repository(ee.repository)->version_metadata(ee.name, ee.version));

        try
        {
            SlotName slot(metadata->slot);
        }
        catch (const NameError &)
        {
            result << Message(qal_fatal, "Invalid SLOT value");
        }
    }
    catch (const InternalError &)
    {
        throw;
    }
    catch (const Exception & err)
    {
        result << Message(qal_fatal, "Caught Exception '" + err.message() + "' ("
                + err.what() + ")");
    }

    return result;
}

const std::string &
SlotCheck::identifier()
{
    static const std::string id("slot");
    return id;
}


