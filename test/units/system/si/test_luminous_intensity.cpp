#include "posu/units/system/si/luminous_intensity.hpp"

#define CATCH_CONFIG_PREFIX_ALL

#include <catch2/catch.hpp>

CATCH_TEST_CASE("luminous intensity literals", "[construct][literals][luminous][si]")
{
    using namespace posu::units::si::luminous_intensity_literals;

    CATCH_SECTION("integer literals")
    {
        CATCH_CHECK(1000_acd == 1_fcd);
        CATCH_CHECK(1000_fcd == 1_pcd);
        CATCH_CHECK(1000_pcd == 1_ncd);
        CATCH_CHECK(1000_ncd == 1_ucd);
        CATCH_CHECK(1000_ucd == 1_mcd);
        CATCH_CHECK(10_mcd == 1_ccd);
        CATCH_CHECK(10_ccd == 1_dcd);
        CATCH_CHECK(10_dcd == 1_cd);
        CATCH_CHECK(10_cd == 1_dacd);
        CATCH_CHECK(10_dacd == 1_hcd);
        CATCH_CHECK(10_hcd == 1_kcd);
        CATCH_CHECK(1000_kcd == 1_Mcd);
        CATCH_CHECK(1000_Mcd == 1_Gcd);
        CATCH_CHECK(1000_Gcd == 1_Tcd);
        CATCH_CHECK(1000_Tcd == 1_Pcd);
        CATCH_CHECK(1000_Pcd == 1_Ecd);
    }

    CATCH_SECTION("floating point literals")
    {
        CATCH_CHECK(1.0_acd == 0.001_fcd);
        CATCH_CHECK(1.0_fcd == 0.001_pcd);
        CATCH_CHECK(1.0_pcd == 0.001_ncd);
        CATCH_CHECK(1.0_ncd == 0.001_ucd);
        CATCH_CHECK(1.0_ucd == 0.001_mcd);
        CATCH_CHECK(1.0_mcd == 0.1_ccd);
        CATCH_CHECK(1.0_ccd == 0.1_dcd);
        CATCH_CHECK(1.0_dcd == 0.1_cd);
        CATCH_CHECK(1.0_cd == 0.1_dacd);
        CATCH_CHECK(1.0_dacd == 0.1_hcd);
        CATCH_CHECK(1.0_hcd == 0.1_kcd);
        CATCH_CHECK(1.0_kcd == 0.001_Mcd);
        CATCH_CHECK(1.0_Mcd == 0.001_Gcd);
        CATCH_CHECK(1.0_Gcd == 0.001_Tcd);
        CATCH_CHECK(1.0_Tcd == 0.001_Pcd);
        CATCH_CHECK(1.0_Pcd == 0.001_Ecd);
    }
}
