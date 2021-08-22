#include "posu/units/system/si/force.hpp"

#define CATCH_CONFIG_PREFIX_ALL

#include <catch2/catch.hpp>

namespace {

    namespace units = posu::units;
    namespace si    = units::si;

} // namespace

namespace Catch {

    template<std::intmax_t Num, std::intmax_t Den>
    struct StringMaker<std::ratio<Num, Den>> {
        static std::string convert(const std::ratio<Num, Den>& /*unused*/)
        {
            return std::to_string(Num) + '/' + std::to_string(Den);
        }
    };

    template<units::quantity_of_measure Quantity>
    struct StringMaker<Quantity> {
        static std::string convert(const Quantity& value)
        {
            return std::to_string(value.count()) + ' ' +
                   StringMaker<units::period_t<Quantity>>::convert(units::period_t<Quantity>{}) +
                   ' ' +
                   StringMaker<units::period_t<units::unit_t<Quantity>>>::convert(
                       units::period_t<units::unit_t<Quantity>>{}) +
                   ' ' + std::string(Quantity::unit_type::value);
        }
    };

} // namespace Catch

CATCH_TEST_CASE("force literals", "[construct][literals][force][si]")
{
    using namespace si::force_literals;

    CATCH_SECTION("integer literals")
    {
        CATCH_CHECK(1000_aN == 1_fN);
        CATCH_CHECK(1000_fN == 1_pN);
        CATCH_CHECK(1000_pN == 1_nN);
        CATCH_CHECK(1000_nN == 1_uN);
        CATCH_CHECK(1000_uN == 1_mN);
        CATCH_CHECK(10_mN == 1_cN);
        CATCH_CHECK(10_cN == 1_dN);
        CATCH_CHECK(10_dN == 1_N);
        CATCH_CHECK(10_N == 1_daN);
        CATCH_CHECK(10_daN == 1_hN);
        CATCH_CHECK(10_hN == 1_kN);
        CATCH_CHECK(1000_kN == 1_MN);
        CATCH_CHECK(1000_MN == 1_GN);
        CATCH_CHECK(1000_GN == 1_TN);
        CATCH_CHECK(1000_TN == 1_PN);
        // CATCH_CHECK(1000_PN == 1_EN);
    }

    CATCH_SECTION("floating point literals")
    {
        CATCH_CHECK(1.0_aN == 0.001_fN);
        CATCH_CHECK(1.0_fN == 0.001_pN);
        CATCH_CHECK(1.0_pN == 0.001_nN);
        CATCH_CHECK(1.0_nN == 0.001_uN);
        CATCH_CHECK(1.0_uN == 0.001_mN);
        CATCH_CHECK(1.0_mN == 0.1_cN);
        CATCH_CHECK(1.0_cN == 0.1_dN);
        CATCH_CHECK(1.0_dN == 0.1_N);
        CATCH_CHECK(1.0_N == 0.1_daN);
        CATCH_CHECK(1.0_daN == 0.1_hN);
        CATCH_CHECK(1.0_hN == 0.1_kN);
        CATCH_CHECK(1.0_kN == 0.001_MN);
        CATCH_CHECK(1.0_MN == 0.001_GN);
        CATCH_CHECK(1.0_GN == 0.001_TN);
        CATCH_CHECK(1.0_TN == 0.001_PN);
        // CATCH_CHECK(1.0_PN == 0.001_EN);
    }
}

CATCH_TEST_CASE("force from multiplication", "[construct][expression][force][si]")
{
    using namespace si::length_references;
    using namespace si::mass_literals;
    using namespace si::force_literals;
    using namespace si::chrono_references;

    CATCH_CHECK(1_fN == 1_kg * (fm / s / s));
    CATCH_CHECK(1_pN == 1_kg * (pm / s / s));
    CATCH_CHECK(1_nN == 1_kg * (nm / s / s));
    CATCH_CHECK(1_uN == 1_kg * (um / s / s));
    CATCH_CHECK(1_mN == 1_kg * (mm / s / s));
    CATCH_CHECK(1_cN == 1_kg * (cm / s / s));
    CATCH_CHECK(1_dN == 1_kg * (dm / s / s));
    CATCH_CHECK(1_N == 1_kg * (m / s / s));
    CATCH_CHECK(1_daN == 1_kg * (dam / s / s));
    CATCH_CHECK(1_hN == 1_kg * (hm / s / s));
    CATCH_CHECK(1_kN == 1_kg * (km / s / s));
    CATCH_CHECK(1_MN == 1_kg * (Mm / s / s));
    CATCH_CHECK(1_GN == 1_kg * (Gm / s / s));
    CATCH_CHECK(1_TN == 1_kg * (Tm / s / s));
    CATCH_CHECK(1_PN == 1_kg * (Pm / s / s));
    // CATCH_CHECK(1_EN == 1000_g * (Em / s / s));

    CATCH_CHECK(1_fN == units::of<si::force>(1_kg * (fm / (s * s))));
    CATCH_CHECK(1_pN == units::of<si::force>(1_kg * (pm / (s * s))));
    CATCH_CHECK(1_nN == units::of<si::force>(1_kg * (nm / (s * s))));
    CATCH_CHECK(1_uN == units::of<si::force>(1_kg * (um / (s * s))));
    CATCH_CHECK(1_mN == units::of<si::force>(1_kg * (mm / (s * s))));
    CATCH_CHECK(1_cN == units::of<si::force>(1_kg * (cm / (s * s))));
    CATCH_CHECK(1_dN == units::of<si::force>(1_kg * (dm / (s * s))));
    CATCH_CHECK(1_N == units::of<si::force>(1_kg * (m / (s * s))));
    CATCH_CHECK(1_daN == units::of<si::force>(1_kg * (dam / (s * s))));
    CATCH_CHECK(1_hN == units::of<si::force>(1_kg * (hm / (s * s))));
    CATCH_CHECK(1_kN == units::of<si::force>(1_kg * (km / (s * s))));
    CATCH_CHECK(1_MN == units::of<si::force>(1_kg * (Mm / (s * s))));
    CATCH_CHECK(1_GN == units::of<si::force>(1_kg * (Gm / (s * s))));
    CATCH_CHECK(1_TN == units::of<si::force>(1_kg * (Tm / (s * s))));
    CATCH_CHECK(1_PN == units::of<si::force>(1_kg * (Pm / (s * s))));
    // CATCH_CHECK(1_EN == units::of<si::force>(1000_g * (Em / (s * s))));
}

CATCH_TEST_CASE("acceleration from force division", "[construct][expression][force][si]")
{
    using namespace si::length_literals;
    using namespace si::chrono_references;
    using namespace si::force_literals;
    using namespace si::mass_references;

    CATCH_CHECK(1_fm / s / s == 1_fN / kg);
    CATCH_CHECK(1_pm / s / s == 1_pN / kg);
    CATCH_CHECK(1_nm / s / s == 1_nN / kg);
    CATCH_CHECK(1_um / s / s == 1_uN / kg);
    CATCH_CHECK(1_mm / s / s == 1_mN / kg);
    CATCH_CHECK(1_cm / s / s == 1_cN / kg);
    CATCH_CHECK(1_dm / s / s == 1_dN / kg);
    CATCH_CHECK(1_m / s / s == 1_N / kg);
    CATCH_CHECK(1_dam / s / s == 1_daN / kg);
    CATCH_CHECK(1_hm / s / s == 1_hN / kg);
    CATCH_CHECK(1_km / s / s == 1_kN / kg);
    CATCH_CHECK(1_Mm / s / s == 1_MN / kg);
    CATCH_CHECK(1_Gm / s / s == 1_GN / kg);
    CATCH_CHECK(1_Tm / s / s == 1_TN / kg);
    CATCH_CHECK(1_Pm / s / s == 1_PN / kg);
    CATCH_CHECK(1_Em / s / s == 1_EN / kg);
}

CATCH_TEST_CASE("mass from force division", "[construct][expression][force][si]")
{
    using namespace si::length_references;
    using namespace si::chrono_references;
    using namespace si::force_literals;
    using namespace si::mass_references;
    using namespace si::mass_literals;

    CATCH_CHECK(1_fg == 1_fN / (km / s / s));
    CATCH_CHECK(1_pg == 1_pN / (km / s / s));
    CATCH_CHECK(1_ng == 1_nN / (km / s / s));
    CATCH_CHECK(1_ug == 1_uN / (km / s / s));
    CATCH_CHECK(1_mg == 1_mN / (km / s / s));
    CATCH_CHECK(1_cg == 1_cN / (km / s / s));
    CATCH_CHECK(1_dg == 1_dN / (km / s / s));
    CATCH_CHECK(1_g == 1_N / (km / s / s));
    CATCH_CHECK(1_dag == 1_daN / (km / s / s));
    CATCH_CHECK(1_hg == 1_hN / (km / s / s));
    CATCH_CHECK(1_kg == 1_kN / (km / s / s));
    CATCH_CHECK(1_Mg == 1_MN / (km / s / s));
    CATCH_CHECK(1_Gg == 1_GN / (km / s / s));
    CATCH_CHECK(1_Tg == 1_TN / (km / s / s));
    CATCH_CHECK(1_Pg == 1_PN / (km / s / s));
    CATCH_CHECK(1_Eg == 1_EN / (km / s / s));
}
