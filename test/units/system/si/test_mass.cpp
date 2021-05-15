#include "posu/units/system/si/mass.hpp"

#include <catch2/catch.hpp>

TEST_CASE("mass literals", "[construct][literals][mass][si]")
{
    using namespace posu::units::si::mass_literals;

    SECTION("integer literals")
    {
        REQUIRE(1000_ag == 1_fg);
        REQUIRE(1000_fg == 1_pg);
        REQUIRE(1000_pg == 1_ng);
        REQUIRE(1000_ng == 1_ug);
        REQUIRE(1000_ug == 1_mg);
        REQUIRE(10_mg == 1_cg);
        REQUIRE(10_cg == 1_dg);
        REQUIRE(10_dg == 1_g);
        REQUIRE(10_g == 1_dag);
        REQUIRE(10_dag == 1_hg);
        REQUIRE(10_hg == 1_kg);
        REQUIRE(1000_kg == 1_Mg);
        REQUIRE(1000_Mg == 1_Gg);
        REQUIRE(1000_Gg == 1_Tg);
        REQUIRE(1000_Tg == 1_Pg);
        REQUIRE(1000_Pg == 1_Eg);
    }

    SECTION("floating point literals")
    {
        REQUIRE(1.0_ag == 0.001_fg);
        REQUIRE(1.0_fg == 0.001_pg);
        REQUIRE(1.0_pg == 0.001_ng);
        REQUIRE(1.0_ng == 0.001_ug);
        REQUIRE(1.0_ug == 0.001_mg);
        REQUIRE(1.0_mg == 0.1_cg);
        REQUIRE(1.0_cg == 0.1_dg);
        REQUIRE(1.0_dg == 0.1_g);
        REQUIRE(1.0_g == 0.1_dag);
        REQUIRE(1.0_dag == 0.1_hg);
        REQUIRE(1.0_hg == 0.1_kg);
        REQUIRE(1.0_kg == 0.001_Mg);
        REQUIRE(1.0_Mg == 0.001_Gg);
        REQUIRE(1.0_Gg == 0.001_Tg);
        REQUIRE(1.0_Tg == 0.001_Pg);
        REQUIRE(1.0_Pg == 0.001_Eg);
    }
}
