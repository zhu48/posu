#include "posu/units.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEMPLATE_TEST_CASE(
    "construction invariants",
    "[construct]",
    posu::units::seconds,
    posu::units::meters,
    posu::units::grams,
    posu::units::amperes,
    posu::units::kelvins,
    posu::units::moles,
    posu::units::candelas)
{
    SECTION("implicit and explicit conversion")
    {
        static_assert(!std::convertible_to<TestType, typename TestType::rep>);
        static_assert(
            std::constructible_from<TestType, typename TestType::rep>);
    }
}
