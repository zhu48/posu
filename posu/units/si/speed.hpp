#ifndef POSU_UNITS_SI_SPEED_HPP
#define POSU_UNITS_SI_SPEED_HPP

#include "posu/units/derived_unit.hpp"
#include "posu/units/si/length.hpp"
#include "posu/units/si/time.hpp"

namespace posu::units {

    using speed_tag = type_ratio<type_list<length_tag>, type_list<time_tag>>;

    template<typename Rep, typename Period>
    using speed = derived_unit<Rep, Period, speed_tag>;

    using attometers_per_second  = speed<int, std::atto>;
    using femtometers_per_second = speed<int, std::femto>;
    using picometers_per_second  = speed<int, std::pico>;
    using nanometers_per_second  = speed<int, std::nano>;
    using micrometers_per_second = speed<int, std::micro>;
    using millimeters_per_second = speed<int, std::milli>;
    using centimeters_per_second = speed<int, std::centi>;
    using decimeters_per_second  = speed<int, std::deci>;
    using meters_per_second      = speed<int, std::ratio<1>>;
    using decameters_per_second  = speed<int, std::deca>;
    using hectometers_per_second = speed<int, std::hecto>;
    using kilometers_per_second  = speed<int, std::kilo>;
    using megameters_per_second  = speed<int, std::mega>;
    using gigameters_per_second  = speed<int, std::giga>;
    using terameters_per_second  = speed<int, std::tera>;
    using petameters_per_second  = speed<int, std::peta>;
    using exameters_per_second   = speed<int, std::exa>;

    template<typename LengthRep, typename LengthPeriod, typename TimeRep, typename TimePeriod>
    [[nodiscard]] constexpr auto
    operator/(const length<LengthRep, LengthPeriod>& lhs, const time<TimeRep, TimePeriod>& rhs);

    template<typename SpeedRep, typename SpeedPeriod, typename TimeRep, typename TimePeriod>
    [[nodiscard]] constexpr auto
    operator*(const speed<SpeedRep, SpeedPeriod>& lhs, const time<TimeRep, TimePeriod>& rhs);

    template<typename SpeedRep, typename SpeedPeriod, typename TimeRep, typename TimePeriod>
    [[nodiscard]] constexpr auto
    operator*(const time<TimeRep, TimePeriod>& rhs, const speed<SpeedRep, SpeedPeriod>& lhs);

    inline namespace literals {

        inline namespace speed_literals {

            [[nodiscard]] constexpr auto operator""_am_per_sec(unsigned long long value)
                -> attometers_per_second;
            [[nodiscard]] constexpr auto operator""_am_per_sec(long double value)
                -> speed<double, std::atto>;
            [[nodiscard]] constexpr auto operator""_fm_per_sec(unsigned long long value)
                -> femtometers_per_second;
            [[nodiscard]] constexpr auto operator""_fm_per_sec(long double value)
                -> speed<double, std::femto>;
            [[nodiscard]] constexpr auto operator""_pm_per_sec(unsigned long long value)
                -> picometers_per_second;
            [[nodiscard]] constexpr auto operator""_pm_per_sec(long double value)
                -> speed<double, std::pico>;
            [[nodiscard]] constexpr auto operator""_nm_per_sec(unsigned long long value)
                -> nanometers_per_second;
            [[nodiscard]] constexpr auto operator""_nm_per_sec(long double value)
                -> speed<double, std::nano>;
            [[nodiscard]] constexpr auto operator""_um_per_sec(unsigned long long value)
                -> micrometers_per_second;
            [[nodiscard]] constexpr auto operator""_um_per_sec(long double value)
                -> speed<double, std::micro>;
            [[nodiscard]] constexpr auto operator""_mm_per_sec(unsigned long long value)
                -> millimeters_per_second;
            [[nodiscard]] constexpr auto operator""_mm_per_sec(long double value)
                -> speed<double, std::milli>;
            [[nodiscard]] constexpr auto operator""_cm_per_sec(unsigned long long value)
                -> centimeters_per_second;
            [[nodiscard]] constexpr auto operator""_cm_per_sec(long double value)
                -> speed<double, std::centi>;
            [[nodiscard]] constexpr auto operator""_dm_per_sec(unsigned long long value)
                -> decimeters_per_second;
            [[nodiscard]] constexpr auto operator""_dm_per_sec(long double value)
                -> speed<double, std::deci>;
            [[nodiscard]] constexpr auto operator""_m_per_sec(unsigned long long value)
                -> meters_per_second;
            [[nodiscard]] constexpr auto operator""_m_per_sec(long double value)
                -> speed<double, std::ratio<1>>;
            [[nodiscard]] constexpr auto operator""_dam_per_sec(unsigned long long value)
                -> decameters_per_second;
            [[nodiscard]] constexpr auto operator""_dam_per_sec(long double value)
                -> speed<double, std::deca>;
            [[nodiscard]] constexpr auto operator""_hm_per_sec(unsigned long long value)
                -> hectometers_per_second;
            [[nodiscard]] constexpr auto operator""_hm_per_sec(long double value)
                -> speed<double, std::hecto>;
            [[nodiscard]] constexpr auto operator""_km_per_sec(unsigned long long value)
                -> kilometers_per_second;
            [[nodiscard]] constexpr auto operator""_km_per_sec(long double value)
                -> speed<double, std::kilo>;
            [[nodiscard]] constexpr auto operator""_Mm_per_sec(unsigned long long value)
                -> megameters_per_second;
            [[nodiscard]] constexpr auto operator""_Mm_per_sec(long double value)
                -> speed<double, std::mega>;
            [[nodiscard]] constexpr auto operator""_Gm_per_sec(unsigned long long value)
                -> gigameters_per_second;
            [[nodiscard]] constexpr auto operator""_Gm_per_sec(long double value)
                -> speed<double, std::giga>;
            [[nodiscard]] constexpr auto operator""_Tm_per_sec(unsigned long long value)
                -> terameters_per_second;
            [[nodiscard]] constexpr auto operator""_Tm_per_sec(long double value)
                -> speed<double, std::tera>;
            [[nodiscard]] constexpr auto operator""_Pm_per_sec(unsigned long long value)
                -> petameters_per_second;
            [[nodiscard]] constexpr auto operator""_Pm_per_sec(long double value)
                -> speed<double, std::peta>;
            [[nodiscard]] constexpr auto operator""_Em_per_sec(unsigned long long value)
                -> exameters_per_second;
            [[nodiscard]] constexpr auto operator""_Em_per_sec(long double value)
                -> speed<double, std::exa>;

        } // namespace speed_literals

    } // namespace literals

    using namespace literals::speed_literals;

} // namespace posu::units

#include "posu/units/si/ipp/speed.ipp"

#endif // #ifndef POSU_UNITS_SI_SPEED_HPP
