/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2008, 2009, 2010 Ciaran McCreesh
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

#ifndef PALUDIS_GUARD_PALUDIS_UTIL_TYPE_LIST_FWD_HH
#define PALUDIS_GUARD_PALUDIS_UTIL_TYPE_LIST_FWD_HH 1

#include <paludis/util/attributes.hh>

namespace paludis
{
    struct PALUDIS_VISIBLE TypeListTail;

    template <typename Item_, typename Tail_>
    struct PALUDIS_VISIBLE TypeListEntry;

    template <typename...>
    struct MakeTypeList;

    template <>
    struct MakeTypeList<>;

    template <typename H_, typename... T_>
    struct MakeTypeList<H_, T_...>;

    template <typename TypeList_>
    struct MakeTypeListConst;

    template <typename Item_>
    struct MakeTypeListConstEntry;

    template <typename TypeList_, typename Item_>
    struct TypeListContains;
}

#endif
