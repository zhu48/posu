#include "posu/utility.hpp"

namespace posu::units {

    template<typename LengthRep, typename LengthPeriod, typename TimeRep, typename TimePeriod>
    [[nodiscard]] constexpr auto
    operator/(const length<LengthRep, LengthPeriod>& lhs, const time<TimeRep, TimePeriod>& rhs)
    {
        return speed<
            std::common_type_t<LengthRep, TimeRep>,
            std::ratio_divide<LengthPeriod, TimePeriod>>(lhs.count() / rhs.count());
    }

    inline namespace literals {

        inline namespace speed_literals {

            [[nodiscard]] constexpr auto operator""_am_per_sec(unsigned long long value)
                -> attometers_per_second
            {
                return attometers_per_second(value);
            }

            [[nodiscard]] constexpr auto operator""_am_per_sec(long double value)
                -> speed<double, std::atto>
            {
                return speed<double, std::atto>(value);
            }

            [[nodiscard]] constexpr auto operator""_fm_per_sec(unsigned long long value)
                -> femtometers_per_second
            {
                return femtometers_per_second(value);
            }

            [[nodiscard]] constexpr auto operator""_fm_per_sec(long double value)
                -> speed<double, std::femto>
            {
                return speed<double, std::femto>(value);
            }

            [[nodiscard]] constexpr auto operator""_pm_per_sec(unsigned long long value)
                -> picometers_per_second
            {
                return picometers_per_second(value);
            }

            [[nodiscard]] constexpr auto operator""_pm_per_sec(long double value)
                -> speed<double, std::pico>
            {
                return speed<double, std::pico>(value);
            }

            [[nodiscard]] constexpr auto operator""_nm_per_sec(unsigned long long value)
                -> nanometers_per_second
            {
                return nanometers_per_second(value);
            }

            [[nodiscard]] constexpr auto operator""_nm_per_sec(long double value)
                -> speed<double, std::nano>
            {
                return speed<double, std::nano>(value);
            }

            [[nodiscard]] constexpr auto operator""_um_per_sec(unsigned long long value)
                -> micrometers_per_second
            {
                return micrometers_per_second(value);
            }

            [[nodiscard]] constexpr auto operator""_um_per_sec(long double value)
                -> speed<double, std::micro>
            {
                return speed<double, std::micro>(value);
            }

            [[nodiscard]] constexpr auto operator""_mm_per_sec(unsigned long long value)
                -> millimeters_per_second
            {
                return millimeters_per_second(value);
            }

            [[nodiscard]] constexpr auto operator""_mm_per_sec(long double value)
                -> speed<double, std::milli>
            {
                return speed<double, std::milli>(value);
            }

            [[nodiscard]] constexpr auto operator""_cm_per_sec(unsigned long long value)
                -> centimeters_per_second
            {
                return centimeters_per_second(value);
            }

            [[nodiscard]] constexpr auto operator""_cm_per_sec(long double value)
                -> speed<double, std::centi>
            {
                return speed<double, std::centi>(value);
            }

            [[nodiscard]] constexpr auto operator""_dm_per_sec(unsigned long long value)
                -> decimeters_per_second
            {
                return decimeters_per_second(value);
            }

            [[nodiscard]] constexpr auto operator""_dm_per_sec(long double value)
                -> speed<double, std::deci>
            {
                return speed<double, std::deci>(value);
            }

            [[nodiscard]] constexpr auto operator""_m_per_sec(unsigned long long value)
                -> meters_per_second
            {
                return meters_per_second(value);
            }

            [[nodiscard]] constexpr auto operator""_m_per_sec(long double value)
                -> speed<double, std::ratio<1>>
            {
                return speed<double, std::ratio<1>>(value);
            }

            [[nodiscard]] constexpr auto operator""_dam_per_sec(unsigned long long value)
                -> decameters_per_second
            {
                return decameters_per_second(value);
            }

            [[nodiscard]] constexpr auto operator""_dam_per_sec(long double value)
                -> speed<double, std::deca>
            {
                return speed<double, std::deca>(value);
            }

            [[nodiscard]] constexpr auto operator""_hm_per_sec(unsigned long long value)
                -> hectometers_per_second
            {
                return hectometers_per_second(value);
            }

            [[nodiscard]] constexpr auto operator""_hm_per_sec(long double value)
                -> speed<double, std::hecto>
            {
                return speed<double, std::hecto>(value);
            }

            [[nodiscard]] constexpr auto operator""_km_per_sec(unsigned long long value)
                -> kilometers_per_second
            {
                return kilometers_per_second(value);
            }

            [[nodiscard]] constexpr auto operator""_km_per_sec(long double value)
                -> speed<double, std::kilo>
            {
                return speed<double, std::kilo>(value);
            }

            [[nodiscard]] constexpr auto operator""_Mm_per_sec(unsigned long long value)
                -> megameters_per_second
            {
                return megameters_per_second(value);
            }

            [[nodiscard]] constexpr auto operator""_Mm_per_sec(long double value)
                -> speed<double, std::mega>
            {
                return speed<double, std::mega>(value);
            }

            [[nodiscard]] constexpr auto operator""_Gm_per_sec(unsigned long long value)
                -> gigameters_per_second
            {
                return gigameters_per_second(value);
            }

            [[nodiscard]] constexpr auto operator""_Gm_per_sec(long double value)
                -> speed<double, std::giga>
            {
                return speed<double, std::giga>(value);
            }

            [[nodiscard]] constexpr auto operator""_Tm_per_sec(unsigned long long value)
                -> terameters_per_second
            {
                return terameters_per_second(value);
            }

            [[nodiscard]] constexpr auto operator""_Tm_per_sec(long double value)
                -> speed<double, std::tera>
            {
                return speed<double, std::tera>(value);
            }

            [[nodiscard]] constexpr auto operator""_Pm_per_sec(unsigned long long value)
                -> petameters_per_second
            {
                return petameters_per_second(value);
            }

            [[nodiscard]] constexpr auto operator""_Pm_per_sec(long double value)
                -> speed<double, std::peta>
            {
                return speed<double, std::peta>(value);
            }

            [[nodiscard]] constexpr auto operator""_Em_per_sec(unsigned long long value)
                -> exameters_per_second
            {
                return exameters_per_second(value);
            }

            [[nodiscard]] constexpr auto operator""_Em_per_sec(long double value)
                -> speed<double, std::exa>
            {
                return speed<double, std::exa>(value);
            }

        } // namespace speed_literals

    } // namespace literals

} // namespace posu::units
