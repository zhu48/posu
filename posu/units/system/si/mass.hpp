#ifndef POSU_UNITS_SI_MASS_HPP
#define POSU_UNITS_SI_MASS_HPP

#include "posu/units/base_unit.hpp"

#include "posu/units/system/mass.hpp"

namespace posu::units::si {

    struct mass : public posu::units::mass {
        using type      = mass;
        using kind_type = posu::units::mass;
    };

} // namespace posu::units::si

namespace posu::units {

    template<>
    inline constexpr bool enable_as_unit<si::mass> = true;

}

namespace posu::units::si {

    template<typename Rep, typename Period>
    using basic_gram = quantity<Rep, Period, mass>;

    using attograms  = basic_gram<int, std::atto>;
    using femtograms = basic_gram<int, std::femto>;
    using picograms  = basic_gram<int, std::pico>;
    using nanograms  = basic_gram<int, std::nano>;
    using micrograms = basic_gram<int, std::micro>;
    using milligrams = basic_gram<int, std::milli>;
    using centigrams = basic_gram<int, std::centi>;
    using decigrams  = basic_gram<int, std::deci>;
    using grams      = basic_gram<int, std::ratio<1>>;
    using decagrams  = basic_gram<int, std::deca>;
    using hectograms = basic_gram<int, std::hecto>;
    using kilograms  = basic_gram<int, std::kilo>;
    using megagrams  = basic_gram<int, std::mega>;
    using gigagrams  = basic_gram<int, std::giga>;
    using teragrams  = basic_gram<int, std::tera>;
    using petagrams  = basic_gram<int, std::peta>;
    using exagrams   = basic_gram<int, std::exa>;

    inline namespace literals {

        inline namespace mass_literals {

            [[nodiscard]] constexpr auto operator""_ag(unsigned long long value) -> attograms;
            [[nodiscard]] constexpr auto operator""_ag(long double value)
                -> basic_gram<double, std::atto>;
            [[nodiscard]] constexpr auto operator""_fg(unsigned long long value) -> femtograms;
            [[nodiscard]] constexpr auto operator""_fg(long double value)
                -> basic_gram<double, std::femto>;
            [[nodiscard]] constexpr auto operator""_pg(unsigned long long value) -> picograms;
            [[nodiscard]] constexpr auto operator""_pg(long double value)
                -> basic_gram<double, std::pico>;
            [[nodiscard]] constexpr auto operator""_ng(unsigned long long value) -> nanograms;
            [[nodiscard]] constexpr auto operator""_ng(long double value)
                -> basic_gram<double, std::nano>;
            [[nodiscard]] constexpr auto operator""_ug(unsigned long long value) -> micrograms;
            [[nodiscard]] constexpr auto operator""_ug(long double value)
                -> basic_gram<double, std::micro>;
            [[nodiscard]] constexpr auto operator""_mg(unsigned long long value) -> milligrams;
            [[nodiscard]] constexpr auto operator""_mg(long double value)
                -> basic_gram<double, std::milli>;
            [[nodiscard]] constexpr auto operator""_cg(unsigned long long value) -> centigrams;
            [[nodiscard]] constexpr auto operator""_cg(long double value)
                -> basic_gram<double, std::centi>;
            [[nodiscard]] constexpr auto operator""_dg(unsigned long long value) -> decigrams;
            [[nodiscard]] constexpr auto operator""_dg(long double value)
                -> basic_gram<double, std::deci>;
            [[nodiscard]] constexpr auto operator""_g(unsigned long long value) -> grams;
            [[nodiscard]] constexpr auto operator""_g(long double value)
                -> basic_gram<double, std::ratio<1>>;
            [[nodiscard]] constexpr auto operator""_dag(unsigned long long value) -> decagrams;
            [[nodiscard]] constexpr auto operator""_dag(long double value)
                -> basic_gram<double, std::deca>;
            [[nodiscard]] constexpr auto operator""_hg(unsigned long long value) -> hectograms;
            [[nodiscard]] constexpr auto operator""_hg(long double value)
                -> basic_gram<double, std::hecto>;
            [[nodiscard]] constexpr auto operator""_kg(unsigned long long value) -> kilograms;
            [[nodiscard]] constexpr auto operator""_kg(long double value)
                -> basic_gram<double, std::kilo>;
            [[nodiscard]] constexpr auto operator""_Mg(unsigned long long value) -> megagrams;
            [[nodiscard]] constexpr auto operator""_Mg(long double value)
                -> basic_gram<double, std::mega>;
            [[nodiscard]] constexpr auto operator""_Gg(unsigned long long value) -> gigagrams;
            [[nodiscard]] constexpr auto operator""_Gg(long double value)
                -> basic_gram<double, std::giga>;
            [[nodiscard]] constexpr auto operator""_Tg(unsigned long long value) -> teragrams;
            [[nodiscard]] constexpr auto operator""_Tg(long double value)
                -> basic_gram<double, std::tera>;
            [[nodiscard]] constexpr auto operator""_Pg(unsigned long long value) -> petagrams;
            [[nodiscard]] constexpr auto operator""_Pg(long double value)
                -> basic_gram<double, std::peta>;
            [[nodiscard]] constexpr auto operator""_Eg(unsigned long long value) -> exagrams;
            [[nodiscard]] constexpr auto operator""_Eg(long double value)
                -> basic_gram<double, std::exa>;

        } // namespace mass_literals

    } // namespace literals

    using namespace literals::mass_literals;

} // namespace posu::units::si

#include "posu/units/system/si/ipp/mass.ipp"

namespace posu::units::si {

    inline namespace references {

        inline namespace mass_references {

            inline constexpr auto ag  = 1_ag;
            inline constexpr auto fg  = 1_fg;
            inline constexpr auto pg  = 1_pg;
            inline constexpr auto ng  = 1_ng;
            inline constexpr auto ug  = 1_ug;
            inline constexpr auto mg  = 1_mg;
            inline constexpr auto cg  = 1_cg;
            inline constexpr auto dg  = 1_dg;
            inline constexpr auto g   = 1_g;
            inline constexpr auto dag = 1_dag;
            inline constexpr auto hg  = 1_hg;
            inline constexpr auto kg  = 1_kg;
            inline constexpr auto Mg  = 1_Mg;
            inline constexpr auto Gg  = 1_Gg;
            inline constexpr auto Tg  = 1_Tg;
            inline constexpr auto Pg  = 1_Pg;
            inline constexpr auto Eg  = 1_Eg;

        } // namespace mass_references

    } // namespace references

} // namespace posu::units::si

#endif // #ifndef POSU_UNITS_SI_MASS_HPP
