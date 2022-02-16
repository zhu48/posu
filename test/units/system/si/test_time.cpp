#include "posu/units/system/si/time.hpp"

#define CATCH_CONFIG_PREFIX_ALL

#include <catch2/catch.hpp>

template<std::intmax_t Num, std::intmax_t Den, std::intmax_t Exp>
struct Catch::StringMaker<posu::ratio<Num, Den, Exp>> {
    static std::string convert(const posu::ratio<Num, Den, Exp>& /*unused*/)
    {
        return '(' + std::to_string(Num) + '/' + std::to_string(Den) + ")e" + std::to_string(Exp);
    }
};

template<posu::units::quantity_of_measure Quantity>
struct Catch::StringMaker<Quantity> {
    static std::string convert(const Quantity& value)
    {
        return std::to_string(value.count()) + ' ' +
               StringMaker<posu::units::period_t<Quantity>>::convert(
                   posu::units::period_t<Quantity>{}) +
               ' ' +
               StringMaker<posu::units::period_t<posu::units::unit_t<Quantity>>>::convert(
                   posu::units::period_t<posu::units::unit_t<Quantity>>{}) +
               ' ' + std::string(Quantity::unit_type::value);
    }
};

template<typename Rep, typename Period>
struct Catch::StringMaker<std::chrono::duration<Rep, Period>> {
    using duration    = std::chrono::duration<Rep, Period>;
    using posu_period = posu::make_ratio<Period>;

    static std::string convert(const std::chrono::duration<Rep, Period>& value)
    {
        return std::to_string(value.count()) + ' ' +
               StringMaker<posu_period>::convert(posu_period{}) + " time";
    }
};

CATCH_TEST_CASE("time literals", "[construct][literals][time][si]")
{
    using namespace posu::units::si::chrono_literals;

    CATCH_SECTION("integer literals")
    {
        CATCH_CHECK(1000_as == 1_fs);
        CATCH_CHECK(1000_fs == 1_ps);
        CATCH_CHECK(1000_ps == 1_ns);
        CATCH_CHECK(1000_ns == 1_us);
        CATCH_CHECK(1000_us == 1_ms);
        CATCH_CHECK(10_ms == 1_cs);
        CATCH_CHECK(10_cs == 1_ds);
        CATCH_CHECK(10_ds == 1_s);
        CATCH_CHECK(10_s == 1_das);
        CATCH_CHECK(10_das == 1_hs);
        CATCH_CHECK(10_hs == 1_ks);
        CATCH_CHECK(1000_ks == 1_Ms);
        CATCH_CHECK(1000_Ms == 1_Gs);
        CATCH_CHECK(1000_Gs == 1_Ts);
        CATCH_CHECK(1000_Ts == 1_Ps);
        CATCH_CHECK(1000_Ps == 1_Es);
        CATCH_CHECK(60_s == 1_min);
        CATCH_CHECK(60_min == 1_h);
    }

    CATCH_SECTION("floating point literals")
    {
        CATCH_CHECK(1.0_as == 0.001_fs);
        CATCH_CHECK(1.0_fs == 0.001_ps);
        CATCH_CHECK(1.0_ps == 0.001_ns);
        CATCH_CHECK(1.0_ns == 0.001_us);
        CATCH_CHECK(1.0_us == 0.001_ms);
        CATCH_CHECK(1.0_ms == 0.1_cs);
        CATCH_CHECK(1.0_cs == 0.1_ds);
        CATCH_CHECK(1.0_ds == 0.1_s);
        CATCH_CHECK(1.0_s == 0.1_das);
        CATCH_CHECK(1.0_das == 0.1_hs);
        CATCH_CHECK(1.0_hs == 0.1_ks);
        CATCH_CHECK(1.0_ks == 0.001_Ms);
        CATCH_CHECK(1.0_Ms == 0.001_Gs);
        CATCH_CHECK(1.0_Gs == 0.001_Ts);
        CATCH_CHECK(1.0_Ts == 0.001_Ps);
        CATCH_CHECK(1.0_Ps == 0.001_Es);
        CATCH_CHECK(30.0_s == 0.5_min);
        CATCH_CHECK(30.0_min == 0.5_h);
    }

    CATCH_SECTION("std::chrono::duration compatibility")
    {
        using namespace std::chrono_literals;

        CATCH_CHECK(1ns == 1'000'000_fs);
        CATCH_CHECK(1ns == 1'000_ps);
        CATCH_CHECK(1ns == 1_ns);
        CATCH_CHECK(1us == 1_us);
        CATCH_CHECK(1ms == 1_ms);
        CATCH_CHECK(10ms == 1_cs);
        CATCH_CHECK(100ms == 1_ds);
        CATCH_CHECK(1s == 1_s);
        CATCH_CHECK(10s == 1_das);
        CATCH_CHECK(100s == 1_hs);
        CATCH_CHECK(1'000s == 1_ks);
        CATCH_CHECK(1'000'000s == 1_Ms);
        CATCH_CHECK(1'000'000'000s == 1_Gs);
        CATCH_CHECK(1'000'000'000'000s == 1_Ts);
        CATCH_CHECK(1'000'000'000'000'000s == 1_Ps);
        CATCH_CHECK(1'000'000'000'000'000'000s == 1_Es);
        CATCH_CHECK(60s == 1_min);
        CATCH_CHECK(60min == 1_h);
    }
}
