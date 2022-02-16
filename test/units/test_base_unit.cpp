#include "posu/units/base_unit.hpp"

#define CATCH_CONFIG_PREFIX_ALL

#include <catch2/catch.hpp>

namespace {

    struct amount_of_ingredients {
        using type       = amount_of_ingredients;
        using value_type = std::string_view;
        using dimensions = type;
        using kind_type  = type;
        using period     = posu::ratio<1>;

        static constexpr auto value = std::string_view{"amount of ingredients"};

        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
    };

    struct distance_traveled {
        using type       = distance_traveled;
        using value_type = std::string_view;
        using dimensions = type;
        using kind_type  = type;
        using period     = posu::ratio<1>;

        static constexpr auto value = std::string_view{"distance traveled"};

        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
    };

} // namespace

template<std::intmax_t Num, std::intmax_t Den, std::intmax_t Exp>
struct Catch::StringMaker<posu::ratio<Num, Den, Exp>> {
    static std::string convert(const posu::ratio<Num, Den, Exp>& /*unused*/)
    {
        return '(' + std::to_string(Num) + '/' + std::to_string(Den) + ")e" + std::to_string(Exp);
    }
};

template<posu::units::quantity_of_measure Quantity>
struct Catch::StringMaker<Quantity> {
    static std::string convert(const Quantity& value)
    {
        return std::to_string(value.count()) + ' ' +
               StringMaker<posu::units::period_t<Quantity>>::convert(
                   posu::units::period_t<Quantity>{}) +
               ' ' +
               StringMaker<posu::units::period_t<posu::units::unit_t<Quantity>>>::convert(
                   posu::units::period_t<posu::units::unit_t<Quantity>>{}) +
               ' ' + std::string(Quantity::unit_type::value);
    }
};

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
    using drop        = ingredients<int, posu::milli>;
    using dash        = ingredients<int, posu::deci>;
    using pinch       = ingredients<int, posu::ratio<1>>;
    using dollop      = ingredients<int, posu::kilo>;

    template<typename Rep, typename Period>
    using distance = posu::units::quantity<Rep, Period, distance_traveled>;
    using skip     = distance<int, posu::milli>;
    using hop      = distance<int, posu::deci>;
    using stretch  = distance<int, posu::ratio<1>>;
    using trek     = distance<int, posu::kilo>;

} // namespace

CATCH_TEMPLATE_TEST_CASE(
    "conversion rules",
    "[construct][convert]",
    (std::tuple<
        dollop,
        pinch,
        ingredients<int, posu::ratio<1, 3>>,
        ingredients<int, posu::ratio<1, 5>>,
        ingredients<double, posu::ratio<1>>,
        stretch>),
    (std::tuple<
        trek,
        stretch,
        distance<int, posu::ratio<1, 3>>,
        distance<int, posu::ratio<1, 5>>,
        distance<double, posu::ratio<1>>,
        pinch>))
{
    using kilo_type      = std::tuple_element_t<0, TestType>;
    using base_type      = std::tuple_element_t<1, TestType>;
    using third_type     = std::tuple_element_t<2, TestType>;
    using fifth_type     = std::tuple_element_t<3, TestType>;
    using double_type    = std::tuple_element_t<4, TestType>;
    using unrelated_type = std::tuple_element_t<5, TestType>;

    CATCH_SECTION("implicit and explicit conversion")
    {
        CATCH_SECTION("representation type")
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
        CATCH_SECTION("wholly-divisible types")
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
        CATCH_SECTION("non-wholly-divisible types")
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
        CATCH_SECTION("integer-floating conversions")
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
        CATCH_SECTION("unrelated base units")
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

CATCH_TEST_CASE("comparison operations", "[compare]")
{
    CATCH_CHECK(drop(1) < dash(1));
    CATCH_CHECK(drop(1) <= dash(1));
    CATCH_CHECK(drop(100) <= dash(1));
    CATCH_CHECK(drop(100) == dash(1));
    CATCH_CHECK(drop(100) >= dash(1));
    CATCH_CHECK(drop(1000) >= dash(1));
    CATCH_CHECK(drop(1000) > dash(1));
}

CATCH_TEMPLATE_TEST_CASE(
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
    CATCH_SECTION("unary +/-")
    {
        constexpr auto value = TestType(1);

        CATCH_CHECK(TestType(1) == +value);
        CATCH_CHECK(TestType(-1) == -value);
    }

    CATCH_SECTION("increment/decrement")
    {
        auto value = TestType(0);

        CATCH_CHECK(--value == TestType(-1));
        CATCH_CHECK(value == TestType(-1));
        CATCH_CHECK(value-- == TestType(-1));
        CATCH_CHECK(value == TestType(-2));
        CATCH_CHECK(++value == TestType(-1));
        CATCH_CHECK(value == TestType(-1));
        CATCH_CHECK(value++ == TestType(-1));
        CATCH_CHECK(value == TestType(0));
    }

    CATCH_SECTION("arithmetic assignment")
    {
        auto value = TestType(0);

        CATCH_CHECK((value += TestType(1)) == TestType(1));
        CATCH_CHECK((value -= TestType(2)) == TestType(-1));
        CATCH_CHECK((value *= 100) == TestType(-100));
        CATCH_CHECK((value /= -2) == TestType(50));
        CATCH_CHECK((value %= 30) == TestType(20));
        CATCH_CHECK((value %= TestType(15)) == TestType(5));
    }

    CATCH_SECTION("arithmetics")
    {
        constexpr auto lhs = TestType(10);
        constexpr auto rhs = TestType(2);

        CATCH_CHECK((lhs + rhs) == TestType(12));
        CATCH_CHECK((lhs - rhs) == TestType(8));
        CATCH_CHECK((lhs * 4) == TestType(40));
        CATCH_CHECK((3 * rhs) == TestType(6));
        CATCH_CHECK((lhs / rhs) == 5);
        CATCH_CHECK((lhs / 5) == TestType(2));
        CATCH_CHECK((lhs % rhs) == TestType(0));
        CATCH_CHECK((lhs % 7) == TestType(3));
    }
}

CATCH_TEST_CASE("arithmetic operations on related types", "[arithmetic]")
{
    CATCH_CHECK((drop(2) + pinch(1)) == drop(1002));
    CATCH_CHECK((pinch(1) - drop(250)) == drop(750));
    CATCH_CHECK((pinch(1) / drop(250)) == 4);
    CATCH_CHECK((drop(2500) % pinch(1)) == drop(500));
}
