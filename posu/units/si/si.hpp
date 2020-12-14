#ifndef POSU_UNITS_SI_SI_HPP
#define POSU_UNITS_SI_SI_HPP

#include "posu/units/si/length.hpp"
#include "posu/units/si/time.hpp"

namespace posu::units {

    struct mass_tag {
        constexpr mass_tag() noexcept = default;
    };

    template<typename Rep, typename Period>
    using mass = base_unit<Rep, Period, mass_tag>;

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

    struct electric_current_tag {
        constexpr electric_current_tag() noexcept = default;
    };

    template<typename Rep, typename Period>
    using electric_current = base_unit<Rep, Period, electric_current_tag>;

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

    struct thermodynamic_temperature_tag {
        constexpr thermodynamic_temperature_tag() noexcept = default;
    };

    template<typename Rep, typename Period>
    using thermodynamic_temperature = base_unit<Rep, Period, thermodynamic_temperature_tag>;

    using attokelvins  = thermodynamic_temperature<int, std::atto>;
    using femtokelvins = thermodynamic_temperature<int, std::femto>;
    using picokelvins  = thermodynamic_temperature<int, std::pico>;
    using nanokelvins  = thermodynamic_temperature<int, std::nano>;
    using microkelvins = thermodynamic_temperature<int, std::micro>;
    using millikelvins = thermodynamic_temperature<int, std::milli>;
    using centikelvins = thermodynamic_temperature<int, std::centi>;
    using decikelvins  = thermodynamic_temperature<int, std::deci>;
    using kelvins      = thermodynamic_temperature<int, std::ratio<1>>;
    using decakelvins  = thermodynamic_temperature<int, std::deca>;
    using hectokelvins = thermodynamic_temperature<int, std::hecto>;
    using kilokelvins  = thermodynamic_temperature<int, std::kilo>;
    using megakelvins  = thermodynamic_temperature<int, std::mega>;
    using gigakelvins  = thermodynamic_temperature<int, std::giga>;
    using terakelvins  = thermodynamic_temperature<int, std::tera>;
    using petakelvins  = thermodynamic_temperature<int, std::peta>;
    using exakelvins   = thermodynamic_temperature<int, std::exa>;

    inline namespace literals {

        inline namespace thermodynamic_temperature_literals {

            [[nodiscard]] constexpr auto operator""_aK(unsigned long long value) -> attokelvins;
            [[nodiscard]] constexpr auto operator""_aK(long double value)
                -> thermodynamic_temperature<double, std::atto>;
            [[nodiscard]] constexpr auto operator""_fK(unsigned long long value) -> femtokelvins;
            [[nodiscard]] constexpr auto operator""_fK(long double value)
                -> thermodynamic_temperature<double, std::femto>;
            [[nodiscard]] constexpr auto operator""_pK(unsigned long long value) -> picokelvins;
            [[nodiscard]] constexpr auto operator""_pK(long double value)
                -> thermodynamic_temperature<double, std::pico>;
            [[nodiscard]] constexpr auto operator""_nK(unsigned long long value) -> nanokelvins;
            [[nodiscard]] constexpr auto operator""_nK(long double value)
                -> thermodynamic_temperature<double, std::nano>;
            [[nodiscard]] constexpr auto operator""_uK(unsigned long long value) -> microkelvins;
            [[nodiscard]] constexpr auto operator""_uK(long double value)
                -> thermodynamic_temperature<double, std::micro>;
            [[nodiscard]] constexpr auto operator""_mK(unsigned long long value) -> millikelvins;
            [[nodiscard]] constexpr auto operator""_mK(long double value)
                -> thermodynamic_temperature<double, std::milli>;
            [[nodiscard]] constexpr auto operator""_cK(unsigned long long value) -> centikelvins;
            [[nodiscard]] constexpr auto operator""_cK(long double value)
                -> thermodynamic_temperature<double, std::centi>;
            [[nodiscard]] constexpr auto operator""_dK(unsigned long long value) -> decikelvins;
            [[nodiscard]] constexpr auto operator""_dK(long double value)
                -> thermodynamic_temperature<double, std::deci>;
            [[nodiscard]] constexpr auto operator""_K(unsigned long long value) -> kelvins;
            [[nodiscard]] constexpr auto operator""_K(long double value)
                -> thermodynamic_temperature<double, std::ratio<1>>;
            [[nodiscard]] constexpr auto operator""_daK(unsigned long long value) -> decakelvins;
            [[nodiscard]] constexpr auto operator""_daK(long double value)
                -> thermodynamic_temperature<double, std::deca>;
            [[nodiscard]] constexpr auto operator""_hK(unsigned long long value) -> hectokelvins;
            [[nodiscard]] constexpr auto operator""_hK(long double value)
                -> thermodynamic_temperature<double, std::hecto>;
            [[nodiscard]] constexpr auto operator""_kK(unsigned long long value) -> kilokelvins;
            [[nodiscard]] constexpr auto operator""_kK(long double value)
                -> thermodynamic_temperature<double, std::kilo>;
            [[nodiscard]] constexpr auto operator""_MK(unsigned long long value) -> megakelvins;
            [[nodiscard]] constexpr auto operator""_MK(long double value)
                -> thermodynamic_temperature<double, std::mega>;
            [[nodiscard]] constexpr auto operator""_GK(unsigned long long value) -> gigakelvins;
            [[nodiscard]] constexpr auto operator""_GK(long double value)
                -> thermodynamic_temperature<double, std::giga>;
            [[nodiscard]] constexpr auto operator""_TK(unsigned long long value) -> terakelvins;
            [[nodiscard]] constexpr auto operator""_TK(long double value)
                -> thermodynamic_temperature<double, std::tera>;
            [[nodiscard]] constexpr auto operator""_PK(unsigned long long value) -> petakelvins;
            [[nodiscard]] constexpr auto operator""_PK(long double value)
                -> thermodynamic_temperature<double, std::peta>;
            [[nodiscard]] constexpr auto operator""_EK(unsigned long long value) -> exakelvins;
            [[nodiscard]] constexpr auto operator""_EK(long double value)
                -> thermodynamic_temperature<double, std::exa>;

        } // namespace thermodynamic_temperature_literals

    } // namespace literals

    using namespace literals::thermodynamic_temperature_literals;

    struct amount_of_substance_tag {
        constexpr amount_of_substance_tag() noexcept = default;
    };

    template<typename Rep, typename Period>
    using amount_of_substance = base_unit<Rep, Period, amount_of_substance_tag>;

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

    struct luminous_intensity_tag {
        constexpr luminous_intensity_tag() noexcept = default;
    };

    template<typename Rep, typename Period>
    using luminous_intensity = base_unit<Rep, Period, luminous_intensity_tag>;

    using attocandelas  = luminous_intensity<int, std::atto>;
    using femtocandelas = luminous_intensity<int, std::femto>;
    using picocandelas  = luminous_intensity<int, std::pico>;
    using nanocandelas  = luminous_intensity<int, std::nano>;
    using microcandelas = luminous_intensity<int, std::micro>;
    using millicandelas = luminous_intensity<int, std::milli>;
    using centicandelas = luminous_intensity<int, std::centi>;
    using decicandelas  = luminous_intensity<int, std::deci>;
    using candelas      = luminous_intensity<int, std::ratio<1>>;
    using decacandelas  = luminous_intensity<int, std::deca>;
    using hectocandelas = luminous_intensity<int, std::hecto>;
    using kilocandelas  = luminous_intensity<int, std::kilo>;
    using megacandelas  = luminous_intensity<int, std::mega>;
    using gigacandelas  = luminous_intensity<int, std::giga>;
    using teracandelas  = luminous_intensity<int, std::tera>;
    using petacandelas  = luminous_intensity<int, std::peta>;
    using exacandelas   = luminous_intensity<int, std::exa>;

    inline namespace literals {

        inline namespace luminous_intensity_literals {

            [[nodiscard]] constexpr auto operator""_acd(unsigned long long value) -> attocandelas;
            [[nodiscard]] constexpr auto operator""_acd(long double value)
                -> luminous_intensity<double, std::atto>;
            [[nodiscard]] constexpr auto operator""_fcd(unsigned long long value) -> femtocandelas;
            [[nodiscard]] constexpr auto operator""_fcd(long double value)
                -> luminous_intensity<double, std::femto>;
            [[nodiscard]] constexpr auto operator""_pcd(unsigned long long value) -> picocandelas;
            [[nodiscard]] constexpr auto operator""_pcd(long double value)
                -> luminous_intensity<double, std::pico>;
            [[nodiscard]] constexpr auto operator""_ncd(unsigned long long value) -> nanocandelas;
            [[nodiscard]] constexpr auto operator""_ncd(long double value)
                -> luminous_intensity<double, std::nano>;
            [[nodiscard]] constexpr auto operator""_ucd(unsigned long long value) -> microcandelas;
            [[nodiscard]] constexpr auto operator""_ucd(long double value)
                -> luminous_intensity<double, std::micro>;
            [[nodiscard]] constexpr auto operator""_mcd(unsigned long long value) -> millicandelas;
            [[nodiscard]] constexpr auto operator""_mcd(long double value)
                -> luminous_intensity<double, std::milli>;
            [[nodiscard]] constexpr auto operator""_ccd(unsigned long long value) -> centicandelas;
            [[nodiscard]] constexpr auto operator""_ccd(long double value)
                -> luminous_intensity<double, std::centi>;
            [[nodiscard]] constexpr auto operator""_dcd(unsigned long long value) -> decicandelas;
            [[nodiscard]] constexpr auto operator""_dcd(long double value)
                -> luminous_intensity<double, std::deci>;
            [[nodiscard]] constexpr auto operator""_cd(unsigned long long value) -> candelas;
            [[nodiscard]] constexpr auto operator""_cd(long double value)
                -> luminous_intensity<double, std::ratio<1>>;
            [[nodiscard]] constexpr auto operator""_dacd(unsigned long long value) -> decacandelas;
            [[nodiscard]] constexpr auto operator""_dacd(long double value)
                -> luminous_intensity<double, std::deca>;
            [[nodiscard]] constexpr auto operator""_hcd(unsigned long long value) -> hectocandelas;
            [[nodiscard]] constexpr auto operator""_hcd(long double value)
                -> luminous_intensity<double, std::hecto>;
            [[nodiscard]] constexpr auto operator""_kcd(unsigned long long value) -> kilocandelas;
            [[nodiscard]] constexpr auto operator""_kcd(long double value)
                -> luminous_intensity<double, std::kilo>;
            [[nodiscard]] constexpr auto operator""_Mcd(unsigned long long value) -> megacandelas;
            [[nodiscard]] constexpr auto operator""_Mcd(long double value)
                -> luminous_intensity<double, std::mega>;
            [[nodiscard]] constexpr auto operator""_Gcd(unsigned long long value) -> gigacandelas;
            [[nodiscard]] constexpr auto operator""_Gcd(long double value)
                -> luminous_intensity<double, std::giga>;
            [[nodiscard]] constexpr auto operator""_Tcd(unsigned long long value) -> teracandelas;
            [[nodiscard]] constexpr auto operator""_Tcd(long double value)
                -> luminous_intensity<double, std::tera>;
            [[nodiscard]] constexpr auto operator""_Pcd(unsigned long long value) -> petacandelas;
            [[nodiscard]] constexpr auto operator""_Pcd(long double value)
                -> luminous_intensity<double, std::peta>;
            [[nodiscard]] constexpr auto operator""_Ecd(unsigned long long value) -> exacandelas;
            [[nodiscard]] constexpr auto operator""_Ecd(long double value)
                -> luminous_intensity<double, std::exa>;

        } // namespace luminous_intensity_literals

    } // namespace literals

    using namespace literals::amount_of_substance_literals;

} // namespace posu::units

#include "posu/units/si/ipp/si.ipp"

#endif // #ifndef POSU_UNITS_SI_SI_HPP
