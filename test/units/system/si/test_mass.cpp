#include "posu/units/system/si/mass.hpp"

#define CATCH_CONFIG_PREFIX_ALL

#include <catch2/catch.hpp>

CATCH_TEST_CASE("mass literals", "[construct][literals][mass][si]")
{
    using namespace posu::units::si::mass_literals;

    CATCH_SECTION("integer literals")
    {
        CATCH_CHECK(1000_ag == 1_fg);
        CATCH_CHECK(1000_fg == 1_pg);
        CATCH_CHECK(1000_pg == 1_ng);
        CATCH_CHECK(1000_ng == 1_ug);
        CATCH_CHECK(1000_ug == 1_mg);
        CATCH_CHECK(10_mg == 1_cg);
        CATCH_CHECK(10_cg == 1_dg);
        CATCH_CHECK(10_dg == 1_g);
        CATCH_CHECK(10_g == 1_dag);
        CATCH_CHECK(10_dag == 1_hg);
        CATCH_CHECK(10_hg == 1_kg);
        CATCH_CHECK(1000_kg == 1_Mg);
        CATCH_CHECK(1000_Mg == 1_Gg);
        CATCH_CHECK(1000_Gg == 1_Tg);
        CATCH_CHECK(1000_Tg == 1_Pg);
        CATCH_CHECK(1000_Pg == 1_Eg);
    }

    CATCH_SECTION("floating point literals")
    {
        CATCH_CHECK(1.0_ag == 0.001_fg);
        CATCH_CHECK(1.0_fg == 0.001_pg);
        CATCH_CHECK(1.0_pg == 0.001_ng);
        CATCH_CHECK(1.0_ng == 0.001_ug);
        CATCH_CHECK(1.0_ug == 0.001_mg);
        CATCH_CHECK(1.0_mg == 0.1_cg);
        CATCH_CHECK(1.0_cg == 0.1_dg);
        CATCH_CHECK(1.0_dg == 0.1_g);
        CATCH_CHECK(1.0_g == 0.1_dag);
        CATCH_CHECK(1.0_dag == 0.1_hg);
        CATCH_CHECK(1.0_hg == 0.1_kg);
        CATCH_CHECK(1.0_kg == 0.001_Mg);
        CATCH_CHECK(1.0_Mg == 0.001_Gg);
        CATCH_CHECK(1.0_Gg == 0.001_Tg);
        CATCH_CHECK(1.0_Tg == 0.001_Pg);
        CATCH_CHECK(1.0_Pg == 0.001_Eg);
    }
}
