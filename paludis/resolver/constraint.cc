/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2009, 2010, 2011 Ciaran McCreesh
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

#include <paludis/resolver/constraint.hh>
#include <paludis/resolver/reason.hh>
#include <paludis/util/stringify.hh>
#include <paludis/util/pimp-impl.hh>
#include <paludis/util/wrapped_forward_iterator-impl.hh>
#include <paludis/util/sequence-impl.hh>
#include <paludis/util/make_named_values.hh>
#include <paludis/serialise-impl.hh>
#include <algorithm>
#include <sstream>
#include <vector>
#include <list>

using namespace paludis;
using namespace paludis::resolver;

namespace paludis
{
    template <>
    struct Imp<Constraints>
    {
        UseExisting strictest_use_existing;
        bool nothing_is_fine_too;
        bool all_untaken;
        bool any_force_unable;

        Sequence<std::shared_ptr<const Constraint> > constraints;

        Imp() :
            strictest_use_existing(static_cast<UseExisting>(last_ue - 1)),
            nothing_is_fine_too(true),
            all_untaken(true),
            any_force_unable(false)
        {
        }
    };

    template <>
    struct WrappedForwardIteratorTraits<Constraints::ConstIteratorTag>
    {
        typedef Sequence<std::shared_ptr<const Constraint> >::ConstIterator UnderlyingIterator;
    };
}

Constraints::Constraints() :
    _imp()
{
}

Constraints::~Constraints()
{
}

bool
Constraints::all_untaken() const
{
    return _imp->all_untaken;
}

bool
Constraints::any_force_unable() const
{
    return _imp->any_force_unable;
}

bool
Constraints::nothing_is_fine_too() const
{
    return _imp->nothing_is_fine_too;
}

UseExisting
Constraints::strictest_use_existing() const
{
    return _imp->strictest_use_existing;
}

Constraints::ConstIterator
Constraints::begin() const
{
    return ConstIterator(_imp->constraints.begin());
}

Constraints::ConstIterator
Constraints::end() const
{
    return ConstIterator(_imp->constraints.end());
}

void
Constraints::add(const std::shared_ptr<const Constraint> & c)
{
    _imp->constraints.push_back(c);
    _imp->strictest_use_existing = std::min(_imp->strictest_use_existing, c->use_existing());
    _imp->nothing_is_fine_too = _imp->nothing_is_fine_too && c->nothing_is_fine_too();
    _imp->all_untaken = _imp->all_untaken && c->untaken();
    _imp->any_force_unable = _imp->any_force_unable || c->force_unable();
}

bool
Constraints::empty() const
{
    return _imp->constraints.empty();
}

void
Constraints::serialise(Serialiser & s) const
{
    s.object("Constraints")
        .member(SerialiserFlags<serialise::container>(), "items", _imp->constraints)
        ;
}

const std::shared_ptr<Constraints>
Constraints::deserialise(Deserialisation & d)
{
    Deserialisator v(d, "Constraints");
    Deserialisator vv(*v.find_remove_member("items"), "c");
    std::shared_ptr<Constraints> result(std::make_shared<Constraints>());
    for (int n(1), n_end(vv.member<int>("count") + 1) ; n != n_end ; ++n)
        result->add(vv.member<std::shared_ptr<Constraint> >(stringify(n)));
    return result;
}

void
Constraint::serialise(Serialiser & s) const
{
    s.object("Constraint")
        .member(SerialiserFlags<>(), "destination_type", stringify(destination_type()))
        .member(SerialiserFlags<>(), "force_unable", stringify(force_unable()))
        .member(SerialiserFlags<serialise::might_be_null>(), "from_id", from_id())
        .member(SerialiserFlags<>(), "nothing_is_fine_too", nothing_is_fine_too())
        .member(SerialiserFlags<serialise::might_be_null>(), "reason", reason())
        .member(SerialiserFlags<>(), "spec", spec())
        .member(SerialiserFlags<>(), "untaken", stringify(untaken()))
        .member(SerialiserFlags<>(), "use_existing", stringify(use_existing()))
        ;
}

const std::shared_ptr<Constraint>
Constraint::deserialise(Deserialisation & d)
{
    Context context("When deserialising:");

    Deserialisator v(d, "Constraint");

    const std::shared_ptr<Reason> reason(v.member<std::shared_ptr<Reason> >("reason"));
    const std::shared_ptr<const PackageID> from_id(v.member<std::shared_ptr<const PackageID> >("from_id"));

    return std::make_shared<Constraint>(make_named_values<Constraint>(
                    n::destination_type() = destringify<DestinationType>(v.member<std::string>("destination_type")),
                    n::force_unable() = v.member<bool>("force_unable"),
                    n::from_id() = from_id,
                    n::nothing_is_fine_too() = v.member<bool>("nothing_is_fine_too"),
                    n::reason() = reason,
                    n::spec() = PackageOrBlockDepSpec::deserialise(*v.find_remove_member("spec"), from_id),
                    n::untaken() = v.member<bool>("untaken"),
                    n::use_existing() = destringify<UseExisting>(v.member<std::string>("use_existing"))
            ));
}

namespace paludis
{
    template class Pimp<Constraints>;
    template class PALUDIS_VISIBLE WrappedForwardIterator<Constraints::ConstIteratorTag, const std::shared_ptr<const Constraint> >;

    template class Sequence<std::shared_ptr<const Constraint> >;
    template class PALUDIS_VISIBLE WrappedForwardIterator<ConstraintSequence::ConstIteratorTag, const std::shared_ptr<const Constraint> >;
}
