#ifndef POSU_UNITS_SI_TIME_HPP
#define POSU_UNITS_SI_TIME_HPP

#include "posu/units/base_unit.hpp"

namespace posu::units {

    struct time_tag {
        constexpr time_tag() noexcept = default;
    };

    template<typename Rep, typename Period> // clang-format off
        requires( std::integral<Rep> || std::floating_point<Rep> )
    class base_unit<Rep, Period, time_tag> : // clang-format on
          public std::chrono::duration<Rep, Period> {
    private:
        using parent_type = std::chrono::duration<Rep, Period>;

    public:
        using parent_type::parent_type;
    };

    template<typename Rep, typename Period>
    using time = base_unit<Rep, Period, time_tag>;

    using attoseconds  = time<int, std::atto>;
    using femtoseconds = time<int, std::femto>;
    using picoseconds  = time<int, std::pico>;
    using nanoseconds  = time<std::chrono::nanoseconds::rep, std::nano>;
    using microseconds = time<std::chrono::microseconds::rep, std::micro>;
    using milliseconds = time<std::chrono::milliseconds::rep, std::milli>;
    using centiseconds = time<int, std::centi>;
    using deciseconds  = time<int, std::deci>;
    using seconds      = time<std::chrono::seconds::rep, std::ratio<1>>;
    using decaseconds  = time<int, std::deca>;
    using hectoseconds = time<int, std::hecto>;
    using kiloseconds  = time<int, std::kilo>;
    using megaseconds  = time<int, std::mega>;
    using gigaseconds  = time<int, std::giga>;
    using teraseconds  = time<int, std::tera>;
    using petaseconds  = time<int, std::peta>;
    using exaseconds   = time<int, std::exa>;
    using minutes      = time<std::chrono::minutes::rep, std::chrono::minutes::period>;
    using hours        = time<std::chrono::hours::rep, std::chrono::hours::period>;
    using days         = time<std::chrono::days::rep, std::chrono::days::period>;
    using weeks        = time<std::chrono::weeks::rep, std::chrono::weeks::period>;
    using months       = time<std::chrono::months::rep, std::chrono::months::period>;
    using years        = time<std::chrono::years::rep, std::chrono::years::period>;

    inline namespace literals {

        inline namespace chrono_literals {

            [[nodiscard]] constexpr auto operator""_as(unsigned long long value) -> attoseconds;
            [[nodiscard]] constexpr auto operator""_as(long double value)
                -> time<double, std::atto>;
            [[nodiscard]] constexpr auto operator""_fs(unsigned long long value) -> femtoseconds;
            [[nodiscard]] constexpr auto operator""_fs(long double value)
                -> time<double, std::femto>;
            [[nodiscard]] constexpr auto operator""_ps(unsigned long long value) -> picoseconds;
            [[nodiscard]] constexpr auto operator""_ps(long double value)
                -> time<double, std::pico>;
            [[nodiscard]] constexpr auto operator""_ns(unsigned long long value) -> nanoseconds;
            [[nodiscard]] constexpr auto operator""_ns(long double value)
                -> time<double, std::nano>;
            [[nodiscard]] constexpr auto operator""_us(unsigned long long value) -> microseconds;
            [[nodiscard]] constexpr auto operator""_us(long double value)
                -> time<double, std::micro>;
            [[nodiscard]] constexpr auto operator""_ms(unsigned long long value) -> milliseconds;
            [[nodiscard]] constexpr auto operator""_ms(long double value)
                -> time<double, std::milli>;
            [[nodiscard]] constexpr auto operator""_cs(unsigned long long value) -> centiseconds;
            [[nodiscard]] constexpr auto operator""_cs(long double value)
                -> time<double, std::centi>;
            [[nodiscard]] constexpr auto operator""_ds(unsigned long long value) -> deciseconds;
            [[nodiscard]] constexpr auto operator""_ds(long double value)
                -> time<double, std::deci>;
            [[nodiscard]] constexpr auto operator""_s(unsigned long long value) -> seconds;
            [[nodiscard]] constexpr auto operator""_s(long double value)
                -> time<double, std::ratio<1>>;
            [[nodiscard]] constexpr auto operator""_das(unsigned long long value) -> decaseconds;
            [[nodiscard]] constexpr auto operator""_das(long double value)
                -> time<double, std::deca>;
            [[nodiscard]] constexpr auto operator""_hs(unsigned long long value) -> hectoseconds;
            [[nodiscard]] constexpr auto operator""_hs(long double value)
                -> time<double, std::hecto>;
            [[nodiscard]] constexpr auto operator""_ks(unsigned long long value) -> kiloseconds;
            [[nodiscard]] constexpr auto operator""_ks(long double value)
                -> time<double, std::kilo>;
            [[nodiscard]] constexpr auto operator""_Ms(unsigned long long value) -> megaseconds;
            [[nodiscard]] constexpr auto operator""_Ms(long double value)
                -> time<double, std::mega>;
            [[nodiscard]] constexpr auto operator""_Gs(unsigned long long value) -> gigaseconds;
            [[nodiscard]] constexpr auto operator""_Gs(long double value)
                -> time<double, std::giga>;
            [[nodiscard]] constexpr auto operator""_Ts(unsigned long long value) -> teraseconds;
            [[nodiscard]] constexpr auto operator""_Ts(long double value)
                -> time<double, std::tera>;
            [[nodiscard]] constexpr auto operator""_Ps(unsigned long long value) -> petaseconds;
            [[nodiscard]] constexpr auto operator""_Ps(long double value)
                -> time<double, std::peta>;
            [[nodiscard]] constexpr auto operator""_Es(unsigned long long value) -> exaseconds;
            [[nodiscard]] constexpr auto operator""_Es(long double value) -> time<double, std::exa>;
            [[nodiscard]] constexpr auto operator""_min(unsigned long long value) -> minutes;
            [[nodiscard]] constexpr auto operator""_min(long double value)
                -> time<double, std::chrono::minutes::period>;
            [[nodiscard]] constexpr auto operator""_h(unsigned long long value) -> hours;
            [[nodiscard]] constexpr auto operator""_h(long double value)
                -> time<double, std::chrono::hours::period>;

        } // namespace chrono_literals

    } // namespace literals

    using namespace literals::chrono_literals;

} // namespace posu::units

#include "posu/units/si/ipp/time.ipp"

#endif // #ifndef POSU_UNITS_SI_TIME_HPP
