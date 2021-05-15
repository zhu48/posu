#include "posu/units/system/si/length.hpp"

#include <catch2/catch.hpp>

TEST_CASE("length literals", "[construct][literals][length][si]")
{
    using namespace posu::units::si::length_literals;

    SECTION("integer literals")
    {
        REQUIRE(1000_am == 1_fm);
        REQUIRE(1000_fm == 1_pm);
        REQUIRE(1000_pm == 1_nm);
        REQUIRE(1000_nm == 1_um);
        REQUIRE(1000_um == 1_mm);
        REQUIRE(10_mm == 1_cm);
        REQUIRE(10_cm == 1_dm);
        REQUIRE(10_dm == 1_m);
        REQUIRE(10_m == 1_dam);
        REQUIRE(10_dam == 1_hm);
        REQUIRE(10_hm == 1_km);
        REQUIRE(1000_km == 1_Mm);
        REQUIRE(1000_Mm == 1_Gm);
        REQUIRE(1000_Gm == 1_Tm);
        REQUIRE(1000_Tm == 1_Pm);
        REQUIRE(1000_Pm == 1_Em);
    }

    SECTION("floating point literals")
    {
        REQUIRE(1.0_am == 0.001_fm);
        REQUIRE(1.0_fm == 0.001_pm);
        REQUIRE(1.0_pm == 0.001_nm);
        REQUIRE(1.0_nm == 0.001_um);
        REQUIRE(1.0_um == 0.001_mm);
        REQUIRE(1.0_mm == 0.1_cm);
        REQUIRE(1.0_cm == 0.1_dm);
        REQUIRE(1.0_dm == 0.1_m);
        REQUIRE(1.0_m == 0.1_dam);
        REQUIRE(1.0_dam == 0.1_hm);
        REQUIRE(1.0_hm == 0.1_km);
        REQUIRE(1.0_km == 0.001_Mm);
        REQUIRE(1.0_Mm == 0.001_Gm);
        REQUIRE(1.0_Gm == 0.001_Tm);
        REQUIRE(1.0_Tm == 0.001_Pm);
        REQUIRE(1.0_Pm == 0.001_Em);
    }
}
