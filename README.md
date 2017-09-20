satin-blocks
============

What is satin-blocks?
--------------------

Satoshi interpreter building blocks, a commandline toolbox for composing Bitcoin script development tools.
Satin is architected as a collection of pipable building blocks and composed applications, inspired by git, gstreamer and the Unix philosophy.

#### Blocks

| Name          | Lang | Description |
|---------------|------|-------------|
| satin-compile | C++  | Satoshi script compiler: translates human readable scripts into binary input for the runtime (satin-run). |
| satin-run     | C++  | Satoshi runtime: runtime for compiled scripts. |

#### Applications

| Name          | Lang | Description |
|---------------|------|-------------|
| satin-shell   | Bash | Simple shell for interactive script evaluation. |

OS support
----------

- GNU/Linux: fully supported.
- POSIX (including Cygwin): all code should be POSIX compliant, but builds might break.
- Windows: compatibility fixes are accepted if not too invasive, otherwise use Cygwin.

License
-------

satin-blocks is released under the terms of the GPLv3 license. See [LICENSE.md](LICENSE.md) for more
information or see https://opensource.org/licenses/GPL-3.0.

Compiling from source
---------------------

#### Dependencies

C++11 compliant compiler
CMake
Boost

#### Build steps

Satin statically links to bitcoinclassic's libbitcoin_*.a libraries.
CMake is able to autodetect headers and libs when installed in include and lib folders.
If not, fetch and compile them using the build-libbitcoin script:

```scripts/build-libbitcoin.sh```

Building satin:

```scripts/build.sh```

If you are familiar with CMake, the `build.sh` script is a simple wrapper around the cmake and make command, make sure to check it out.

Installing satin:

```
cd build
sudo make install
```

Contributing
------------

satin-blocks are composable blocks that can be built using any language or technology.
Contributions should adhere to the Unix philosophy as stated below.
To be considered for acceptance, contributed blocks need to nicely integrate with the build system and strong arguments should be applied to the choice of language or technology.

#### Unix philosophy

The UNIX philosophy is documented by Doug McIlroy in the Bell System Technical Journal from 1978:

- Make each program do one thing well. To do a new job, build afresh rather than complicate old programs by adding new "features".
- Expect the output of every program to become the input to another, as yet unknown, program. Don't clutter output with extraneous information. Avoid stringently columnar or binary input formats. Don't insist on interactive input.
- Design and build software, even operating systems, to be tried early, ideally within weeks. Don't hesitate to throw away the clumsy parts and rebuild them.
- Use tools in preference to unskilled help to lighten a programming task, even if you have to detour to build the tools and expect to throw some of them out after you've finished using them.

Satin does not fully comply with the second rule for the communication with the runtime `statin-run`.
Communication with the runtime uses a binary representation of input scripts and runtime output.
The binary runtime protocol makes the system more modular by allowing reimplementation of the pre- and post-processors of the runtime.

For more information read Eric Raymond’s 17 Unix Rules in [UNIX_RULES.md](UNIX_RULES.md).

#### Preferred languages/technologies

- C++
- Rust
- Bash
- Python3
- C

#### Rejected languages/technologies

- node.js
- Python2
- JVM
- .Net
- Go
