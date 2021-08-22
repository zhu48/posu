#include "posu/units/system/velocity.hpp"

#define CATCH_CONFIG_PREFIX_ALL

#include "posu/units/system/si/length.hpp"
#include "posu/units/system/si/time.hpp"

#include <catch2/catch.hpp>

namespace {

    namespace units = posu::units;
    namespace si    = units::si;

} // namespace

CATCH_TEST_CASE("speed literals", "[construct][literals][speed][si]")
{
    using namespace posu::units::si::length_references;
    using namespace posu::units::si::chrono_references;

    CATCH_SECTION("integer literals")
    {
        CATCH_CHECK(1000 * (am / s) == 1 * (fm / s));
        CATCH_CHECK(1000 * (fm / s) == 1 * (pm / s));
        CATCH_CHECK(1000 * (pm / s) == 1 * (nm / s));
        CATCH_CHECK(1000 * (nm / s) == 1 * (um / s));
        CATCH_CHECK(1000 * (um / s) == 1 * (mm / s));
        CATCH_CHECK(10 * (mm / s) == 1 * (cm / s));
        CATCH_CHECK(10 * (cm / s) == 1 * (dm / s));
        CATCH_CHECK(10 * (dm / s) == 1 * (m / s));
        CATCH_CHECK(10 * (m / s) == 1 * (dam / s));
        CATCH_CHECK(10 * (dam / s) == 1 * (hm / s));
        CATCH_CHECK(10 * (hm / s) == 1 * (km / s));
        CATCH_CHECK(1000 * (km / s) == 1 * (Mm / s));
        CATCH_CHECK(1000 * (Mm / s) == 1 * (Gm / s));
        CATCH_CHECK(1000 * (Gm / s) == 1 * (Tm / s));
        CATCH_CHECK(1000 * (Tm / s) == 1 * (Pm / s));
        CATCH_CHECK(1000 * (Pm / s) == 1 * (Em / s));

        CATCH_CHECK(1 * (m / s) == 1 * (mm / ms));
        CATCH_CHECK(1 * (m / s) == 1000 * (mm / s));
        CATCH_CHECK(1 * (m / s) == 100 * (mm / ds));
    }

    CATCH_SECTION("floating point literals")
    {
        CATCH_CHECK(1.0 * (am / s) == 0.001 * (fm / s));
        CATCH_CHECK(1.0 * (fm / s) == 0.001 * (pm / s));
        CATCH_CHECK(1.0 * (pm / s) == 0.001 * (nm / s));
        CATCH_CHECK(1.0 * (nm / s) == 0.001 * (um / s));
        CATCH_CHECK(1.0 * (um / s) == 0.001 * (mm / s));
        CATCH_CHECK(1.0 * (mm / s) == 0.1 * (cm / s));
        CATCH_CHECK(1.0 * (cm / s) == 0.1 * (dm / s));
        CATCH_CHECK(1.0 * (dm / s) == 0.1 * (m / s));
        CATCH_CHECK(1.0 * (m / s) == 0.1 * (dam / s));
        CATCH_CHECK(1.0 * (dam / s) == 0.1 * (hm / s));
        CATCH_CHECK(1.0 * (hm / s) == 0.1 * (km / s));
        CATCH_CHECK(1.0 * (km / s) == 0.001 * (Mm / s));
        CATCH_CHECK(1.0 * (Mm / s) == 0.001 * (Gm / s));
        CATCH_CHECK(1.0 * (Gm / s) == 0.001 * (Tm / s));
        CATCH_CHECK(1.0 * (Tm / s) == 0.001 * (Pm / s));
        CATCH_CHECK(1.0 * (Pm / s) == 0.001 * (Em / s));

        CATCH_CHECK(1.0 * (m / s) == 1.0 * (mm / ms));
        CATCH_CHECK(1.0 * (m / s) == 1000.0 * (mm / s));
        CATCH_CHECK(1.0 * (m / s) == 100.0 * (mm / ds));
    }
}

CATCH_TEST_CASE("speed from division", "[construct][expression][speed][si]")
{
    using namespace posu::units::si::length_literals;
    using namespace posu::units::si::chrono_literals;
    using namespace posu::units::si::length_references;
    using namespace posu::units::si::chrono_references;

    CATCH_SECTION("integer literals")
    {
        CATCH_CHECK(5_m / 1_s == 5 * (m / s));
        CATCH_CHECK(2_mm / 8_ks == 0 * (m / s));
    }

    CATCH_SECTION("floating point literals")
    {
        CATCH_CHECK(2.5_km / 5_s == 0.5 * (km / s));
        CATCH_CHECK(2_mm / 8.0_ks == 0.25 * (um / s));
    }
}

CATCH_TEST_CASE("length from multiplication", "[construct][expression][speed][si]")
{
    using namespace posu::units::si::length_literals;
    using namespace posu::units::si::chrono_literals;
    using namespace posu::units::si::length_references;
    using namespace posu::units::si::chrono_references;

    CATCH_SECTION("integer literals")
    {
        CATCH_CHECK(5 * (m / s) * 1_s == 5_m);
        CATCH_CHECK(1_s * 5 * (m / s) == 5_m);
        CATCH_CHECK(32 * (m / s) * 8_ks == 256_km);
        CATCH_CHECK(8_ks * 32 * (m / s) == 256_km);
    }

    CATCH_SECTION("floating point literals")
    {
        CATCH_CHECK(0.5 * (km / s) * 5_s == 2.5_km);
        CATCH_CHECK(5_s * 0.5 * (km / s) == 2.5_km);
        CATCH_CHECK(0.25 * (um / s) * 8.0_ks == 2_mm);
        CATCH_CHECK(8.0_ks * 0.25 * (um / s) == 2_mm);
    }
}
