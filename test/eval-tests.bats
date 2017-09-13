#!/usr/bin/env bats

@test "Test script evaluation" {
    script="OP_1 OP_DUP OP_HASH160 OP_5 OP_EQUALVERIFY"
    result=$(echo $script | ./build/bin/satin-interpret | ./build/bin/satin-eval | hexdump -e '/1 "%02x"')
    # SCRIPT_ERR_EQUALVERIFY = 0x0b
    [ "$result" == "0b" ]
}
