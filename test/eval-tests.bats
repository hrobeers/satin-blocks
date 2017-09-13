#!/usr/bin/env bats

@test "Test script evaluation" {
    result=$(./build/bin/satin-eval | hexdump -e '/1 "%02x"')
    # SCRIPT_ERR_EQUALVERIFY = 0x0b
    [ "$result" == "0b" ]
}
