#!/usr/bin/env bats

@test "Test script evaluation" {
    result=$(./build/bin/satin-eval | hexdump -e '/1 "%x"')
    # SCRIPT_ERR_EQUALVERIFY = 0xba
    [ "$result" == "ba" ]
}
