/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2011 Ciaran McCreesh
 * Copyright (c) 2011 Kim Højgaard-Hansen
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

#include "cmd_mirror.hh"
#include "exceptions.hh"

#include <paludis/args/args.hh>
#include <paludis/args/do_help.hh>

#include <paludis/util/set.hh>
#include <paludis/util/wrapped_forward_iterator.hh>
#include <paludis/util/indirect_iterator-impl.hh>
#include <paludis/util/visitor_cast.hh>
#include <paludis/util/iterator_funcs.hh>
#include <paludis/util/map.hh>
#include <paludis/util/make_named_values.hh>
#include <paludis/util/make_null_shared_ptr.hh>
#include <paludis/util/stringify.hh>

#include <paludis/name.hh>
#include <paludis/environment.hh>
#include <paludis/repository.hh>
#include <paludis/generator.hh>
#include <paludis/filtered_generator.hh>
#include <paludis/filter.hh>
#include <paludis/filter_handler.hh>
#include <paludis/selection.hh>
#include <paludis/user_dep_spec.hh>
#include <paludis/package_id.hh>
#include <paludis/mask.hh>
#include <paludis/metadata_key.hh>
#include <paludis/standard_output_manager.hh>
#include <paludis/action.hh>
#include <paludis/partially_made_package_dep_spec.hh>

#include <cstdlib>
#include <iostream>
#include <algorithm>

#include "command_command_line.hh"

using namespace paludis;
using namespace cave;
using std::cout;
using std::endl;

namespace
{
    struct MirrorCommandLine :
        CaveCommandCommandLine
    {
        virtual std::string app_name() const
        {
            return "cave mirror";
        }

        virtual std::string app_synopsis() const
        {
            return "Fetches files for a set of IDs.";
        }

        virtual std::string app_description() const
        {
            return "Fetches files for a set of IDs.";
        }

        args::ArgsGroup g_filters;
        args::StringSetArg a_matching;

        MirrorCommandLine() :
            g_filters(main_options_section(), "Filters", "Filter the output. Each filter may be specified more than once."),
            a_matching(&g_filters, "matching", 'm', "Consider only IDs matching this spec.",
                    args::StringSetArg::StringSetArgOptions())
        {
            add_usage_line("[ --matching spec ]");
        }
    };

    std::shared_ptr<OutputManager> make_standard_output_manager(const Action &)
    {
        return std::make_shared<StandardOutputManager>();
    }

    WantPhase want_all_phases(const std::string &)
    {
        return wp_yes;
    }
}

int
MirrorCommand::run(
        const std::shared_ptr<Environment> & env,
        const std::shared_ptr<const Sequence<std::string > > & args
        )
{
    MirrorCommandLine cmdline;
    cmdline.run(args, "CAVE", "CAVE_MIRROR_OPTIONS", "CAVE_MIRROR_CMDLINE");

    if (cmdline.a_help.specified())
    {
        cout << cmdline;
        return EXIT_SUCCESS;
    }

    if (cmdline.begin_parameters() != cmdline.end_parameters())
        throw args::DoHelp("mirror takes no parameters");

    Generator g((generator::All()));
    if (cmdline.a_matching.specified())
    {
        for (args::StringSetArg::ConstIterator m(cmdline.a_matching.begin_args()),
                m_end(cmdline.a_matching.end_args()) ;
                m != m_end ; ++m)
        {
            PackageDepSpec s(parse_user_package_dep_spec(*m, env.get(), { updso_allow_wildcards }));
            g = g & generator::Matches(s, make_null_shared_ptr(), { });
        }
    }

    const std::shared_ptr<const PackageIDSequence> ids((*env)[selection::AllVersionsSorted(g)]);

    for (PackageIDSequence::ConstIterator i(ids->begin()), i_end(ids->end()) ;
            i != i_end ; ++i)
    {
        Context i_context("When fetching ID '" + stringify(**i) + "':");

        FetchAction a(make_named_values<FetchActionOptions>(
                    n::errors() = std::make_shared<Sequence<FetchActionFailure>>(),
                    n::exclude_unmirrorable() = true,
                    n::fetch_parts() = FetchParts() + fp_regulars + fp_unneeded,
                    n::ignore_not_in_manifest() = false,
                    n::ignore_unfetched() = false,
                    n::make_output_manager() = &make_standard_output_manager,
                    n::safe_resume() = true,
                    n::want_phase() = &want_all_phases
                    ));

        if ((*i)->supports_action(SupportsActionTest<FetchAction>()))
        {
            cout << "Fetching " << **i << "..." << endl;
            (*i)->perform_action(a);
        }
        else
            cout << "No fetching supported for " << **i << endl;

        cout << endl;
    }

    return EXIT_SUCCESS;
}

std::shared_ptr<args::ArgsHandler>
MirrorCommand::make_doc_cmdline()
{
    return std::make_shared<MirrorCommandLine>();
}

CommandImportance
MirrorCommand::importance() const
{
    return ci_development;
}

