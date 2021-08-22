#include "posu/units/system/si/amount_of_substance.hpp"

#define CATCH_CONFIG_PREFIX_ALL

#include <catch2/catch.hpp>

CATCH_TEST_CASE("amount of substance literals", "[construct][literals][amount][si]")
{
    using namespace posu::units::si::amount_of_substance_literals;

    CATCH_SECTION("integer literals")
    {
        CATCH_CHECK(1000_amol == 1_fmol);
        CATCH_CHECK(1000_fmol == 1_pmol);
        CATCH_CHECK(1000_pmol == 1_nmol);
        CATCH_CHECK(1000_nmol == 1_umol);
        CATCH_CHECK(1000_umol == 1_mmol);
        CATCH_CHECK(10_mmol == 1_cmol);
        CATCH_CHECK(10_cmol == 1_dmol);
        CATCH_CHECK(10_dmol == 1_mol);
        CATCH_CHECK(10_mol == 1_damol);
        CATCH_CHECK(10_damol == 1_hmol);
        CATCH_CHECK(10_hmol == 1_kmol);
        CATCH_CHECK(1000_kmol == 1_Mmol);
        CATCH_CHECK(1000_Mmol == 1_Gmol);
        CATCH_CHECK(1000_Gmol == 1_Tmol);
        CATCH_CHECK(1000_Tmol == 1_Pmol);
        CATCH_CHECK(1000_Pmol == 1_Emol);
    }

    CATCH_SECTION("floating point literals")
    {
        CATCH_CHECK(1.0_amol == 0.001_fmol);
        CATCH_CHECK(1.0_fmol == 0.001_pmol);
        CATCH_CHECK(1.0_pmol == 0.001_nmol);
        CATCH_CHECK(1.0_nmol == 0.001_umol);
        CATCH_CHECK(1.0_umol == 0.001_mmol);
        CATCH_CHECK(1.0_mmol == 0.1_cmol);
        CATCH_CHECK(1.0_cmol == 0.1_dmol);
        CATCH_CHECK(1.0_dmol == 0.1_mol);
        CATCH_CHECK(1.0_mol == 0.1_damol);
        CATCH_CHECK(1.0_damol == 0.1_hmol);
        CATCH_CHECK(1.0_hmol == 0.1_kmol);
        CATCH_CHECK(1.0_kmol == 0.001_Mmol);
        CATCH_CHECK(1.0_Mmol == 0.001_Gmol);
        CATCH_CHECK(1.0_Gmol == 0.001_Tmol);
        CATCH_CHECK(1.0_Tmol == 0.001_Pmol);
        CATCH_CHECK(1.0_Pmol == 0.001_Emol);
    }
}
