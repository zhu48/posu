#ifndef POSU_UNITS_SI_AMOUNT_OF_SUBSTANCE_HPP
#define POSU_UNITS_SI_AMOUNT_OF_SUBSTANCE_HPP

#include "posu/units/base_unit.hpp"

#include "posu/units/system/amount_of_substance.hpp"

namespace posu::units::si {

    template<typename Rep, typename Period>
    using amount_of_substance = quantity<Rep, Period, posu::units::amount_of_substance>;

    using attomoles  = amount_of_substance<int, std::atto>;
    using femtomoles = amount_of_substance<int, std::femto>;
    using picomoles  = amount_of_substance<int, std::pico>;
    using nanomoles  = amount_of_substance<int, std::nano>;
    using micromoles = amount_of_substance<int, std::micro>;
    using millimoles = amount_of_substance<int, std::milli>;
    using centimoles = amount_of_substance<int, std::centi>;
    using decimoles  = amount_of_substance<int, std::deci>;
    using moles      = amount_of_substance<int, std::ratio<1>>;
    using decamoles  = amount_of_substance<int, std::deca>;
    using hectomoles = amount_of_substance<int, std::hecto>;
    using kilomoles  = amount_of_substance<int, std::kilo>;
    using megamoles  = amount_of_substance<int, std::mega>;
    using gigamoles  = amount_of_substance<int, std::giga>;
    using teramoles  = amount_of_substance<int, std::tera>;
    using petamoles  = amount_of_substance<int, std::peta>;
    using examoles   = amount_of_substance<int, std::exa>;

    inline namespace literals {

        inline namespace amount_of_substance_literals {

            [[nodiscard]] constexpr auto operator""_amol(unsigned long long value) -> attomoles;
            [[nodiscard]] constexpr auto operator""_amol(long double value)
                -> amount_of_substance<double, std::atto>;
            [[nodiscard]] constexpr auto operator""_fmol(unsigned long long value) -> femtomoles;
            [[nodiscard]] constexpr auto operator""_fmol(long double value)
                -> amount_of_substance<double, std::femto>;
            [[nodiscard]] constexpr auto operator""_pmol(unsigned long long value) -> picomoles;
            [[nodiscard]] constexpr auto operator""_pmol(long double value)
                -> amount_of_substance<double, std::pico>;
            [[nodiscard]] constexpr auto operator""_nmol(unsigned long long value) -> nanomoles;
            [[nodiscard]] constexpr auto operator""_nmol(long double value)
                -> amount_of_substance<double, std::nano>;
            [[nodiscard]] constexpr auto operator""_umol(unsigned long long value) -> micromoles;
            [[nodiscard]] constexpr auto operator""_umol(long double value)
                -> amount_of_substance<double, std::micro>;
            [[nodiscard]] constexpr auto operator""_mmol(unsigned long long value) -> millimoles;
            [[nodiscard]] constexpr auto operator""_mmol(long double value)
                -> amount_of_substance<double, std::milli>;
            [[nodiscard]] constexpr auto operator""_cmol(unsigned long long value) -> centimoles;
            [[nodiscard]] constexpr auto operator""_cmol(long double value)
                -> amount_of_substance<double, std::centi>;
            [[nodiscard]] constexpr auto operator""_dmol(unsigned long long value) -> decimoles;
            [[nodiscard]] constexpr auto operator""_dmol(long double value)
                -> amount_of_substance<double, std::deci>;
            [[nodiscard]] constexpr auto operator""_mol(unsigned long long value) -> moles;
            [[nodiscard]] constexpr auto operator""_mol(long double value)
                -> amount_of_substance<double, std::ratio<1>>;
            [[nodiscard]] constexpr auto operator""_damol(unsigned long long value) -> decamoles;
            [[nodiscard]] constexpr auto operator""_damol(long double value)
                -> amount_of_substance<double, std::deca>;
            [[nodiscard]] constexpr auto operator""_hmol(unsigned long long value) -> hectomoles;
            [[nodiscard]] constexpr auto operator""_hmol(long double value)
                -> amount_of_substance<double, std::hecto>;
            [[nodiscard]] constexpr auto operator""_kmol(unsigned long long value) -> kilomoles;
            [[nodiscard]] constexpr auto operator""_kmol(long double value)
                -> amount_of_substance<double, std::kilo>;
            [[nodiscard]] constexpr auto operator""_Mmol(unsigned long long value) -> megamoles;
            [[nodiscard]] constexpr auto operator""_Mmol(long double value)
                -> amount_of_substance<double, std::mega>;
            [[nodiscard]] constexpr auto operator""_Gmol(unsigned long long value) -> gigamoles;
            [[nodiscard]] constexpr auto operator""_Gmol(long double value)
                -> amount_of_substance<double, std::giga>;
            [[nodiscard]] constexpr auto operator""_Tmol(unsigned long long value) -> teramoles;
            [[nodiscard]] constexpr auto operator""_Tmol(long double value)
                -> amount_of_substance<double, std::tera>;
            [[nodiscard]] constexpr auto operator""_Pmol(unsigned long long value) -> petamoles;
            [[nodiscard]] constexpr auto operator""_Pmol(long double value)
                -> amount_of_substance<double, std::peta>;
            [[nodiscard]] constexpr auto operator""_Emol(unsigned long long value) -> examoles;
            [[nodiscard]] constexpr auto operator""_Emol(long double value)
                -> amount_of_substance<double, std::exa>;

        } // namespace amount_of_substance_literals

    } // namespace literals

    using namespace literals::amount_of_substance_literals;

} // namespace posu::units::si

#include "posu/units/system/si/ipp/amount_of_substance.ipp"

#endif // #ifndef POSU_UNITS_SI_AMOUNT_OF_SUBSTANCE_HPP
