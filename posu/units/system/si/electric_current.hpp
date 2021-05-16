#ifndef POSU_UNITS_SI_ELECTRIC_CURRENT_HPP
#define POSU_UNITS_SI_ELECTRIC_CURRENT_HPP

#include "posu/units/base_unit.hpp"

#include "posu/units/system/electric_current.hpp"

namespace posu::units::si {

    template<typename Rep, typename Period>
    using electric_current = quantity<Rep, Period, posu::units::electric_current>;

    using attoamperes  = electric_current<int, std::atto>;
    using femtoamperes = electric_current<int, std::femto>;
    using picoamperes  = electric_current<int, std::pico>;
    using nanoamperes  = electric_current<int, std::nano>;
    using microamperes = electric_current<int, std::micro>;
    using milliamperes = electric_current<int, std::milli>;
    using centiamperes = electric_current<int, std::centi>;
    using deciamperes  = electric_current<int, std::deci>;
    using amperes      = electric_current<int, std::ratio<1>>;
    using decaamperes  = electric_current<int, std::deca>;
    using hectoamperes = electric_current<int, std::hecto>;
    using kiloamperes  = electric_current<int, std::kilo>;
    using megaamperes  = electric_current<int, std::mega>;
    using gigaamperes  = electric_current<int, std::giga>;
    using teraamperes  = electric_current<int, std::tera>;
    using petaamperes  = electric_current<int, std::peta>;
    using exaamperes   = electric_current<int, std::exa>;

    inline namespace literals {

        inline namespace electric_current_literals {

            [[nodiscard]] constexpr auto operator""_aA(unsigned long long value) -> attoamperes;
            [[nodiscard]] constexpr auto operator""_aA(long double value)
                -> electric_current<double, std::atto>;
            [[nodiscard]] constexpr auto operator""_fA(unsigned long long value) -> femtoamperes;
            [[nodiscard]] constexpr auto operator""_fA(long double value)
                -> electric_current<double, std::femto>;
            [[nodiscard]] constexpr auto operator""_pA(unsigned long long value) -> picoamperes;
            [[nodiscard]] constexpr auto operator""_pA(long double value)
                -> electric_current<double, std::pico>;
            [[nodiscard]] constexpr auto operator""_nA(unsigned long long value) -> nanoamperes;
            [[nodiscard]] constexpr auto operator""_nA(long double value)
                -> electric_current<double, std::nano>;
            [[nodiscard]] constexpr auto operator""_uA(unsigned long long value) -> microamperes;
            [[nodiscard]] constexpr auto operator""_uA(long double value)
                -> electric_current<double, std::micro>;
            [[nodiscard]] constexpr auto operator""_mA(unsigned long long value) -> milliamperes;
            [[nodiscard]] constexpr auto operator""_mA(long double value)
                -> electric_current<double, std::milli>;
            [[nodiscard]] constexpr auto operator""_cA(unsigned long long value) -> centiamperes;
            [[nodiscard]] constexpr auto operator""_cA(long double value)
                -> electric_current<double, std::centi>;
            [[nodiscard]] constexpr auto operator""_dA(unsigned long long value) -> deciamperes;
            [[nodiscard]] constexpr auto operator""_dA(long double value)
                -> electric_current<double, std::deci>;
            [[nodiscard]] constexpr auto operator""_A(unsigned long long value) -> amperes;
            [[nodiscard]] constexpr auto operator""_A(long double value)
                -> electric_current<double, std::ratio<1>>;
            [[nodiscard]] constexpr auto operator""_daA(unsigned long long value) -> decaamperes;
            [[nodiscard]] constexpr auto operator""_daA(long double value)
                -> electric_current<double, std::deca>;
            [[nodiscard]] constexpr auto operator""_hA(unsigned long long value) -> hectoamperes;
            [[nodiscard]] constexpr auto operator""_hA(long double value)
                -> electric_current<double, std::hecto>;
            [[nodiscard]] constexpr auto operator""_kA(unsigned long long value) -> kiloamperes;
            [[nodiscard]] constexpr auto operator""_kA(long double value)
                -> electric_current<double, std::kilo>;
            [[nodiscard]] constexpr auto operator""_MA(unsigned long long value) -> megaamperes;
            [[nodiscard]] constexpr auto operator""_MA(long double value)
                -> electric_current<double, std::mega>;
            [[nodiscard]] constexpr auto operator""_GA(unsigned long long value) -> gigaamperes;
            [[nodiscard]] constexpr auto operator""_GA(long double value)
                -> electric_current<double, std::giga>;
            [[nodiscard]] constexpr auto operator""_TA(unsigned long long value) -> teraamperes;
            [[nodiscard]] constexpr auto operator""_TA(long double value)
                -> electric_current<double, std::tera>;
            [[nodiscard]] constexpr auto operator""_PA(unsigned long long value) -> petaamperes;
            [[nodiscard]] constexpr auto operator""_PA(long double value)
                -> electric_current<double, std::peta>;
            [[nodiscard]] constexpr auto operator""_EA(unsigned long long value) -> exaamperes;
            [[nodiscard]] constexpr auto operator""_EA(long double value)
                -> electric_current<double, std::exa>;

        } // namespace electric_current_literals

    } // namespace literals

    using namespace literals::electric_current_literals;

} // namespace posu::units::si

#include "posu/units/system/si/ipp/electric_current.ipp"

namespace posu::units::si {

    inline namespace references {

        inline namespace electric_current_references {

            inline constexpr auto aA  = 1_aA;
            inline constexpr auto fA  = 1_fA;
            inline constexpr auto pA  = 1_pA;
            inline constexpr auto nA  = 1_nA;
            inline constexpr auto uA  = 1_uA;
            inline constexpr auto mA  = 1_mA;
            inline constexpr auto cA  = 1_cA;
            inline constexpr auto dA  = 1_dA;
            inline constexpr auto A   = 1_A;
            inline constexpr auto daA = 1_daA;
            inline constexpr auto hA  = 1_hA;
            inline constexpr auto kA  = 1_kA;
            inline constexpr auto MA  = 1_MA;
            inline constexpr auto GA  = 1_GA;
            inline constexpr auto TA  = 1_TA;
            inline constexpr auto PA  = 1_PA;
            inline constexpr auto EA  = 1_EA;

        } // namespace electric_current_references

    } // namespace references

} // namespace posu::units::si

#endif // #ifndef POSU_UNITS_SI_ELECTRIC_CURRENT_HPP
