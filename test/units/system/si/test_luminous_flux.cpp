#include "posu/units/system/si/luminous_flux.hpp"

#define CATCH_CONFIG_PREFIX_ALL

#include <catch2/catch.hpp>

namespace {

    namespace units = posu::units;
    namespace si    = units::si;

} // namespace

CATCH_TEST_CASE("luminous flux literals", "[construct][literals][luminous_flux][si]")
{
    using namespace si::luminous_flux_literals;

    CATCH_SECTION("integer literals")
    {
        CATCH_CHECK(1000_alm == 1_flm);
        CATCH_CHECK(1000_flm == 1_plm);
        CATCH_CHECK(1000_plm == 1_nlm);
        CATCH_CHECK(1000_nlm == 1_ulm);
        CATCH_CHECK(1000_ulm == 1_mlm);
        CATCH_CHECK(10_mlm == 1_clm);
        CATCH_CHECK(10_clm == 1_dlm);
        CATCH_CHECK(10_dlm == 1_lm);
        CATCH_CHECK(10_lm == 1_dalm);
        CATCH_CHECK(10_dalm == 1_hlm);
        CATCH_CHECK(10_hlm == 1_klm);
        CATCH_CHECK(1000_klm == 1_Mlm);
        CATCH_CHECK(1000_Mlm == 1_Glm);
        CATCH_CHECK(1000_Glm == 1_Tlm);
        CATCH_CHECK(1000_Tlm == 1_Plm);
        CATCH_CHECK(1000_Plm == 1_Elm);
    }

    CATCH_SECTION("floating point literals")
    {
        CATCH_CHECK(1.0_alm == 0.001_flm);
        CATCH_CHECK(1.0_flm == 0.001_plm);
        CATCH_CHECK(1.0_plm == 0.001_nlm);
        CATCH_CHECK(1.0_nlm == 0.001_ulm);
        CATCH_CHECK(1.0_ulm == 0.001_mlm);
        CATCH_CHECK(1.0_mlm == 0.1_clm);
        CATCH_CHECK(1.0_clm == 0.1_dlm);
        CATCH_CHECK(1.0_dlm == 0.1_lm);
        CATCH_CHECK(1.0_lm == 0.1_dalm);
        CATCH_CHECK(1.0_dalm == 0.1_hlm);
        CATCH_CHECK(1.0_hlm == 0.1_klm);
        CATCH_CHECK(1.0_klm == 0.001_Mlm);
        CATCH_CHECK(1.0_Mlm == 0.001_Glm);
        CATCH_CHECK(1.0_Glm == 0.001_Tlm);
        CATCH_CHECK(1.0_Tlm == 0.001_Plm);
        CATCH_CHECK(1.0_Plm == 0.001_Elm);
    }
}

CATCH_TEST_CASE("luminous flux from multiplication", "[construct][expression][luminous_flux][si]")
{
    using namespace si::luminous_flux_literals;
    using namespace si::luminous_intensity_literals;
    using namespace si::solid_angle_references;

    CATCH_CHECK(1_flm == units::of<si::luminous_flux>(1_fcd * sr));
    CATCH_CHECK(1_plm == units::of<si::luminous_flux>(1_pcd * sr));
    CATCH_CHECK(1_nlm == units::of<si::luminous_flux>(1_ncd * sr));
    CATCH_CHECK(1_ulm == units::of<si::luminous_flux>(1_ucd * sr));
    CATCH_CHECK(1_mlm == units::of<si::luminous_flux>(1_mcd * sr));
    CATCH_CHECK(1_clm == units::of<si::luminous_flux>(1_ccd * sr));
    CATCH_CHECK(1_dlm == units::of<si::luminous_flux>(1_dcd * sr));
    CATCH_CHECK(1_lm == units::of<si::luminous_flux>(1_cd * sr));
    CATCH_CHECK(1_dalm == units::of<si::luminous_flux>(1_dacd * sr));
    CATCH_CHECK(1_hlm == units::of<si::luminous_flux>(1_hcd * sr));
    CATCH_CHECK(1_klm == units::of<si::luminous_flux>(1_kcd * sr));
    CATCH_CHECK(1_Mlm == units::of<si::luminous_flux>(1_Mcd * sr));
    CATCH_CHECK(1_Glm == units::of<si::luminous_flux>(1_Gcd * sr));
    CATCH_CHECK(1_Tlm == units::of<si::luminous_flux>(1_Tcd * sr));
    CATCH_CHECK(1_Plm == units::of<si::luminous_flux>(1_Pcd * sr));
    CATCH_CHECK(1_Elm == units::of<si::luminous_flux>(1_Ecd * sr));
}

CATCH_TEST_CASE(
    "luminous intensity from luminous flux division",
    "[construct][expression][luminous_flux][si]")
{
    using namespace si::luminous_flux_literals;
    using namespace si::luminous_intensity_literals;
    using namespace si::solid_angle_references;

    CATCH_CHECK(1_fcd == units::of<si::luminous_intensity>(1_flm / sr));
    CATCH_CHECK(1_pcd == units::of<si::luminous_intensity>(1_plm / sr));
    CATCH_CHECK(1_ncd == units::of<si::luminous_intensity>(1_nlm / sr));
    CATCH_CHECK(1_ucd == units::of<si::luminous_intensity>(1_ulm / sr));
    CATCH_CHECK(1_mcd == units::of<si::luminous_intensity>(1_mlm / sr));
    CATCH_CHECK(1_ccd == units::of<si::luminous_intensity>(1_clm / sr));
    CATCH_CHECK(1_dcd == units::of<si::luminous_intensity>(1_dlm / sr));
    CATCH_CHECK(1_cd == units::of<si::luminous_intensity>(1_lm / sr));
    CATCH_CHECK(1_dacd == units::of<si::luminous_intensity>(1_dalm / sr));
    CATCH_CHECK(1_hcd == units::of<si::luminous_intensity>(1_hlm / sr));
    CATCH_CHECK(1_kcd == units::of<si::luminous_intensity>(1_klm / sr));
    CATCH_CHECK(1_Mcd == units::of<si::luminous_intensity>(1_Mlm / sr));
    CATCH_CHECK(1_Gcd == units::of<si::luminous_intensity>(1_Glm / sr));
    CATCH_CHECK(1_Tcd == units::of<si::luminous_intensity>(1_Tlm / sr));
    CATCH_CHECK(1_Pcd == units::of<si::luminous_intensity>(1_Plm / sr));
    CATCH_CHECK(1_Ecd == units::of<si::luminous_intensity>(1_Elm / sr));
}

CATCH_TEST_CASE(
    "solid angle from luminous flux division",
    "[construct][expression][luminous_flux][si]")
{
    using namespace si::luminous_flux_literals;
    using namespace si::solid_angle_literals;
    using namespace si::luminous_intensity_references;

    CATCH_CHECK(1_fsr == units::of<si::solid_angle>(1_flm / cd));
    CATCH_CHECK(1_psr == units::of<si::solid_angle>(1_plm / cd));
    CATCH_CHECK(1_nsr == units::of<si::solid_angle>(1_nlm / cd));
    CATCH_CHECK(1_usr == units::of<si::solid_angle>(1_ulm / cd));
    CATCH_CHECK(1_msr == units::of<si::solid_angle>(1_mlm / cd));
    CATCH_CHECK(1_csr == units::of<si::solid_angle>(1_clm / cd));
    CATCH_CHECK(1_dsr == units::of<si::solid_angle>(1_dlm / cd));
    CATCH_CHECK(1_sr == units::of<si::solid_angle>(1_lm / cd));
    CATCH_CHECK(1_dasr == units::of<si::solid_angle>(1_dalm / cd));
    CATCH_CHECK(1_hsr == units::of<si::solid_angle>(1_hlm / cd));
    CATCH_CHECK(1_ksr == units::of<si::solid_angle>(1_klm / cd));
    CATCH_CHECK(1_Msr == units::of<si::solid_angle>(1_Mlm / cd));
    CATCH_CHECK(1_Gsr == units::of<si::solid_angle>(1_Glm / cd));
    CATCH_CHECK(1_Tsr == units::of<si::solid_angle>(1_Tlm / cd));
    CATCH_CHECK(1_Psr == units::of<si::solid_angle>(1_Plm / cd));
    CATCH_CHECK(1_Esr == units::of<si::solid_angle>(1_Elm / cd));
}
