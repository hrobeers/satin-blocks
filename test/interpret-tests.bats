#!/usr/bin/env bats

@test "Test script interpretation" {
    result=$(./build/bin/satin-interpret | hexdump -e '/1 "%x"')
    # OP_1 OP_DUP OP_HASH160 OP_5 OP_EQUALVERIFY
    [ "$result" == "5176a95588" ]
}
