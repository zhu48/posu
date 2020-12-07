# Open-Source Utilities

![Regression Tests](https://github.com/zhu48/posu/workflows/CMake/badge.svg)

This repository demonstrates using [CMake](https://cmake.org/) and
[Clang tools](https://clang.llvm.org/docs/ClangTools.html) to automate building
and testing. The stub library in this repository demonstrates using and
extending the Standard Library and its core ideals to implement highly flexible
software components.

# Building

The build script, `CMakeLists.txt`, supports GCC and Clang, and requires the
compiler to support C++20 Concepts. To build the unit tests, which are the only
things to build for this header-only library,
[Catch2](https://github.com/catchorg/Catch2) must be installed on the build
machine.

Building requires

- [CMake](https://cmake.org/)
- a GCC or Clang installation that supports C++20 Concepts
    - see the CppReference
      [compiler support page](https://en.cppreference.com/w/cpp/compiler_support)
- [Catch2](https://github.com/catchorg/Catch2)

## Procedure

To build the library, navigate to the repository root, and run the command

    cmake . -B ../build

to generate the build directory at `../build`. Then, navigate to the build
directory and run the command

    cmake --build .

to run the build. This will build the only executables that exist in this
repository, the two unit tests.

## Compiler Selection

CMake drives the compiler and manages the actual build scripts. To select a
compiler different from the system default, pass
`-DCMAKE_CXX_COMPILER=[compiler]` to CMake when setting up the build directory.
For example, to force CMake to use Clang instead of GCC on Linux, use the
command

    cmake . -B ../build -DCMAKE_CXX_COMPILER=clang++

to generate the build directory.

# Testing

To run the unit tests, first build the project. Then, navigate to the build
directory, and run the command

    ctest . --output-on-failure

to run the unit tests. The unit test framework, `Catch2`, will report any unit
test failures and errors.

# Components

The library currently consists of only two useful header-only components:

- `utility.hpp` contains two function templates that can iterate over members
  of a tuple-like object.
- `vmath.hpp` contains the class template `vmath::arith_tuple`, a tuple-like
  vector-arithmetic object.

## Utility

The `utility` header contains the function templates `for_each` and
`make_from_for_each`.

### `for_each`

`for_each` applies a given
[*Callable*](https://en.cppreference.com/w/cpp/named_req/Callable) object to
each member of a tuple-like object in index order. For example, the following
example prints

    10
    12.5
    string data

```c++
#include <iostream>
#include <string>
#include <tuple>

#include "posu/utility.hpp"

int main(int argc, char** argv) {
    const auto data = std::tuple( 10, 12.5, std::string( "string data" ) );

    posu::for_each( []( auto&& elem ) { std::cout << elem << '\n'; }, data );
}
```

### `make_from_for_each`

`make_from_for_each` does the same thing as `for_each`, but stores the result of
each call in a result object of the user's choosing. For example, the following
example prints

    8
    3.14
    another string

```c++
#include <iostream>
#include <string>
#include <tuple>

#include "posu/utility.hpp"

namespace {

    struct result_struct {
        result_struct( int i, double d, std::string s ) noexcept :
            m_integer{i},
            m_f64{d},
            m_string{std::move( s )}
        {}

        int         m_integer;
        double      m_f64;
        std::string m_string;
    };

}

int main(int argc, char** argv) {
    const auto data = std::tuple( 8, 3.14, std::string( "another string" ) );

    const auto result =
        posu::make_from_for_each<result_struct>(
            []( auto&& elem ) { return elem; },
            data );

    std::cout << result_struct.m_integer << '\n'
              << result_struct.m_f64 << '\n'
              << result_struct.m_string << '\n';
}
```

## VMath

VMath contains the class template `vmath::arith_tuple`. It implements a
statically-sized and statically-typed vector arithmetic type. For example,
the following example prints

    0
    0
    0

    1
    1
    1

    15
    15
    15

```c++
#include <iostream>

#include "posu/vmath.hpp"

int main(int argc, char** argv) {
    constexpr auto lhs = posu::vmath::arith_tuple{-1, 2, 15};
    constexpr auto rhs = posu::vmath::arith_tuple{1, -2, -15};

    // vector addition of two arithmetic tuples
    constexpr auto result_0 = lhs + rhs;
    std::cout << std::get<0>( result_0 ) << '\n'
              << std::get<1>( result_0 ) << '\n'
              << std::get<2>( result_0 ) << '\n';

    // vector-scaler addition of an arithmetic tuple and a scaler
    constexpr auto result_1 = result_0 + 1;
    std::cout << std::get<0>( new_result_1 ) << '\n'
              << std::get<1>( new_result_1 ) << '\n'
              << std::get<2>( new_result_1 ) << '\n';

    // element-wise multiplication of an arithmetic tuple and a scaler
    constexpr auto result_2 = result_0 * 15;
    std::cout << std::get<0>( new_result_2 ) << '\n'
              << std::get<1>( new_result_2 ) << '\n'
              << std::get<2>( new_result_2 ) << '\n';
}
```
