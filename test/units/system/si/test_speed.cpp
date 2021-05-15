#include "posu/units/system/si/speed.hpp"

#include <catch2/catch.hpp>

TEST_CASE("speed literals", "[construct][literals][speed][si]")
{
    using namespace posu::units::si::speed_literals;

    SECTION("integer literals")
    {
        REQUIRE(1000_am_per_sec == 1_fm_per_sec);
        REQUIRE(1000_fm_per_sec == 1_pm_per_sec);
        REQUIRE(1000_pm_per_sec == 1_nm_per_sec);
        REQUIRE(1000_nm_per_sec == 1_um_per_sec);
        REQUIRE(1000_um_per_sec == 1_mm_per_sec);
        REQUIRE(10_mm_per_sec == 1_cm_per_sec);
        REQUIRE(10_cm_per_sec == 1_dm_per_sec);
        REQUIRE(10_dm_per_sec == 1_m_per_sec);
        REQUIRE(10_m_per_sec == 1_dam_per_sec);
        REQUIRE(10_dam_per_sec == 1_hm_per_sec);
        REQUIRE(10_hm_per_sec == 1_km_per_sec);
        REQUIRE(1000_km_per_sec == 1_Mm_per_sec);
        REQUIRE(1000_Mm_per_sec == 1_Gm_per_sec);
        REQUIRE(1000_Gm_per_sec == 1_Tm_per_sec);
        REQUIRE(1000_Tm_per_sec == 1_Pm_per_sec);
        REQUIRE(1000_Pm_per_sec == 1_Em_per_sec);
    }

    SECTION("floating point literals")
    {
        REQUIRE(1.0_am_per_sec == 0.001_fm_per_sec);
        REQUIRE(1.0_fm_per_sec == 0.001_pm_per_sec);
        REQUIRE(1.0_pm_per_sec == 0.001_nm_per_sec);
        REQUIRE(1.0_nm_per_sec == 0.001_um_per_sec);
        REQUIRE(1.0_um_per_sec == 0.001_mm_per_sec);
        REQUIRE(1.0_mm_per_sec == 0.1_cm_per_sec);
        REQUIRE(1.0_cm_per_sec == 0.1_dm_per_sec);
        REQUIRE(1.0_dm_per_sec == 0.1_m_per_sec);
        REQUIRE(1.0_m_per_sec == 0.1_dam_per_sec);
        REQUIRE(1.0_dam_per_sec == 0.1_hm_per_sec);
        REQUIRE(1.0_hm_per_sec == 0.1_km_per_sec);
        REQUIRE(1.0_km_per_sec == 0.001_Mm_per_sec);
        REQUIRE(1.0_Mm_per_sec == 0.001_Gm_per_sec);
        REQUIRE(1.0_Gm_per_sec == 0.001_Tm_per_sec);
        REQUIRE(1.0_Tm_per_sec == 0.001_Pm_per_sec);
        REQUIRE(1.0_Pm_per_sec == 0.001_Em_per_sec);
    }
}

TEST_CASE("speed from division", "[construct][expression][speed][si]")
{
    using namespace posu::units::si::length_literals;
    using namespace posu::units::si::chrono_literals;
    using namespace posu::units::si::speed_literals;

    SECTION("integer literals")
    {
        REQUIRE(5_m / 1_s == 5_m_per_sec);
        REQUIRE(2_mm / 8_ks == 0_m_per_sec);
    }

    SECTION("floating point literals")
    {
        REQUIRE(2.5_km / 5_s == 0.5_km_per_sec);
        REQUIRE(2_mm / 8.0_ks == 0.25_um_per_sec);
    }
}

TEST_CASE("length from multiplication", "[construct][expression][speed][si]")
{
    using namespace posu::units::si::length_literals;
    using namespace posu::units::si::chrono_literals;
    using namespace posu::units::si::speed_literals;

    SECTION("integer literals")
    {
        REQUIRE(5_m_per_sec * 1_s == 5_m);
        REQUIRE(1_s * 5_m_per_sec == 5_m);
        REQUIRE(32_m_per_sec * 8_ks == 256_km);
        REQUIRE(8_ks * 32_m_per_sec == 256_km);
    }

    SECTION("floating point literals")
    {
        REQUIRE(0.5_km_per_sec * 5_s == 2.5_km);
        REQUIRE(5_s * 0.5_km_per_sec == 2.5_km);
        REQUIRE(0.25_um_per_sec * 8.0_ks == 2_mm);
        REQUIRE(8.0_ks * 0.25_um_per_sec == 2_mm);
    }
}
