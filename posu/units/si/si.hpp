#ifndef POSU_UNITS_SI_SI_HPP
#define POSU_UNITS_SI_SI_HPP

#include "posu/units/si/electric_current.hpp"
#include "posu/units/si/length.hpp"
#include "posu/units/si/mass.hpp"
#include "posu/units/si/time.hpp"

namespace posu::units {

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
