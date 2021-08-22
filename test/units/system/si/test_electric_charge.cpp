#include "posu/units/system/si/electric_charge.hpp"

#define CATCH_CONFIG_PREFIX_ALL

#include <catch2/catch.hpp>

namespace {

    namespace units = posu::units;
    namespace si    = units::si;

} // namespace

CATCH_TEST_CASE("electric_charge literals", "[construct][literals][electric_charge][si]")
{
    using namespace si::electric_charge_literals;

    CATCH_SECTION("integer literals")
    {
        CATCH_CHECK(1000_aC == 1_fC);
        CATCH_CHECK(1000_fC == 1_pC);
        CATCH_CHECK(1000_pC == 1_nC);
        CATCH_CHECK(1000_nC == 1_uC);
        CATCH_CHECK(1000_uC == 1_mC);
        CATCH_CHECK(10_mC == 1_cC);
        CATCH_CHECK(10_cC == 1_dC);
        CATCH_CHECK(10_dC == 1_C);
        CATCH_CHECK(10_C == 1_daC);
        CATCH_CHECK(10_daC == 1_hC);
        CATCH_CHECK(10_hC == 1_kC);
        CATCH_CHECK(1000_kC == 1_MC);
        CATCH_CHECK(1000_MC == 1_GC);
        CATCH_CHECK(1000_GC == 1_TC);
        CATCH_CHECK(1000_TC == 1_PC);
        CATCH_CHECK(1000_PC == 1_EC);
    }

    CATCH_SECTION("floating point literals")
    {
        CATCH_CHECK(1.0_aC == 0.001_fC);
        CATCH_CHECK(1.0_fC == 0.001_pC);
        CATCH_CHECK(1.0_pC == 0.001_nC);
        CATCH_CHECK(1.0_nC == 0.001_uC);
        CATCH_CHECK(1.0_uC == 0.001_mC);
        CATCH_CHECK(1.0_mC == 0.1_cC);
        CATCH_CHECK(1.0_cC == 0.1_dC);
        CATCH_CHECK(1.0_dC == 0.1_C);
        CATCH_CHECK(1.0_C == 0.1_daC);
        CATCH_CHECK(1.0_daC == 0.1_hC);
        CATCH_CHECK(1.0_hC == 0.1_kC);
        CATCH_CHECK(1.0_kC == 0.001_MC);
        CATCH_CHECK(1.0_MC == 0.001_GC);
        CATCH_CHECK(1.0_GC == 0.001_TC);
        CATCH_CHECK(1.0_TC == 0.001_PC);
        CATCH_CHECK(1.0_PC == 0.001_EC);
    }
}

CATCH_TEST_CASE(
    "electric_charge from multiplication",
    "[construct][expression][electric_charge][si]")
{
    using namespace si::electric_current_references;
    using namespace si::chrono_references;
    using namespace si::electric_charge_literals;

    CATCH_CHECK(1_fC == units::of<si::electric_charge>(1 * (fA * s)));
    CATCH_CHECK(1_pC == units::of<si::electric_charge>(1 * (pA * s)));
    CATCH_CHECK(1_nC == units::of<si::electric_charge>(1 * (nA * s)));
    CATCH_CHECK(1_uC == units::of<si::electric_charge>(1 * (uA * s)));
    CATCH_CHECK(1_mC == units::of<si::electric_charge>(1 * (mA * s)));
    CATCH_CHECK(1_cC == units::of<si::electric_charge>(1 * (cA * s)));
    CATCH_CHECK(1_dC == units::of<si::electric_charge>(1 * (dA * s)));
    CATCH_CHECK(1_C == units::of<si::electric_charge>(1 * (A * s)));
    CATCH_CHECK(1_daC == units::of<si::electric_charge>(1 * (daA * s)));
    CATCH_CHECK(1_hC == units::of<si::electric_charge>(1 * (hA * s)));
    CATCH_CHECK(1_kC == units::of<si::electric_charge>(1 * (kA * s)));
    CATCH_CHECK(1_MC == units::of<si::electric_charge>(1 * (MA * s)));
    CATCH_CHECK(1_GC == units::of<si::electric_charge>(1 * (GA * s)));
    CATCH_CHECK(1_TC == units::of<si::electric_charge>(1 * (TA * s)));
    CATCH_CHECK(1_PC == units::of<si::electric_charge>(1 * (PA * s)));
    CATCH_CHECK(1_EC == units::of<si::electric_charge>(1 * (EA * s)));
}

CATCH_TEST_CASE(
    "electric_current from electric_charge division",
    "[construct][expression][electric_charge][si]")
{
    using namespace si::chrono_references;
    using namespace si::electric_charge_literals;
    using namespace si::electric_current_literals;

    CATCH_CHECK(1_fA == units::of<si::electric_current>(1_fC / s));
    CATCH_CHECK(1_pA == units::of<si::electric_current>(1_pC / s));
    CATCH_CHECK(1_nA == units::of<si::electric_current>(1_nC / s));
    CATCH_CHECK(1_uA == units::of<si::electric_current>(1_uC / s));
    CATCH_CHECK(1_mA == units::of<si::electric_current>(1_mC / s));
    CATCH_CHECK(1_cA == units::of<si::electric_current>(1_cC / s));
    CATCH_CHECK(1_dA == units::of<si::electric_current>(1_dC / s));
    CATCH_CHECK(1_A == units::of<si::electric_current>(1_C / s));
    CATCH_CHECK(1_daA == units::of<si::electric_current>(1_daC / s));
    CATCH_CHECK(1_hA == units::of<si::electric_current>(1_hC / s));
    CATCH_CHECK(1_kA == units::of<si::electric_current>(1_kC / s));
    CATCH_CHECK(1_MA == units::of<si::electric_current>(1_MC / s));
    CATCH_CHECK(1_GA == units::of<si::electric_current>(1_GC / s));
    CATCH_CHECK(1_TA == units::of<si::electric_current>(1_TC / s));
    CATCH_CHECK(1_PA == units::of<si::electric_current>(1_PC / s));
    CATCH_CHECK(1_EA == units::of<si::electric_current>(1_EC / s));
}

CATCH_TEST_CASE(
    "time from electric_charge division",
    "[construct][expression][electric_charge][si]")
{
    using namespace si::chrono_literals;
    using namespace si::electric_charge_literals;
    using namespace si::electric_current_references;

    CATCH_CHECK(1_fs == units::of<si::time>(1_fC / A));
    CATCH_CHECK(1_ps == units::of<si::time>(1_pC / A));
    CATCH_CHECK(1_ns == units::of<si::time>(1_nC / A));
    CATCH_CHECK(1_us == units::of<si::time>(1_uC / A));
    CATCH_CHECK(1_ms == units::of<si::time>(1_mC / A));
    CATCH_CHECK(1_cs == units::of<si::time>(1_cC / A));
    CATCH_CHECK(1_ds == units::of<si::time>(1_dC / A));
    CATCH_CHECK(1_s == units::of<si::time>(1_C / A));
    CATCH_CHECK(1_das == units::of<si::time>(1_daC / A));
    CATCH_CHECK(1_hs == units::of<si::time>(1_hC / A));
    CATCH_CHECK(1_ks == units::of<si::time>(1_kC / A));
    CATCH_CHECK(1_Ms == units::of<si::time>(1_MC / A));
    CATCH_CHECK(1_Gs == units::of<si::time>(1_GC / A));
    CATCH_CHECK(1_Ts == units::of<si::time>(1_TC / A));
    CATCH_CHECK(1_Ps == units::of<si::time>(1_PC / A));
    CATCH_CHECK(1_Es == units::of<si::time>(1_EC / A));
}
