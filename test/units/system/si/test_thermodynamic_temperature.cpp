#include "posu/units/system/si/thermodynamic_temperature.hpp"

#include <catch2/catch.hpp>

TEST_CASE("thermodynamic temperature literals", "[construct][literals][temperature][si]")
{
    using namespace posu::units::si::thermodynamic_temperature_literals;

    SECTION("integer literals")
    {
        REQUIRE(1000_aK == 1_fK);
        REQUIRE(1000_fK == 1_pK);
        REQUIRE(1000_pK == 1_nK);
        REQUIRE(1000_nK == 1_uK);
        REQUIRE(1000_uK == 1_mK);
        REQUIRE(10_mK == 1_cK);
        REQUIRE(10_cK == 1_dK);
        REQUIRE(10_dK == 1_K);
        REQUIRE(10_K == 1_daK);
        REQUIRE(10_daK == 1_hK);
        REQUIRE(10_hK == 1_kK);
        REQUIRE(1000_kK == 1_MK);
        REQUIRE(1000_MK == 1_GK);
        REQUIRE(1000_GK == 1_TK);
        REQUIRE(1000_TK == 1_PK);
        REQUIRE(1000_PK == 1_EK);
    }

    SECTION("floating point literals")
    {
        REQUIRE(1.0_aK == 0.001_fK);
        REQUIRE(1.0_fK == 0.001_pK);
        REQUIRE(1.0_pK == 0.001_nK);
        REQUIRE(1.0_nK == 0.001_uK);
        REQUIRE(1.0_uK == 0.001_mK);
        REQUIRE(1.0_mK == 0.1_cK);
        REQUIRE(1.0_cK == 0.1_dK);
        REQUIRE(1.0_dK == 0.1_K);
        REQUIRE(1.0_K == 0.1_daK);
        REQUIRE(1.0_daK == 0.1_hK);
        REQUIRE(1.0_hK == 0.1_kK);
        REQUIRE(1.0_kK == 0.001_MK);
        REQUIRE(1.0_MK == 0.001_GK);
        REQUIRE(1.0_GK == 0.001_TK);
        REQUIRE(1.0_TK == 0.001_PK);
        REQUIRE(1.0_PK == 0.001_EK);
    }
}
