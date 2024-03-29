#ifndef POSU_UNITS_SYSTEM_SI_ENERGY_HPP
#define POSU_UNITS_SYSTEM_SI_ENERGY_HPP

#include "posu/units/system/energy.hpp"

#include "posu/units/system/si/force.hpp"

namespace posu::units::si {

    struct energy : public posu::units::energy {
        using type      = energy;
        using kind_type = posu::units::energy;
        using period    = kilo;
    };

} // namespace posu::units::si

namespace posu::units {

    template<>
    inline constexpr bool enable_as_unit<si::energy> = true;

}

namespace posu::units::si {

    template<typename Rep, typename Period>
    using basic_joule = quantity<Rep, Period, energy>;

    using attojoules  = basic_joule<int, atto>;
    using femtojoules = basic_joule<int, femto>;
    using picojoules  = basic_joule<int, pico>;
    using nanojoules  = basic_joule<int, nano>;
    using microjoules = basic_joule<int, micro>;
    using millijoules = basic_joule<int, milli>;
    using centijoules = basic_joule<int, centi>;
    using decijoules  = basic_joule<int, deci>;
    using joules      = basic_joule<int, ratio<1>>;
    using decajoules  = basic_joule<int, deca>;
    using hectojoules = basic_joule<int, hecto>;
    using kilojoules  = basic_joule<int, kilo>;
    using megajoules  = basic_joule<int, mega>;
    using gigajoules  = basic_joule<int, giga>;
    using terajoules  = basic_joule<int, tera>;
    using petajoules  = basic_joule<int, peta>;
    using exajoules   = basic_joule<int, exa>;

    inline namespace literals {

        inline namespace energy_literals {

            [[nodiscard]] constexpr auto operator""_aJ(unsigned long long value) -> attojoules;
            [[nodiscard]] constexpr auto operator""_aJ(long double value)
                -> basic_joule<double, atto>;
            [[nodiscard]] constexpr auto operator""_fJ(unsigned long long value) -> femtojoules;
            [[nodiscard]] constexpr auto operator""_fJ(long double value)
                -> basic_joule<double, femto>;
            [[nodiscard]] constexpr auto operator""_pJ(unsigned long long value) -> picojoules;
            [[nodiscard]] constexpr auto operator""_pJ(long double value)
                -> basic_joule<double, pico>;
            [[nodiscard]] constexpr auto operator""_nJ(unsigned long long value) -> nanojoules;
            [[nodiscard]] constexpr auto operator""_nJ(long double value)
                -> basic_joule<double, nano>;
            [[nodiscard]] constexpr auto operator""_uJ(unsigned long long value) -> microjoules;
            [[nodiscard]] constexpr auto operator""_uJ(long double value)
                -> basic_joule<double, micro>;
            [[nodiscard]] constexpr auto operator""_mJ(unsigned long long value) -> millijoules;
            [[nodiscard]] constexpr auto operator""_mJ(long double value)
                -> basic_joule<double, milli>;
            [[nodiscard]] constexpr auto operator""_cJ(unsigned long long value) -> centijoules;
            [[nodiscard]] constexpr auto operator""_cJ(long double value)
                -> basic_joule<double, centi>;
            [[nodiscard]] constexpr auto operator""_dJ(unsigned long long value) -> decijoules;
            [[nodiscard]] constexpr auto operator""_dJ(long double value)
                -> basic_joule<double, deci>;
            [[nodiscard]] constexpr auto operator""_J(unsigned long long value) -> joules;
            [[nodiscard]] constexpr auto operator""_J(long double value)
                -> basic_joule<double, ratio<1>>;
            [[nodiscard]] constexpr auto operator""_daJ(unsigned long long value) -> decajoules;
            [[nodiscard]] constexpr auto operator""_daJ(long double value)
                -> basic_joule<double, deca>;
            [[nodiscard]] constexpr auto operator""_hJ(unsigned long long value) -> hectojoules;
            [[nodiscard]] constexpr auto operator""_hJ(long double value)
                -> basic_joule<double, hecto>;
            [[nodiscard]] constexpr auto operator""_kJ(unsigned long long value) -> kilojoules;
            [[nodiscard]] constexpr auto operator""_kJ(long double value)
                -> basic_joule<double, kilo>;
            [[nodiscard]] constexpr auto operator""_MJ(unsigned long long value) -> megajoules;
            [[nodiscard]] constexpr auto operator""_MJ(long double value)
                -> basic_joule<double, mega>;
            [[nodiscard]] constexpr auto operator""_GJ(unsigned long long value) -> gigajoules;
            [[nodiscard]] constexpr auto operator""_GJ(long double value)
                -> basic_joule<double, giga>;
            [[nodiscard]] constexpr auto operator""_TJ(unsigned long long value) -> terajoules;
            [[nodiscard]] constexpr auto operator""_TJ(long double value)
                -> basic_joule<double, tera>;
            [[nodiscard]] constexpr auto operator""_PJ(unsigned long long value) -> petajoules;
            [[nodiscard]] constexpr auto operator""_PJ(long double value)
                -> basic_joule<double, peta>;
            [[nodiscard]] constexpr auto operator""_EJ(unsigned long long value) -> exajoules;
            [[nodiscard]] constexpr auto operator""_EJ(long double value)
                -> basic_joule<double, exa>;

        } // namespace energy_literals

    } // namespace literals

    using namespace literals::energy_literals;

} // namespace posu::units::si

#include "posu/units/system/si/ipp/energy.ipp"

namespace posu::units::si {

    inline namespace references {

        inline namespace energy_references {

            inline constexpr auto aJ  = 1_aJ;
            inline constexpr auto fJ  = 1_fJ;
            inline constexpr auto pJ  = 1_pJ;
            inline constexpr auto nJ  = 1_nJ;
            inline constexpr auto uJ  = 1_uJ;
            inline constexpr auto mJ  = 1_mJ;
            inline constexpr auto cJ  = 1_cJ;
            inline constexpr auto dJ  = 1_dJ;
            inline constexpr auto J   = 1_J;
            inline constexpr auto daJ = 1_daJ;
            inline constexpr auto hJ  = 1_hJ;
            inline constexpr auto kJ  = 1_kJ;
            inline constexpr auto MJ  = 1_MJ;
            inline constexpr auto GJ  = 1_GJ;
            inline constexpr auto TJ  = 1_TJ;
            inline constexpr auto PJ  = 1_PJ;
            inline constexpr auto EJ  = 1_EJ;

        } // namespace energy_references

    } // namespace references

} // namespace posu::units::si

#endif // #ifndef POSU_UNITS_SYSTEM_SI_ENERGY_HPP
