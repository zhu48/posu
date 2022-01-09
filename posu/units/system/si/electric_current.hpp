#ifndef POSU_UNITS_SI_ELECTRIC_CURRENT_HPP
#define POSU_UNITS_SI_ELECTRIC_CURRENT_HPP

#include "posu/units/base_unit.hpp"

#include "posu/units/system/electric_current.hpp"

namespace posu::units::si {

    struct electric_current : public posu::units::electric_current {
        using type      = electric_current;
        using kind_type = posu::units::electric_current;
        using period    = ratio<1>;
    };

} // namespace posu::units::si

namespace posu::units {

    template<>
    inline constexpr bool enable_as_unit<si::electric_current> = true;

}

namespace posu::units::si {

    template<typename Rep, typename Period>
    using basic_ampere = quantity<Rep, Period, electric_current>;

    using attoamperes  = basic_ampere<int, atto>;
    using femtoamperes = basic_ampere<int, femto>;
    using picoamperes  = basic_ampere<int, pico>;
    using nanoamperes  = basic_ampere<int, nano>;
    using microamperes = basic_ampere<int, micro>;
    using milliamperes = basic_ampere<int, milli>;
    using centiamperes = basic_ampere<int, centi>;
    using deciamperes  = basic_ampere<int, deci>;
    using amperes      = basic_ampere<int, ratio<1>>;
    using decaamperes  = basic_ampere<int, deca>;
    using hectoamperes = basic_ampere<int, hecto>;
    using kiloamperes  = basic_ampere<int, kilo>;
    using megaamperes  = basic_ampere<int, mega>;
    using gigaamperes  = basic_ampere<int, giga>;
    using teraamperes  = basic_ampere<int, tera>;
    using petaamperes  = basic_ampere<int, peta>;
    using exaamperes   = basic_ampere<int, exa>;

    inline namespace literals {

        inline namespace electric_current_literals {

            [[nodiscard]] constexpr auto operator""_aA(unsigned long long value) -> attoamperes;
            [[nodiscard]] constexpr auto operator""_aA(long double value)
                -> basic_ampere<double, atto>;
            [[nodiscard]] constexpr auto operator""_fA(unsigned long long value) -> femtoamperes;
            [[nodiscard]] constexpr auto operator""_fA(long double value)
                -> basic_ampere<double, femto>;
            [[nodiscard]] constexpr auto operator""_pA(unsigned long long value) -> picoamperes;
            [[nodiscard]] constexpr auto operator""_pA(long double value)
                -> basic_ampere<double, pico>;
            [[nodiscard]] constexpr auto operator""_nA(unsigned long long value) -> nanoamperes;
            [[nodiscard]] constexpr auto operator""_nA(long double value)
                -> basic_ampere<double, nano>;
            [[nodiscard]] constexpr auto operator""_uA(unsigned long long value) -> microamperes;
            [[nodiscard]] constexpr auto operator""_uA(long double value)
                -> basic_ampere<double, micro>;
            [[nodiscard]] constexpr auto operator""_mA(unsigned long long value) -> milliamperes;
            [[nodiscard]] constexpr auto operator""_mA(long double value)
                -> basic_ampere<double, milli>;
            [[nodiscard]] constexpr auto operator""_cA(unsigned long long value) -> centiamperes;
            [[nodiscard]] constexpr auto operator""_cA(long double value)
                -> basic_ampere<double, centi>;
            [[nodiscard]] constexpr auto operator""_dA(unsigned long long value) -> deciamperes;
            [[nodiscard]] constexpr auto operator""_dA(long double value)
                -> basic_ampere<double, deci>;
            [[nodiscard]] constexpr auto operator""_A(unsigned long long value) -> amperes;
            [[nodiscard]] constexpr auto operator""_A(long double value)
                -> basic_ampere<double, ratio<1>>;
            [[nodiscard]] constexpr auto operator""_daA(unsigned long long value) -> decaamperes;
            [[nodiscard]] constexpr auto operator""_daA(long double value)
                -> basic_ampere<double, deca>;
            [[nodiscard]] constexpr auto operator""_hA(unsigned long long value) -> hectoamperes;
            [[nodiscard]] constexpr auto operator""_hA(long double value)
                -> basic_ampere<double, hecto>;
            [[nodiscard]] constexpr auto operator""_kA(unsigned long long value) -> kiloamperes;
            [[nodiscard]] constexpr auto operator""_kA(long double value)
                -> basic_ampere<double, kilo>;
            [[nodiscard]] constexpr auto operator""_MA(unsigned long long value) -> megaamperes;
            [[nodiscard]] constexpr auto operator""_MA(long double value)
                -> basic_ampere<double, mega>;
            [[nodiscard]] constexpr auto operator""_GA(unsigned long long value) -> gigaamperes;
            [[nodiscard]] constexpr auto operator""_GA(long double value)
                -> basic_ampere<double, giga>;
            [[nodiscard]] constexpr auto operator""_TA(unsigned long long value) -> teraamperes;
            [[nodiscard]] constexpr auto operator""_TA(long double value)
                -> basic_ampere<double, tera>;
            [[nodiscard]] constexpr auto operator""_PA(unsigned long long value) -> petaamperes;
            [[nodiscard]] constexpr auto operator""_PA(long double value)
                -> basic_ampere<double, peta>;
            [[nodiscard]] constexpr auto operator""_EA(unsigned long long value) -> exaamperes;
            [[nodiscard]] constexpr auto operator""_EA(long double value)
                -> basic_ampere<double, exa>;

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
