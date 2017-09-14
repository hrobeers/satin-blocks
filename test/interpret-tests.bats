#!/usr/bin/env bats

@test "Test script interpretation" {
    # opcode interpretation
    result=$(echo "OP_1 OP_DUP OP_HASH160 OP_5 OP_EQUALVERIFY" | ./build/bin/satin-interpret | hexdump -e '/1 "%02x"')
    [ "$result" == "5176a95588" ]

    # hexadecimal data pushes
    result=$(echo "0x01234567 0x89abcdef OP_EQUALVERIFY" | ./build/bin/satin-interpret | hexdump -e '/1 "%02x"')
    [ "$result" == "04012345670489abcdef88" ]
}
