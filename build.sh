#!/bin/bash

BASE_DIR=$(dirname "$(readlink -f $0)")
BASE_NAME=$(basename "${BASE_DIR}")

BUILD_DIR=${BASE_DIR}/build/

mkdir -p ${BUILD_DIR} || exit $?
pushd ${BUILD_DIR}

# debug to get code coverage.
# TODO OP refer to test binary output from CMake infos
# TODO OP how have both coverage and release? two sequential builds?
cmake -DCMAKE_BUILD_TYPE=Debug ${BASE_DIR} || exit $?
make -j4 || exit $?
