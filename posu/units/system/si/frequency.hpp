#ifndef POSU_UNITS_SYSTEM_SI_FREQUENCY_HPP
#define POSU_UNITS_SYSTEM_SI_FREQUENCY_HPP

#include "posu/units/base_unit.hpp"

#include "posu/units/system/frequency.hpp"

#include "posu/units/system/si/time.hpp"

namespace posu::units::si {

    struct frequency : public posu::units::frequency {
        using type      = frequency;
        using kind_type = posu::units::frequency;
        using period    = ratio<1>;
    };

} // namespace posu::units::si

namespace posu::units {

    template<>
    inline constexpr bool enable_as_unit<si::frequency> = true;

    template<>
    struct unit_multiply_result<si::frequency, si::time> {
        using type = scaler<>;
    };

    template<>
    struct unit_multiply_result<si::time, si::frequency> {
        using type = scaler<>;
    };

    template<>
    struct unit_divide_result<scaler<>, si::time> {
        using type = si::frequency;
    };

} // namespace posu::units

namespace posu::units::si {

    template<typename Rep, typename Period>
    using basic_hertz = quantity<Rep, Period, frequency>;

    using attohertz  = basic_hertz<int, atto>;
    using femtohertz = basic_hertz<int, femto>;
    using picohertz  = basic_hertz<int, pico>;
    using nanohertz  = basic_hertz<int, nano>;
    using microhertz = basic_hertz<int, micro>;
    using millihertz = basic_hertz<int, milli>;
    using centihertz = basic_hertz<int, centi>;
    using decihertz  = basic_hertz<int, deci>;
    using hertz      = basic_hertz<int, ratio<1>>;
    using decahertz  = basic_hertz<int, deca>;
    using hectohertz = basic_hertz<int, hecto>;
    using kilohertz  = basic_hertz<int, kilo>;
    using megahertz  = basic_hertz<int, mega>;
    using gigahertz  = basic_hertz<int, giga>;
    using terahertz  = basic_hertz<int, tera>;
    using petahertz  = basic_hertz<int, peta>;
    using exahertz   = basic_hertz<int, exa>;

    inline namespace literals {

        inline namespace frequency_literals {

            [[nodiscard]] constexpr auto operator""_aHz(unsigned long long value) -> attohertz;
            [[nodiscard]] constexpr auto operator""_aHz(long double value)
                -> basic_hertz<double, atto>;
            [[nodiscard]] constexpr auto operator""_fHz(unsigned long long value) -> femtohertz;
            [[nodiscard]] constexpr auto operator""_fHz(long double value)
                -> basic_hertz<double, femto>;
            [[nodiscard]] constexpr auto operator""_pHz(unsigned long long value) -> picohertz;
            [[nodiscard]] constexpr auto operator""_pHz(long double value)
                -> basic_hertz<double, pico>;
            [[nodiscard]] constexpr auto operator""_nHz(unsigned long long value) -> nanohertz;
            [[nodiscard]] constexpr auto operator""_nHz(long double value)
                -> basic_hertz<double, nano>;
            [[nodiscard]] constexpr auto operator""_uHz(unsigned long long value) -> microhertz;
            [[nodiscard]] constexpr auto operator""_uHz(long double value)
                -> basic_hertz<double, micro>;
            [[nodiscard]] constexpr auto operator""_mHz(unsigned long long value) -> millihertz;
            [[nodiscard]] constexpr auto operator""_mHz(long double value)
                -> basic_hertz<double, milli>;
            [[nodiscard]] constexpr auto operator""_cHz(unsigned long long value) -> centihertz;
            [[nodiscard]] constexpr auto operator""_cHz(long double value)
                -> basic_hertz<double, centi>;
            [[nodiscard]] constexpr auto operator""_dHz(unsigned long long value) -> decihertz;
            [[nodiscard]] constexpr auto operator""_dHz(long double value)
                -> basic_hertz<double, deci>;
            [[nodiscard]] constexpr auto operator""_Hz(unsigned long long value) -> hertz;
            [[nodiscard]] constexpr auto operator""_Hz(long double value)
                -> basic_hertz<double, ratio<1>>;
            [[nodiscard]] constexpr auto operator""_daHz(unsigned long long value) -> decahertz;
            [[nodiscard]] constexpr auto operator""_daHz(long double value)
                -> basic_hertz<double, deca>;
            [[nodiscard]] constexpr auto operator""_hHz(unsigned long long value) -> hectohertz;
            [[nodiscard]] constexpr auto operator""_hHz(long double value)
                -> basic_hertz<double, hecto>;
            [[nodiscard]] constexpr auto operator""_kHz(unsigned long long value) -> kilohertz;
            [[nodiscard]] constexpr auto operator""_kHz(long double value)
                -> basic_hertz<double, kilo>;
            [[nodiscard]] constexpr auto operator""_MHz(unsigned long long value) -> megahertz;
            [[nodiscard]] constexpr auto operator""_MHz(long double value)
                -> basic_hertz<double, mega>;
            [[nodiscard]] constexpr auto operator""_GHz(unsigned long long value) -> gigahertz;
            [[nodiscard]] constexpr auto operator""_GHz(long double value)
                -> basic_hertz<double, giga>;
            [[nodiscard]] constexpr auto operator""_THz(unsigned long long value) -> terahertz;
            [[nodiscard]] constexpr auto operator""_THz(long double value)
                -> basic_hertz<double, tera>;
            [[nodiscard]] constexpr auto operator""_PHz(unsigned long long value) -> petahertz;
            [[nodiscard]] constexpr auto operator""_PHz(long double value)
                -> basic_hertz<double, peta>;
            [[nodiscard]] constexpr auto operator""_EHz(unsigned long long value) -> exahertz;
            [[nodiscard]] constexpr auto operator""_EHz(long double value)
                -> basic_hertz<double, exa>;

        } // namespace frequency_literals

    } // namespace literals

    using namespace literals::frequency_literals;

} // namespace posu::units::si

#include "posu/units/system/si/ipp/frequency.ipp"

namespace posu::units::si {

    inline namespace references {

        inline namespace frequency_references {

            inline constexpr auto aHz  = 1_aHz;
            inline constexpr auto fHz  = 1_fHz;
            inline constexpr auto pHz  = 1_pHz;
            inline constexpr auto nHz  = 1_nHz;
            inline constexpr auto uHz  = 1_uHz;
            inline constexpr auto mHz  = 1_mHz;
            inline constexpr auto cHz  = 1_cHz;
            inline constexpr auto dHz  = 1_dHz;
            inline constexpr auto Hz   = 1_Hz;
            inline constexpr auto daHz = 1_daHz;
            inline constexpr auto hHz  = 1_hHz;
            inline constexpr auto kHz  = 1_kHz;
            inline constexpr auto MHz  = 1_MHz;
            inline constexpr auto GHz  = 1_GHz;
            inline constexpr auto THz  = 1_THz;
            inline constexpr auto PHz  = 1_PHz;
            inline constexpr auto EHz  = 1_EHz;

        } // namespace frequency_references

    } // namespace references

} // namespace posu::units::si

#endif // #ifndef POSU_UNITS_SYSTEM_SI_FREQUENCY_HPP
