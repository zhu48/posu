#ifndef POSU_UNITS_SI_MASS_HPP
#define POSU_UNITS_SI_MASS_HPP

#include "posu/units/base_unit.hpp"
#include "posu/units/system/mass.hpp"

namespace posu::units::si {

    template<typename Rep, typename Period>
    using mass = quantity<Rep, Period, posu::units::mass>;

    using attograms  = mass<int, std::atto>;
    using femtograms = mass<int, std::femto>;
    using picograms  = mass<int, std::pico>;
    using nanograms  = mass<int, std::nano>;
    using micrograms = mass<int, std::micro>;
    using milligrams = mass<int, std::milli>;
    using centigrams = mass<int, std::centi>;
    using decigrams  = mass<int, std::deci>;
    using grams      = mass<int, std::ratio<1>>;
    using decagrams  = mass<int, std::deca>;
    using hectograms = mass<int, std::hecto>;
    using kilograms  = mass<int, std::kilo>;
    using megagrams  = mass<int, std::mega>;
    using gigagrams  = mass<int, std::giga>;
    using teragrams  = mass<int, std::tera>;
    using petagrams  = mass<int, std::peta>;
    using exagrams   = mass<int, std::exa>;

    inline namespace literals {

        inline namespace mass_literals {

            [[nodiscard]] constexpr auto operator""_ag(unsigned long long value) -> attograms;
            [[nodiscard]] constexpr auto operator""_ag(long double value)
                -> mass<double, std::atto>;
            [[nodiscard]] constexpr auto operator""_fg(unsigned long long value) -> femtograms;
            [[nodiscard]] constexpr auto operator""_fg(long double value)
                -> mass<double, std::femto>;
            [[nodiscard]] constexpr auto operator""_pg(unsigned long long value) -> picograms;
            [[nodiscard]] constexpr auto operator""_pg(long double value)
                -> mass<double, std::pico>;
            [[nodiscard]] constexpr auto operator""_ng(unsigned long long value) -> nanograms;
            [[nodiscard]] constexpr auto operator""_ng(long double value)
                -> mass<double, std::nano>;
            [[nodiscard]] constexpr auto operator""_ug(unsigned long long value) -> micrograms;
            [[nodiscard]] constexpr auto operator""_ug(long double value)
                -> mass<double, std::micro>;
            [[nodiscard]] constexpr auto operator""_mg(unsigned long long value) -> milligrams;
            [[nodiscard]] constexpr auto operator""_mg(long double value)
                -> mass<double, std::milli>;
            [[nodiscard]] constexpr auto operator""_cg(unsigned long long value) -> centigrams;
            [[nodiscard]] constexpr auto operator""_cg(long double value)
                -> mass<double, std::centi>;
            [[nodiscard]] constexpr auto operator""_dg(unsigned long long value) -> decigrams;
            [[nodiscard]] constexpr auto operator""_dg(long double value)
                -> mass<double, std::deci>;
            [[nodiscard]] constexpr auto operator""_g(unsigned long long value) -> grams;
            [[nodiscard]] constexpr auto operator""_g(long double value)
                -> mass<double, std::ratio<1>>;
            [[nodiscard]] constexpr auto operator""_dag(unsigned long long value) -> decagrams;
            [[nodiscard]] constexpr auto operator""_dag(long double value)
                -> mass<double, std::deca>;
            [[nodiscard]] constexpr auto operator""_hg(unsigned long long value) -> hectograms;
            [[nodiscard]] constexpr auto operator""_hg(long double value)
                -> mass<double, std::hecto>;
            [[nodiscard]] constexpr auto operator""_kg(unsigned long long value) -> kilograms;
            [[nodiscard]] constexpr auto operator""_kg(long double value)
                -> mass<double, std::kilo>;
            [[nodiscard]] constexpr auto operator""_Mg(unsigned long long value) -> megagrams;
            [[nodiscard]] constexpr auto operator""_Mg(long double value)
                -> mass<double, std::mega>;
            [[nodiscard]] constexpr auto operator""_Gg(unsigned long long value) -> gigagrams;
            [[nodiscard]] constexpr auto operator""_Gg(long double value)
                -> mass<double, std::giga>;
            [[nodiscard]] constexpr auto operator""_Tg(unsigned long long value) -> teragrams;
            [[nodiscard]] constexpr auto operator""_Tg(long double value)
                -> mass<double, std::tera>;
            [[nodiscard]] constexpr auto operator""_Pg(unsigned long long value) -> petagrams;
            [[nodiscard]] constexpr auto operator""_Pg(long double value)
                -> mass<double, std::peta>;
            [[nodiscard]] constexpr auto operator""_Eg(unsigned long long value) -> exagrams;
            [[nodiscard]] constexpr auto operator""_Eg(long double value) -> mass<double, std::exa>;

        } // namespace mass_literals

    } // namespace literals

    using namespace literals::mass_literals;

} // namespace posu::units::si

#include "posu/units/si/ipp/mass.ipp"

#endif // #ifndef POSU_UNITS_SI_MASS_HPP
