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
}

CATCH_TEST_CASE("mass from force division", "[construct][expression][force][si]")
{
}
