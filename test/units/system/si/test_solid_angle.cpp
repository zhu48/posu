#include "posu/units/system/si/solid_angle.hpp"

#define CATCH_CONFIG_PREFIX_ALL

#include <catch2/catch.hpp>

namespace {

    namespace units = posu::units;
    namespace si    = units::si;

} // namespace

CATCH_TEST_CASE("solid_angle literals", "[construct][literals][solid_angle][si]")
{
    using namespace si::solid_angle_literals;

    CATCH_SECTION("integer literals")
    {
        CATCH_CHECK(1000_asr == 1_fsr);
        CATCH_CHECK(1000_fsr == 1_psr);
        CATCH_CHECK(1000_psr == 1_nsr);
        CATCH_CHECK(1000_nsr == 1_usr);
        CATCH_CHECK(1000_usr == 1_msr);
        CATCH_CHECK(10_msr == 1_csr);
        CATCH_CHECK(10_csr == 1_dsr);
        CATCH_CHECK(10_dsr == 1_sr);
        CATCH_CHECK(10_sr == 1_dasr);
        CATCH_CHECK(10_dasr == 1_hsr);
        CATCH_CHECK(10_hsr == 1_ksr);
        CATCH_CHECK(1000_ksr == 1_Msr);
        CATCH_CHECK(1000_Msr == 1_Gsr);
        CATCH_CHECK(1000_Gsr == 1_Tsr);
        CATCH_CHECK(1000_Tsr == 1_Psr);
        CATCH_CHECK(1000_Psr == 1_Esr);
    }

    CATCH_SECTION("floating point literals")
    {
        CATCH_CHECK(1.0_asr == 0.001_fsr);
        CATCH_CHECK(1.0_fsr == 0.001_psr);
        CATCH_CHECK(1.0_psr == 0.001_nsr);
        CATCH_CHECK(1.0_nsr == 0.001_usr);
        CATCH_CHECK(1.0_usr == 0.001_msr);
        CATCH_CHECK(1.0_msr == 0.1_csr);
        CATCH_CHECK(1.0_csr == 0.1_dsr);
        CATCH_CHECK(1.0_dsr == 0.1_sr);
        CATCH_CHECK(1.0_sr == 0.1_dasr);
        CATCH_CHECK(1.0_dasr == 0.1_hsr);
        CATCH_CHECK(1.0_hsr == 0.1_ksr);
        CATCH_CHECK(1.0_ksr == 0.001_Msr);
        CATCH_CHECK(1.0_Msr == 0.001_Gsr);
        CATCH_CHECK(1.0_Gsr == 0.001_Tsr);
        CATCH_CHECK(1.0_Tsr == 0.001_Psr);
        CATCH_CHECK(1.0_Psr == 0.001_Esr);
    }
}

CATCH_TEST_CASE("solid angle from multiplication", "[construct][expression][solid_angle][si]")
{
    using namespace si::solid_angle_literals;
    using namespace si::angle_literals;
    using namespace si::angle_references;

    CATCH_CHECK(1_fsr == units::of<si::solid_angle>(1_frad * rad));
    CATCH_CHECK(1_psr == units::of<si::solid_angle>(1_prad * rad));
    CATCH_CHECK(1_nsr == units::of<si::solid_angle>(1_nrad * rad));
    CATCH_CHECK(1_usr == units::of<si::solid_angle>(1_urad * rad));
    CATCH_CHECK(1_msr == units::of<si::solid_angle>(1_mrad * rad));
    CATCH_CHECK(1_csr == units::of<si::solid_angle>(1_crad * rad));
    CATCH_CHECK(1_dsr == units::of<si::solid_angle>(1_drad * rad));
    CATCH_CHECK(1_sr == units::of<si::solid_angle>(1_rad * rad));
    CATCH_CHECK(1_dasr == units::of<si::solid_angle>(1_darad * rad));
    CATCH_CHECK(1_hsr == units::of<si::solid_angle>(1_hrad * rad));
    CATCH_CHECK(1_ksr == units::of<si::solid_angle>(1_krad * rad));
    CATCH_CHECK(1_Msr == units::of<si::solid_angle>(1_Mrad * rad));
    CATCH_CHECK(1_Gsr == units::of<si::solid_angle>(1_Grad * rad));
    CATCH_CHECK(1_Tsr == units::of<si::solid_angle>(1_Trad * rad));
    CATCH_CHECK(1_Psr == units::of<si::solid_angle>(1_Prad * rad));
    CATCH_CHECK(1_Esr == units::of<si::solid_angle>(1_Erad * rad));
}

CATCH_TEST_CASE("angle from solid angle division", "[construct][expression][solid_angle][si]")
{
    using namespace si::solid_angle_literals;
    using namespace si::angle_literals;
    using namespace si::angle_references;

    CATCH_CHECK(1_frad == units::of<si::angle>(1_fsr / rad));
    CATCH_CHECK(1_prad == units::of<si::angle>(1_psr / rad));
    CATCH_CHECK(1_nrad == units::of<si::angle>(1_nsr / rad));
    CATCH_CHECK(1_urad == units::of<si::angle>(1_usr / rad));
    CATCH_CHECK(1_mrad == units::of<si::angle>(1_msr / rad));
    CATCH_CHECK(1_crad == units::of<si::angle>(1_csr / rad));
    CATCH_CHECK(1_drad == units::of<si::angle>(1_dsr / rad));
    CATCH_CHECK(1_rad == units::of<si::angle>(1_sr / rad));
    CATCH_CHECK(1_darad == units::of<si::angle>(1_dasr / rad));
    CATCH_CHECK(1_hrad == units::of<si::angle>(1_hsr / rad));
    CATCH_CHECK(1_krad == units::of<si::angle>(1_ksr / rad));
    CATCH_CHECK(1_Mrad == units::of<si::angle>(1_Msr / rad));
    CATCH_CHECK(1_Grad == units::of<si::angle>(1_Gsr / rad));
    CATCH_CHECK(1_Trad == units::of<si::angle>(1_Tsr / rad));
    CATCH_CHECK(1_Prad == units::of<si::angle>(1_Psr / rad));
    CATCH_CHECK(1_Erad == units::of<si::angle>(1_Esr / rad));
}
