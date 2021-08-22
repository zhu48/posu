#include "posu/units/system/si/power.hpp"

#define CATCH_CONFIG_PREFIX_ALL

#include <catch2/catch.hpp>

namespace {

    namespace units = posu::units;
    namespace si    = units::si;

} // namespace

CATCH_TEST_CASE("power literals", "[construct][literals][power][si]")
{
    using namespace si::power_literals;

    CATCH_SECTION("integer literals")
    {
        CATCH_CHECK(1000_aW == 1_fW);
        CATCH_CHECK(1000_fW == 1_pW);
        CATCH_CHECK(1000_pW == 1_nW);
        CATCH_CHECK(1000_nW == 1_uW);
        CATCH_CHECK(1000_uW == 1_mW);
        CATCH_CHECK(10_mW == 1_cW);
        CATCH_CHECK(10_cW == 1_dW);
        CATCH_CHECK(10_dW == 1_W);
        CATCH_CHECK(10_W == 1_daW);
        CATCH_CHECK(10_daW == 1_hW);
        CATCH_CHECK(10_hW == 1_kW);
        CATCH_CHECK(1000_kW == 1_MW);
        CATCH_CHECK(1000_MW == 1_GW);
        CATCH_CHECK(1000_GW == 1_TW);
        CATCH_CHECK(1000_TW == 1_PW);
        // CATCH_CHECK(1000_PW == 1_EW);
    }

    CATCH_SECTION("floating point literals")
    {
        CATCH_CHECK(1.0_aW == 0.001_fW);
        CATCH_CHECK(1.0_fW == 0.001_pW);
        CATCH_CHECK(1.0_pW == 0.001_nW);
        CATCH_CHECK(1.0_nW == 0.001_uW);
        CATCH_CHECK(1.0_uW == 0.001_mW);
        CATCH_CHECK(1.0_mW == 0.1_cW);
        CATCH_CHECK(1.0_cW == 0.1_dW);
        CATCH_CHECK(1.0_dW == 0.1_W);
        CATCH_CHECK(1.0_W == 0.1_daW);
        CATCH_CHECK(1.0_daW == 0.1_hW);
        CATCH_CHECK(1.0_hW == 0.1_kW);
        CATCH_CHECK(1.0_kW == 0.001_MW);
        CATCH_CHECK(1.0_MW == 0.001_GW);
        CATCH_CHECK(1.0_GW == 0.001_TW);
        CATCH_CHECK(1.0_TW == 0.001_PW);
        // CATCH_CHECK(1.0_PW == 0.001_EW);
    }
}

CATCH_TEST_CASE("power from division", "[construct][expression][power][si]")
{
    using namespace si::power_literals;
    using namespace si::energy_literals;
    using namespace si::chrono_references;

    CATCH_CHECK(1_fW == units::of<si::power>(1_fJ / s));
    CATCH_CHECK(1_pW == units::of<si::power>(1_pJ / s));
    CATCH_CHECK(1_nW == units::of<si::power>(1_nJ / s));
    CATCH_CHECK(1_uW == units::of<si::power>(1_uJ / s));
    CATCH_CHECK(1_mW == units::of<si::power>(1_mJ / s));
    CATCH_CHECK(1_cW == units::of<si::power>(1_cJ / s));
    CATCH_CHECK(1_dW == units::of<si::power>(1_dJ / s));
    CATCH_CHECK(1_W == units::of<si::power>(1_J / s));
    CATCH_CHECK(1_daW == units::of<si::power>(1_daJ / s));
    CATCH_CHECK(1_hW == units::of<si::power>(1_hJ / s));
    CATCH_CHECK(1_kW == units::of<si::power>(1_kJ / s));
    CATCH_CHECK(1_MW == units::of<si::power>(1_MJ / s));
    CATCH_CHECK(1_GW == units::of<si::power>(1_GJ / s));
    CATCH_CHECK(1_TW == units::of<si::power>(1_TJ / s));
    CATCH_CHECK(1_PW == units::of<si::power>(1_PJ / s));
    // CATCH_CHECK(1_EW == units::of<si::power>(1_EJ / s));
}

CATCH_TEST_CASE("energy from power division", "[construct][expression][power][si]")
{
    using namespace si::power_literals;
    using namespace si::energy_literals;
    using namespace si::chrono_references;

    CATCH_CHECK(1_fJ == units::of<si::energy>(1_fW * s));
    CATCH_CHECK(1_pJ == units::of<si::energy>(1_pW * s));
    CATCH_CHECK(1_nJ == units::of<si::energy>(1_nW * s));
    CATCH_CHECK(1_uJ == units::of<si::energy>(1_uW * s));
    CATCH_CHECK(1_mJ == units::of<si::energy>(1_mW * s));
    CATCH_CHECK(1_cJ == units::of<si::energy>(1_cW * s));
    CATCH_CHECK(1_dJ == units::of<si::energy>(1_dW * s));
    CATCH_CHECK(1_J == units::of<si::energy>(1_W * s));
    CATCH_CHECK(1_daJ == units::of<si::energy>(1_daW * s));
    CATCH_CHECK(1_hJ == units::of<si::energy>(1_hW * s));
    CATCH_CHECK(1_kJ == units::of<si::energy>(1_kW * s));
    CATCH_CHECK(1_MJ == units::of<si::energy>(1_MW * s));
    CATCH_CHECK(1_GJ == units::of<si::energy>(1_GW * s));
    CATCH_CHECK(1_TJ == units::of<si::energy>(1_TW * s));
    CATCH_CHECK(1_PJ == units::of<si::energy>(1_PW * s));
    // CATCH_CHECK(1_EJ == units::of<si::energy>(1_EW * s));
}

CATCH_TEST_CASE("time from power division", "[construct][expression][power][si]")
{
    using namespace si::power_references;
    using namespace si::energy_literals;
    using namespace si::chrono_literals;

    CATCH_CHECK(1_fs == units::of<si::time>(1_fJ / W));
    CATCH_CHECK(1_ps == units::of<si::time>(1_pJ / W));
    CATCH_CHECK(1_ns == units::of<si::time>(1_nJ / W));
    CATCH_CHECK(1_us == units::of<si::time>(1_uJ / W));
    CATCH_CHECK(1_ms == units::of<si::time>(1_mJ / W));
    CATCH_CHECK(1_cs == units::of<si::time>(1_cJ / W));
    CATCH_CHECK(1_ds == units::of<si::time>(1_dJ / W));
    CATCH_CHECK(1_s == units::of<si::time>(1_J / W));
    CATCH_CHECK(1_das == units::of<si::time>(1_daJ / W));
    CATCH_CHECK(1_hs == units::of<si::time>(1_hJ / W));
    CATCH_CHECK(1_ks == units::of<si::time>(1_kJ / W));
    CATCH_CHECK(1_Ms == units::of<si::time>(1_MJ / W));
    CATCH_CHECK(1_Gs == units::of<si::time>(1_GJ / W));
    CATCH_CHECK(1_Ts == units::of<si::time>(1_TJ / W));
    CATCH_CHECK(1_Ps == units::of<si::time>(1_PJ / W));
    CATCH_CHECK(1_Es == units::of<si::time>(1_EJ / W));
}
