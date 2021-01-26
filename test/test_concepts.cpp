#include "posu/concepts.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

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

TEST_CASE("boolean constants", "[bool_constant][integral_constant]")
{
    static_assert(posu::bool_constant<std::true_type>);
    static_assert(posu::true_constant<std::true_type>);
    static_assert(posu::integral_constant<std::true_type>);
    static_assert(posu::numeric_constant<std::true_type>);

    static_assert(posu::bool_constant<std::false_type>);
    static_assert(posu::false_constant<std::false_type>);
    static_assert(posu::integral_constant<std::false_type>);
    static_assert(posu::numeric_constant<std::false_type>);
}

TEMPLATE_TEST_CASE(
    "unsigned integral constants",
    "[unsigned][integral_constant]",
#ifdef UINT8_MAX
    std::uint8_t,
#endif
    std::uint_fast8_t,
    std::uint_least8_t,
#ifdef UINT16_MAX
    std::uint16_t,
#endif
    std::uint_fast16_t,
    std::uint_least16_t,
#ifdef UINT32_MAX
    std::uint32_t,
#endif
    std::uint_fast32_t,
    std::uint_least32_t,
#ifdef UINT64_MAX
    std::uint64_t,
#endif
    std::uint_fast64_t,
    std::uint_least64_t)
{
    using zero = std::integral_constant<TestType, 0>;
    using one  = std::integral_constant<TestType, 1>;

    static_assert(posu::meta_constant<zero, TestType>);
    static_assert(posu::unsigned_integral_constant<zero>);
    static_assert(posu::integral_constant<zero>);
    static_assert(posu::unsigned_numeric_constant<zero>);
    static_assert(posu::numeric_constant<zero>);
    static_assert(posu::unsigned_arithmetic_constant<zero>);
    static_assert(posu::arithmetic_constant<zero>);

    static_assert(posu::zero_constant<zero>);
    static_assert(posu::one_constant<one>);
}

TEMPLATE_TEST_CASE(
    "signed integral constants",
    "[signed][integral_constant]",
#ifdef INT8_MAX
    std::int8_t,
#endif
    std::int_fast8_t,
    std::int_least8_t,
#ifdef INT16_MAX
    std::int16_t,
#endif
    std::int_fast16_t,
    std::int_least16_t,
#ifdef INT32_MAX
    std::int32_t,
#endif
    std::int_fast32_t,
    std::int_least32_t,
#ifdef INT64_MAX
    std::int64_t,
#endif
    std::int_fast64_t,
    std::int_least64_t)
{
    using zero = std::integral_constant<TestType, 0>;
    using one  = std::integral_constant<TestType, 1>;

    static_assert(posu::meta_constant<zero, TestType>);
    static_assert(posu::signed_integral_constant<zero>);
    static_assert(posu::integral_constant<zero>);
    static_assert(posu::signed_numeric_constant<zero>);
    static_assert(posu::numeric_constant<zero>);
    static_assert(posu::signed_arithmetic_constant<zero>);
    static_assert(posu::arithmetic_constant<zero>);

    static_assert(posu::zero_constant<zero>);
    static_assert(posu::one_constant<one>);
}
