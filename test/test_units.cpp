#include "posu/units.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEMPLATE_TEST_CASE(
    "",
    "",
    posu::units::seconds,
    posu::units::meters,
    posu::units::grams,
    posu::units::amperes,
    posu::units::kelvins,
    posu::units::moles,
    posu::units::candelas)
{
}
