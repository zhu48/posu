#include "posu/units/units.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEMPLATE_TEST_CASE(
    "SI units conversion rules",
    "[si][construct][convert]",
    (std::tuple<
        posu::units::si::kiloseconds,
        posu::units::si::seconds,
        posu::units::si::time<int, std::ratio<1, 3>>,
        posu::units::si::time<int, std::ratio<1, 5>>,
        posu::units::si::time<double, std::ratio<1>>,
        posu::units::si::candelas>),
    (std::tuple<
        posu::units::si::kilometers,
        posu::units::si::meters,
        posu::units::si::length<int, std::ratio<1, 3>>,
        posu::units::si::length<int, std::ratio<1, 5>>,
        posu::units::si::length<double, std::ratio<1>>,
        posu::units::si::seconds>),
    (std::tuple<
        posu::units::si::kilograms,
        posu::units::si::grams,
        posu::units::si::mass<int, std::ratio<1, 3>>,
        posu::units::si::mass<int, std::ratio<1, 5>>,
        posu::units::si::mass<double, std::ratio<1>>,
        posu::units::si::meters>),
    (std::tuple<
        posu::units::si::kiloamperes,
        posu::units::si::amperes,
        posu::units::si::electric_current<int, std::ratio<1, 3>>,
        posu::units::si::electric_current<int, std::ratio<1, 5>>,
        posu::units::si::electric_current<double, std::ratio<1>>,
        posu::units::si::grams>),
    (std::tuple<
        posu::units::si::kilokelvins,
        posu::units::si::kelvins,
        posu::units::si::thermodynamic_temperature<int, std::ratio<1, 3>>,
        posu::units::si::thermodynamic_temperature<int, std::ratio<1, 5>>,
        posu::units::si::thermodynamic_temperature<double, std::ratio<1>>,
        posu::units::si::amperes>),
    (std::tuple<
        posu::units::si::kilomoles,
        posu::units::si::moles,
        posu::units::si::amount_of_substance<int, std::ratio<1, 3>>,
        posu::units::si::amount_of_substance<int, std::ratio<1, 5>>,
        posu::units::si::amount_of_substance<double, std::ratio<1>>,
        posu::units::si::kelvins>),
    (std::tuple<
        posu::units::si::kilocandelas,
        posu::units::si::candelas,
        posu::units::si::luminous_intensity<int, std::ratio<1, 3>>,
        posu::units::si::luminous_intensity<int, std::ratio<1, 5>>,
        posu::units::si::luminous_intensity<double, std::ratio<1>>,
        posu::units::si::moles>))
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
