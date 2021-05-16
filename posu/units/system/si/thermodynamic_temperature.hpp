#ifndef POSU_UNITS_SI_THERMODYNAMIC_TEMPERATURE_HPP
#define POSU_UNITS_SI_THERMODYNAMIC_TEMPERATURE_HPP

#include "posu/units/base_unit.hpp"

#include "posu/units/system/thermodynamic_temperature.hpp"

namespace posu::units::si {

    template<typename Rep, typename Period>
    using thermodynamic_temperature = quantity<Rep, Period, posu::units::thermodynamic_temperature>;

    using attokelvins  = thermodynamic_temperature<int, std::atto>;
    using femtokelvins = thermodynamic_temperature<int, std::femto>;
    using picokelvins  = thermodynamic_temperature<int, std::pico>;
    using nanokelvins  = thermodynamic_temperature<int, std::nano>;
    using microkelvins = thermodynamic_temperature<int, std::micro>;
    using millikelvins = thermodynamic_temperature<int, std::milli>;
    using centikelvins = thermodynamic_temperature<int, std::centi>;
    using decikelvins  = thermodynamic_temperature<int, std::deci>;
    using kelvins      = thermodynamic_temperature<int, std::ratio<1>>;
    using decakelvins  = thermodynamic_temperature<int, std::deca>;
    using hectokelvins = thermodynamic_temperature<int, std::hecto>;
    using kilokelvins  = thermodynamic_temperature<int, std::kilo>;
    using megakelvins  = thermodynamic_temperature<int, std::mega>;
    using gigakelvins  = thermodynamic_temperature<int, std::giga>;
    using terakelvins  = thermodynamic_temperature<int, std::tera>;
    using petakelvins  = thermodynamic_temperature<int, std::peta>;
    using exakelvins   = thermodynamic_temperature<int, std::exa>;

    inline namespace literals {

        inline namespace thermodynamic_temperature_literals {

            [[nodiscard]] constexpr auto operator""_aK(unsigned long long value) -> attokelvins;
            [[nodiscard]] constexpr auto operator""_aK(long double value)
                -> thermodynamic_temperature<double, std::atto>;
            [[nodiscard]] constexpr auto operator""_fK(unsigned long long value) -> femtokelvins;
            [[nodiscard]] constexpr auto operator""_fK(long double value)
                -> thermodynamic_temperature<double, std::femto>;
            [[nodiscard]] constexpr auto operator""_pK(unsigned long long value) -> picokelvins;
            [[nodiscard]] constexpr auto operator""_pK(long double value)
                -> thermodynamic_temperature<double, std::pico>;
            [[nodiscard]] constexpr auto operator""_nK(unsigned long long value) -> nanokelvins;
            [[nodiscard]] constexpr auto operator""_nK(long double value)
                -> thermodynamic_temperature<double, std::nano>;
            [[nodiscard]] constexpr auto operator""_uK(unsigned long long value) -> microkelvins;
            [[nodiscard]] constexpr auto operator""_uK(long double value)
                -> thermodynamic_temperature<double, std::micro>;
            [[nodiscard]] constexpr auto operator""_mK(unsigned long long value) -> millikelvins;
            [[nodiscard]] constexpr auto operator""_mK(long double value)
                -> thermodynamic_temperature<double, std::milli>;
            [[nodiscard]] constexpr auto operator""_cK(unsigned long long value) -> centikelvins;
            [[nodiscard]] constexpr auto operator""_cK(long double value)
                -> thermodynamic_temperature<double, std::centi>;
            [[nodiscard]] constexpr auto operator""_dK(unsigned long long value) -> decikelvins;
            [[nodiscard]] constexpr auto operator""_dK(long double value)
                -> thermodynamic_temperature<double, std::deci>;
            [[nodiscard]] constexpr auto operator""_K(unsigned long long value) -> kelvins;
            [[nodiscard]] constexpr auto operator""_K(long double value)
                -> thermodynamic_temperature<double, std::ratio<1>>;
            [[nodiscard]] constexpr auto operator""_daK(unsigned long long value) -> decakelvins;
            [[nodiscard]] constexpr auto operator""_daK(long double value)
                -> thermodynamic_temperature<double, std::deca>;
            [[nodiscard]] constexpr auto operator""_hK(unsigned long long value) -> hectokelvins;
            [[nodiscard]] constexpr auto operator""_hK(long double value)
                -> thermodynamic_temperature<double, std::hecto>;
            [[nodiscard]] constexpr auto operator""_kK(unsigned long long value) -> kilokelvins;
            [[nodiscard]] constexpr auto operator""_kK(long double value)
                -> thermodynamic_temperature<double, std::kilo>;
            [[nodiscard]] constexpr auto operator""_MK(unsigned long long value) -> megakelvins;
            [[nodiscard]] constexpr auto operator""_MK(long double value)
                -> thermodynamic_temperature<double, std::mega>;
            [[nodiscard]] constexpr auto operator""_GK(unsigned long long value) -> gigakelvins;
            [[nodiscard]] constexpr auto operator""_GK(long double value)
                -> thermodynamic_temperature<double, std::giga>;
            [[nodiscard]] constexpr auto operator""_TK(unsigned long long value) -> terakelvins;
            [[nodiscard]] constexpr auto operator""_TK(long double value)
                -> thermodynamic_temperature<double, std::tera>;
            [[nodiscard]] constexpr auto operator""_PK(unsigned long long value) -> petakelvins;
            [[nodiscard]] constexpr auto operator""_PK(long double value)
                -> thermodynamic_temperature<double, std::peta>;
            [[nodiscard]] constexpr auto operator""_EK(unsigned long long value) -> exakelvins;
            [[nodiscard]] constexpr auto operator""_EK(long double value)
                -> thermodynamic_temperature<double, std::exa>;

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
