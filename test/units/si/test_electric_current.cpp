#include "posu/units/si/electric_current.hpp"

#include <catch2/catch.hpp>

TEST_CASE("electric current literals", "[construct][literals][current][si]")
{
    using namespace posu::units::electric_current_literals;

    SECTION("integer literals")
    {
        REQUIRE(1000_aA == 1_fA);
        REQUIRE(1000_fA == 1_pA);
        REQUIRE(1000_pA == 1_nA);
        REQUIRE(1000_nA == 1_uA);
        REQUIRE(1000_uA == 1_mA);
        REQUIRE(10_mA == 1_cA);
        REQUIRE(10_cA == 1_dA);
        REQUIRE(10_dA == 1_A);
        REQUIRE(10_A == 1_daA);
        REQUIRE(10_daA == 1_hA);
        REQUIRE(10_hA == 1_kA);
        REQUIRE(1000_kA == 1_MA);
        REQUIRE(1000_MA == 1_GA);
        REQUIRE(1000_GA == 1_TA);
        REQUIRE(1000_TA == 1_PA);
        REQUIRE(1000_PA == 1_EA);
    }

    SECTION("floating point literals")
    {
        REQUIRE(1.0_aA == 0.001_fA);
        REQUIRE(1.0_fA == 0.001_pA);
        REQUIRE(1.0_pA == 0.001_nA);
        REQUIRE(1.0_nA == 0.001_uA);
        REQUIRE(1.0_uA == 0.001_mA);
        REQUIRE(1.0_mA == 0.1_cA);
        REQUIRE(1.0_cA == 0.1_dA);
        REQUIRE(1.0_dA == 0.1_A);
        REQUIRE(1.0_A == 0.1_daA);
        REQUIRE(1.0_daA == 0.1_hA);
        REQUIRE(1.0_hA == 0.1_kA);
        REQUIRE(1.0_kA == 0.001_MA);
        REQUIRE(1.0_MA == 0.001_GA);
        REQUIRE(1.0_GA == 0.001_TA);
        REQUIRE(1.0_TA == 0.001_PA);
        REQUIRE(1.0_PA == 0.001_EA);
    }
}
