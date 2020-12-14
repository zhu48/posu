#ifndef POSU_UNITS_SI_LENGTH_HPP
#define POSU_UNITS_SI_LENGTH_HPP

namespace posu::units {

    struct length_tag {
        constexpr length_tag() noexcept = default;
    };

    template<typename Rep, typename Period>
    using length = base_unit<Rep, Period, length_tag>;

    using attometers  = length<int, std::atto>;
    using femtometers = length<int, std::femto>;
    using picometers  = length<int, std::pico>;
    using nanometers  = length<int, std::nano>;
    using micrometers = length<int, std::micro>;
    using millimeters = length<int, std::milli>;
    using centimeters = length<int, std::centi>;
    using decimeters  = length<int, std::deci>;
    using meters      = length<int, std::ratio<1>>;
    using decameters  = length<int, std::deca>;
    using hectometers = length<int, std::hecto>;
    using kilometers  = length<int, std::kilo>;
    using megameters  = length<int, std::mega>;
    using gigameters  = length<int, std::giga>;
    using terameters  = length<int, std::tera>;
    using petameters  = length<int, std::peta>;
    using exameters   = length<int, std::exa>;

    inline namespace literals {

        inline namespace length_literals {

            [[nodiscard]] constexpr auto operator""_am(unsigned long long value) -> attometers;
            [[nodiscard]] constexpr auto operator""_am(long double value)
                -> length<double, std::atto>;
            [[nodiscard]] constexpr auto operator""_fm(unsigned long long value) -> femtometers;
            [[nodiscard]] constexpr auto operator""_fm(long double value)
                -> length<double, std::femto>;
            [[nodiscard]] constexpr auto operator""_pm(unsigned long long value) -> picometers;
            [[nodiscard]] constexpr auto operator""_pm(long double value)
                -> length<double, std::pico>;
            [[nodiscard]] constexpr auto operator""_nm(unsigned long long value) -> nanometers;
            [[nodiscard]] constexpr auto operator""_nm(long double value)
                -> length<double, std::nano>;
            [[nodiscard]] constexpr auto operator""_um(unsigned long long value) -> micrometers;
            [[nodiscard]] constexpr auto operator""_um(long double value)
                -> length<double, std::micro>;
            [[nodiscard]] constexpr auto operator""_mm(unsigned long long value) -> millimeters;
            [[nodiscard]] constexpr auto operator""_mm(long double value)
                -> length<double, std::milli>;
            [[nodiscard]] constexpr auto operator""_cm(unsigned long long value) -> centimeters;
            [[nodiscard]] constexpr auto operator""_cm(long double value)
                -> length<double, std::centi>;
            [[nodiscard]] constexpr auto operator""_dm(unsigned long long value) -> decimeters;
            [[nodiscard]] constexpr auto operator""_dm(long double value)
                -> length<double, std::deci>;
            [[nodiscard]] constexpr auto operator""_m(unsigned long long value) -> meters;
            [[nodiscard]] constexpr auto operator""_m(long double value)
                -> length<double, std::ratio<1>>;
            [[nodiscard]] constexpr auto operator""_dam(unsigned long long value) -> decameters;
            [[nodiscard]] constexpr auto operator""_dam(long double value)
                -> length<double, std::deca>;
            [[nodiscard]] constexpr auto operator""_hm(unsigned long long value) -> hectometers;
            [[nodiscard]] constexpr auto operator""_hm(long double value)
                -> length<double, std::hecto>;
            [[nodiscard]] constexpr auto operator""_km(unsigned long long value) -> kilometers;
            [[nodiscard]] constexpr auto operator""_km(long double value)
                -> length<double, std::kilo>;
            [[nodiscard]] constexpr auto operator""_Mm(unsigned long long value) -> megameters;
            [[nodiscard]] constexpr auto operator""_Mm(long double value)
                -> length<double, std::mega>;
            [[nodiscard]] constexpr auto operator""_Gm(unsigned long long value) -> gigameters;
            [[nodiscard]] constexpr auto operator""_Gm(long double value)
                -> length<double, std::giga>;
            [[nodiscard]] constexpr auto operator""_Tm(unsigned long long value) -> terameters;
            [[nodiscard]] constexpr auto operator""_Tm(long double value)
                -> length<double, std::tera>;
            [[nodiscard]] constexpr auto operator""_Pm(unsigned long long value) -> petameters;
            [[nodiscard]] constexpr auto operator""_Pm(long double value)
                -> length<double, std::peta>;
            [[nodiscard]] constexpr auto operator""_Em(unsigned long long value) -> exameters;
            [[nodiscard]] constexpr auto operator""_Em(long double value)
                -> length<double, std::exa>;

        } // namespace length_literals

    } // namespace literals

    using namespace literals::length_literals;

}

#include "posu/units/si/ipp/length.ipp"

#endif // #ifndef POSU_UNITS_SI_LENGTH_HPP
