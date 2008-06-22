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

#ifndef PALUDIS_GUARD_PALUDIS_REPOSITORIES_UNAVAILABLE_UNAVAILABLE_ID_HH
#define PALUDIS_GUARD_PALUDIS_REPOSITORIES_UNAVAILABLE_UNAVAILABLE_ID_HH 1

#include <paludis/package_id.hh>
#include <paludis/repositories/unavailable/unavailable_repository_file-fwd.hh>
#include <paludis/repositories/unavailable/unavailable_repository-fwd.hh>

namespace paludis
{
    namespace unavailable_repository
    {
        typedef kc::KeyedClass<
            kc::Field<k::name, QualifiedPackageName>,
            kc::Field<k::version, VersionSpec>,
            kc::Field<k::slot, SlotName>,
            kc::Field<k::repository, const UnavailableRepository *>,
            kc::Field<k::owning_repository, std::tr1::shared_ptr<const MetadataValueKey<std::string> > >,
            kc::Field<k::repository_homepage, std::tr1::shared_ptr<const MetadataValueKey<std::string> > >,
            kc::Field<k::repository_description, std::tr1::shared_ptr<const MetadataValueKey<std::string> > >,
            kc::Field<k::description, std::tr1::shared_ptr<const MetadataValueKey<std::string> > >,
            kc::Field<k::mask, std::tr1::shared_ptr<const Mask> >
                > UnavailableIDParams;

        class PALUDIS_VISIBLE UnavailableID :
            public PackageID,
            private PrivateImplementationPattern<UnavailableID>
        {
            private:
                PrivateImplementationPattern<UnavailableID>::ImpPtr & _imp;

            protected:
                void need_keys_added() const;
                void need_masks_added() const;

            public:
                UnavailableID(const UnavailableIDParams &);
                ~UnavailableID();

                 const std::string canonical_form(const PackageIDCanonicalForm) const;
                 const QualifiedPackageName name() const;
                 const VersionSpec version() const;
                 const SlotName slot() const;
                 const std::tr1::shared_ptr<const Repository> repository() const;

                 const std::tr1::shared_ptr<const MetadataValueKey<std::tr1::shared_ptr<const PackageID> > >
                     virtual_for_key() const;
                 const std::tr1::shared_ptr<const MetadataCollectionKey<KeywordNameSet> > keywords_key() const;
                 const std::tr1::shared_ptr<const MetadataCollectionKey<IUseFlagSet> > iuse_key() const;
                 const std::tr1::shared_ptr<const MetadataSpecTreeKey<ProvideSpecTree> > provide_key() const;
                 const std::tr1::shared_ptr<const MetadataCollectionKey<PackageIDSequence> > contains_key() const;
                 const std::tr1::shared_ptr<const MetadataValueKey<std::tr1::shared_ptr<const PackageID> > >
                     contained_in_key() const;
                 const std::tr1::shared_ptr<const MetadataSpecTreeKey<DependencySpecTree> >
                     build_dependencies_key() const;
                 const std::tr1::shared_ptr<const MetadataSpecTreeKey<DependencySpecTree> >
                     run_dependencies_key() const;
                 const std::tr1::shared_ptr<const MetadataSpecTreeKey<DependencySpecTree> >
                     post_dependencies_key() const;
                 const std::tr1::shared_ptr<const MetadataSpecTreeKey<DependencySpecTree> >
                     suggested_dependencies_key() const;
                 const std::tr1::shared_ptr<const MetadataSpecTreeKey<FetchableURISpecTree> > fetches_key() const;
                 const std::tr1::shared_ptr<const MetadataSpecTreeKey<SimpleURISpecTree> > homepage_key() const;
                 const std::tr1::shared_ptr<const MetadataValueKey<std::string> > short_description_key() const;
                 const std::tr1::shared_ptr<const MetadataValueKey<std::string> > long_description_key() const;
                 const std::tr1::shared_ptr<const MetadataValueKey<std::tr1::shared_ptr<const Contents> > >
                     contents_key() const;
                 const std::tr1::shared_ptr<const MetadataTimeKey> installed_time_key() const;
                 const std::tr1::shared_ptr<const MetadataValueKey<std::string> > source_origin_key() const;
                 const std::tr1::shared_ptr<const MetadataValueKey<std::string> > binary_origin_key() const;
                 const std::tr1::shared_ptr<const MetadataValueKey<FSEntry> > fs_location_key() const;
                 const std::tr1::shared_ptr<const MetadataValueKey<bool> > transient_key() const;

                 bool supports_action(const SupportsActionTestBase &) const
                     PALUDIS_ATTRIBUTE((warn_unused_result));
                 void perform_action(Action &) const PALUDIS_ATTRIBUTE((noreturn));

                 std::tr1::shared_ptr<const Set<std::string> > breaks_portage() const
                     PALUDIS_ATTRIBUTE((warn_unused_result));

                 bool arbitrary_less_than_comparison(const PackageID &) const
                    PALUDIS_ATTRIBUTE((warn_unused_result));
                 std::size_t extra_hash_value() const
                    PALUDIS_ATTRIBUTE((warn_unused_result));
        };
    }
}

#endif