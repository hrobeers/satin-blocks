#!/bin/bash

SCRIPT_DIR=$(dirname "$(readlink -f $0)")
mkdir -p ${SCRIPT_DIR}/../deps
pushd ${SCRIPT_DIR}/../deps

git clone --branch v1.3.6 --depth 1 https://github.com/bitcoinclassic/bitcoinclassic
pushd bitcoinclassic

echo ""
echo "Running autogen.sh"
./autogen.sh

echo ""
echo "Running configure"
./configure --without-gui --disable-wallet --disable-tests --without-qrencode --without-miniupnpc --disable-zmq --disable-hardening

echo ""
echo "Compiling"
make -j4
