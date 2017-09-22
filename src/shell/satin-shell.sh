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

# Forward generic options to satin-help
ARGS=`getopt -o av --long about,version -n 'satin-shell' -- "$@"`
if [[ $ARGS != " --"* ]]
then
    satin-help $ARGS
    exit 0
fi

prefix="satin-0.1$"

echo "satin-shell 0.1"
#echo "Type \"help\", \"copyright\", \"credits\" or \"license\" for more information."

echo -n "${prefix} "
while read input
do
    echo $input | satin-compile | satin-run
    echo -n "${prefix} "
done < /dev/tty
