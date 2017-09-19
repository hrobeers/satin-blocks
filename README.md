satin-blocks
============

What is satin-blocks?
--------------------

Satoshi interpreter building blocks, a commandline toolbox for composing Bitcoin script development tools.
Satin is architected as a collection of pipable building blocks and composed applications, inspired by git and gstreamer.

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

Contributing
------------

satin-blocks are pipable blocks that can be built using any language or technology.
To be considered for acceptance, contributed blocks need to nicely integrate with the build system and strong arguments should be applied to the choice of language or technology.

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
