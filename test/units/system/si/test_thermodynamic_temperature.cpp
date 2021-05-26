#include "posu/units/system/si/thermodynamic_temperature.hpp"

#define CATCH_CONFIG_PREFIX_ALL

#include <catch2/catch.hpp>

CATCH_TEST_CASE("thermodynamic temperature literals", "[construct][literals][temperature][si]")
{
    using namespace posu::units::si::thermodynamic_temperature_literals;

    CATCH_SECTION("integer literals")
    {
        CATCH_CHECK(1000_aK == 1_fK);
        CATCH_CHECK(1000_fK == 1_pK);
        CATCH_CHECK(1000_pK == 1_nK);
        CATCH_CHECK(1000_nK == 1_uK);
        CATCH_CHECK(1000_uK == 1_mK);
        CATCH_CHECK(10_mK == 1_cK);
        CATCH_CHECK(10_cK == 1_dK);
        CATCH_CHECK(10_dK == 1_K);
        CATCH_CHECK(10_K == 1_daK);
        CATCH_CHECK(10_daK == 1_hK);
        CATCH_CHECK(10_hK == 1_kK);
        CATCH_CHECK(1000_kK == 1_MK);
        CATCH_CHECK(1000_MK == 1_GK);
        CATCH_CHECK(1000_GK == 1_TK);
        CATCH_CHECK(1000_TK == 1_PK);
        CATCH_CHECK(1000_PK == 1_EK);
    }

    CATCH_SECTION("floating point literals")
    {
        CATCH_CHECK(1.0_aK == 0.001_fK);
        CATCH_CHECK(1.0_fK == 0.001_pK);
        CATCH_CHECK(1.0_pK == 0.001_nK);
        CATCH_CHECK(1.0_nK == 0.001_uK);
        CATCH_CHECK(1.0_uK == 0.001_mK);
        CATCH_CHECK(1.0_mK == 0.1_cK);
        CATCH_CHECK(1.0_cK == 0.1_dK);
        CATCH_CHECK(1.0_dK == 0.1_K);
        CATCH_CHECK(1.0_K == 0.1_daK);
        CATCH_CHECK(1.0_daK == 0.1_hK);
        CATCH_CHECK(1.0_hK == 0.1_kK);
        CATCH_CHECK(1.0_kK == 0.001_MK);
        CATCH_CHECK(1.0_MK == 0.001_GK);
        CATCH_CHECK(1.0_GK == 0.001_TK);
        CATCH_CHECK(1.0_TK == 0.001_PK);
        CATCH_CHECK(1.0_PK == 0.001_EK);
    }
}
