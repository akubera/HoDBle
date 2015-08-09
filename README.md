# HoDBle

A library wrapping the odbc database connection library with modern C++11
features.

With the use of variadic templates, type-safe database queries can be made
using C++11. This library tries to make use of this feature and provide an
interface to multiple database backends.

## Installation

HoDBle uses [cmake][cmake] to build and install the library, and comes with a
unix makefile to automatically setup the cmake build. To build you can either
do a raw cmake build `mkdir build && cd build && cmake ..` or have the makefile
setup cmake and build with default options: `make`.

## Using

This is a header-only library. To use, add the hodble directory to your include
path and include the hodble/hodble.hh file in your source files.

## License

This library is distributed under the Apache v2.0 license, so you may use and
modify the library.

[cmake]: http://cmake.org/
