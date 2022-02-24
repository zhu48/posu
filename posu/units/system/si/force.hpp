#ifndef POSU_UNITS_SYSTEM_SI_FORCE_HPP
#define POSU_UNITS_SYSTEM_SI_FORCE_HPP

#include "posu/units/base_unit.hpp"

#include "posu/units/system/force.hpp"

#include "posu/units/system/si/length.hpp"
#include "posu/units/system/si/mass.hpp"
#include "posu/units/system/si/time.hpp"

namespace posu::units::si {

    struct force : public posu::units::force {
        using type      = force;
        using kind_type = posu::units::force;
        using period    = kilo;
    };

} // namespace posu::units::si

template<>
inline constexpr bool posu::units::enable_as_unit<posu::units::si::force> = true;

namespace posu::units::si {

    template<typename Rep, typename Period>
    using basic_newton = quantity<Rep, Period, force>;

    using attonewtons  = basic_newton<int, atto>;
    using femtonewtons = basic_newton<int, femto>;
    using piconewtons  = basic_newton<int, pico>;
    using nanonewtons  = basic_newton<int, nano>;
    using micronewtons = basic_newton<int, micro>;
    using millinewtons = basic_newton<int, milli>;
    using centinewtons = basic_newton<int, centi>;
    using decinewtons  = basic_newton<int, deci>;
    using newtons      = basic_newton<int, ratio<1>>;
    using decanewtons  = basic_newton<int, deca>;
    using hectonewtons = basic_newton<int, hecto>;
    using kilonewtons  = basic_newton<int, kilo>;
    using meganewtons  = basic_newton<int, mega>;
    using giganewtons  = basic_newton<int, giga>;
    using teranewtons  = basic_newton<int, tera>;
    using petanewtons  = basic_newton<int, peta>;
    using exanewtons   = basic_newton<int, exa>;

    inline namespace literals {

        inline namespace force_literals {

            [[nodiscard]] constexpr auto operator""_aN(unsigned long long value) -> attonewtons;
            [[nodiscard]] constexpr auto operator""_aN(long double value)
                -> basic_newton<double, atto>;
            [[nodiscard]] constexpr auto operator""_fN(unsigned long long value) -> femtonewtons;
            [[nodiscard]] constexpr auto operator""_fN(long double value)
                -> basic_newton<double, femto>;
            [[nodiscard]] constexpr auto operator""_pN(unsigned long long value) -> piconewtons;
            [[nodiscard]] constexpr auto operator""_pN(long double value)
                -> basic_newton<double, pico>;
            [[nodiscard]] constexpr auto operator""_nN(unsigned long long value) -> nanonewtons;
            [[nodiscard]] constexpr auto operator""_nN(long double value)
                -> basic_newton<double, nano>;
            [[nodiscard]] constexpr auto operator""_uN(unsigned long long value) -> micronewtons;
            [[nodiscard]] constexpr auto operator""_uN(long double value)
                -> basic_newton<double, micro>;
            [[nodiscard]] constexpr auto operator""_mN(unsigned long long value) -> millinewtons;
            [[nodiscard]] constexpr auto operator""_mN(long double value)
                -> basic_newton<double, milli>;
            [[nodiscard]] constexpr auto operator""_cN(unsigned long long value) -> centinewtons;
            [[nodiscard]] constexpr auto operator""_cN(long double value)
                -> basic_newton<double, centi>;
            [[nodiscard]] constexpr auto operator""_dN(unsigned long long value) -> decinewtons;
            [[nodiscard]] constexpr auto operator""_dN(long double value)
                -> basic_newton<double, deci>;
            [[nodiscard]] constexpr auto operator""_N(unsigned long long value) -> newtons;
            [[nodiscard]] constexpr auto operator""_N(long double value)
                -> basic_newton<double, ratio<1>>;
            [[nodiscard]] constexpr auto operator""_daN(unsigned long long value) -> decanewtons;
            [[nodiscard]] constexpr auto operator""_daN(long double value)
                -> basic_newton<double, deca>;
            [[nodiscard]] constexpr auto operator""_hN(unsigned long long value) -> hectonewtons;
            [[nodiscard]] constexpr auto operator""_hN(long double value)
                -> basic_newton<double, hecto>;
            [[nodiscard]] constexpr auto operator""_kN(unsigned long long value) -> kilonewtons;
            [[nodiscard]] constexpr auto operator""_kN(long double value)
                -> basic_newton<double, kilo>;
            [[nodiscard]] constexpr auto operator""_MN(unsigned long long value) -> meganewtons;
            [[nodiscard]] constexpr auto operator""_MN(long double value)
                -> basic_newton<double, mega>;
            [[nodiscard]] constexpr auto operator""_GN(unsigned long long value) -> giganewtons;
            [[nodiscard]] constexpr auto operator""_GN(long double value)
                -> basic_newton<double, giga>;
            [[nodiscard]] constexpr auto operator""_TN(unsigned long long value) -> teranewtons;
            [[nodiscard]] constexpr auto operator""_TN(long double value)
                -> basic_newton<double, tera>;
            [[nodiscard]] constexpr auto operator""_PN(unsigned long long value) -> petanewtons;
            [[nodiscard]] constexpr auto operator""_PN(long double value)
                -> basic_newton<double, peta>;
            [[nodiscard]] constexpr auto operator""_EN(unsigned long long value) -> exanewtons;
            [[nodiscard]] constexpr auto operator""_EN(long double value)
                -> basic_newton<double, exa>;

        } // namespace force_literals

    } // namespace literals

    using namespace literals::force_literals;

} // namespace posu::units::si

#include "posu/units/system/si/ipp/force.ipp"

namespace posu::units::si {

    inline namespace references {

        inline namespace force_references {

            inline constexpr auto aN  = 1_aN;
            inline constexpr auto fN  = 1_fN;
            inline constexpr auto pN  = 1_pN;
            inline constexpr auto nN  = 1_nN;
            inline constexpr auto uN  = 1_uN;
            inline constexpr auto mN  = 1_mN;
            inline constexpr auto cN  = 1_cN;
            inline constexpr auto dN  = 1_dN;
            inline constexpr auto N   = 1_N;
            inline constexpr auto daN = 1_daN;
            inline constexpr auto hN  = 1_hN;
            inline constexpr auto kN  = 1_kN;
            inline constexpr auto MN  = 1_MN;
            inline constexpr auto GN  = 1_GN;
            inline constexpr auto TN  = 1_TN;
            inline constexpr auto PN  = 1_PN;
            inline constexpr auto EN  = 1_EN;

        } // namespace force_references

    } // namespace references

} // namespace posu::units::si

#endif // #ifndef POSU_UNITS_SYSTEM_SI_FORCE_HPP
