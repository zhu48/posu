#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "posu/concepts.hpp"

TEMPLATE_TEST_CASE(
    "fundamental integral types",
    "[signed][integral][arithmetic]",
    short,
    int,
    long,
    long long)
{
    static_assert(posu::integral_arithmetic<TestType>);
    static_assert(posu::signed_arithmetic<TestType>);
    static_assert(posu::arithmetic<TestType>);
}

TEMPLATE_TEST_CASE(
    "fundamental integral types",
    "[unsigned][integral][arithmetic]",
    unsigned short,
    unsigned int,
    unsigned long,
    unsigned long long)
{
    static_assert(posu::integral_arithmetic<TestType>);
    static_assert(posu::unsigned_arithmetic<TestType>);
    static_assert(posu::arithmetic<TestType>);
}

TEMPLATE_TEST_CASE(
    "fundamental integral types",
    "[signed][floating-point][arithmetic]",
    float,
    double,
    long double)
{
    static_assert(posu::floating_point_arithmetic<TestType>);
    static_assert(posu::signed_arithmetic<TestType>);
    static_assert(posu::arithmetic<TestType>);
}

TEST_CASE("Standard integral constant values", "[integral_constant]")
{
    static_assert(posu::integral_constant<std::true_type>);
}
