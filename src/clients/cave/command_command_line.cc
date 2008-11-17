/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2008 Saleem Abdulrasool
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

#include "command_command_line.hh"

using namespace paludis;
using namespace cave;

CaveCommandCommandLine::CaveCommandCommandLine() :
    g_global_options(this, "Global Options", "Global options, used by every subcommand."),
    a_help(&g_global_options, "help", 'h', "display help message")
{
}

std::ostream &
paludis::cave::operator<< (std::ostream & os, const CaveCommandCommandLine & cmdline)
{
    os << "usage: " << cmdline.app_name() << " ";
    std::copy(cmdline.begin_usage_lines(), cmdline.end_usage_lines(),
            std::ostream_iterator<std::string>(os, "\n"));
    os << std::endl;

    os << static_cast<const args::ArgsHandler &>(cmdline);

    return os;
}

