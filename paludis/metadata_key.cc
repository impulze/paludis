/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2007, 2008, 2009, 2010, 2011 Ciaran McCreesh
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

#include <paludis/metadata_key.hh>
#include <paludis/util/exception.hh>
#include <paludis/util/stringify.hh>
#include <paludis/util/set.hh>
#include <paludis/util/sequence.hh>
#include <paludis/util/indirect_iterator-impl.hh>
#include <paludis/name.hh>
#include <functional>
#include <list>
#include <algorithm>

using namespace paludis;

#include <paludis/metadata_key-se.cc>

MetadataKey::~MetadataKey()
{
}

MetadataSectionKey::~MetadataSectionKey()
{
}

MetadataTimeKey::~MetadataTimeKey()
{
}

template <typename T_>
MetadataCollectionKey<T_>::~MetadataCollectionKey()
{
}

template <typename T_>
MetadataSpecTreeKey<T_>::~MetadataSpecTreeKey()
{
}

template <typename T_>
MetadataValueKey<T_>::~MetadataValueKey()
{
}

MetadataSpecTreeKey<FetchableURISpecTree>::~MetadataSpecTreeKey()
{
}

MetadataSpecTreeKey<DependencySpecTree>::~MetadataSpecTreeKey()
{
}

namespace paludis
{
    template class MetadataCollectionKey<KeywordNameSet>;
    template class MetadataCollectionKey<Set<std::string> >;
    template class MetadataCollectionKey<Sequence<std::string> >;
    template class MetadataCollectionKey<Map<std::string, std::string> >;
    template class MetadataCollectionKey<PackageIDSequence>;
    template class MetadataCollectionKey<FSPathSequence>;
    template class MetadataCollectionKey<Maintainers>;

    template class MetadataSpecTreeKey<LicenseSpecTree>;
    template class MetadataSpecTreeKey<PlainTextSpecTree>;
    template class MetadataSpecTreeKey<RequiredUseSpecTree>;
#ifndef PALUDIS_NO_EXPLICIT_FULLY_SPECIALISED
    template class MetadataSpecTreeKey<FetchableURISpecTree>;
    template class MetadataSpecTreeKey<DependencySpecTree>;
#endif
    template class MetadataSpecTreeKey<SimpleURISpecTree>;

    template class MetadataValueKey<std::string>;
    template class MetadataValueKey<long>;
    template class MetadataValueKey<bool>;
    template class MetadataValueKey<FSPath>;
    template class MetadataValueKey<SlotName>;
    template class MetadataValueKey<std::shared_ptr<const PackageID> >;
    template class MetadataValueKey<std::shared_ptr<const Choices> >;
}

