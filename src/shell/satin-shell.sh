#! /bin/bash

prefix="satin-0.1$"

echo "satin-shell 0.1"
#echo "Type \"help\", \"copyright\", \"credits\" or \"license\" for more information."

echo -n "${prefix} "
while read input
do
    echo $input | satin-compile | satin-run
    echo -n "${prefix} "
done < /dev/tty
