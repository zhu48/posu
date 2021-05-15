#include "posu/units/si/amount_of_substance.hpp"

#include <catch2/catch.hpp>

TEST_CASE("amount of substance literals", "[construct][literals][amount][si]")
{
    using namespace posu::units::si::amount_of_substance_literals;

    SECTION("integer literals")
    {
        REQUIRE(1000_amol == 1_fmol);
        REQUIRE(1000_fmol == 1_pmol);
        REQUIRE(1000_pmol == 1_nmol);
        REQUIRE(1000_nmol == 1_umol);
        REQUIRE(1000_umol == 1_mmol);
        REQUIRE(10_mmol == 1_cmol);
        REQUIRE(10_cmol == 1_dmol);
        REQUIRE(10_dmol == 1_mol);
        REQUIRE(10_mol == 1_damol);
        REQUIRE(10_damol == 1_hmol);
        REQUIRE(10_hmol == 1_kmol);
        REQUIRE(1000_kmol == 1_Mmol);
        REQUIRE(1000_Mmol == 1_Gmol);
        REQUIRE(1000_Gmol == 1_Tmol);
        REQUIRE(1000_Tmol == 1_Pmol);
        REQUIRE(1000_Pmol == 1_Emol);
    }

    SECTION("floating point literals")
    {
        REQUIRE(1.0_amol == 0.001_fmol);
        REQUIRE(1.0_fmol == 0.001_pmol);
        REQUIRE(1.0_pmol == 0.001_nmol);
        REQUIRE(1.0_nmol == 0.001_umol);
        REQUIRE(1.0_umol == 0.001_mmol);
        REQUIRE(1.0_mmol == 0.1_cmol);
        REQUIRE(1.0_cmol == 0.1_dmol);
        REQUIRE(1.0_dmol == 0.1_mol);
        REQUIRE(1.0_mol == 0.1_damol);
        REQUIRE(1.0_damol == 0.1_hmol);
        REQUIRE(1.0_hmol == 0.1_kmol);
        REQUIRE(1.0_kmol == 0.001_Mmol);
        REQUIRE(1.0_Mmol == 0.001_Gmol);
        REQUIRE(1.0_Gmol == 0.001_Tmol);
        REQUIRE(1.0_Tmol == 0.001_Pmol);
        REQUIRE(1.0_Pmol == 0.001_Emol);
    }
}
