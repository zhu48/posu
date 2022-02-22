#include "posu/units/system/si/pressure.hpp"

#define CATCH_CONFIG_PREFIX_ALL

#include "posu/units/system/area.hpp"

#include <catch2/catch.hpp>

namespace {

    namespace units = posu::units;
    namespace si    = units::si;

} // namespace

CATCH_TEST_CASE("pressure literals", "[construct][literals][pressure][si]")
{
    using namespace si::pressure_literals;

    CATCH_SECTION("integer literals")
    {
        CATCH_CHECK(1000_aPa == 1_fPa);
        CATCH_CHECK(1000_fPa == 1_pPa);
        CATCH_CHECK(1000_pPa == 1_nPa);
        CATCH_CHECK(1000_nPa == 1_uPa);
        CATCH_CHECK(1000_uPa == 1_mPa);
        CATCH_CHECK(10_mPa == 1_cPa);
        CATCH_CHECK(10_cPa == 1_dPa);
        CATCH_CHECK(10_dPa == 1_Pa);
        CATCH_CHECK(10_Pa == 1_daPa);
        CATCH_CHECK(10_daPa == 1_hPa);
        CATCH_CHECK(10_hPa == 1_kPa);
        CATCH_CHECK(1000_kPa == 1_MPa);
        CATCH_CHECK(1000_MPa == 1_GPa);
        CATCH_CHECK(1000_GPa == 1_TPa);
        CATCH_CHECK(1000_TPa == 1_PPa);
        CATCH_CHECK(1000_PPa == 1_EPa);
    }

    CATCH_SECTION("floating point literals")
    {
        CATCH_CHECK(1.0_aPa == 0.001_fPa);
        CATCH_CHECK(1.0_fPa == 0.001_pPa);
        CATCH_CHECK(1.0_pPa == 0.001_nPa);
        CATCH_CHECK(1.0_nPa == 0.001_uPa);
        CATCH_CHECK(1.0_uPa == 0.001_mPa);
        CATCH_CHECK(1.0_mPa == 0.1_cPa);
        CATCH_CHECK(1.0_cPa == 0.1_dPa);
        CATCH_CHECK(1.0_dPa == 0.1_Pa);
        CATCH_CHECK(1.0_Pa == 0.1_daPa);
        CATCH_CHECK(1.0_daPa == 0.1_hPa);
        CATCH_CHECK(1.0_hPa == 0.1_kPa);
        CATCH_CHECK(1.0_kPa == 0.001_MPa);
        CATCH_CHECK(1.0_MPa == 0.001_GPa);
        CATCH_CHECK(1.0_GPa == 0.001_TPa);
        CATCH_CHECK(1.0_TPa == 0.001_PPa);
        CATCH_CHECK(1.0_PPa == 0.001_EPa);
    }
}

CATCH_TEST_CASE("pressure from division", "[construct][expression][pressure][si]")
{
    using namespace si::pressure_literals;
    using namespace si::force_literals;
    using namespace si::length_references;

    CATCH_CHECK(1_fPa == units::of<si::pressure>(1_fN / (m * m)));
    CATCH_CHECK(1_pPa == units::of<si::pressure>(1_pN / (m * m)));
    CATCH_CHECK(1_nPa == units::of<si::pressure>(1_nN / (m * m)));
    CATCH_CHECK(1_uPa == units::of<si::pressure>(1_uN / (m * m)));
    CATCH_CHECK(1_mPa == units::of<si::pressure>(1_mN / (m * m)));
    CATCH_CHECK(1_cPa == units::of<si::pressure>(1_cN / (m * m)));
    CATCH_CHECK(1_dPa == units::of<si::pressure>(1_dN / (m * m)));
    CATCH_CHECK(1_Pa == units::of<si::pressure>(1_N / (m * m)));
    CATCH_CHECK(1_daPa == units::of<si::pressure>(1_daN / (m * m)));
    CATCH_CHECK(1_hPa == units::of<si::pressure>(1_hN / (m * m)));
    CATCH_CHECK(1_kPa == units::of<si::pressure>(1_kN / (m * m)));
    CATCH_CHECK(1_MPa == units::of<si::pressure>(1_MN / (m * m)));
    CATCH_CHECK(1_GPa == units::of<si::pressure>(1_GN / (m * m)));
    CATCH_CHECK(1_TPa == units::of<si::pressure>(1_TN / (m * m)));
    CATCH_CHECK(1_PPa == units::of<si::pressure>(1_PN / (m * m)));
    CATCH_CHECK(1_EPa == units::of<si::pressure>(1_EN / (m * m)));
}

CATCH_TEST_CASE("force from pressure multiplication", "[construct][expression][pressure][si]")
{
    using namespace si::pressure_literals;
    using namespace si::force_literals;
    using namespace si::length_references;

    CATCH_CHECK(1_fN == units::of<si::force>(1_fPa * (m * m)));
    CATCH_CHECK(1_pN == units::of<si::force>(1_pPa * (m * m)));
    CATCH_CHECK(1_nN == units::of<si::force>(1_nPa * (m * m)));
    CATCH_CHECK(1_uN == units::of<si::force>(1_uPa * (m * m)));
    CATCH_CHECK(1_mN == units::of<si::force>(1_mPa * (m * m)));
    CATCH_CHECK(1_cN == units::of<si::force>(1_cPa * (m * m)));
    CATCH_CHECK(1_dN == units::of<si::force>(1_dPa * (m * m)));
    CATCH_CHECK(1_N == units::of<si::force>(1_Pa * (m * m)));
    CATCH_CHECK(1_daN == units::of<si::force>(1_daPa * (m * m)));
    CATCH_CHECK(1_hN == units::of<si::force>(1_hPa * (m * m)));
    CATCH_CHECK(1_kN == units::of<si::force>(1_kPa * (m * m)));
    CATCH_CHECK(1_MN == units::of<si::force>(1_MPa * (m * m)));
    CATCH_CHECK(1_GN == units::of<si::force>(1_GPa * (m * m)));
    CATCH_CHECK(1_TN == units::of<si::force>(1_TPa * (m * m)));
    CATCH_CHECK(1_PN == units::of<si::force>(1_PPa * (m * m)));
    CATCH_CHECK(1_EN == units::of<si::force>(1_EPa * (m * m)));
}

CATCH_TEST_CASE("area from pressure division", "[construct][expression][pressure][si]")
{
    using namespace si::force_literals;
    using namespace si::pressure_references;
    using namespace si::length_literals;
    using namespace si::length_references;

    CATCH_CHECK(units::of<units::area>(1_fm * m) == units::of<units::area>(1_fN / Pa));
    CATCH_CHECK(units::of<units::area>(1_pm * m) == units::of<units::area>(1_pN / Pa));
    CATCH_CHECK(units::of<units::area>(1_nm * m) == units::of<units::area>(1_nN / Pa));
    CATCH_CHECK(units::of<units::area>(1_um * m) == units::of<units::area>(1_uN / Pa));
    CATCH_CHECK(units::of<units::area>(1_mm * m) == units::of<units::area>(1_mN / Pa));
    CATCH_CHECK(units::of<units::area>(1_cm * m) == units::of<units::area>(1_cN / Pa));
    CATCH_CHECK(units::of<units::area>(1_dm * m) == units::of<units::area>(1_dN / Pa));
    CATCH_CHECK(units::of<units::area>(1_m * m) == units::of<units::area>(1_N / Pa));
    CATCH_CHECK(units::of<units::area>(1_dam * m) == units::of<units::area>(1_daN / Pa));
    CATCH_CHECK(units::of<units::area>(1_hm * m) == units::of<units::area>(1_hN / Pa));
    CATCH_CHECK(units::of<units::area>(1_km * m) == units::of<units::area>(1_kN / Pa));
    CATCH_CHECK(units::of<units::area>(1_Mm * m) == units::of<units::area>(1_MN / Pa));
    CATCH_CHECK(units::of<units::area>(1_Gm * m) == units::of<units::area>(1_GN / Pa));
    CATCH_CHECK(units::of<units::area>(1_Tm * m) == units::of<units::area>(1_TN / Pa));
    CATCH_CHECK(units::of<units::area>(1_Pm * m) == units::of<units::area>(1_PN / Pa));
    CATCH_CHECK(units::of<units::area>(1_Em * m) == units::of<units::area>(1_EN / Pa));
}
