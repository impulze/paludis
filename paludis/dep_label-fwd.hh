/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2007, 2008, 2009, 2010 Ciaran McCreesh
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

#ifndef PALUDIS_GUARD_PALUDIS_DEP_LABEL_FWD_HH
#define PALUDIS_GUARD_PALUDIS_DEP_LABEL_FWD_HH 1

#include <paludis/util/attributes.hh>
#include <paludis/util/sequence-fwd.hh>
#include <memory>
#include <iosfwd>

/** \file
 * Forward declarations for paludis/dep_label.hh .
 *
 * \ingroup g_dep_spec
 */

namespace paludis
{
    struct PALUDIS_VISIBLE URILabel;

    template <typename T_> struct PALUDIS_VISIBLE SpecificURILabel;

    struct URIMirrorsThenListedLabelTag;
    typedef SpecificURILabel<URIMirrorsThenListedLabelTag> URIMirrorsThenListedLabel;

    struct URIMirrorsOnlyLabelTag;
    typedef SpecificURILabel<URIMirrorsOnlyLabelTag> URIMirrorsOnlyLabel;

    struct URIListedOnlyLabelTag;
    typedef SpecificURILabel<URIListedOnlyLabelTag> URIListedOnlyLabel;

    struct URIListedThenMirrorsLabelTag;
    typedef SpecificURILabel<URIListedThenMirrorsLabelTag> URIListedThenMirrorsLabel;

    struct URILocalMirrorsOnlyLabelTag;
    typedef SpecificURILabel<URILocalMirrorsOnlyLabelTag> URILocalMirrorsOnlyLabel;

    struct URIManualOnlyLabelTag;
    typedef SpecificURILabel<URIManualOnlyLabelTag> URIManualOnlyLabel;

    /**
     * A URILabel can be written to a stream.
     *
     * \ingroup g_dep_spec
     * \since 0.26
     */
    std::ostream & operator<< (std::ostream &, const URILabel &) PALUDIS_VISIBLE;

    struct PALUDIS_VISIBLE DependenciesLabel;

    template <typename>
    struct SpecificDependenciesLabel;

    /**
     * Tag for DependenciesBuildLabel.
     *
     * \since 0.42
     * \ingroup g_dep_spec
     */
    struct DependenciesBuildLabelTag;

    /**
     * Dependencies label.
     *
     * \since 0.42
     * \ingroup g_dep_spec
     */
    typedef SpecificDependenciesLabel<DependenciesBuildLabelTag> DependenciesBuildLabel;

    /**
     * Tag for DependenciesRunLabel.
     *
     * \since 0.42
     * \ingroup g_dep_spec
     */
    struct DependenciesRunLabelTag;

    /**
     * Dependencies label.
     *
     * \since 0.42
     * \ingroup g_dep_spec
     */
    typedef SpecificDependenciesLabel<DependenciesRunLabelTag> DependenciesRunLabel;

    /**
     * Tag for DependenciesPostLabel.
     *
     * \since 0.42
     * \ingroup g_dep_spec
     */
    struct DependenciesPostLabelTag;

    /**
     * Dependencies label.
     *
     * \since 0.42
     * \ingroup g_dep_spec
     */
    typedef SpecificDependenciesLabel<DependenciesPostLabelTag> DependenciesPostLabel;

    /**
     * Tag for DependenciesCompileAgainstLabel.
     *
     * \since 0.42
     * \ingroup g_dep_spec
     */
    struct DependenciesCompileAgainstLabelTag;

    /**
     * Dependencies label.
     *
     * \since 0.42
     * \ingroup g_dep_spec
     */
    typedef SpecificDependenciesLabel<DependenciesCompileAgainstLabelTag> DependenciesCompileAgainstLabel;

    /**
     * Tag for DependenciesFetchLabel.
     *
     * \since 0.42
     * \ingroup g_dep_spec
     */
    struct DependenciesFetchLabelTag;

    /**
     * Dependencies label.
     *
     * \since 0.42
     * \ingroup g_dep_spec
     */
    typedef SpecificDependenciesLabel<DependenciesFetchLabelTag> DependenciesFetchLabel;

    /**
     * Tag for DependenciesInstallLabel.
     *
     * \since 0.42
     * \ingroup g_dep_spec
     */
    struct DependenciesInstallLabelTag;

    /**
     * Dependencies label.
     *
     * \since 0.42
     * \ingroup g_dep_spec
     */
    typedef SpecificDependenciesLabel<DependenciesInstallLabelTag> DependenciesInstallLabel;

    /**
     * Tag for DependenciesSuggestionLabel.
     *
     * \since 0.42
     * \ingroup g_dep_spec
     */
    struct DependenciesSuggestionLabelTag;

    /**
     * Dependencies label.
     *
     * \since 0.42
     * \ingroup g_dep_spec
     */
    typedef SpecificDependenciesLabel<DependenciesSuggestionLabelTag> DependenciesSuggestionLabel;

    /**
     * Tag for DependenciesRecommendationLabel.
     *
     * \since 0.42
     * \ingroup g_dep_spec
     */
    struct DependenciesRecommendationLabelTag;

    /**
     * Dependencies label.
     *
     * \since 0.42
     * \ingroup g_dep_spec
     */
    typedef SpecificDependenciesLabel<DependenciesRecommendationLabelTag> DependenciesRecommendationLabel;

    /**
     * Tag for DependenciesTestLabel.
     *
     * \since 0.42
     * \ingroup g_dep_spec
     */
    struct DependenciesTestLabelTag;

    /**
     * Dependencies label.
     *
     * \since 0.42
     * \ingroup g_dep_spec
     */
    typedef SpecificDependenciesLabel<DependenciesTestLabelTag> DependenciesTestLabel;

    /**
     * A collection of DependencyLabel instances.
     *
     * \ingroup g_dep_spec
     * \since 0.42
     */
    typedef Sequence<std::shared_ptr<const DependenciesLabel> > DependenciesLabelSequence;

    /**
     * A DependenciesLabel can be written to a stream.
     *
     * \ingroup g_dep_spec
     * \since 0.42
     */
    std::ostream & operator<< (std::ostream &, const DependenciesLabel &) PALUDIS_VISIBLE;
}

#endif
