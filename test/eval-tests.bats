#!/usr/bin/env bats

@test "Test script evaluation" {
    # OP_1 OP_1 OP_EQUALVERIFY
    result=$(echo -en '\x51\x51\x88' | ./build/bin/satin-eval | hexdump -e '/1 "%02x"')
    # SCRIPT_ERR_OK = 0x00
    [ "$result" == "00" ]

    # OP_1 OP_DUP OP_HASH160 OP_5 OP_EQUALVERIFY
    result=$(echo -en '\x51\x76\xa9\x55\x88' | ./build/bin/satin-eval | hexdump -e '/1 "%02x"')
    # SCRIPT_ERR_EQUALVERIFY = 0x0b
    [ "$result" == "0b" ]
}
