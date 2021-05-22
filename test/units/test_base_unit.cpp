#include "posu/units/base_unit.hpp"

#include <catch2/catch.hpp>

namespace {

    struct amount_of_ingredients {
        using type       = amount_of_ingredients;
        using value_type = std::string_view;
        using dimensions = type;
        using kind_type  = type;

        static constexpr auto value = std::string_view{"amount of ingredients"};

        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
    };

    struct distance_traveled {
        using type       = distance_traveled;
        using value_type = std::string_view;
        using dimensions = type;
        using kind_type  = type;

        static constexpr auto value = std::string_view{"distance traveled"};

        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
    };

} // namespace

namespace posu::units {

    template<>
    inline constexpr bool enable_as_dimension<amount_of_ingredients> = true;

    template<>
    inline constexpr bool enable_as_kind<amount_of_ingredients> = true;

    template<>
    inline constexpr bool enable_as_unit<amount_of_ingredients> = true;

    template<>
    inline constexpr bool enable_as_dimension<distance_traveled> = true;

    template<>
    inline constexpr bool enable_as_kind<distance_traveled> = true;

    template<>
    inline constexpr bool enable_as_unit<distance_traveled> = true;

} // namespace posu::units

namespace {

    template<typename Rep, typename Period>
    using ingredients = posu::units::quantity<Rep, Period, amount_of_ingredients>;
    using drop        = ingredients<int, std::milli>;
    using dash        = ingredients<int, std::deci>;
    using pinch       = ingredients<int, std::ratio<1>>;
    using dollop      = ingredients<int, std::kilo>;

    template<typename Rep, typename Period>
    using distance = posu::units::quantity<Rep, Period, distance_traveled>;
    using skip     = distance<int, std::milli>;
    using hop      = distance<int, std::deci>;
    using stretch  = distance<int, std::ratio<1>>;
    using trek     = distance<int, std::kilo>;

} // namespace

TEMPLATE_TEST_CASE(
    "conversion rules",
    "[construct][convert]",
    (std::tuple<
        dollop,
        pinch,
        ingredients<int, std::ratio<1, 3>>,
        ingredients<int, std::ratio<1, 5>>,
        ingredients<double, std::ratio<1>>,
        stretch>),
    (std::tuple<
        trek,
        stretch,
        distance<int, std::ratio<1, 3>>,
        distance<int, std::ratio<1, 5>>,
        distance<double, std::ratio<1>>,
        pinch>))
{
    using kilo_type      = std::tuple_element_t<0, TestType>;
    using base_type      = std::tuple_element_t<1, TestType>;
    using third_type     = std::tuple_element_t<2, TestType>;
    using fifth_type     = std::tuple_element_t<3, TestType>;
    using double_type    = std::tuple_element_t<4, TestType>;
    using unrelated_type = std::tuple_element_t<5, TestType>;

    SECTION("implicit and explicit conversion")
    {
        SECTION("representation type")
        {
            static_assert(
                std::constructible_from<base_type, typename base_type::rep>,
                "base_type must be explicitly constructible from its "
                "representation type");
            static_assert(
                !std::convertible_to<base_type, typename base_type::rep>,
                "base_type must not be implicitly constructible from its "
                "representation type");
        }
        SECTION("wholly-divisible types")
        {
            static_assert(
                std::convertible_to<kilo_type, base_type>,
                "values with larger units must be convertible to values with "
                "smaller units");
            static_assert(
                !std::convertible_to<base_type, kilo_type>,
                "values with smaller units must not be convertible to values "
                "with larger units");
        }
        SECTION("non-wholly-divisible types")
        {
            static_assert(
                !std::convertible_to<fifth_type, third_type>,
                "values that are not unit-multiples of each others must not "
                "convert");
            static_assert(
                !std::convertible_to<third_type, fifth_type>,
                "values that are not unit-multiples of each others must not "
                "convert");
        }
        SECTION("integer-floating conversions")
        {
            static_assert(
                std::convertible_to<base_type, double_type>,
                "integer-representation values must convert to "
                "floating-point-representation values");
            static_assert(
                !std::convertible_to<double_type, base_type>,
                "floating-point-representation values must not convert to "
                "integer-representation values");
        }
        SECTION("unrelated base units")
        {
            static_assert(
                !std::constructible_from<base_type, unrelated_type>,
                "unrelated units should not convert to each other");
            static_assert(
                !std::constructible_from<unrelated_type, base_type>,
                "unrelated units should not convert to each other");
            static_assert(
                !std::convertible_to<base_type, unrelated_type>,
                "unrelated units should not convert to each other");
            static_assert(
                !std::convertible_to<unrelated_type, base_type>,
                "unrelated units should not convert to each other");
        }
    }
}

TEST_CASE("comparison operations", "[compare]")
{
    REQUIRE(drop(1) < dash(1));
    REQUIRE(drop(1) <= dash(1));
    REQUIRE(drop(100) <= dash(1));
    REQUIRE(drop(100) == dash(1));
    REQUIRE(drop(100) >= dash(1));
    REQUIRE(drop(1000) >= dash(1));
    REQUIRE(drop(1000) > dash(1));
}

TEMPLATE_TEST_CASE(
    "arithmetic operations on the same type",
    "[arithmetic]",
    drop,
    dash,
    pinch,
    dollop,
    skip,
    hop,
    stretch,
    trek)
{
    SECTION("unary +/-")
    {
        constexpr auto value = TestType(1);

        REQUIRE(TestType(1) == +value);
        REQUIRE(TestType(-1) == -value);
    }

    SECTION("increment/decrement")
    {
        auto value = TestType(0);

        REQUIRE(--value == TestType(-1));
        REQUIRE(value == TestType(-1));
        REQUIRE(value-- == TestType(-1));
        REQUIRE(value == TestType(-2));
        REQUIRE(++value == TestType(-1));
        REQUIRE(value == TestType(-1));
        REQUIRE(value++ == TestType(-1));
        REQUIRE(value == TestType(0));
    }

    SECTION("arithmetic assignment")
    {
        auto value = TestType(0);

        REQUIRE((value += TestType(1)) == TestType(1));
        REQUIRE((value -= TestType(2)) == TestType(-1));
        REQUIRE((value *= 100) == TestType(-100));
        REQUIRE((value /= -2) == TestType(50));
        REQUIRE((value %= 30) == TestType(20));
        REQUIRE((value %= TestType(15)) == TestType(5));
    }

    SECTION("arithmetics")
    {
        constexpr auto lhs = TestType(10);
        constexpr auto rhs = TestType(2);

        REQUIRE((lhs + rhs) == TestType(12));
        REQUIRE((lhs - rhs) == TestType(8));
        REQUIRE((lhs * 4) == TestType(40));
        REQUIRE((3 * rhs) == TestType(6));
        REQUIRE((lhs / rhs) == 5);
        REQUIRE((lhs / 5) == TestType(2));
        REQUIRE((lhs % rhs) == TestType(0));
        REQUIRE((lhs % 7) == TestType(3));
    }
}

TEST_CASE("arithmetic operations on related types", "[arithmetic]")
{
    REQUIRE((drop(2) + pinch(1)) == drop(1002));
    REQUIRE((pinch(1) - drop(250)) == drop(750));
    REQUIRE((pinch(1) / drop(250)) == 4);
    REQUIRE((drop(2500) % pinch(1)) == drop(500));
}
