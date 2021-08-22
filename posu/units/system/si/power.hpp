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
        using period    = std::kilo;
    };

} // namespace posu::units::si

namespace posu::units {

    template<>
    inline constexpr bool enable_as_unit<si::power> = true;

} // namespace posu::units

namespace posu::units::si {

    template<typename Rep, typename Period>
    using basic_watt = quantity<Rep, Period, power>;

    using attowatts  = basic_watt<int, std::atto>;
    using femtowatts = basic_watt<int, std::femto>;
    using picowatts  = basic_watt<int, std::pico>;
    using nanowatts  = basic_watt<int, std::nano>;
    using microwatts = basic_watt<int, std::micro>;
    using milliwatts = basic_watt<int, std::milli>;
    using centiwatts = basic_watt<int, std::centi>;
    using deciwatts  = basic_watt<int, std::deci>;
    using watts      = basic_watt<int, std::ratio<1>>;
    using decawatts  = basic_watt<int, std::deca>;
    using hectowatts = basic_watt<int, std::hecto>;
    using kilowatts  = basic_watt<int, std::kilo>;
    using megawatts  = basic_watt<int, std::mega>;
    using gigawatts  = basic_watt<int, std::giga>;
    using terawatts  = basic_watt<int, std::tera>;
    using petawatts  = basic_watt<int, std::peta>;
    using exawatts   = basic_watt<int, std::exa>;

    inline namespace literals {

        inline namespace power_literals {

            [[nodiscard]] constexpr auto operator""_aW(unsigned long long value) -> attowatts;
            [[nodiscard]] constexpr auto operator""_aW(long double value)
                -> basic_watt<double, std::atto>;
            [[nodiscard]] constexpr auto operator""_fW(unsigned long long value) -> femtowatts;
            [[nodiscard]] constexpr auto operator""_fW(long double value)
                -> basic_watt<double, std::femto>;
            [[nodiscard]] constexpr auto operator""_pW(unsigned long long value) -> picowatts;
            [[nodiscard]] constexpr auto operator""_pW(long double value)
                -> basic_watt<double, std::pico>;
            [[nodiscard]] constexpr auto operator""_nW(unsigned long long value) -> nanowatts;
            [[nodiscard]] constexpr auto operator""_nW(long double value)
                -> basic_watt<double, std::nano>;
            [[nodiscard]] constexpr auto operator""_uW(unsigned long long value) -> microwatts;
            [[nodiscard]] constexpr auto operator""_uW(long double value)
                -> basic_watt<double, std::micro>;
            [[nodiscard]] constexpr auto operator""_mW(unsigned long long value) -> milliwatts;
            [[nodiscard]] constexpr auto operator""_mW(long double value)
                -> basic_watt<double, std::milli>;
            [[nodiscard]] constexpr auto operator""_cW(unsigned long long value) -> centiwatts;
            [[nodiscard]] constexpr auto operator""_cW(long double value)
                -> basic_watt<double, std::centi>;
            [[nodiscard]] constexpr auto operator""_dW(unsigned long long value) -> deciwatts;
            [[nodiscard]] constexpr auto operator""_dW(long double value)
                -> basic_watt<double, std::deci>;
            [[nodiscard]] constexpr auto operator""_W(unsigned long long value) -> watts;
            [[nodiscard]] constexpr auto operator""_W(long double value)
                -> basic_watt<double, std::ratio<1>>;
            [[nodiscard]] constexpr auto operator""_daW(unsigned long long value) -> decawatts;
            [[nodiscard]] constexpr auto operator""_daW(long double value)
                -> basic_watt<double, std::deca>;
            [[nodiscard]] constexpr auto operator""_hW(unsigned long long value) -> hectowatts;
            [[nodiscard]] constexpr auto operator""_hW(long double value)
                -> basic_watt<double, std::hecto>;
            [[nodiscard]] constexpr auto operator""_kW(unsigned long long value) -> kilowatts;
            [[nodiscard]] constexpr auto operator""_kW(long double value)
                -> basic_watt<double, std::kilo>;
            [[nodiscard]] constexpr auto operator""_MW(unsigned long long value) -> megawatts;
            [[nodiscard]] constexpr auto operator""_MW(long double value)
                -> basic_watt<double, std::mega>;
            [[nodiscard]] constexpr auto operator""_GW(unsigned long long value) -> gigawatts;
            [[nodiscard]] constexpr auto operator""_GW(long double value)
                -> basic_watt<double, std::giga>;
            [[nodiscard]] constexpr auto operator""_TW(unsigned long long value) -> terawatts;
            [[nodiscard]] constexpr auto operator""_TW(long double value)
                -> basic_watt<double, std::tera>;
            [[nodiscard]] constexpr auto operator""_PW(unsigned long long value) -> petawatts;
            [[nodiscard]] constexpr auto operator""_PW(long double value)
                -> basic_watt<double, std::peta>;
            [[nodiscard]] constexpr auto operator""_EW(unsigned long long value) -> exawatts;
            [[nodiscard]] constexpr auto operator""_EW(long double value)
                -> basic_watt<double, std::exa>;

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
