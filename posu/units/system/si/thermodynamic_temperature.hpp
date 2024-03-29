#ifndef POSU_UNITS_SI_THERMODYNAMIC_TEMPERATURE_HPP
#define POSU_UNITS_SI_THERMODYNAMIC_TEMPERATURE_HPP

#include "posu/units/base_unit.hpp"

#include "posu/units/system/thermodynamic_temperature.hpp"

namespace posu::units::si {

    struct thermodynamic_temperature : public posu::units::thermodynamic_temperature {
        using type      = thermodynamic_temperature;
        using kind_type = posu::units::thermodynamic_temperature;
        using period    = ratio<1>;
    };

} // namespace posu::units::si

namespace posu::units {

    template<>
    inline constexpr bool enable_as_unit<si::thermodynamic_temperature> = true;

}

namespace posu::units::si {

    template<typename Rep, typename Period>
    using basic_kelvin = quantity<Rep, Period, thermodynamic_temperature>;

    using attokelvins  = basic_kelvin<int, atto>;
    using femtokelvins = basic_kelvin<int, femto>;
    using picokelvins  = basic_kelvin<int, pico>;
    using nanokelvins  = basic_kelvin<int, nano>;
    using microkelvins = basic_kelvin<int, micro>;
    using millikelvins = basic_kelvin<int, milli>;
    using centikelvins = basic_kelvin<int, centi>;
    using decikelvins  = basic_kelvin<int, deci>;
    using kelvins      = basic_kelvin<int, ratio<1>>;
    using decakelvins  = basic_kelvin<int, deca>;
    using hectokelvins = basic_kelvin<int, hecto>;
    using kilokelvins  = basic_kelvin<int, kilo>;
    using megakelvins  = basic_kelvin<int, mega>;
    using gigakelvins  = basic_kelvin<int, giga>;
    using terakelvins  = basic_kelvin<int, tera>;
    using petakelvins  = basic_kelvin<int, peta>;
    using exakelvins   = basic_kelvin<int, exa>;

    inline namespace literals {

        inline namespace thermodynamic_temperature_literals {

            [[nodiscard]] constexpr auto operator""_aK(unsigned long long value) -> attokelvins;
            [[nodiscard]] constexpr auto operator""_aK(long double value)
                -> basic_kelvin<double, atto>;
            [[nodiscard]] constexpr auto operator""_fK(unsigned long long value) -> femtokelvins;
            [[nodiscard]] constexpr auto operator""_fK(long double value)
                -> basic_kelvin<double, femto>;
            [[nodiscard]] constexpr auto operator""_pK(unsigned long long value) -> picokelvins;
            [[nodiscard]] constexpr auto operator""_pK(long double value)
                -> basic_kelvin<double, pico>;
            [[nodiscard]] constexpr auto operator""_nK(unsigned long long value) -> nanokelvins;
            [[nodiscard]] constexpr auto operator""_nK(long double value)
                -> basic_kelvin<double, nano>;
            [[nodiscard]] constexpr auto operator""_uK(unsigned long long value) -> microkelvins;
            [[nodiscard]] constexpr auto operator""_uK(long double value)
                -> basic_kelvin<double, micro>;
            [[nodiscard]] constexpr auto operator""_mK(unsigned long long value) -> millikelvins;
            [[nodiscard]] constexpr auto operator""_mK(long double value)
                -> basic_kelvin<double, milli>;
            [[nodiscard]] constexpr auto operator""_cK(unsigned long long value) -> centikelvins;
            [[nodiscard]] constexpr auto operator""_cK(long double value)
                -> basic_kelvin<double, centi>;
            [[nodiscard]] constexpr auto operator""_dK(unsigned long long value) -> decikelvins;
            [[nodiscard]] constexpr auto operator""_dK(long double value)
                -> basic_kelvin<double, deci>;
            [[nodiscard]] constexpr auto operator""_K(unsigned long long value) -> kelvins;
            [[nodiscard]] constexpr auto operator""_K(long double value)
                -> basic_kelvin<double, ratio<1>>;
            [[nodiscard]] constexpr auto operator""_daK(unsigned long long value) -> decakelvins;
            [[nodiscard]] constexpr auto operator""_daK(long double value)
                -> basic_kelvin<double, deca>;
            [[nodiscard]] constexpr auto operator""_hK(unsigned long long value) -> hectokelvins;
            [[nodiscard]] constexpr auto operator""_hK(long double value)
                -> basic_kelvin<double, hecto>;
            [[nodiscard]] constexpr auto operator""_kK(unsigned long long value) -> kilokelvins;
            [[nodiscard]] constexpr auto operator""_kK(long double value)
                -> basic_kelvin<double, kilo>;
            [[nodiscard]] constexpr auto operator""_MK(unsigned long long value) -> megakelvins;
            [[nodiscard]] constexpr auto operator""_MK(long double value)
                -> basic_kelvin<double, mega>;
            [[nodiscard]] constexpr auto operator""_GK(unsigned long long value) -> gigakelvins;
            [[nodiscard]] constexpr auto operator""_GK(long double value)
                -> basic_kelvin<double, giga>;
            [[nodiscard]] constexpr auto operator""_TK(unsigned long long value) -> terakelvins;
            [[nodiscard]] constexpr auto operator""_TK(long double value)
                -> basic_kelvin<double, tera>;
            [[nodiscard]] constexpr auto operator""_PK(unsigned long long value) -> petakelvins;
            [[nodiscard]] constexpr auto operator""_PK(long double value)
                -> basic_kelvin<double, peta>;
            [[nodiscard]] constexpr auto operator""_EK(unsigned long long value) -> exakelvins;
            [[nodiscard]] constexpr auto operator""_EK(long double value)
                -> basic_kelvin<double, exa>;

        } // namespace thermodynamic_temperature_literals

    } // namespace literals

    using namespace literals::thermodynamic_temperature_literals;

} // namespace posu::units::si

#include "posu/units/system/si/ipp/thermodynamic_temperature.ipp"

namespace posu::units::si {

    inline namespace references {

        inline namespace thermodynamic_temperature_references {

            inline constexpr auto aK  = 1_aK;
            inline constexpr auto fK  = 1_fK;
            inline constexpr auto pK  = 1_pK;
            inline constexpr auto nK  = 1_nK;
            inline constexpr auto uK  = 1_uK;
            inline constexpr auto mK  = 1_mK;
            inline constexpr auto cK  = 1_cK;
            inline constexpr auto dK  = 1_dK;
            inline constexpr auto K   = 1_K;
            inline constexpr auto daK = 1_daK;
            inline constexpr auto hK  = 1_hK;
            inline constexpr auto kK  = 1_kK;
            inline constexpr auto MK  = 1_MK;
            inline constexpr auto GK  = 1_GK;
            inline constexpr auto TK  = 1_TK;
            inline constexpr auto PK  = 1_PK;
            inline constexpr auto EK  = 1_EK;

        } // namespace thermodynamic_temperature_references

    } // namespace references

} // namespace posu::units::si

#endif // #ifndef POSU_UNITS_SI_THERMODYNAMIC_TEMPERATURE_HPP
