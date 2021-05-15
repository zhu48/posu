#include "posu/units/system/si/time.hpp"

#include <catch2/catch.hpp>

TEST_CASE("time literals", "[construct][literals][time][si]")
{
    using namespace posu::units::si::chrono_literals;

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
