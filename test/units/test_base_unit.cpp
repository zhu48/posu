#include "posu/units/base_unit.hpp"

#include <catch2/catch.hpp>

namespace {

    constexpr char ingredients_unit_string[] = "pinch";
    constexpr char distance_unit_string[]    = "stretch";

    using ingredients_tag = posu::units::base_unit_tag<ingredients_unit_string>;
    using distance_tag    = posu::units::base_unit_tag<distance_unit_string>;

    template<typename Rep, typename Period>
    using ingredients = posu::units::base_unit<Rep, Period, ingredients_tag>;
    using drop        = ingredients<int, std::milli>;
    using dash        = ingredients<int, std::deci>;
    using pinch       = ingredients<int, std::ratio<1>>;
    using dollop      = ingredients<int, std::kilo>;

    template<typename Rep, typename Period>
    using distance = posu::units::base_unit<Rep, Period, distance_tag>;
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
