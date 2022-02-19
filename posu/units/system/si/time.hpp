#ifndef POSU_UNITS_SI_TIME_HPP
#define POSU_UNITS_SI_TIME_HPP

#include "posu/units/base_unit.hpp"

#include "posu/units/system/time.hpp"

namespace posu::units {

    namespace si {

        struct time : public posu::units::time {
            using type      = time;
            using kind_type = posu::units::time;
            using period    = ratio<1>;
        };

    } // namespace si

    template<>
    inline constexpr bool enable_as_unit<si::time> = true;

} // namespace posu::units

namespace posu::units::si {

    template<typename Rep, typename Period>
    using basic_second = quantity<Rep, Period, time>;

    using attoseconds  = basic_second<std::chrono::nanoseconds::rep, atto>;
    using femtoseconds = basic_second<std::chrono::nanoseconds::rep, femto>;
    using picoseconds  = basic_second<std::chrono::nanoseconds::rep, pico>;
    using nanoseconds  = basic_second<std::chrono::nanoseconds::rep, nano>;
    using microseconds = basic_second<std::chrono::microseconds::rep, micro>;
    using milliseconds = basic_second<std::chrono::milliseconds::rep, milli>;
    using centiseconds = basic_second<std::chrono::milliseconds::rep, centi>;
    using deciseconds  = basic_second<std::chrono::milliseconds::rep, deci>;
    using seconds      = basic_second<std::chrono::seconds::rep, ratio<1>>;
    using decaseconds  = basic_second<std::chrono::seconds::rep, deca>;
    using hectoseconds = basic_second<std::chrono::seconds::rep, hecto>;
    using kiloseconds  = basic_second<std::chrono::seconds::rep, kilo>;
    using megaseconds  = basic_second<std::chrono::seconds::rep, mega>;
    using gigaseconds  = basic_second<std::chrono::seconds::rep, giga>;
    using teraseconds  = basic_second<std::chrono::seconds::rep, tera>;
    using petaseconds  = basic_second<std::chrono::seconds::rep, peta>;
    using exaseconds   = basic_second<std::chrono::seconds::rep, exa>;
    using minutes =
        basic_second<std::chrono::minutes::rep, make_ratio<std::chrono::minutes::period>>;
    using hours  = basic_second<std::chrono::hours::rep, make_ratio<std::chrono::hours::period>>;
    using days   = basic_second<std::chrono::days::rep, make_ratio<std::chrono::days::period>>;
    using weeks  = basic_second<std::chrono::weeks::rep, make_ratio<std::chrono::weeks::period>>;
    using months = basic_second<std::chrono::months::rep, make_ratio<std::chrono::months::period>>;
    using years  = basic_second<std::chrono::years::rep, make_ratio<std::chrono::years::period>>;

    inline namespace literals {

        inline namespace chrono_literals {

            [[nodiscard]] constexpr auto operator""_as(unsigned long long value) -> attoseconds;
            [[nodiscard]] constexpr auto operator""_as(long double value)
                -> basic_second<double, atto>;
            [[nodiscard]] constexpr auto operator""_fs(unsigned long long value) -> femtoseconds;
            [[nodiscard]] constexpr auto operator""_fs(long double value)
                -> basic_second<double, femto>;
            [[nodiscard]] constexpr auto operator""_ps(unsigned long long value) -> picoseconds;
            [[nodiscard]] constexpr auto operator""_ps(long double value)
                -> basic_second<double, pico>;
            [[nodiscard]] constexpr auto operator""_ns(unsigned long long value) -> nanoseconds;
            [[nodiscard]] constexpr auto operator""_ns(long double value)
                -> basic_second<double, nano>;
            [[nodiscard]] constexpr auto operator""_us(unsigned long long value) -> microseconds;
            [[nodiscard]] constexpr auto operator""_us(long double value)
                -> basic_second<double, micro>;
            [[nodiscard]] constexpr auto operator""_ms(unsigned long long value) -> milliseconds;
            [[nodiscard]] constexpr auto operator""_ms(long double value)
                -> basic_second<double, milli>;
            [[nodiscard]] constexpr auto operator""_cs(unsigned long long value) -> centiseconds;
            [[nodiscard]] constexpr auto operator""_cs(long double value)
                -> basic_second<double, centi>;
            [[nodiscard]] constexpr auto operator""_ds(unsigned long long value) -> deciseconds;
            [[nodiscard]] constexpr auto operator""_ds(long double value)
                -> basic_second<double, deci>;
            [[nodiscard]] constexpr auto operator""_s(unsigned long long value) -> seconds;
            [[nodiscard]] constexpr auto operator""_s(long double value)
                -> basic_second<double, ratio<1>>;
            [[nodiscard]] constexpr auto operator""_das(unsigned long long value) -> decaseconds;
            [[nodiscard]] constexpr auto operator""_das(long double value)
                -> basic_second<double, deca>;
            [[nodiscard]] constexpr auto operator""_hs(unsigned long long value) -> hectoseconds;
            [[nodiscard]] constexpr auto operator""_hs(long double value)
                -> basic_second<double, hecto>;
            [[nodiscard]] constexpr auto operator""_ks(unsigned long long value) -> kiloseconds;
            [[nodiscard]] constexpr auto operator""_ks(long double value)
                -> basic_second<double, kilo>;
            [[nodiscard]] constexpr auto operator""_Ms(unsigned long long value) -> megaseconds;
            [[nodiscard]] constexpr auto operator""_Ms(long double value)
                -> basic_second<double, mega>;
            [[nodiscard]] constexpr auto operator""_Gs(unsigned long long value) -> gigaseconds;
            [[nodiscard]] constexpr auto operator""_Gs(long double value)
                -> basic_second<double, giga>;
            [[nodiscard]] constexpr auto operator""_Ts(unsigned long long value) -> teraseconds;
            [[nodiscard]] constexpr auto operator""_Ts(long double value)
                -> basic_second<double, tera>;
            [[nodiscard]] constexpr auto operator""_Ps(unsigned long long value) -> petaseconds;
            [[nodiscard]] constexpr auto operator""_Ps(long double value)
                -> basic_second<double, peta>;
            [[nodiscard]] constexpr auto operator""_Es(unsigned long long value) -> exaseconds;
            [[nodiscard]] constexpr auto operator""_Es(long double value)
                -> basic_second<double, exa>;
            [[nodiscard]] constexpr auto operator""_min(unsigned long long value) -> minutes;
            [[nodiscard]] constexpr auto operator""_min(long double value)
                -> basic_second<double, minutes::period>;
            [[nodiscard]] constexpr auto operator""_h(unsigned long long value) -> hours;
            [[nodiscard]] constexpr auto operator""_h(long double value)
                -> basic_second<double, hours::period>;

        } // namespace chrono_literals

    } // namespace literals

    using namespace literals::chrono_literals;

} // namespace posu::units::si

#include "posu/units/system/si/ipp/time.ipp"

namespace posu::units::si {

    inline namespace references {

        inline namespace chrono_references {

            inline constexpr auto as  = 1_as;
            inline constexpr auto fs  = 1_fs;
            inline constexpr auto ps  = 1_ps;
            inline constexpr auto ns  = 1_ns;
            inline constexpr auto us  = 1_us;
            inline constexpr auto ms  = 1_ms;
            inline constexpr auto cs  = 1_cs;
            inline constexpr auto ds  = 1_ds;
            inline constexpr auto s   = 1_s;
            inline constexpr auto das = 1_das;
            inline constexpr auto hs  = 1_hs;
            inline constexpr auto ks  = 1_ks;
            inline constexpr auto Ms  = 1_Ms;
            inline constexpr auto Gs  = 1_Gs;
            inline constexpr auto Ts  = 1_Ts;
            inline constexpr auto Ps  = 1_Ps;
            inline constexpr auto Es  = 1_Es;

            inline constexpr auto min = 1_min;
            inline constexpr auto h   = 1_h;

        } // namespace chrono_references

    } // namespace references

} // namespace posu::units::si

#endif // #ifndef POSU_UNITS_SI_TIME_HPP
