#!/usr/bin/env bats

BD=${BATS_TEST_DIRNAME}/../build/bin

@test "run: success & failure" {
    # OP_1 OP_1 OP_EQUALVERIFY
    result=$(echo -en '\x51\x51\x88' | ${BD}/satin-run | hexdump -e '/1 "%02x"')
    # SCRIPT_ERR_OK = 0x00
    [ "$result" == "00" ]

    # OP_1 OP_DUP OP_HASH160 OP_5 OP_EQUALVERIFY
    result=$(echo -en '\x51\x76\xa9\x55\x88' | ${BD}/satin-run | hexdump -e '/1 "%02x"')
    # SCRIPT_ERR_EQUALVERIFY = 0x0b
    [ "$result" == "0b" ]
}

@test "run: fail on empty input" {
    # hello (some invalid data)
    result=$(echo -n '' | ${BD}/satin-run | hexdump -e '/1 "%02x"')
    # SCRIPT_ERR_BAD_OPCODE = 0x0f
    [ "$result" == "0f" ]
}
