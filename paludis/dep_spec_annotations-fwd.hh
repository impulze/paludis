/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2010, 2011 Ciaran McCreesh
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

#ifndef PALUDIS_GUARD_PALUDIS_DEP_SPEC_ANNOTATIONS_FWD_HH
#define PALUDIS_GUARD_PALUDIS_DEP_SPEC_ANNOTATIONS_FWD_HH 1

#include <paludis/util/attributes.hh>
#include <iosfwd>
#include <memory>

namespace paludis
{
    class PALUDIS_VISIBLE DepSpecAnnotation;
    class PALUDIS_VISIBLE DepSpecAnnotations;

#include <paludis/dep_spec_annotations-se.hh>

    DepSpecAnnotationRole find_blocker_role_in_annotations(
            const std::shared_ptr<const DepSpecAnnotations> & maybe_annotations) PALUDIS_VISIBLE PALUDIS_ATTRIBUTE((warn_unused_result));
}

#endif
