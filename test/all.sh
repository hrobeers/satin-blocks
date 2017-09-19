# Run this file to run all the tests, once
TEST_DIR=$(dirname "$(readlink -f $0)")
bats ${TEST_DIR}/*.bats
