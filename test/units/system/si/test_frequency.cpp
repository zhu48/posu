#include "posu/units/system/si/frequency.hpp"

#define CATCH_CONFIG_PREFIX_ALL

#include <catch2/catch.hpp>

CATCH_TEST_CASE("frequency literals", "[construct][literals][frequency][si]")
{
    using namespace posu::units::si::frequency_literals;

    CATCH_SECTION("integer literals")
    {
        CATCH_REQUIRE(1000_aHz == 1_fHz);
        CATCH_REQUIRE(1000_fHz == 1_pHz);
        CATCH_REQUIRE(1000_pHz == 1_nHz);
        CATCH_REQUIRE(1000_nHz == 1_uHz);
        CATCH_REQUIRE(1000_uHz == 1_mHz);
        CATCH_REQUIRE(10_mHz == 1_cHz);
        CATCH_REQUIRE(10_cHz == 1_dHz);
        CATCH_REQUIRE(10_dHz == 1_Hz);
        CATCH_REQUIRE(10_Hz == 1_daHz);
        CATCH_REQUIRE(10_daHz == 1_hHz);
        CATCH_REQUIRE(10_hHz == 1_kHz);
        CATCH_REQUIRE(1000_kHz == 1_MHz);
        CATCH_REQUIRE(1000_MHz == 1_GHz);
        CATCH_REQUIRE(1000_GHz == 1_THz);
        CATCH_REQUIRE(1000_THz == 1_PHz);
        CATCH_REQUIRE(1000_PHz == 1_EHz);
    }

    CATCH_SECTION("floating point literals")
    {
        CATCH_REQUIRE(1.0_aHz == 0.001_fHz);
        CATCH_REQUIRE(1.0_fHz == 0.001_pHz);
        CATCH_REQUIRE(1.0_pHz == 0.001_nHz);
        CATCH_REQUIRE(1.0_nHz == 0.001_uHz);
        CATCH_REQUIRE(1.0_uHz == 0.001_mHz);
        CATCH_REQUIRE(1.0_mHz == 0.1_cHz);
        CATCH_REQUIRE(1.0_cHz == 0.1_dHz);
        CATCH_REQUIRE(1.0_dHz == 0.1_Hz);
        CATCH_REQUIRE(1.0_Hz == 0.1_daHz);
        CATCH_REQUIRE(1.0_daHz == 0.1_hHz);
        CATCH_REQUIRE(1.0_hHz == 0.1_kHz);
        CATCH_REQUIRE(1.0_kHz == 0.001_MHz);
        CATCH_REQUIRE(1.0_MHz == 0.001_GHz);
        CATCH_REQUIRE(1.0_GHz == 0.001_THz);
        CATCH_REQUIRE(1.0_THz == 0.001_PHz);
        CATCH_REQUIRE(1.0_PHz == 0.001_EHz);
    }
}
