#ifndef POSU_UNITS_SYSTEM_SI_FREQUENCY_HPP
#define POSU_UNITS_SYSTEM_SI_FREQUENCY_HPP

#include "posu/units/base_unit.hpp"

#include "posu/units/system/frequency.hpp"

#include "posu/units/system/si/time.hpp"

namespace posu::units::si {

    template<typename Rep, typename Period>
    using frequency = quantity<Rep, Period, posu::units::frequency>;

    using attohertz  = frequency<int, std::atto>;
    using femtohertz = frequency<int, std::femto>;
    using picohertz  = frequency<int, std::pico>;
    using nanohertz  = frequency<int, std::nano>;
    using microhertz = frequency<int, std::micro>;
    using millihertz = frequency<int, std::milli>;
    using centihertz = frequency<int, std::centi>;
    using decihertz  = frequency<int, std::deci>;
    using hertz      = frequency<int, std::ratio<1>>;
    using decahertz  = frequency<int, std::deca>;
    using hectohertz = frequency<int, std::hecto>;
    using kilohertz  = frequency<int, std::kilo>;
    using megahertz  = frequency<int, std::mega>;
    using gigahertz  = frequency<int, std::giga>;
    using terahertz  = frequency<int, std::tera>;
    using petahertz  = frequency<int, std::peta>;
    using exahertz   = frequency<int, std::exa>;

    inline namespace literals {

        inline namespace frequency_literals {

            [[nodiscard]] constexpr auto operator""_aHz(unsigned long long value) -> attohertz;
            [[nodiscard]] constexpr auto operator""_aHz(long double value)
                -> frequency<double, std::atto>;
            [[nodiscard]] constexpr auto operator""_fHz(unsigned long long value) -> femtohertz;
            [[nodiscard]] constexpr auto operator""_fHz(long double value)
                -> frequency<double, std::femto>;
            [[nodiscard]] constexpr auto operator""_pHz(unsigned long long value) -> picohertz;
            [[nodiscard]] constexpr auto operator""_pHz(long double value)
                -> frequency<double, std::pico>;
            [[nodiscard]] constexpr auto operator""_nHz(unsigned long long value) -> nanohertz;
            [[nodiscard]] constexpr auto operator""_nHz(long double value)
                -> frequency<double, std::nano>;
            [[nodiscard]] constexpr auto operator""_uHz(unsigned long long value) -> microhertz;
            [[nodiscard]] constexpr auto operator""_uHz(long double value)
                -> frequency<double, std::micro>;
            [[nodiscard]] constexpr auto operator""_mHz(unsigned long long value) -> millihertz;
            [[nodiscard]] constexpr auto operator""_mHz(long double value)
                -> frequency<double, std::milli>;
            [[nodiscard]] constexpr auto operator""_cHz(unsigned long long value) -> centihertz;
            [[nodiscard]] constexpr auto operator""_cHz(long double value)
                -> frequency<double, std::centi>;
            [[nodiscard]] constexpr auto operator""_dHz(unsigned long long value) -> decihertz;
            [[nodiscard]] constexpr auto operator""_dHz(long double value)
                -> frequency<double, std::deci>;
            [[nodiscard]] constexpr auto operator""_Hz(unsigned long long value) -> hertz;
            [[nodiscard]] constexpr auto operator""_Hz(long double value)
                -> frequency<double, std::ratio<1>>;
            [[nodiscard]] constexpr auto operator""_daHz(unsigned long long value) -> decahertz;
            [[nodiscard]] constexpr auto operator""_daHz(long double value)
                -> frequency<double, std::deca>;
            [[nodiscard]] constexpr auto operator""_hHz(unsigned long long value) -> hectohertz;
            [[nodiscard]] constexpr auto operator""_hHz(long double value)
                -> frequency<double, std::hecto>;
            [[nodiscard]] constexpr auto operator""_kHz(unsigned long long value) -> kilohertz;
            [[nodiscard]] constexpr auto operator""_kHz(long double value)
                -> frequency<double, std::kilo>;
            [[nodiscard]] constexpr auto operator""_MHz(unsigned long long value) -> megahertz;
            [[nodiscard]] constexpr auto operator""_MHz(long double value)
                -> frequency<double, std::mega>;
            [[nodiscard]] constexpr auto operator""_GHz(unsigned long long value) -> gigahertz;
            [[nodiscard]] constexpr auto operator""_GHz(long double value)
                -> frequency<double, std::giga>;
            [[nodiscard]] constexpr auto operator""_THz(unsigned long long value) -> terahertz;
            [[nodiscard]] constexpr auto operator""_THz(long double value)
                -> frequency<double, std::tera>;
            [[nodiscard]] constexpr auto operator""_PHz(unsigned long long value) -> petahertz;
            [[nodiscard]] constexpr auto operator""_PHz(long double value)
                -> frequency<double, std::peta>;
            [[nodiscard]] constexpr auto operator""_EHz(unsigned long long value) -> exahertz;
            [[nodiscard]] constexpr auto operator""_EHz(long double value)
                -> frequency<double, std::exa>;

        } // namespace frequency_literals

    } // namespace literals

    using namespace literals::frequency_literals;

} // namespace posu::units::si

#endif // #ifndef POSU_UNITS_SYSTEM_SI_FREQUENCY_HPP
