#!/usr/bin/env bats

BD=${BATS_TEST_DIRNAME}/../build/bin

@test "compile: opcode interpretation" {
    result=$(echo "OP_1 OP_DUP OP_HASH160 OP_5 OP_EQUALVERIFY" | ${BD}/satin-compile | hexdump -e '/1 "%02x"')
    [ "$result" == "5176a95588" ]
}

@test "compile: hexadecimal data pushes" {
    result=$(echo "0x01234567 0x89abcdef OP_EQUALVERIFY" | ${BD}/satin-compile | hexdump -e '/1 "%02x"')
    [ "$result" == "04012345670489abcdef88" ]
}

@test "compile: handle invalid inputs" {
    result=$(echo "hello" | ${BD}/satin-compile | hexdump -e '/1 "%02x"')
    # OP_INVALIDOPCODE = 0xff
    [ "$result" = "ff" ]
}
