#ifndef POSU_UNITS_SYSTEM_SI_LUMINOUS_FLUX_HPP
#define POSU_UNITS_SYSTEM_SI_LUMINOUS_FLUX_HPP

#include "posu/units/base_unit.hpp"

#include "posu/units/system/luminous_flux.hpp"

#include "posu/units/system/si/luminous_intensity.hpp"
#include "posu/units/system/si/solid_angle.hpp"

namespace posu::units::si {

    struct luminous_flux : public posu::units::luminous_flux {
        using type      = luminous_flux;
        using kind_type = posu::units::luminous_flux;
        using period    = ratio<1>;
    };

} // namespace posu::units::si

namespace posu::units {

    template<>
    inline constexpr bool enable_as_unit<si::luminous_flux> = true;

    template<>
    struct unit_multiply_result<si::luminous_intensity, si::solid_angle> {
        using type = si::luminous_flux;
    };

    template<>
    struct unit_divide_result<si::luminous_flux, si::luminous_intensity> {
        using type = si::solid_angle;
    };

    template<>
    struct unit_divide_result<si::luminous_flux, si::solid_angle> {
        using type = si::luminous_intensity;
    };

} // namespace posu::units

namespace posu::units::si {

    template<typename Rep, typename Period>
    using basic_lumen = quantity<Rep, Period, luminous_flux>;

    using attolumens  = basic_lumen<int, atto>;
    using femtolumens = basic_lumen<int, femto>;
    using picolumens  = basic_lumen<int, pico>;
    using nanolumens  = basic_lumen<int, nano>;
    using microlumens = basic_lumen<int, micro>;
    using millilumens = basic_lumen<int, milli>;
    using centilumens = basic_lumen<int, centi>;
    using decilumens  = basic_lumen<int, deci>;
    using lumens      = basic_lumen<int, ratio<1>>;
    using decalumens  = basic_lumen<int, deca>;
    using hectolumens = basic_lumen<int, hecto>;
    using kilolumens  = basic_lumen<int, kilo>;
    using megalumens  = basic_lumen<int, mega>;
    using gigalumens  = basic_lumen<int, giga>;
    using teralumens  = basic_lumen<int, tera>;
    using petalumens  = basic_lumen<int, peta>;
    using exalumens   = basic_lumen<int, exa>;

    inline namespace literals {

        inline namespace luminous_flux_literals {

            [[nodiscard]] constexpr auto operator""_alm(unsigned long long value) -> attolumens;
            [[nodiscard]] constexpr auto operator""_alm(long double value)
                -> basic_lumen<double, atto>;
            [[nodiscard]] constexpr auto operator""_flm(unsigned long long value) -> femtolumens;
            [[nodiscard]] constexpr auto operator""_flm(long double value)
                -> basic_lumen<double, femto>;
            [[nodiscard]] constexpr auto operator""_plm(unsigned long long value) -> picolumens;
            [[nodiscard]] constexpr auto operator""_plm(long double value)
                -> basic_lumen<double, pico>;
            [[nodiscard]] constexpr auto operator""_nlm(unsigned long long value) -> nanolumens;
            [[nodiscard]] constexpr auto operator""_nlm(long double value)
                -> basic_lumen<double, nano>;
            [[nodiscard]] constexpr auto operator""_ulm(unsigned long long value) -> microlumens;
            [[nodiscard]] constexpr auto operator""_ulm(long double value)
                -> basic_lumen<double, micro>;
            [[nodiscard]] constexpr auto operator""_mlm(unsigned long long value) -> millilumens;
            [[nodiscard]] constexpr auto operator""_mlm(long double value)
                -> basic_lumen<double, milli>;
            [[nodiscard]] constexpr auto operator""_clm(unsigned long long value) -> centilumens;
            [[nodiscard]] constexpr auto operator""_clm(long double value)
                -> basic_lumen<double, centi>;
            [[nodiscard]] constexpr auto operator""_dlm(unsigned long long value) -> decilumens;
            [[nodiscard]] constexpr auto operator""_dlm(long double value)
                -> basic_lumen<double, deci>;
            [[nodiscard]] constexpr auto operator""_lm(unsigned long long value) -> lumens;
            [[nodiscard]] constexpr auto operator""_lm(long double value)
                -> basic_lumen<double, ratio<1>>;
            [[nodiscard]] constexpr auto operator""_dalm(unsigned long long value) -> decalumens;
            [[nodiscard]] constexpr auto operator""_dalm(long double value)
                -> basic_lumen<double, deca>;
            [[nodiscard]] constexpr auto operator""_hlm(unsigned long long value) -> hectolumens;
            [[nodiscard]] constexpr auto operator""_hlm(long double value)
                -> basic_lumen<double, hecto>;
            [[nodiscard]] constexpr auto operator""_klm(unsigned long long value) -> kilolumens;
            [[nodiscard]] constexpr auto operator""_klm(long double value)
                -> basic_lumen<double, kilo>;
            [[nodiscard]] constexpr auto operator""_Mlm(unsigned long long value) -> megalumens;
            [[nodiscard]] constexpr auto operator""_Mlm(long double value)
                -> basic_lumen<double, mega>;
            [[nodiscard]] constexpr auto operator""_Glm(unsigned long long value) -> gigalumens;
            [[nodiscard]] constexpr auto operator""_Glm(long double value)
                -> basic_lumen<double, giga>;
            [[nodiscard]] constexpr auto operator""_Tlm(unsigned long long value) -> teralumens;
            [[nodiscard]] constexpr auto operator""_Tlm(long double value)
                -> basic_lumen<double, tera>;
            [[nodiscard]] constexpr auto operator""_Plm(unsigned long long value) -> petalumens;
            [[nodiscard]] constexpr auto operator""_Plm(long double value)
                -> basic_lumen<double, peta>;
            [[nodiscard]] constexpr auto operator""_Elm(unsigned long long value) -> exalumens;
            [[nodiscard]] constexpr auto operator""_Elm(long double value)
                -> basic_lumen<double, exa>;

        } // namespace luminous_flux_literals

    } // namespace literals

    using namespace literals::luminous_flux_literals;

} // namespace posu::units::si

#include "posu/units/system/si/ipp/luminous_flux.ipp"

namespace posu::units::si {

    inline namespace references {

        inline namespace luminous_flux_references {

            inline constexpr auto alm  = 1_alm;
            inline constexpr auto flm  = 1_flm;
            inline constexpr auto plm  = 1_plm;
            inline constexpr auto nlm  = 1_nlm;
            inline constexpr auto ulm  = 1_ulm;
            inline constexpr auto mlm  = 1_mlm;
            inline constexpr auto clm  = 1_clm;
            inline constexpr auto dlm  = 1_dlm;
            inline constexpr auto lm   = 1_lm;
            inline constexpr auto dalm = 1_dalm;
            inline constexpr auto hlm  = 1_hlm;
            inline constexpr auto klm  = 1_klm;
            inline constexpr auto Mlm  = 1_Mlm;
            inline constexpr auto Glm  = 1_Glm;
            inline constexpr auto Tlm  = 1_Tlm;
            inline constexpr auto Plm  = 1_Plm;
            inline constexpr auto Elm  = 1_Elm;

        } // namespace luminous_flux_references

    } // namespace references

} // namespace posu::units::si

#endif // #ifndef POSU_UNITS_SYSTEM_SI_LUMINOUS_FLUX_HPP
