#ifndef POSU_UNITS_SYSTEM_SI_POWER_HPP
#define POSU_UNITS_SYSTEM_SI_POWER_HPP

#include "posu/units/base_unit.hpp"

#include "posu/units/system/power.hpp"

#include "posu/units/system/si/energy.hpp"
#include "posu/units/system/si/time.hpp"

namespace posu::units::si {

    struct power : public posu::units::power {
        using type      = power;
        using kind_type = posu::units::power;
        using period    = kilo;
    };

} // namespace posu::units::si

namespace posu::units {

    template<>
    inline constexpr bool enable_as_unit<si::power> = true;

} // namespace posu::units

namespace posu::units::si {

    template<typename Rep, typename Period>
    using basic_watt = quantity<Rep, Period, power>;

    using attowatts  = basic_watt<int, atto>;
    using femtowatts = basic_watt<int, femto>;
    using picowatts  = basic_watt<int, pico>;
    using nanowatts  = basic_watt<int, nano>;
    using microwatts = basic_watt<int, micro>;
    using milliwatts = basic_watt<int, milli>;
    using centiwatts = basic_watt<int, centi>;
    using deciwatts  = basic_watt<int, deci>;
    using watts      = basic_watt<int, ratio<1>>;
    using decawatts  = basic_watt<int, deca>;
    using hectowatts = basic_watt<int, hecto>;
    using kilowatts  = basic_watt<int, kilo>;
    using megawatts  = basic_watt<int, mega>;
    using gigawatts  = basic_watt<int, giga>;
    using terawatts  = basic_watt<int, tera>;
    using petawatts  = basic_watt<int, peta>;
    using exawatts   = basic_watt<int, exa>;

    inline namespace literals {

        inline namespace power_literals {

            [[nodiscard]] constexpr auto operator""_aW(unsigned long long value) -> attowatts;
            [[nodiscard]] constexpr auto operator""_aW(long double value)
                -> basic_watt<double, atto>;
            [[nodiscard]] constexpr auto operator""_fW(unsigned long long value) -> femtowatts;
            [[nodiscard]] constexpr auto operator""_fW(long double value)
                -> basic_watt<double, femto>;
            [[nodiscard]] constexpr auto operator""_pW(unsigned long long value) -> picowatts;
            [[nodiscard]] constexpr auto operator""_pW(long double value)
                -> basic_watt<double, pico>;
            [[nodiscard]] constexpr auto operator""_nW(unsigned long long value) -> nanowatts;
            [[nodiscard]] constexpr auto operator""_nW(long double value)
                -> basic_watt<double, nano>;
            [[nodiscard]] constexpr auto operator""_uW(unsigned long long value) -> microwatts;
            [[nodiscard]] constexpr auto operator""_uW(long double value)
                -> basic_watt<double, micro>;
            [[nodiscard]] constexpr auto operator""_mW(unsigned long long value) -> milliwatts;
            [[nodiscard]] constexpr auto operator""_mW(long double value)
                -> basic_watt<double, milli>;
            [[nodiscard]] constexpr auto operator""_cW(unsigned long long value) -> centiwatts;
            [[nodiscard]] constexpr auto operator""_cW(long double value)
                -> basic_watt<double, centi>;
            [[nodiscard]] constexpr auto operator""_dW(unsigned long long value) -> deciwatts;
            [[nodiscard]] constexpr auto operator""_dW(long double value)
                -> basic_watt<double, deci>;
            [[nodiscard]] constexpr auto operator""_W(unsigned long long value) -> watts;
            [[nodiscard]] constexpr auto operator""_W(long double value)
                -> basic_watt<double, ratio<1>>;
            [[nodiscard]] constexpr auto operator""_daW(unsigned long long value) -> decawatts;
            [[nodiscard]] constexpr auto operator""_daW(long double value)
                -> basic_watt<double, deca>;
            [[nodiscard]] constexpr auto operator""_hW(unsigned long long value) -> hectowatts;
            [[nodiscard]] constexpr auto operator""_hW(long double value)
                -> basic_watt<double, hecto>;
            [[nodiscard]] constexpr auto operator""_kW(unsigned long long value) -> kilowatts;
            [[nodiscard]] constexpr auto operator""_kW(long double value)
                -> basic_watt<double, kilo>;
            [[nodiscard]] constexpr auto operator""_MW(unsigned long long value) -> megawatts;
            [[nodiscard]] constexpr auto operator""_MW(long double value)
                -> basic_watt<double, mega>;
            [[nodiscard]] constexpr auto operator""_GW(unsigned long long value) -> gigawatts;
            [[nodiscard]] constexpr auto operator""_GW(long double value)
                -> basic_watt<double, giga>;
            [[nodiscard]] constexpr auto operator""_TW(unsigned long long value) -> terawatts;
            [[nodiscard]] constexpr auto operator""_TW(long double value)
                -> basic_watt<double, tera>;
            [[nodiscard]] constexpr auto operator""_PW(unsigned long long value) -> petawatts;
            [[nodiscard]] constexpr auto operator""_PW(long double value)
                -> basic_watt<double, peta>;
            [[nodiscard]] constexpr auto operator""_EW(unsigned long long value) -> exawatts;
            [[nodiscard]] constexpr auto operator""_EW(long double value)
                -> basic_watt<double, exa>;

        } // namespace power_literals

    } // namespace literals

    using namespace literals::power_literals;

} // namespace posu::units::si

#include "posu/units/system/si/ipp/power.ipp"

namespace posu::units::si {

    inline namespace references {

        inline namespace power_references {

            inline constexpr auto aW  = 1_aW;
            inline constexpr auto fW  = 1_fW;
            inline constexpr auto pW  = 1_pW;
            inline constexpr auto nW  = 1_nW;
            inline constexpr auto uW  = 1_uW;
            inline constexpr auto mW  = 1_mW;
            inline constexpr auto cW  = 1_cW;
            inline constexpr auto dW  = 1_dW;
            inline constexpr auto W   = 1_W;
            inline constexpr auto daW = 1_daW;
            inline constexpr auto hW  = 1_hW;
            inline constexpr auto kW  = 1_kW;
            inline constexpr auto MW  = 1_MW;
            inline constexpr auto GW  = 1_GW;
            inline constexpr auto TW  = 1_TW;
            inline constexpr auto PW  = 1_PW;
            inline constexpr auto EW  = 1_EW;

        } // namespace power_references

    } // namespace references

} // namespace posu::units::si

#endif // #ifndef POSU_UNITS_SYSTEM_SI_POWER_HPP
