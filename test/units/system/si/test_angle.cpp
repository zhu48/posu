#include "posu/units/system/si/angle.hpp"

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

CATCH_TEST_CASE("angle literals", "[construct][literals][angle][si]")
{
    using namespace si::angle_literals;

    CATCH_SECTION("integer literals")
    {
        CATCH_CHECK(1000_arad == 1_frad);
        CATCH_CHECK(1000_frad == 1_prad);
        CATCH_CHECK(1000_prad == 1_nrad);
        CATCH_CHECK(1000_nrad == 1_urad);
        CATCH_CHECK(1000_urad == 1_mrad);
        CATCH_CHECK(10_mrad == 1_crad);
        CATCH_CHECK(10_crad == 1_drad);
        CATCH_CHECK(10_drad == 1_rad);
        CATCH_CHECK(10_rad == 1_darad);
        CATCH_CHECK(10_darad == 1_hrad);
        CATCH_CHECK(10_hrad == 1_krad);
        CATCH_CHECK(1000_krad == 1_Mrad);
        CATCH_CHECK(1000_Mrad == 1_Grad);
        CATCH_CHECK(1000_Grad == 1_Trad);
        CATCH_CHECK(1000_Trad == 1_Prad);
        CATCH_CHECK(1000_Prad == 1_Erad);
    }

    CATCH_SECTION("floating point literals")
    {
        CATCH_CHECK(1.0_arad == 0.001_frad);
        CATCH_CHECK(1.0_frad == 0.001_prad);
        CATCH_CHECK(1.0_prad == 0.001_nrad);
        CATCH_CHECK(1.0_nrad == 0.001_urad);
        CATCH_CHECK(1.0_urad == 0.001_mrad);
        CATCH_CHECK(1.0_mrad == 0.1_crad);
        CATCH_CHECK(1.0_crad == 0.1_drad);
        CATCH_CHECK(1.0_drad == 0.1_rad);
        CATCH_CHECK(1.0_rad == 0.1_darad);
        CATCH_CHECK(1.0_darad == 0.1_hrad);
        CATCH_CHECK(1.0_hrad == 0.1_krad);
        CATCH_CHECK(1.0_krad == 0.001_Mrad);
        CATCH_CHECK(1.0_Mrad == 0.001_Grad);
        CATCH_CHECK(1.0_Grad == 0.001_Trad);
        CATCH_CHECK(1.0_Trad == 0.001_Prad);
        CATCH_CHECK(1.0_Prad == 0.001_Erad);
    }
}

CATCH_TEST_CASE("angle from division", "[construct][expression][angle][si]")
{
    using namespace si::angle_literals;
    using namespace si::length_literals;
    using namespace si::length_references;

    CATCH_CHECK(1_frad == units::of<si::angle>(1.0_fm / m));
    CATCH_CHECK(1_prad == units::of<si::angle>(1.0_pm / m));
    CATCH_CHECK(1_nrad == units::of<si::angle>(1.0_nm / m));
    CATCH_CHECK(1_urad == units::of<si::angle>(1.0_um / m));
    CATCH_CHECK(1_mrad == units::of<si::angle>(1.0_mm / m));
    CATCH_CHECK(1_crad == units::of<si::angle>(1.0_cm / m));
    CATCH_CHECK(1_drad == units::of<si::angle>(1.0_dm / m));
    CATCH_CHECK(1_rad == units::of<si::angle>(1.0_m / m));
    CATCH_CHECK(1_darad == units::of<si::angle>(1.0_dam / m));
    CATCH_CHECK(1_hrad == units::of<si::angle>(1.0_hm / m));
    CATCH_CHECK(1_krad == units::of<si::angle>(1.0_km / m));
    CATCH_CHECK(1_Mrad == units::of<si::angle>(1.0_Mm / m));
    CATCH_CHECK(1_Grad == units::of<si::angle>(1.0_Gm / m));
    CATCH_CHECK(1_Trad == units::of<si::angle>(1.0_Tm / m));
    CATCH_CHECK(1_Prad == units::of<si::angle>(1.0_Pm / m));
    CATCH_CHECK(1_Erad == units::of<si::angle>(1.0_Em / m));
}

CATCH_TEST_CASE("length from angle multiplication", "[construct][expression][angle][si]")
{
    using namespace si::angle_literals;
    using namespace si::length_literals;
    using namespace si::length_references;

    CATCH_CHECK(1_fm == units::of<si::length>(1_frad * m));
    CATCH_CHECK(1_pm == units::of<si::length>(1_prad * m));
    CATCH_CHECK(1_nm == units::of<si::length>(1_nrad * m));
    CATCH_CHECK(1_um == units::of<si::length>(1_urad * m));
    CATCH_CHECK(1_mm == units::of<si::length>(1_mrad * m));
    CATCH_CHECK(1_cm == units::of<si::length>(1_crad * m));
    CATCH_CHECK(1_dm == units::of<si::length>(1_drad * m));
    CATCH_CHECK(1_m == units::of<si::length>(1_rad * m));
    CATCH_CHECK(1_dam == units::of<si::length>(1_darad * m));
    CATCH_CHECK(1_hm == units::of<si::length>(1_hrad * m));
    CATCH_CHECK(1_km == units::of<si::length>(1_krad * m));
    CATCH_CHECK(1_Mm == units::of<si::length>(1_Mrad * m));
    CATCH_CHECK(1_Gm == units::of<si::length>(1_Grad * m));
    CATCH_CHECK(1_Tm == units::of<si::length>(1_Trad * m));
    CATCH_CHECK(1_Pm == units::of<si::length>(1_Prad * m));
    CATCH_CHECK(1_Em == units::of<si::length>(1_Erad * m));
}
