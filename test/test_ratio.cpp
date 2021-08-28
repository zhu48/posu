#include "posu/ratio.hpp"

#define CATCH_CONFIG_PREFIX_ALL

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

CATCH_TEST_CASE("ratio operations")
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
    CATCH_CHECK(std::same_as<posu::ratio<1>, posu::ratio_multiply<posu::ratio<1>, posu::ratio<1>>>);
}
