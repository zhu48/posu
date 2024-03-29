#include "posu/ratio.hpp"

#define CATCH_CONFIG_PREFIX_ALL

#include <catch2/catch.hpp>

CATCH_TEST_CASE("ratio operations")
{
    CATCH_SECTION("denormalization")
    {
        CATCH_CHECK(std::same_as<posu::ratio<100, 1, -1>, posu::denormalize<posu::deca, -1>>);
    }

    CATCH_SECTION("common type")
    {
        CATCH_CHECK(std::same_as<
                    posu::ratio<1, 42>,
                    posu::common_ratio<posu::ratio<2, 3, 1>, posu::ratio<5, 7, -1>>>);
    }

    CATCH_SECTION("addition")
    {
        CATCH_CHECK(
            std::same_as<posu::ratio<11>, posu::ratio_add<posu::ratio<10>, posu::ratio<1>>>);
        CATCH_CHECK(std::same_as<
                    posu::ratio<11, 15>,
                    posu::ratio_add<posu::ratio<1, 3>, posu::ratio<2, 5>>>);
        CATCH_CHECK(
            std::same_as<posu::ratio<11>, posu::ratio_add<posu::ratio<1, 1, 1>, posu::ratio<1>>>);
        CATCH_CHECK(std::same_as<
                    posu::ratio<101, 1, -1>,
                    posu::ratio_add<posu::ratio<1, 1, 1>, posu::ratio<1, 1, -1>>>);
    }

    CATCH_SECTION("subtraction")
    {
        CATCH_CHECK(
            std::same_as<posu::ratio<99, 1, -1>, posu::ratio_subtract<posu::deca, posu::deci>>);
    }

    CATCH_SECTION("multiplication")
    {
        CATCH_CHECK(std::same_as<posu::ratio<1>, posu::ratio_multiply<posu::yocto, posu::yotta>>);
        CATCH_CHECK(std::same_as<posu::ratio<1>, posu::ratio_multiply<posu::zepto, posu::zetta>>);
        CATCH_CHECK(std::same_as<posu::ratio<1>, posu::ratio_multiply<posu::atto, posu::exa>>);
        CATCH_CHECK(std::same_as<posu::ratio<1>, posu::ratio_multiply<posu::femto, posu::peta>>);
        CATCH_CHECK(std::same_as<posu::ratio<1>, posu::ratio_multiply<posu::pico, posu::tera>>);
        CATCH_CHECK(std::same_as<posu::ratio<1>, posu::ratio_multiply<posu::nano, posu::giga>>);
        CATCH_CHECK(std::same_as<posu::ratio<1>, posu::ratio_multiply<posu::micro, posu::mega>>);
        CATCH_CHECK(std::same_as<posu::ratio<1>, posu::ratio_multiply<posu::milli, posu::kilo>>);
        CATCH_CHECK(std::same_as<posu::ratio<1>, posu::ratio_multiply<posu::centi, posu::hecto>>);
        CATCH_CHECK(std::same_as<posu::ratio<1>, posu::ratio_multiply<posu::deci, posu::deca>>);
        CATCH_CHECK(
            std::same_as<posu::ratio<1>, posu::ratio_multiply<posu::ratio<1>, posu::ratio<1>>>);
    }

    CATCH_SECTION("comparison")
    {
        CATCH_CHECK(posu::ratio_equal<posu::deca, posu::ratio<100, 10>>{});
        CATCH_CHECK(posu::ratio_not_equal<posu::deca, posu::deci>{});
        CATCH_CHECK(posu::ratio_less<posu::deci, posu::deca>{});
        CATCH_CHECK(posu::ratio_less_equal<posu::deci, posu::deca>{});
        CATCH_CHECK(posu::ratio_less_equal<posu::deci, posu::deci>{});
        CATCH_CHECK(posu::ratio_greater<posu::deca, posu::deci>{});
        CATCH_CHECK(posu::ratio_greater_equal<posu::deca, posu::deci>{});
        CATCH_CHECK(posu::ratio_greater_equal<posu::deca, posu::deca>{});
    }
}
