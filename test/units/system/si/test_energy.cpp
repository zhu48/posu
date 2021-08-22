#include "posu/units/system/si/energy.hpp"

#define CATCH_CONFIG_PREFIX_ALL

#include <catch2/catch.hpp>

namespace {

    namespace units = posu::units;
    namespace si    = units::si;

} // namespace

CATCH_TEST_CASE("energy literals", "[construct][literals][energy][si]")
{
    using namespace si::energy_literals;

    CATCH_SECTION("integer literals")
    {
        CATCH_CHECK(1000_aJ == 1_fJ);
        CATCH_CHECK(1000_fJ == 1_pJ);
        CATCH_CHECK(1000_pJ == 1_nJ);
        CATCH_CHECK(1000_nJ == 1_uJ);
        CATCH_CHECK(1000_uJ == 1_mJ);
        CATCH_CHECK(10_mJ == 1_cJ);
        CATCH_CHECK(10_cJ == 1_dJ);
        CATCH_CHECK(10_dJ == 1_J);
        CATCH_CHECK(10_J == 1_daJ);
        CATCH_CHECK(10_daJ == 1_hJ);
        CATCH_CHECK(10_hJ == 1_kJ);
        CATCH_CHECK(1000_kJ == 1_MJ);
        CATCH_CHECK(1000_MJ == 1_GJ);
        CATCH_CHECK(1000_GJ == 1_TJ);
        CATCH_CHECK(1000_TJ == 1_PJ);
        // CATCH_CHECK(1000_PJ == 1_EJ);
    }

    CATCH_SECTION("floating point literals")
    {
        CATCH_CHECK(1.0_aJ == 0.001_fJ);
        CATCH_CHECK(1.0_fJ == 0.001_pJ);
        CATCH_CHECK(1.0_pJ == 0.001_nJ);
        CATCH_CHECK(1.0_nJ == 0.001_uJ);
        CATCH_CHECK(1.0_uJ == 0.001_mJ);
        CATCH_CHECK(1.0_mJ == 0.1_cJ);
        CATCH_CHECK(1.0_cJ == 0.1_dJ);
        CATCH_CHECK(1.0_dJ == 0.1_J);
        CATCH_CHECK(1.0_J == 0.1_daJ);
        CATCH_CHECK(1.0_daJ == 0.1_hJ);
        CATCH_CHECK(1.0_hJ == 0.1_kJ);
        CATCH_CHECK(1.0_kJ == 0.001_MJ);
        CATCH_CHECK(1.0_MJ == 0.001_GJ);
        CATCH_CHECK(1.0_GJ == 0.001_TJ);
        CATCH_CHECK(1.0_TJ == 0.001_PJ);
        // CATCH_CHECK(1.0_PJ == 0.001_EJ);
    }
}

CATCH_TEST_CASE("energy from multiplication", "[construct][expression][energy][si]")
{
    using namespace si::force_references;
    using namespace si::length_references;
    using namespace si::energy_literals;

    CATCH_CHECK(1_fJ == units::of<si::energy>(1 * (fN * m)));
    CATCH_CHECK(1_pJ == units::of<si::energy>(1 * (pN * m)));
    CATCH_CHECK(1_nJ == units::of<si::energy>(1 * (nN * m)));
    CATCH_CHECK(1_uJ == units::of<si::energy>(1 * (uN * m)));
    CATCH_CHECK(1_mJ == units::of<si::energy>(1 * (mN * m)));
    CATCH_CHECK(1_cJ == units::of<si::energy>(1 * (cN * m)));
    CATCH_CHECK(1_dJ == units::of<si::energy>(1 * (dN * m)));
    CATCH_CHECK(1_J == units::of<si::energy>(1 * (N * m)));
    CATCH_CHECK(1_daJ == units::of<si::energy>(1 * (daN * m)));
    CATCH_CHECK(1_hJ == units::of<si::energy>(1 * (hN * m)));
    CATCH_CHECK(1_kJ == units::of<si::energy>(1 * (kN * m)));
    CATCH_CHECK(1_MJ == units::of<si::energy>(1 * (MN * m)));
    CATCH_CHECK(1_GJ == units::of<si::energy>(1 * (GN * m)));
    CATCH_CHECK(1_TJ == units::of<si::energy>(1 * (TN * m)));
    CATCH_CHECK(1_PJ == units::of<si::energy>(1 * (PN * m)));
    // CATCH_CHECK(1_EJ == units::of<si::energy>(1 * (N * m)));
}

CATCH_TEST_CASE("force from energy division", "[construct][expression][energy][si]")
{
    using namespace si::length_references;
    using namespace si::energy_literals;
    using namespace si::force_literals;

    CATCH_CHECK(1_fN == units::of<si::force>(1_fJ / m));
    CATCH_CHECK(1_pN == units::of<si::force>(1_pJ / m));
    CATCH_CHECK(1_nN == units::of<si::force>(1_nJ / m));
    CATCH_CHECK(1_uN == units::of<si::force>(1_uJ / m));
    CATCH_CHECK(1_mN == units::of<si::force>(1_mJ / m));
    CATCH_CHECK(1_cN == units::of<si::force>(1_cJ / m));
    CATCH_CHECK(1_dN == units::of<si::force>(1_dJ / m));
    CATCH_CHECK(1_N == units::of<si::force>(1_J / m));
    CATCH_CHECK(1_daN == units::of<si::force>(1_daJ / m));
    CATCH_CHECK(1_hN == units::of<si::force>(1_hJ / m));
    CATCH_CHECK(1_kN == units::of<si::force>(1_kJ / m));
    CATCH_CHECK(1_MN == units::of<si::force>(1_MJ / m));
    CATCH_CHECK(1_GN == units::of<si::force>(1_GJ / m));
    CATCH_CHECK(1_TN == units::of<si::force>(1_TJ / m));
    CATCH_CHECK(1_PN == units::of<si::force>(1_PJ / m));
    // CATCH_CHECK(1_EN == units::of<si::force>(1_EJ / m));
}

CATCH_TEST_CASE("length from energy division", "[construct][expression][energy][si]")
{
    using namespace si::length_literals;
    using namespace si::energy_literals;
    using namespace si::force_references;

    CATCH_CHECK(1_fm == units::of<si::length>(1_fJ / N));
    CATCH_CHECK(1_pm == units::of<si::length>(1_pJ / N));
    CATCH_CHECK(1_nm == units::of<si::length>(1_nJ / N));
    CATCH_CHECK(1_um == units::of<si::length>(1_uJ / N));
    CATCH_CHECK(1_mm == units::of<si::length>(1_mJ / N));
    CATCH_CHECK(1_cm == units::of<si::length>(1_cJ / N));
    CATCH_CHECK(1_dm == units::of<si::length>(1_dJ / N));
    CATCH_CHECK(1_m == units::of<si::length>(1_J / N));
    CATCH_CHECK(1_dam == units::of<si::length>(1_daJ / N));
    CATCH_CHECK(1_hm == units::of<si::length>(1_hJ / N));
    CATCH_CHECK(1_km == units::of<si::length>(1_kJ / N));
    CATCH_CHECK(1_Mm == units::of<si::length>(1_MJ / N));
    CATCH_CHECK(1_Gm == units::of<si::length>(1_GJ / N));
    CATCH_CHECK(1_Tm == units::of<si::length>(1_TJ / N));
    CATCH_CHECK(1_Pm == units::of<si::length>(1_PJ / N));
    CATCH_CHECK(1_Em == units::of<si::length>(1_EJ / N));
}
