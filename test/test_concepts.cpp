#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "posu/concepts.hpp"

TEMPLATE_TEST_CASE(
    "fundamental integral types",
    "[integral][arithmetic]",
    short,
    unsigned short,
    int,
    unsigned int,
    long,
    unsigned long,
    long long,
    unsigned long long)
{
    static_assert(posu::integral_arithmetic<TestType>);
    static_assert(posu::arithmetic<TestType>);
}

TEMPLATE_TEST_CASE(
    "fundamental integral types",
    "[integral][arithmetic]",
    float,
    double,
    long double)
{
    static_assert(posu::floating_point_arithmetic<TestType>);
    static_assert(posu::arithmetic<TestType>);
}

TEST_CASE("Standard integral constant values", "[integral_constant]")
{
    static_assert(posu::integral_constant<std::true_type>);
}
