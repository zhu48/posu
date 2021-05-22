#ifndef POSU_UNITS_SI_TIME_HPP
#define POSU_UNITS_SI_TIME_HPP

#include "posu/units/base_unit.hpp"

#include "posu/units/system/time.hpp"

namespace posu::units {

    namespace si {

        struct time : public posu::units::time {
            using type      = time;
            using kind_type = posu::units::time;
        };

    } // namespace si

    template<>
    inline constexpr bool enable_as_unit<si::time> = true;

    template<typename Rep, typename Period>
    class quantity<Rep, Period, si::time> : public std::chrono::duration<Rep, Period> {
    private:
        using parent_type = std::chrono::duration<Rep, Period>;

        [[nodiscard]] constexpr auto this_parent() const noexcept
        {
            return static_cast<const parent_type*>(this);
        }

        [[nodiscard]] constexpr auto this_parent() noexcept
        {
            return static_cast<parent_type*>(this);
        }

    public:
        using rep        = typename parent_type::rep;
        using period     = typename parent_type::period;
        using unit_type  = si::time;
        using kind_type  = kind_t<unit_type>;
        using dimensions = dimension_t<kind_type>;

        using parent_type::parent_type;

        using parent_type::count;

        [[nodiscard]] constexpr auto operator+() const noexcept { return quantity(count()); }

        [[nodiscard]] constexpr auto operator-() const noexcept { return quantity(-count()); }

        constexpr auto& operator++() noexcept
        {
            ++(*this_parent());

            return *this;
        }

        constexpr auto operator++(int) noexcept
        {
            const auto old_val = count();

            ++(*this_parent());

            return *this;
        }

        constexpr auto& operator--() noexcept
        {
            --(*this_parent());

            return *this;
        }

        constexpr auto operator--(int) noexcept
        {
            const auto old_val = count();

            --(*this_parent());

            return *this;
        }

        constexpr auto& operator+=(const quantity& rhs) noexcept
        {
            *this_parent() += *rhs.this_parent();

            return *this;
        }

        constexpr auto& operator-=(const quantity& rhs) noexcept
        {
            *this_parent() -= *rhs.this_parent();

            return *this;
        }

        constexpr auto& operator*=(const rep& rhs) noexcept
        {
            *this_parent() *= rhs;

            return *this;
        }

        constexpr auto& operator/=(const rep& rhs) noexcept
        {
            *this_parent() /= rhs;

            return *this;
        }

        constexpr auto& operator%=(const rep& rhs) noexcept
        {
            *this_parent() %= rhs;

            return *this;
        }

        constexpr auto& operator%=(const quantity& rhs) noexcept
        {
            *this_parent() %= rhs;

            return *this;
        }

        [[nodiscard]] friend constexpr auto
        operator+(const quantity& lhs, const quantity_of<unit_type> auto& rhs) noexcept
        {
            return std::common_type_t<quantity, std::remove_cvref_t<decltype(rhs)>>(
                (lhs.m_duration + detail::to_duration(rhs)).count());
        }

        [[nodiscard]] friend constexpr auto
        operator-(const quantity& lhs, const quantity_of<unit_type> auto& rhs) noexcept
        {
            return std::common_type_t<quantity, std::remove_cvref_t<decltype(rhs)>>(
                (lhs.m_duration - detail::to_duration(rhs)).count());
        }

        [[nodiscard]] friend constexpr auto
        operator*(const arithmetic auto& lhs, const quantity& rhs) noexcept
        {
            using lhs_type = std::remove_cvref_t<decltype(lhs)>;

            return quantity<std::common_type_t<lhs_type, rep>, period, unit_type>(
                (lhs * detail::to_duration(rhs)).count());
        }

        [[nodiscard]] friend constexpr auto
        operator*(const quantity& lhs, const arithmetic auto& rhs) noexcept
        {
            return rhs * lhs;
        }

        [[nodiscard]] friend constexpr auto
        operator/(const quantity& lhs, const quantity_of<unit_type> auto& rhs) noexcept
        {
            using rep = decltype(lhs.m_duration / detail::to_duration(rhs));

            return quantity<rep, std::ratio<1>, scaler>(lhs.m_duration / detail::to_duration(rhs));
        }

        [[nodiscard]] friend constexpr auto
        operator/(const quantity& lhs, const arithmetic auto& rhs) noexcept
        {
            using rhs_type = std::remove_cvref_t<decltype(rhs)>;

            return quantity<std::common_type_t<rep, rhs_type>, period, unit_type>(
                lhs.count() / rhs);
        }

        [[nodiscard]] friend constexpr auto
        operator%(const quantity& lhs, const quantity_of<unit_type> auto& rhs) noexcept
        {
            return std::common_type_t<quantity, std::remove_cvref_t<decltype(rhs)>>(
                (lhs.m_duration % detail::to_duration(rhs)).count());
        }

        [[nodiscard]] friend constexpr auto
        operator%(const quantity& lhs, const arithmetic auto& rhs) noexcept
        {
            using rhs_type = std::remove_cvref_t<decltype(rhs)>;

            return quantity<std::common_type_t<rep, rhs_type>, period, unit_type>(
                lhs.count() % rhs);
        }
    };

} // namespace posu::units

namespace posu::units::si {

    template<typename Rep, typename Period>
    using basic_second = quantity<Rep, Period, time>;

    using attoseconds  = basic_second<int, std::atto>;
    using femtoseconds = basic_second<int, std::femto>;
    using picoseconds  = basic_second<int, std::pico>;
    using nanoseconds  = basic_second<std::chrono::nanoseconds::rep, std::nano>;
    using microseconds = basic_second<std::chrono::microseconds::rep, std::micro>;
    using milliseconds = basic_second<std::chrono::milliseconds::rep, std::milli>;
    using centiseconds = basic_second<int, std::centi>;
    using deciseconds  = basic_second<int, std::deci>;
    using seconds      = basic_second<std::chrono::seconds::rep, std::ratio<1>>;
    using decaseconds  = basic_second<int, std::deca>;
    using hectoseconds = basic_second<int, std::hecto>;
    using kiloseconds  = basic_second<int, std::kilo>;
    using megaseconds  = basic_second<int, std::mega>;
    using gigaseconds  = basic_second<int, std::giga>;
    using teraseconds  = basic_second<int, std::tera>;
    using petaseconds  = basic_second<int, std::peta>;
    using exaseconds   = basic_second<int, std::exa>;
    using minutes      = basic_second<std::chrono::minutes::rep, std::chrono::minutes::period>;
    using hours        = basic_second<std::chrono::hours::rep, std::chrono::hours::period>;
    using days         = basic_second<std::chrono::days::rep, std::chrono::days::period>;
    using weeks        = basic_second<std::chrono::weeks::rep, std::chrono::weeks::period>;
    using months       = basic_second<std::chrono::months::rep, std::chrono::months::period>;
    using years        = basic_second<std::chrono::years::rep, std::chrono::years::period>;

    inline namespace literals {

        inline namespace chrono_literals {

            [[nodiscard]] constexpr auto operator""_as(unsigned long long value) -> attoseconds;
            [[nodiscard]] constexpr auto operator""_as(long double value)
                -> basic_second<double, std::atto>;
            [[nodiscard]] constexpr auto operator""_fs(unsigned long long value) -> femtoseconds;
            [[nodiscard]] constexpr auto operator""_fs(long double value)
                -> basic_second<double, std::femto>;
            [[nodiscard]] constexpr auto operator""_ps(unsigned long long value) -> picoseconds;
            [[nodiscard]] constexpr auto operator""_ps(long double value)
                -> basic_second<double, std::pico>;
            [[nodiscard]] constexpr auto operator""_ns(unsigned long long value) -> nanoseconds;
            [[nodiscard]] constexpr auto operator""_ns(long double value)
                -> basic_second<double, std::nano>;
            [[nodiscard]] constexpr auto operator""_us(unsigned long long value) -> microseconds;
            [[nodiscard]] constexpr auto operator""_us(long double value)
                -> basic_second<double, std::micro>;
            [[nodiscard]] constexpr auto operator""_ms(unsigned long long value) -> milliseconds;
            [[nodiscard]] constexpr auto operator""_ms(long double value)
                -> basic_second<double, std::milli>;
            [[nodiscard]] constexpr auto operator""_cs(unsigned long long value) -> centiseconds;
            [[nodiscard]] constexpr auto operator""_cs(long double value)
                -> basic_second<double, std::centi>;
            [[nodiscard]] constexpr auto operator""_ds(unsigned long long value) -> deciseconds;
            [[nodiscard]] constexpr auto operator""_ds(long double value)
                -> basic_second<double, std::deci>;
            [[nodiscard]] constexpr auto operator""_s(unsigned long long value) -> seconds;
            [[nodiscard]] constexpr auto operator""_s(long double value)
                -> basic_second<double, std::ratio<1>>;
            [[nodiscard]] constexpr auto operator""_das(unsigned long long value) -> decaseconds;
            [[nodiscard]] constexpr auto operator""_das(long double value)
                -> basic_second<double, std::deca>;
            [[nodiscard]] constexpr auto operator""_hs(unsigned long long value) -> hectoseconds;
            [[nodiscard]] constexpr auto operator""_hs(long double value)
                -> basic_second<double, std::hecto>;
            [[nodiscard]] constexpr auto operator""_ks(unsigned long long value) -> kiloseconds;
            [[nodiscard]] constexpr auto operator""_ks(long double value)
                -> basic_second<double, std::kilo>;
            [[nodiscard]] constexpr auto operator""_Ms(unsigned long long value) -> megaseconds;
            [[nodiscard]] constexpr auto operator""_Ms(long double value)
                -> basic_second<double, std::mega>;
            [[nodiscard]] constexpr auto operator""_Gs(unsigned long long value) -> gigaseconds;
            [[nodiscard]] constexpr auto operator""_Gs(long double value)
                -> basic_second<double, std::giga>;
            [[nodiscard]] constexpr auto operator""_Ts(unsigned long long value) -> teraseconds;
            [[nodiscard]] constexpr auto operator""_Ts(long double value)
                -> basic_second<double, std::tera>;
            [[nodiscard]] constexpr auto operator""_Ps(unsigned long long value) -> petaseconds;
            [[nodiscard]] constexpr auto operator""_Ps(long double value)
                -> basic_second<double, std::peta>;
            [[nodiscard]] constexpr auto operator""_Es(unsigned long long value) -> exaseconds;
            [[nodiscard]] constexpr auto operator""_Es(long double value)
                -> basic_second<double, std::exa>;
            [[nodiscard]] constexpr auto operator""_min(unsigned long long value) -> minutes;
            [[nodiscard]] constexpr auto operator""_min(long double value)
                -> basic_second<double, std::chrono::minutes::period>;
            [[nodiscard]] constexpr auto operator""_h(unsigned long long value) -> hours;
            [[nodiscard]] constexpr auto operator""_h(long double value)
                -> basic_second<double, std::chrono::hours::period>;

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
