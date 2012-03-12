/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2005, 2006, 2007, 2008, 2009, 2010 Ciaran McCreesh
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

#include <paludis/additional_package_dep_spec_requirement.hh>
#include <paludis/util/sequence-impl.hh>
#include <paludis/util/wrapped_forward_iterator-impl.hh>
#include <ostream>

using namespace paludis;

AdditionalPackageDepSpecRequirement::~AdditionalPackageDepSpecRequirement() = default;

std::ostream &
paludis::operator<< (std::ostream & s, const AdditionalPackageDepSpecRequirement & a)
{
    s << a.as_raw_string();
    return s;
}

namespace paludis
{
    template class Sequence<std::shared_ptr<const AdditionalPackageDepSpecRequirement> >;
    template class PALUDIS_VISIBLE WrappedForwardIterator<AdditionalPackageDepSpecRequirements::ConstIteratorTag, const std::shared_ptr<const AdditionalPackageDepSpecRequirement> >;
}
