/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2005, 2006, 2007, 2008, 2009, 2010, 2011 Ciaran McCreesh
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

#ifndef PALUDIS_GUARD_PALUDIS_PARTIALLY_MADE_PACKAGE_DEP_SPEC_HH
#define PALUDIS_GUARD_PALUDIS_PARTIALLY_MADE_PACKAGE_DEP_SPEC_HH 1

#include <paludis/partially_made_package_dep_spec-fwd.hh>
#include <paludis/util/pimp.hh>
#include <paludis/name-fwd.hh>
#include <paludis/dep_spec.hh>

namespace paludis
{
    /**
     * A PartiallyMadePackageDepSpec is returned by make_package_dep_spec()
     * and is used to incrementally build a PackageDepSpec.
     *
     * \ingroup g_dep_spec
     * \since 0.26
     */
    class PALUDIS_VISIBLE PartiallyMadePackageDepSpec
    {
        private:
            Pimp<PartiallyMadePackageDepSpec> _imp;

        public:
            ///\name Basic operations
            ///\{

            PartiallyMadePackageDepSpec(const PartiallyMadePackageDepSpecOptions &);
            ~PartiallyMadePackageDepSpec();
            PartiallyMadePackageDepSpec(const PackageDepSpec &);
            PartiallyMadePackageDepSpec(const PartiallyMadePackageDepSpec &);

            ///\}

            /**
             * Set our package constraints, return ourself.
             */
            PartiallyMadePackageDepSpec & package(const QualifiedPackageName &);

            /**
             * Clear our package constraints, return ourself.
             *
             * \since 0.55
             */
            PartiallyMadePackageDepSpec & clear_package();

            /**
             * Set our exact slot constraints, return ourself.
             *
             * \since 0.61
             */
            PartiallyMadePackageDepSpec & exact_slot_constraint(
                    const SlotName &, const bool);

            /**
             * Set our locked slot constraints, return ourself.
             *
             * \since 0.61
             */
             PartiallyMadePackageDepSpec & any_slot_constraint(
                     const bool);

            /**
             * Clear our exact slot constraints, return ourself.
             *
             * \since 0.61
             */
            PartiallyMadePackageDepSpec & clear_exact_slot();

            /**
             * Clear our any slot constraints, return ourself.
             *
             * \since 0.61
             */
            PartiallyMadePackageDepSpec & clear_any_slot();

            /**
             * Set our in-repository constraint, return ourself.
             */
            PartiallyMadePackageDepSpec & in_repository(const RepositoryName &);

            /**
             * Clear our in-repository constraint, return ourself.
             *
             * \since 0.55
             */
            PartiallyMadePackageDepSpec & clear_in_repository();

            /**
             * Set our from-repository constraint, return ourself.
             */
            PartiallyMadePackageDepSpec & from_repository(const RepositoryName &);

            /**
             * Clear our from-repository constraint, return ourself.
             *
             * \since 0.55
             */
            PartiallyMadePackageDepSpec & clear_from_repository();

            /**
             * Set our installable-to-repository constraint, return ourself.
             *
             * \since 0.61
             */
            PartiallyMadePackageDepSpec & installable_to_repository(const RepositoryName &, const bool);

            /**
             * Clear our installable-to-repository constraint, return ourself.
             *
             * \since 0.55
             */
            PartiallyMadePackageDepSpec & clear_installable_to_repository();

            /**
             * Set our installed-at-path constraint, return ourself.
             *
             * \since 0.32
             */
            PartiallyMadePackageDepSpec & installed_at_path(const FSPath &);

            /**
             * Clear our installed-at-path constraint, return ourself.
             *
             * \since 0.55
             */
            PartiallyMadePackageDepSpec & clear_installed_at_path();

            /**
             * Set our installable-to-path constraint, return ourself.
             *
             * \since 0.61
             */
            PartiallyMadePackageDepSpec & installable_to_path(const FSPath &, const bool include_masked);

            /**
             * Clear our installable-to-path constraint, return ourself.
             *
             * \since 0.55
             */
            PartiallyMadePackageDepSpec & clear_installable_to_path();

            /**
             * Set our package name part constraints, return ourself.
             */
            PartiallyMadePackageDepSpec & package_name_part(const PackageNamePart &);

            /**
             * Clear our package name part constraints, return ourself.
             *
             * \since 0.55
             */
            PartiallyMadePackageDepSpec & clear_package_name_part();

            /**
             * Set our category name part constraints, return ourself.
             */
            PartiallyMadePackageDepSpec & category_name_part(const CategoryNamePart &);

            /**
             * Clear our category name part constraints, return ourself.
             *
             * \since 0.55
             */
            PartiallyMadePackageDepSpec & clear_category_name_part();

            /**
             * Add a version constraint, return ourself.
             *
             * \since 0.61
             */
            PartiallyMadePackageDepSpec & version_constraint(
                    const VersionSpec &, const VersionOperator &, const VersionConstraintCombiner);

            /**
             * Clear all version constraints, return ourself.
             *
             * \since 0.55
             */
            PartiallyMadePackageDepSpec & clear_version();

            /**
             * Add a choice constraint, return ourself.
             *
             * \since 0.61
             */
            PartiallyMadePackageDepSpec & choice_constraint(
                    const std::shared_ptr<const ChoiceConstraint> &);

            /**
             * Add a key constraint, return ourself.
             */
            PartiallyMadePackageDepSpec & key_constraint(
                    const std::string & key, const KeyConstraintOperation, const std::string & pattern);

            /**
             * Clear choice constraints, return ourself.
             *
             * \since 0.61
             */
            PartiallyMadePackageDepSpec & clear_choices();

            /**
             * Turn ourselves into a PackageDepSpec.
             */
            operator const PackageDepSpec() const;

            /**
             * Explicitly turn ourselves into a PackageDepSpec.
             */
            const PackageDepSpec to_package_dep_spec() const;
    };

    extern template class Pimp<PartiallyMadePackageDepSpec>;
}

#endif
