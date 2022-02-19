#include "posu/utility.hpp"

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_am_per_sec(unsigned long long value)
        -> attometers_per_second
{
    return attometers_per_second(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_am_per_sec(long double value)
        -> speed<double, atto>
{
    return speed<double, atto>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_fm_per_sec(unsigned long long value)
        -> femtometers_per_second
{
    return femtometers_per_second(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_fm_per_sec(long double value)
        -> speed<double, femto>
{
    return speed<double, femto>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_pm_per_sec(unsigned long long value)
        -> picometers_per_second
{
    return picometers_per_second(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_pm_per_sec(long double value)
        -> speed<double, pico>
{
    return speed<double, pico>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_nm_per_sec(unsigned long long value)
        -> nanometers_per_second
{
    return nanometers_per_second(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_nm_per_sec(long double value)
        -> speed<double, nano>
{
    return speed<double, nano>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_um_per_sec(unsigned long long value)
        -> micrometers_per_second
{
    return micrometers_per_second(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_um_per_sec(long double value)
        -> speed<double, micro>
{
    return speed<double, micro>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_mm_per_sec(unsigned long long value)
        -> millimeters_per_second
{
    return millimeters_per_second(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_mm_per_sec(long double value)
        -> speed<double, milli>
{
    return speed<double, milli>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_cm_per_sec(unsigned long long value)
        -> centimeters_per_second
{
    return centimeters_per_second(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_cm_per_sec(long double value)
        -> speed<double, centi>
{
    return speed<double, centi>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_dm_per_sec(unsigned long long value)
        -> decimeters_per_second
{
    return decimeters_per_second(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_dm_per_sec(long double value)
        -> speed<double, deci>
{
    return speed<double, deci>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_m_per_sec(unsigned long long value)
        -> meters_per_second
{
    return meters_per_second(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_m_per_sec(long double value)
        -> speed<double, ratio<1>>
{
    return speed<double, ratio<1>>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_dam_per_sec(unsigned long long value)
        -> decameters_per_second
{
    return decameters_per_second(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_dam_per_sec(long double value)
        -> speed<double, deca>
{
    return speed<double, deca>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_hm_per_sec(unsigned long long value)
        -> hectometers_per_second
{
    return hectometers_per_second(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_hm_per_sec(long double value)
        -> speed<double, hecto>
{
    return speed<double, hecto>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_km_per_sec(unsigned long long value)
        -> kilometers_per_second
{
    return kilometers_per_second(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_km_per_sec(long double value)
        -> speed<double, kilo>
{
    return speed<double, kilo>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_Mm_per_sec(unsigned long long value)
        -> megameters_per_second
{
    return megameters_per_second(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_Mm_per_sec(long double value)
        -> speed<double, mega>
{
    return speed<double, mega>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_Gm_per_sec(unsigned long long value)
        -> gigameters_per_second
{
    return gigameters_per_second(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_Gm_per_sec(long double value)
        -> speed<double, giga>
{
    return speed<double, giga>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_Tm_per_sec(unsigned long long value)
        -> terameters_per_second
{
    return terameters_per_second(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_Tm_per_sec(long double value)
        -> speed<double, tera>
{
    return speed<double, tera>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_Pm_per_sec(unsigned long long value)
        -> petameters_per_second
{
    return petameters_per_second(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_Pm_per_sec(long double value)
        -> speed<double, peta>
{
    return speed<double, peta>(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_Em_per_sec(unsigned long long value)
        -> exameters_per_second
{
    return exameters_per_second(value);
}

[[nodiscard]] constexpr auto
    posu::units::si::literals::speed_literals::operator""_Em_per_sec(long double value)
        -> speed<double, exa>
{
    return speed<double, exa>(value);
}
