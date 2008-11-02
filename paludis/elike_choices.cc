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

#include <paludis/elike_choices.hh>
#include <paludis/environment.hh>
#include <paludis/util/tribool.hh>
#include <paludis/util/stringify.hh>

using namespace paludis;

const UnprefixedChoiceName
ELikeStripChoiceValue::canonical_unprefixed_name()
{
    return UnprefixedChoiceName("strip");
}

const ChoiceNameWithPrefix
ELikeStripChoiceValue::canonical_name_with_prefix()
{
    return ChoiceNameWithPrefix(stringify(canonical_build_options_prefix()) + ":" + stringify(canonical_unprefixed_name()));
}

ELikeStripChoiceValue::ELikeStripChoiceValue(const std::tr1::shared_ptr<const PackageID> & id,
        const Environment * const env, const std::tr1::shared_ptr<const Choice> & choice) :
    _enabled(! env->want_choice_enabled(id, choice, canonical_unprefixed_name()).is_false())
{
}

const UnprefixedChoiceName
ELikeStripChoiceValue::unprefixed_name() const
{
    return canonical_unprefixed_name();
}

const ChoiceNameWithPrefix
ELikeStripChoiceValue::name_with_prefix() const
{
    return canonical_name_with_prefix();
}

bool
ELikeStripChoiceValue::enabled() const
{
    return _enabled;
}

bool
ELikeStripChoiceValue::enabled_by_default() const
{
    return true;
}

bool
ELikeStripChoiceValue::locked() const
{
    return false;
}

const std::string
ELikeStripChoiceValue::description() const
{
    return "Strip binaries and libraries before installation";
}

bool
ELikeStripChoiceValue::explicitly_listed() const
{
    return true;
}

const UnprefixedChoiceName
ELikeSplitChoiceValue::canonical_unprefixed_name()
{
    return UnprefixedChoiceName("split");
}

const ChoiceNameWithPrefix
ELikeSplitChoiceValue::canonical_name_with_prefix()
{
    return ChoiceNameWithPrefix(stringify(canonical_build_options_prefix()) + ":" + stringify(canonical_unprefixed_name()));
}

ELikeSplitChoiceValue::ELikeSplitChoiceValue(const std::tr1::shared_ptr<const PackageID> & id,
        const Environment * const env, const std::tr1::shared_ptr<const Choice> & choice) :
    _enabled(! env->want_choice_enabled(id, choice, canonical_unprefixed_name()).is_false())
{
}

const UnprefixedChoiceName
ELikeSplitChoiceValue::unprefixed_name() const
{
    return canonical_unprefixed_name();
}

const ChoiceNameWithPrefix
ELikeSplitChoiceValue::name_with_prefix() const
{
    return canonical_name_with_prefix();
}

bool
ELikeSplitChoiceValue::enabled() const
{
    return _enabled;
}

bool
ELikeSplitChoiceValue::enabled_by_default() const
{
    return true;
}

bool
ELikeSplitChoiceValue::locked() const
{
    return false;
}

const std::string
ELikeSplitChoiceValue::description() const
{
    return "Split debugging information out from binaries and libraries before installation";
}

bool
ELikeSplitChoiceValue::explicitly_listed() const
{
    return true;
}

const UnprefixedChoiceName
ELikeOptionalTestsChoiceValue::canonical_unprefixed_name()
{
    return UnprefixedChoiceName("optional_tests");
}

const ChoiceNameWithPrefix
ELikeOptionalTestsChoiceValue::canonical_name_with_prefix()
{
    return ChoiceNameWithPrefix(stringify(canonical_build_options_prefix()) + ":" + stringify(canonical_unprefixed_name()));
}

ELikeOptionalTestsChoiceValue::ELikeOptionalTestsChoiceValue(const std::tr1::shared_ptr<const PackageID> & id,
        const Environment * const env, const std::tr1::shared_ptr<const Choice> & choice) :
    _enabled(env->want_choice_enabled(id, choice, canonical_unprefixed_name()).is_true())
{
}

const UnprefixedChoiceName
ELikeOptionalTestsChoiceValue::unprefixed_name() const
{
    return canonical_unprefixed_name();
}

const ChoiceNameWithPrefix
ELikeOptionalTestsChoiceValue::name_with_prefix() const
{
    return canonical_name_with_prefix();
}

bool
ELikeOptionalTestsChoiceValue::enabled() const
{
    return _enabled;
}

bool
ELikeOptionalTestsChoiceValue::enabled_by_default() const
{
    return false;
}

bool
ELikeOptionalTestsChoiceValue::locked() const
{
    return false;
}

const std::string
ELikeOptionalTestsChoiceValue::description() const
{
    return "Run tests considered by the package to be optional";
}

bool
ELikeOptionalTestsChoiceValue::explicitly_listed() const
{
    return true;
}

const UnprefixedChoiceName
ELikeRecommendedTestsChoiceValue::canonical_unprefixed_name()
{
    return UnprefixedChoiceName("recommended_tests");
}

const ChoiceNameWithPrefix
ELikeRecommendedTestsChoiceValue::canonical_name_with_prefix()
{
    return ChoiceNameWithPrefix(stringify(canonical_build_options_prefix()) + ":" + stringify(canonical_unprefixed_name()));
}

ELikeRecommendedTestsChoiceValue::ELikeRecommendedTestsChoiceValue(const std::tr1::shared_ptr<const PackageID> & id,
        const Environment * const env, const std::tr1::shared_ptr<const Choice> & choice) :
    _enabled(! env->want_choice_enabled(id, choice, canonical_unprefixed_name()).is_false())
{
}

const UnprefixedChoiceName
ELikeRecommendedTestsChoiceValue::unprefixed_name() const
{
    return canonical_unprefixed_name();
}

const ChoiceNameWithPrefix
ELikeRecommendedTestsChoiceValue::name_with_prefix() const
{
    return canonical_name_with_prefix();
}

bool
ELikeRecommendedTestsChoiceValue::enabled() const
{
    return _enabled;
}

bool
ELikeRecommendedTestsChoiceValue::enabled_by_default() const
{
    return true;
}

bool
ELikeRecommendedTestsChoiceValue::locked() const
{
    return false;
}

const std::string
ELikeRecommendedTestsChoiceValue::description() const
{
    return "Run tests considered by the package to be recommended";
}

bool
ELikeRecommendedTestsChoiceValue::explicitly_listed() const
{
    return true;
}

const ChoicePrefixName
paludis::canonical_build_options_prefix()
{
    return ChoicePrefixName("build_options");
}

const std::string
paludis::canonical_build_options_raw_name()
{
    return "build_options";
}

const std::string
paludis::canonical_build_options_human_name()
{
    return "Build Options";
}
