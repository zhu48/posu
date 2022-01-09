#ifndef POSU_UNITS_SI_AMOUNT_OF_SUBSTANCE_HPP
#define POSU_UNITS_SI_AMOUNT_OF_SUBSTANCE_HPP

#include "posu/units/base_unit.hpp"

#include "posu/units/system/amount_of_substance.hpp"

namespace posu::units::si {

    struct amount_of_substance : public posu::units::amount_of_substance {
        using type      = amount_of_substance;
        using kind_type = posu::units::amount_of_substance;
        using period    = ratio<1>;
    };

} // namespace posu::units::si

namespace posu::units {

    template<>
    inline constexpr bool enable_as_unit<si::amount_of_substance> = true;

}

namespace posu::units::si {

    template<typename Rep, typename Period>
    using basic_mole = quantity<Rep, Period, amount_of_substance>;

    using attomoles  = basic_mole<int, atto>;
    using femtomoles = basic_mole<int, femto>;
    using picomoles  = basic_mole<int, pico>;
    using nanomoles  = basic_mole<int, nano>;
    using micromoles = basic_mole<int, micro>;
    using millimoles = basic_mole<int, milli>;
    using centimoles = basic_mole<int, centi>;
    using decimoles  = basic_mole<int, deci>;
    using moles      = basic_mole<int, ratio<1>>;
    using decamoles  = basic_mole<int, deca>;
    using hectomoles = basic_mole<int, hecto>;
    using kilomoles  = basic_mole<int, kilo>;
    using megamoles  = basic_mole<int, mega>;
    using gigamoles  = basic_mole<int, giga>;
    using teramoles  = basic_mole<int, tera>;
    using petamoles  = basic_mole<int, peta>;
    using examoles   = basic_mole<int, exa>;

    inline namespace literals {

        inline namespace amount_of_substance_literals {

            [[nodiscard]] constexpr auto operator""_amol(unsigned long long value) -> attomoles;
            [[nodiscard]] constexpr auto operator""_amol(long double value)
                -> basic_mole<double, atto>;
            [[nodiscard]] constexpr auto operator""_fmol(unsigned long long value) -> femtomoles;
            [[nodiscard]] constexpr auto operator""_fmol(long double value)
                -> basic_mole<double, femto>;
            [[nodiscard]] constexpr auto operator""_pmol(unsigned long long value) -> picomoles;
            [[nodiscard]] constexpr auto operator""_pmol(long double value)
                -> basic_mole<double, pico>;
            [[nodiscard]] constexpr auto operator""_nmol(unsigned long long value) -> nanomoles;
            [[nodiscard]] constexpr auto operator""_nmol(long double value)
                -> basic_mole<double, nano>;
            [[nodiscard]] constexpr auto operator""_umol(unsigned long long value) -> micromoles;
            [[nodiscard]] constexpr auto operator""_umol(long double value)
                -> basic_mole<double, micro>;
            [[nodiscard]] constexpr auto operator""_mmol(unsigned long long value) -> millimoles;
            [[nodiscard]] constexpr auto operator""_mmol(long double value)
                -> basic_mole<double, milli>;
            [[nodiscard]] constexpr auto operator""_cmol(unsigned long long value) -> centimoles;
            [[nodiscard]] constexpr auto operator""_cmol(long double value)
                -> basic_mole<double, centi>;
            [[nodiscard]] constexpr auto operator""_dmol(unsigned long long value) -> decimoles;
            [[nodiscard]] constexpr auto operator""_dmol(long double value)
                -> basic_mole<double, deci>;
            [[nodiscard]] constexpr auto operator""_mol(unsigned long long value) -> moles;
            [[nodiscard]] constexpr auto operator""_mol(long double value)
                -> basic_mole<double, ratio<1>>;
            [[nodiscard]] constexpr auto operator""_damol(unsigned long long value) -> decamoles;
            [[nodiscard]] constexpr auto operator""_damol(long double value)
                -> basic_mole<double, deca>;
            [[nodiscard]] constexpr auto operator""_hmol(unsigned long long value) -> hectomoles;
            [[nodiscard]] constexpr auto operator""_hmol(long double value)
                -> basic_mole<double, hecto>;
            [[nodiscard]] constexpr auto operator""_kmol(unsigned long long value) -> kilomoles;
            [[nodiscard]] constexpr auto operator""_kmol(long double value)
                -> basic_mole<double, kilo>;
            [[nodiscard]] constexpr auto operator""_Mmol(unsigned long long value) -> megamoles;
            [[nodiscard]] constexpr auto operator""_Mmol(long double value)
                -> basic_mole<double, mega>;
            [[nodiscard]] constexpr auto operator""_Gmol(unsigned long long value) -> gigamoles;
            [[nodiscard]] constexpr auto operator""_Gmol(long double value)
                -> basic_mole<double, giga>;
            [[nodiscard]] constexpr auto operator""_Tmol(unsigned long long value) -> teramoles;
            [[nodiscard]] constexpr auto operator""_Tmol(long double value)
                -> basic_mole<double, tera>;
            [[nodiscard]] constexpr auto operator""_Pmol(unsigned long long value) -> petamoles;
            [[nodiscard]] constexpr auto operator""_Pmol(long double value)
                -> basic_mole<double, peta>;
            [[nodiscard]] constexpr auto operator""_Emol(unsigned long long value) -> examoles;
            [[nodiscard]] constexpr auto operator""_Emol(long double value)
                -> basic_mole<double, exa>;

        } // namespace amount_of_substance_literals

    } // namespace literals

    using namespace literals::amount_of_substance_literals;

} // namespace posu::units::si

#include "posu/units/system/si/ipp/amount_of_substance.ipp"

namespace posu::units::si {

    inline namespace references {

        inline namespace amount_of_substance_references {

            inline constexpr auto amol  = 1_amol;
            inline constexpr auto fmol  = 1_fmol;
            inline constexpr auto pmol  = 1_pmol;
            inline constexpr auto nmol  = 1_nmol;
            inline constexpr auto umol  = 1_umol;
            inline constexpr auto mmol  = 1_mmol;
            inline constexpr auto cmol  = 1_cmol;
            inline constexpr auto dmol  = 1_dmol;
            inline constexpr auto mol   = 1_mol;
            inline constexpr auto damol = 1_damol;
            inline constexpr auto hmol  = 1_hmol;
            inline constexpr auto kmol  = 1_kmol;
            inline constexpr auto Mmol  = 1_Mmol;
            inline constexpr auto Gmol  = 1_Gmol;
            inline constexpr auto Tmol  = 1_Tmol;
            inline constexpr auto Pmol  = 1_Pmol;
            inline constexpr auto Emol  = 1_Emol;

        } // namespace amount_of_substance_references

    } // namespace references

} // namespace posu::units::si

#endif // #ifndef POSU_UNITS_SI_AMOUNT_OF_SUBSTANCE_HPP
