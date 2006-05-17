#!/bin/bash
# vim: set sw=4 sts=4 et :

# Copyright (c) 2006 Ciaran McCreesh <ciaran.mccreesh@blueyonder.co.uk>
#
# Based in part upon ebuild.sh from Portage, which is Copyright 1995-2005
# Gentoo Foundation and distributed under the terms of the GNU General
# Public License v2.
#
# This file is part of the Paludis package manager. Paludis is free software;
# you can redistribute it and/or modify it under the terms of the GNU General
# Public License as published by the Free Software Foundation; either version
# 2 of the License, or (at your option) any later version.
#
# Paludis is distributed in the hope that it will be useful, but WITHOUT ANY
# WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
# details.
#
# You should have received a copy of the GNU General Public License along with
# this program; if not, write to the Free Software Foundation, Inc., 59 Temple
# Place, Suite 330, Boston, MA  02111-1307  USA

COLOUR_GOOD=$'\e[32;01m'
COLOUR_WARN=$'\e[33;01m'
COLOUR_BAD=$'\e[31;01m'
COLOUR_BRACKET=$'\e[34;01m'
COLOUR_NORMAL=$'\e[0m'
PALUDIS_ENDCOL=$'\e[A\e['$(( ${COLUMNS:-80} - 7 ))'G'

einfon()
{
    echo -ne " ${COLOUR_GOOD}*${COLOUR_NORMAL} $*"
    PALUDIS_LAST_E_CMD=einfon
}

einfo()
{
    einfon "$*\n"
    PALUDIS_LAST_E_CMD=einfo
}

ewarn()
{
    echo -e " ${COLOUR_WARN}*${COLOUR_NORMAL} $*"
    PALUDIS_LAST_E_CMD=ewarn
}

eerror()
{
    echo -e " ${COLOUR_BAD}*${COLOUR_NORMAL} $*"
    PALUDIS_LAST_E_CMD=eerror
}

ebegin()
{
    einfo "$* ..."
    PALUDIS_LAST_E_CMD=ebegin
    PALUDIS_LAST_E_LEN=$(( 4 + ${#msg} ))
}

_eend()
{
    local retval=${1:-0} efunc=${2:-eerror} msg
    shift 2

    if [[ ${retval} == 0 ]]; then
        msg="${COLOUR_BRACKET}[ ${COLOUR_GOOD}ok${COLOUR_BRACKET} ]${COLOUR_NORMAL}"
    else
        if [[ -n "$*" ]]; then
            ${efunc} $*
        fi
        msg="${COLOUR_BRACKET}[ ${COLOUR_BAD}!!${COLOUR_BRACKET} ]${COLOUR_NORMAL}"
    fi

#    printf "%$(( ${COLUMNS:-80} - PALUDIS_LAST_E_LEN - 6))s%b\n" '' "${msg}"
    echo -e "${PALUDIS_ENDCOL} ${msg}"

    return ${retval}
}

eend()
{
    local retval=${1:-0}
    shift
    _eend ${retval} eerror "$*"
    PALUDIS_LAST_E_CMD=eend
    return ${retval}
}

ewend()
{
    local retval=${1:-0}
    shift
    _eend ${retval} ewarn "$*"
    PALUDIS_LAST_E_CMD=ewend
    return ${retval}
}

use_with()
{
    if useq "${1}" ; then
        echo "--with-${2:-${1}}${3+=${3}}"
    else
        echo "--without-${2:-${1}}"
    fi
}

use_enable()
{
    if useq "${1}" ; then
        echo "--enable-${2:-${1}}${3+=${3}}"
    else
        echo "--disable-${2:-${1}}"
    fi
}

ebuild_notice_level()
{
    case "$1" in
        debug)
            echo "1";
            ;;

        qa)
            echo "2";
            ;;

        warning)
            echo "3";
            ;;

        silent)
            echo "4";
            ;;

        *)
            echo "[WARNING.EBUILD] Bad value '$1' for qa level" 1>&2
            echo "2";
            ;;
    esac
}

ebuild_notice()
{
    local level="$1"
    shift

    local level_num=$(ebuild_notice_level "${level}" )
    local min_level_num=$(ebuild_notice_level "${PALUDIS_EBUILD_LOG_LEVEL}" )

    if [[ "${level_num}" -ge "${min_level_num}" ]] ; then
        local upper_level=$(echo ${level} | ${ebuild_real_tr:-tr} '[:lower:]' '[:upper:]' )
        echo -n "${EBUILD_PROGRAM_NAME:-ebuild.bash}@$(date +%s ): " 1>&2
        echo "[${upper_level}.EBUILD] $* (from ${EBUILD:-?})" 1>&2
    fi
    true
}

ebuild_section()
{
    echo ">>> $*"
}

