#include "posu/units/system/si/length.hpp"

#define CATCH_CONFIG_PREFIX_ALL

#include <catch2/catch.hpp>

CATCH_TEST_CASE("length literals", "[construct][literals][length][si]")
{
    using namespace posu::units::si::length_literals;

    CATCH_SECTION("integer literals")
    {
        CATCH_CHECK(1000_am == 1_fm);
        CATCH_CHECK(1000_fm == 1_pm);
        CATCH_CHECK(1000_pm == 1_nm);
        CATCH_CHECK(1000_nm == 1_um);
        CATCH_CHECK(1000_um == 1_mm);
        CATCH_CHECK(10_mm == 1_cm);
        CATCH_CHECK(10_cm == 1_dm);
        CATCH_CHECK(10_dm == 1_m);
        CATCH_CHECK(10_m == 1_dam);
        CATCH_CHECK(10_dam == 1_hm);
        CATCH_CHECK(10_hm == 1_km);
        CATCH_CHECK(1000_km == 1_Mm);
        CATCH_CHECK(1000_Mm == 1_Gm);
        CATCH_CHECK(1000_Gm == 1_Tm);
        CATCH_CHECK(1000_Tm == 1_Pm);
        CATCH_CHECK(1000_Pm == 1_Em);
    }

    CATCH_SECTION("floating point literals")
    {
        CATCH_CHECK(1.0_am == 0.001_fm);
        CATCH_CHECK(1.0_fm == 0.001_pm);
        CATCH_CHECK(1.0_pm == 0.001_nm);
        CATCH_CHECK(1.0_nm == 0.001_um);
        CATCH_CHECK(1.0_um == 0.001_mm);
        CATCH_CHECK(1.0_mm == 0.1_cm);
        CATCH_CHECK(1.0_cm == 0.1_dm);
        CATCH_CHECK(1.0_dm == 0.1_m);
        CATCH_CHECK(1.0_m == 0.1_dam);
        CATCH_CHECK(1.0_dam == 0.1_hm);
        CATCH_CHECK(1.0_hm == 0.1_km);
        CATCH_CHECK(1.0_km == 0.001_Mm);
        CATCH_CHECK(1.0_Mm == 0.001_Gm);
        CATCH_CHECK(1.0_Gm == 0.001_Tm);
        CATCH_CHECK(1.0_Tm == 0.001_Pm);
        CATCH_CHECK(1.0_Pm == 0.001_Em);
    }
}
