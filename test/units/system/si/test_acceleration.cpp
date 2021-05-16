#include "posu/units/system/acceleration.hpp"

#define CATCH_CONFIG_PREFIX_ALL

#include "posu/units/system/si/length.hpp"
#include "posu/units/system/si/time.hpp"

#include <catch2/catch.hpp>

namespace {

    namespace units = posu::units;
    namespace si    = units::si;

} // namespace

CATCH_TEST_CASE("acceleration literals", "[construct][literals][acceleration][si]")
{
    using namespace posu::units::si::length_references;
    using namespace posu::units::si::chrono_references;

    CATCH_SECTION("integer literals")
    {
        CATCH_CHECK(1000 * (am / (s * s)) == 1 * (fm / (s * s)));
        CATCH_CHECK(1000 * (fm / (s * s)) == 1 * (pm / (s * s)));
        CATCH_CHECK(1000 * (pm / (s * s)) == 1 * (nm / (s * s)));
        CATCH_CHECK(1000 * (nm / (s * s)) == 1 * (um / (s * s)));
        CATCH_CHECK(1000 * (um / (s * s)) == 1 * (mm / (s * s)));
        CATCH_CHECK(10 * (mm / (s * s)) == 1 * (cm / (s * s)));
        CATCH_CHECK(10 * (cm / (s * s)) == 1 * (dm / (s * s)));
        CATCH_CHECK(10 * (dm / (s * s)) == 1 * (m / (s * s)));
        CATCH_CHECK(10 * (m / (s * s)) == 1 * (dam / (s * s)));
        CATCH_CHECK(10 * (dam / (s * s)) == 1 * (hm / (s * s)));
        CATCH_CHECK(10 * (hm / (s * s)) == 1 * (km / (s * s)));
        CATCH_CHECK(1000 * (km / (s * s)) == 1 * (Mm / (s * s)));
        CATCH_CHECK(1000 * (Mm / (s * s)) == 1 * (Gm / (s * s)));
        CATCH_CHECK(1000 * (Gm / (s * s)) == 1 * (Tm / (s * s)));
        CATCH_CHECK(1000 * (Tm / (s * s)) == 1 * (Pm / (s * s)));
        CATCH_CHECK(1000 * (Pm / (s * s)) == 1 * (Em / (s * s)));
    }

    CATCH_SECTION("floating point literals")
    {
        CATCH_CHECK(1.0 * (am / (s * s)) == 0.001 * (fm / (s * s)));
        CATCH_CHECK(1.0 * (fm / (s * s)) == 0.001 * (pm / (s * s)));
        CATCH_CHECK(1.0 * (pm / (s * s)) == 0.001 * (nm / (s * s)));
        CATCH_CHECK(1.0 * (nm / (s * s)) == 0.001 * (um / (s * s)));
        CATCH_CHECK(1.0 * (um / (s * s)) == 0.001 * (mm / (s * s)));
        CATCH_CHECK(1.0 * (mm / (s * s)) == 0.1 * (cm / (s * s)));
        CATCH_CHECK(1.0 * (cm / (s * s)) == 0.1 * (dm / (s * s)));
        CATCH_CHECK(1.0 * (dm / (s * s)) == 0.1 * (m / (s * s)));
        CATCH_CHECK(1.0 * (m / (s * s)) == 0.1 * (dam / (s * s)));
        CATCH_CHECK(1.0 * (dam / (s * s)) == 0.1 * (hm / (s * s)));
        CATCH_CHECK(1.0 * (hm / (s * s)) == 0.1 * (km / (s * s)));
        CATCH_CHECK(1.0 * (km / (s * s)) == 0.001 * (Mm / (s * s)));
        CATCH_CHECK(1.0 * (Mm / (s * s)) == 0.001 * (Gm / (s * s)));
        CATCH_CHECK(1.0 * (Gm / (s * s)) == 0.001 * (Tm / (s * s)));
        CATCH_CHECK(1.0 * (Tm / (s * s)) == 0.001 * (Pm / (s * s)));
        CATCH_CHECK(1.0 * (Pm / (s * s)) == 0.001 * (Em / (s * s)));
    }
}
