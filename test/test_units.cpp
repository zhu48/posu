#include "posu/units.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEMPLATE_TEST_CASE(
    "conversion rules",
    "[construct][convert]",
    (std::tuple<
        posu::units::kiloseconds,
        posu::units::seconds,
        posu::units::time<int, std::ratio<1, 3>>,
        posu::units::time<int, std::ratio<1, 5>>,
        posu::units::time<double, std::ratio<1>>,
        posu::units::candelas>),
    (std::tuple<
        posu::units::kilometers,
        posu::units::meters,
        posu::units::length<int, std::ratio<1, 3>>,
        posu::units::length<int, std::ratio<1, 5>>,
        posu::units::length<double, std::ratio<1>>,
        posu::units::seconds>),
    (std::tuple<
        posu::units::kilograms,
        posu::units::grams,
        posu::units::mass<int, std::ratio<1, 3>>,
        posu::units::mass<int, std::ratio<1, 5>>,
        posu::units::mass<double, std::ratio<1>>,
        posu::units::meters>),
    (std::tuple<
        posu::units::kiloamperes,
        posu::units::amperes,
        posu::units::electric_current<int, std::ratio<1, 3>>,
        posu::units::electric_current<int, std::ratio<1, 5>>,
        posu::units::electric_current<double, std::ratio<1>>,
        posu::units::grams>),
    (std::tuple<
        posu::units::kilokelvins,
        posu::units::kelvins,
        posu::units::thermodynamic_temperature<int, std::ratio<1, 3>>,
        posu::units::thermodynamic_temperature<int, std::ratio<1, 5>>,
        posu::units::thermodynamic_temperature<double, std::ratio<1>>,
        posu::units::amperes>),
    (std::tuple<
        posu::units::kilomoles,
        posu::units::moles,
        posu::units::amount_of_substance<int, std::ratio<1, 3>>,
        posu::units::amount_of_substance<int, std::ratio<1, 5>>,
        posu::units::amount_of_substance<double, std::ratio<1>>,
        posu::units::kelvins>),
    (std::tuple<
        posu::units::kilocandelas,
        posu::units::candelas,
        posu::units::luminous_intensity<int, std::ratio<1, 3>>,
        posu::units::luminous_intensity<int, std::ratio<1, 5>>,
        posu::units::luminous_intensity<double, std::ratio<1>>,
        posu::units::moles>))
{
    using kilo_type      = std::tuple_element_t<0, TestType>;
    using base_type      = std::tuple_element_t<1, TestType>;
    using third_type     = std::tuple_element_t<2, TestType>;
    using fifth_type     = std::tuple_element_t<3, TestType>;
    using double_type    = std::tuple_element_t<4, TestType>;
    using unrelated_type = std::tuple_element_t<5, TestType>;

    SECTION("implicit and explicit conversion")
    {
        SECTION("representation type")
        {
            static_assert(
                std::constructible_from<base_type, typename base_type::rep>,
                "base_type must be explicitly constructible from its "
                "representation type");
            static_assert(
                !std::convertible_to<base_type, typename base_type::rep>,
                "base_type must not be implicitly constructible from its "
                "representation type");
        }
        SECTION("wholly-divisible types")
        {
            static_assert(
                std::convertible_to<kilo_type, base_type>,
                "values with larger units must be convertible to values with "
                "smaller units");
            static_assert(
                !std::convertible_to<base_type, kilo_type>,
                "values with smaller units must not be convertible to values "
                "with larger units");
        }
        SECTION("non-wholly-divisible types")
        {
            static_assert(
                !std::convertible_to<fifth_type, third_type>,
                "values that are not unit-multiples of each others must not "
                "convert");
            static_assert(
                !std::convertible_to<third_type, fifth_type>,
                "values that are not unit-multiples of each others must not "
                "convert");
        }
        SECTION("integer-floating conversions")
        {
            static_assert(
                std::convertible_to<base_type, double_type>,
                "integer-representation values must convert to "
                "floating-point-representation values");
            static_assert(
                !std::convertible_to<double_type, base_type>,
                "floating-point-representation values must not convert to "
                "integer-representation values");
        }
        SECTION("unrelated base units")
        {
            static_assert(
                !std::constructible_from<base_type, unrelated_type>,
                "unrelated units should not convert to each other");
            static_assert(
                !std::constructible_from<unrelated_type, base_type>,
                "unrelated units should not convert to each other");
            static_assert(
                !std::convertible_to<base_type, unrelated_type>,
                "unrelated units should not convert to each other");
            static_assert(
                !std::convertible_to<unrelated_type, base_type>,
                "unrelated units should not convert to each other");
        }
    }
}

TEST_CASE("unit literals", "[construct][literals]")
{
    SECTION("time literals")
    {
        using namespace posu::units::chrono_literals;

        SECTION("integer literals")
        {
            REQUIRE(1000_as == 1_fs);
            REQUIRE(1000_fs == 1_ps);
            REQUIRE(1000_ps == 1_ns);
            REQUIRE(1000_ns == 1_us);
            REQUIRE(1000_us == 1_ms);
            REQUIRE(10_ms == 1_cs);
            REQUIRE(10_cs == 1_ds);
            REQUIRE(10_ds == 1_s);
            REQUIRE(10_s == 1_das);
            REQUIRE(10_das == 1_hs);
            REQUIRE(10_hs == 1_ks);
            REQUIRE(1000_ks == 1_Ms);
            REQUIRE(1000_Ms == 1_Gs);
            REQUIRE(1000_Gs == 1_Ts);
            REQUIRE(1000_Ts == 1_Ps);
            REQUIRE(1000_Ps == 1_Es);
            REQUIRE(60_s == 1_min);
            REQUIRE(60_min == 1_h);
        }

        SECTION("floating point literals")
        {
            REQUIRE(1.0_as == 0.001_fs);
            REQUIRE(1.0_fs == 0.001_ps);
            REQUIRE(1.0_ps == 0.001_ns);
            REQUIRE(1.0_ns == 0.001_us);
            REQUIRE(1.0_us == 0.001_ms);
            REQUIRE(1.0_ms == 0.1_cs);
            REQUIRE(1.0_cs == 0.1_ds);
            REQUIRE(1.0_ds == 0.1_s);
            REQUIRE(1.0_s == 0.1_das);
            REQUIRE(1.0_das == 0.1_hs);
            REQUIRE(1.0_hs == 0.1_ks);
            REQUIRE(1.0_ks == 0.001_Ms);
            REQUIRE(1.0_Ms == 0.001_Gs);
            REQUIRE(1.0_Gs == 0.001_Ts);
            REQUIRE(1.0_Ts == 0.001_Ps);
            REQUIRE(1.0_Ps == 0.001_Es);
            REQUIRE(30.0_s == 0.5_min);
            REQUIRE(30.0_min == 0.5_h);
        }
    }

    SECTION("length literals")
    {
        using namespace posu::units::length_literals;

        SECTION("integer literals")
        {
            REQUIRE(1000_am == 1_fm);
            REQUIRE(1000_fm == 1_pm);
            REQUIRE(1000_pm == 1_nm);
            REQUIRE(1000_nm == 1_um);
            REQUIRE(1000_um == 1_mm);
            REQUIRE(10_mm == 1_cm);
            REQUIRE(10_cm == 1_dm);
            REQUIRE(10_dm == 1_m);
            REQUIRE(10_m == 1_dam);
            REQUIRE(10_dam == 1_hm);
            REQUIRE(10_hm == 1_km);
            REQUIRE(1000_km == 1_Mm);
            REQUIRE(1000_Mm == 1_Gm);
            REQUIRE(1000_Gm == 1_Tm);
            REQUIRE(1000_Tm == 1_Pm);
            REQUIRE(1000_Pm == 1_Em);
        }

        SECTION("floating point literals")
        {
            REQUIRE(1.0_am == 0.001_fm);
            REQUIRE(1.0_fm == 0.001_pm);
            REQUIRE(1.0_pm == 0.001_nm);
            REQUIRE(1.0_nm == 0.001_um);
            REQUIRE(1.0_um == 0.001_mm);
            REQUIRE(1.0_mm == 0.1_cm);
            REQUIRE(1.0_cm == 0.1_dm);
            REQUIRE(1.0_dm == 0.1_m);
            REQUIRE(1.0_m == 0.1_dam);
            REQUIRE(1.0_dam == 0.1_hm);
            REQUIRE(1.0_hm == 0.1_km);
            REQUIRE(1.0_km == 0.001_Mm);
            REQUIRE(1.0_Mm == 0.001_Gm);
            REQUIRE(1.0_Gm == 0.001_Tm);
            REQUIRE(1.0_Tm == 0.001_Pm);
            REQUIRE(1.0_Pm == 0.001_Em);
        }
    }

    SECTION("mass literals")
    {
        using namespace posu::units::mass_literals;

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
}
