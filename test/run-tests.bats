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

@test "run: pretty printing" {
    # Pipe through cat to make sure no tty is detected
    result_bin=$(echo "hello" | satin-run | cat | hexdump -e '/1 "%02x"')
    [ "$result_bin" == "13" ]

    result_text=$(echo "hello" | satin-run -t | cat)
    [ "$result_text" == "Invalid OP_IF construction" ]

    result_pretty=$(echo "hello" | satin-run -p | cat | hexdump -e '/2 "%02x"')
    [ "$result_pretty" == "5b1b3133496d766e6c6164694f205f50464963206e6f7473757274636f691b6e305b6d300a" ]
}
