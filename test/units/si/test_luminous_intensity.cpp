#include "posu/units/si/luminous_intensity.hpp"

#include <catch2/catch.hpp>

TEST_CASE("luminous intensity literals", "[construct][literals][luminous][si]")
{
    using namespace posu::units::luminous_intensity_literals;

    SECTION("integer literals")
    {
        REQUIRE(1000_acd == 1_fcd);
        REQUIRE(1000_fcd == 1_pcd);
        REQUIRE(1000_pcd == 1_ncd);
        REQUIRE(1000_ncd == 1_ucd);
        REQUIRE(1000_ucd == 1_mcd);
        REQUIRE(10_mcd == 1_ccd);
        REQUIRE(10_ccd == 1_dcd);
        REQUIRE(10_dcd == 1_cd);
        REQUIRE(10_cd == 1_dacd);
        REQUIRE(10_dacd == 1_hcd);
        REQUIRE(10_hcd == 1_kcd);
        REQUIRE(1000_kcd == 1_Mcd);
        REQUIRE(1000_Mcd == 1_Gcd);
        REQUIRE(1000_Gcd == 1_Tcd);
        REQUIRE(1000_Tcd == 1_Pcd);
        REQUIRE(1000_Pcd == 1_Ecd);
    }

    SECTION("floating point literals")
    {
        REQUIRE(1.0_acd == 0.001_fcd);
        REQUIRE(1.0_fcd == 0.001_pcd);
        REQUIRE(1.0_pcd == 0.001_ncd);
        REQUIRE(1.0_ncd == 0.001_ucd);
        REQUIRE(1.0_ucd == 0.001_mcd);
        REQUIRE(1.0_mcd == 0.1_ccd);
        REQUIRE(1.0_ccd == 0.1_dcd);
        REQUIRE(1.0_dcd == 0.1_cd);
        REQUIRE(1.0_cd == 0.1_dacd);
        REQUIRE(1.0_dacd == 0.1_hcd);
        REQUIRE(1.0_hcd == 0.1_kcd);
        REQUIRE(1.0_kcd == 0.001_Mcd);
        REQUIRE(1.0_Mcd == 0.001_Gcd);
        REQUIRE(1.0_Gcd == 0.001_Tcd);
        REQUIRE(1.0_Tcd == 0.001_Pcd);
        REQUIRE(1.0_Pcd == 0.001_Ecd);
    }
}