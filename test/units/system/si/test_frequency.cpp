#include "posu/units/system/si/frequency.hpp"

#define CATCH_CONFIG_PREFIX_ALL

#include <catch2/catch.hpp>

CATCH_TEST_CASE("frequency literals", "[construct][literals][frequency][si]")
{
    using namespace posu::units::si::frequency_literals;

    CATCH_SECTION("integer literals")
    {
        CATCH_CHECK(1000_aHz == 1_fHz);
        CATCH_CHECK(1000_fHz == 1_pHz);
        CATCH_CHECK(1000_pHz == 1_nHz);
        CATCH_CHECK(1000_nHz == 1_uHz);
        CATCH_CHECK(1000_uHz == 1_mHz);
        CATCH_CHECK(10_mHz == 1_cHz);
        CATCH_CHECK(10_cHz == 1_dHz);
        CATCH_CHECK(10_dHz == 1_Hz);
        CATCH_CHECK(10_Hz == 1_daHz);
        CATCH_CHECK(10_daHz == 1_hHz);
        CATCH_CHECK(10_hHz == 1_kHz);
        CATCH_CHECK(1000_kHz == 1_MHz);
        CATCH_CHECK(1000_MHz == 1_GHz);
        CATCH_CHECK(1000_GHz == 1_THz);
        CATCH_CHECK(1000_THz == 1_PHz);
        CATCH_CHECK(1000_PHz == 1_EHz);
    }

    CATCH_SECTION("floating point literals")
    {
        CATCH_CHECK(1.0_aHz == 0.001_fHz);
        CATCH_CHECK(1.0_fHz == 0.001_pHz);
        CATCH_CHECK(1.0_pHz == 0.001_nHz);
        CATCH_CHECK(1.0_nHz == 0.001_uHz);
        CATCH_CHECK(1.0_uHz == 0.001_mHz);
        CATCH_CHECK(1.0_mHz == 0.1_cHz);
        CATCH_CHECK(1.0_cHz == 0.1_dHz);
        CATCH_CHECK(1.0_dHz == 0.1_Hz);
        CATCH_CHECK(1.0_Hz == 0.1_daHz);
        CATCH_CHECK(1.0_daHz == 0.1_hHz);
        CATCH_CHECK(1.0_hHz == 0.1_kHz);
        CATCH_CHECK(1.0_kHz == 0.001_MHz);
        CATCH_CHECK(1.0_MHz == 0.001_GHz);
        CATCH_CHECK(1.0_GHz == 0.001_THz);
        CATCH_CHECK(1.0_THz == 0.001_PHz);
        CATCH_CHECK(1.0_PHz == 0.001_EHz);
    }
}

CATCH_TEST_CASE("frequency from division", "[construct][expression][frequency][si]")
{
    using namespace posu::units::si::chrono_literals;
    using namespace posu::units::si::frequency_literals;

    namespace units = posu::units;
    namespace si    = units::si;

    CATCH_SECTION("integer literals")
    {
        CATCH_CHECK(units::of<si::frequency>(5 / 1_s) == 5_Hz);
        CATCH_CHECK(units::of<si::frequency>(2 / 8_ks) == 0_Hz);
    }

    CATCH_SECTION("floating point literals")
    {
        CATCH_CHECK(units::of<si::frequency>(2500 / 5.0_s) == 0.5_kHz);
        CATCH_CHECK(units::of<si::frequency>(0.002 / 8.0_ks) == 0.25_uHz);
    }
}

CATCH_TEST_CASE("scaler from multiplication", "[construct][expression][frequency][si]")
{
    using namespace posu::units::si::chrono_literals;
    using namespace posu::units::si::frequency_literals;

    CATCH_SECTION("integer literals")
    {
        CATCH_CHECK(5_Hz * 1_s == 5);
        CATCH_CHECK(1_s * 5_Hz == 5);
        CATCH_CHECK(32_Hz * 8_ks == 256'000);
        CATCH_CHECK(8_ks * 32_Hz == 256'000);

        CATCH_CHECK(5 == 5_Hz * 1_s);
        CATCH_CHECK(5 == 1_s * 5_Hz);
        CATCH_CHECK(256'000 == 32_Hz * 8_ks);
        CATCH_CHECK(256'000 == 8_ks * 32_Hz);
    }

    CATCH_SECTION("floating point literals")
    {
        CATCH_CHECK(0.5_kHz * 5_s == 2'500);
        CATCH_CHECK(5_s * 0.5_kHz == 2'500);
        CATCH_CHECK(0.25_uHz * 8.0_ks == 0.002);
        CATCH_CHECK(8.0_ks * 0.25_uHz == 0.002);

        CATCH_CHECK(2'500 == 0.5_kHz * 5_s);
        CATCH_CHECK(2'500 == 5_s * 0.5_kHz);
        CATCH_CHECK(0.002 == 0.25_uHz * 8.0_ks);
        CATCH_CHECK(0.002 == 8.0_ks * 0.25_uHz);
    }
}
