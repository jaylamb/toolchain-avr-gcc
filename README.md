# toolchain-avr-gcc
![CI](https://github.com/apcountryman/toolchain-avr-gcc/workflows/CI/badge.svg)

`toolchain-avr-gcc` is a CMake toolchain for cross compiling for the Atmel AVR family of
microcontrollers using avr-gcc.
In addition to configuring CMake for cross compiling with avr-gcc, the toolchain provides
an optional function that acts as a wrapper of avrdude for programming and verifying the
microcontroller's Flash and/or EEPROM.

## Obtaining the Source Code
HTTPS:
```shell
git clone https://github.com/apcountryman/toolchain-avr-gcc.git
```
SSH:
```shell
git clone git@github.com:apcountryman/toolchain-avr-gcc.git
```

## Usage (Dependency)
To use this toolchain, simply set `CMAKE_TOOLCHAIN_FILE` to the path to this repository's
`toolchain.cmake` file when initializing CMake.

Documentation for the usage of `add_avrdude_programming_targets()` and the targets it
creates [can be found in the `toolchain.cmake` file in this repository](toolchain.cmake).
Usage examples [can be found in the `examples` directory in this repository](examples).

### Finding Tools
This toolchain expects to find `avr-gcc`, `avr-g++`, associated binary utilities, and
`avrdude` in the path(s) searched by CMake's `find_program()` command.
`avrdude` is only required if `add_avrdude_programming_targets()` is used.
If the toolchain fails to locate tools, consult the documentation for CMake's
`find_program()` command.

## Usage (Development)
This repository's Git `pre-commit` hook script is the simplest way to configure, build,
and test this project during development.
See the `pre-commit` script's help text for usage details.
```shell
./git/hooks/pre-commit --help
```

Additional checks, such as static analysis, are performed by this project's GitHub Actions
CI workflow.

## Versioning
Post version 0.3.0, `toolchain-avr-gcc` will follow the [Abseil Live at Head
philosophy](https://abseil.io/about/philosophy).

## Workflow
`toolchain-avr-gcc` uses the [GitHub flow](https://guides.github.com/introduction/flow/)
workflow.

## Git Hooks
To install this repository's Git hooks, run the `install` script located in the
`git/hooks` directory.
See the script's help text for usage details.
```
$ ./git/hooks/install --help
```

## Authors
- Andrew Countryman

## License
`toolchain-avr-gcc` is licensed under the Apache License, Version 2.0.
For more information, [see the LICENSE file in this repository](LICENSE).
