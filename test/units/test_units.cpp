#include "posu/units/units.hpp"

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

    SECTION("electric current literals")
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

    SECTION("thermodynamic temperature literals")
    {
        using namespace posu::units::thermodynamic_temperature_literals;

        SECTION("integer literals")
        {
            REQUIRE(1000_aK == 1_fK);
            REQUIRE(1000_fK == 1_pK);
            REQUIRE(1000_pK == 1_nK);
            REQUIRE(1000_nK == 1_uK);
            REQUIRE(1000_uK == 1_mK);
            REQUIRE(10_mK == 1_cK);
            REQUIRE(10_cK == 1_dK);
            REQUIRE(10_dK == 1_K);
            REQUIRE(10_K == 1_daK);
            REQUIRE(10_daK == 1_hK);
            REQUIRE(10_hK == 1_kK);
            REQUIRE(1000_kK == 1_MK);
            REQUIRE(1000_MK == 1_GK);
            REQUIRE(1000_GK == 1_TK);
            REQUIRE(1000_TK == 1_PK);
            REQUIRE(1000_PK == 1_EK);
        }

        SECTION("floating point literals")
        {
            REQUIRE(1.0_aK == 0.001_fK);
            REQUIRE(1.0_fK == 0.001_pK);
            REQUIRE(1.0_pK == 0.001_nK);
            REQUIRE(1.0_nK == 0.001_uK);
            REQUIRE(1.0_uK == 0.001_mK);
            REQUIRE(1.0_mK == 0.1_cK);
            REQUIRE(1.0_cK == 0.1_dK);
            REQUIRE(1.0_dK == 0.1_K);
            REQUIRE(1.0_K == 0.1_daK);
            REQUIRE(1.0_daK == 0.1_hK);
            REQUIRE(1.0_hK == 0.1_kK);
            REQUIRE(1.0_kK == 0.001_MK);
            REQUIRE(1.0_MK == 0.001_GK);
            REQUIRE(1.0_GK == 0.001_TK);
            REQUIRE(1.0_TK == 0.001_PK);
            REQUIRE(1.0_PK == 0.001_EK);
        }
    }

    SECTION("luminous intensity literals")
    {
        using namespace posu::units::luminous_intensity_literals;

        SECTION("integer literals")
        {
            REQUIRE(1000_acd == 1_fcd);
            REQUIRE(1000_fcd == 1_pcd);
            REQUIRE(1000_pcd == 1_ncd);
            REQUIRE(1000_ncd == 1_ucd);
            REQUIRE(1000_ucd == 1_mcd);
            REQUIRE(10_mcd == 1_ccd);
            REQUIRE(10_ccd == 1_dcd);
            REQUIRE(10_dcd == 1_cd);
            REQUIRE(10_cd == 1_dacd);
            REQUIRE(10_dacd == 1_hcd);
            REQUIRE(10_hcd == 1_kcd);
            REQUIRE(1000_kcd == 1_Mcd);
            REQUIRE(1000_Mcd == 1_Gcd);
            REQUIRE(1000_Gcd == 1_Tcd);
            REQUIRE(1000_Tcd == 1_Pcd);
            REQUIRE(1000_Pcd == 1_Ecd);
        }

        SECTION("floating point literals")
        {
            REQUIRE(1.0_acd == 0.001_fcd);
            REQUIRE(1.0_fcd == 0.001_pcd);
            REQUIRE(1.0_pcd == 0.001_ncd);
            REQUIRE(1.0_ncd == 0.001_ucd);
            REQUIRE(1.0_ucd == 0.001_mcd);
            REQUIRE(1.0_mcd == 0.1_ccd);
            REQUIRE(1.0_ccd == 0.1_dcd);
            REQUIRE(1.0_dcd == 0.1_cd);
            REQUIRE(1.0_cd == 0.1_dacd);
            REQUIRE(1.0_dacd == 0.1_hcd);
            REQUIRE(1.0_hcd == 0.1_kcd);
            REQUIRE(1.0_kcd == 0.001_Mcd);
            REQUIRE(1.0_Mcd == 0.001_Gcd);
            REQUIRE(1.0_Gcd == 0.001_Tcd);
            REQUIRE(1.0_Tcd == 0.001_Pcd);
            REQUIRE(1.0_Pcd == 0.001_Ecd);
        }
    }
}
