#include "posu/units/system/si/electric_current.hpp"

#define CATCH_CONFIG_PREFIX_ALL

#include <catch2/catch.hpp>

CATCH_TEST_CASE("electric current literals", "[construct][literals][current][si]")
{
    using namespace posu::units::si::electric_current_literals;

    CATCH_SECTION("integer literals")
    {
        CATCH_CHECK(1000_aA == 1_fA);
        CATCH_CHECK(1000_fA == 1_pA);
        CATCH_CHECK(1000_pA == 1_nA);
        CATCH_CHECK(1000_nA == 1_uA);
        CATCH_CHECK(1000_uA == 1_mA);
        CATCH_CHECK(10_mA == 1_cA);
        CATCH_CHECK(10_cA == 1_dA);
        CATCH_CHECK(10_dA == 1_A);
        CATCH_CHECK(10_A == 1_daA);
        CATCH_CHECK(10_daA == 1_hA);
        CATCH_CHECK(10_hA == 1_kA);
        CATCH_CHECK(1000_kA == 1_MA);
        CATCH_CHECK(1000_MA == 1_GA);
        CATCH_CHECK(1000_GA == 1_TA);
        CATCH_CHECK(1000_TA == 1_PA);
        CATCH_CHECK(1000_PA == 1_EA);
    }

    CATCH_SECTION("floating point literals")
    {
        CATCH_CHECK(1.0_aA == 0.001_fA);
        CATCH_CHECK(1.0_fA == 0.001_pA);
        CATCH_CHECK(1.0_pA == 0.001_nA);
        CATCH_CHECK(1.0_nA == 0.001_uA);
        CATCH_CHECK(1.0_uA == 0.001_mA);
        CATCH_CHECK(1.0_mA == 0.1_cA);
        CATCH_CHECK(1.0_cA == 0.1_dA);
        CATCH_CHECK(1.0_dA == 0.1_A);
        CATCH_CHECK(1.0_A == 0.1_daA);
        CATCH_CHECK(1.0_daA == 0.1_hA);
        CATCH_CHECK(1.0_hA == 0.1_kA);
        CATCH_CHECK(1.0_kA == 0.001_MA);
        CATCH_CHECK(1.0_MA == 0.001_GA);
        CATCH_CHECK(1.0_GA == 0.001_TA);
        CATCH_CHECK(1.0_TA == 0.001_PA);
        CATCH_CHECK(1.0_PA == 0.001_EA);
    }
}
