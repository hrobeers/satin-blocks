#! /bin/bash

# Copyright (C) 2017 hrobeers (https://github.com/hrobeers)
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# Parse options to forward to satin-help
ARGS=`getopt -o av --long about,version -n 'satin-shell' -- "$@"`

# start the default satin shell if no valid arguments are provided
if [ "$ARGS" == " --" ]
then
    satin-shell
    exit $?
fi

# interpret the file contents of the first positional argument
if [[ $ARGS == " -- "* ]]
then
    cat "$1" | satin-compile | satin-run
    exit $?
fi

# other wise print help (valid satin-help options are provided)
satin-help $ARGS
exit 0
