#ifndef POSU_UNITS_SI_LUMINOUS_INTENSITY_HPP
#define POSU_UNITS_SI_LUMINOUS_INTENSITY_HPP

#include "posu/units/base_unit.hpp"

#include "posu/units/system/luminous_intensity.hpp"

namespace posu::units::si {

    struct luminous_intensity : public posu::units::luminous_intensity {
        using type      = luminous_intensity;
        using kind_type = posu::units::luminous_intensity;
        using period    = std::ratio<1>;
    };

} // namespace posu::units::si

namespace posu::units {

    template<>
    inline constexpr bool enable_as_unit<si::luminous_intensity> = true;

}

namespace posu::units::si {

    template<typename Rep, typename Period>
    using basic_candela = quantity<Rep, Period, luminous_intensity>;

    using attocandelas  = basic_candela<int, std::atto>;
    using femtocandelas = basic_candela<int, std::femto>;
    using picocandelas  = basic_candela<int, std::pico>;
    using nanocandelas  = basic_candela<int, std::nano>;
    using microcandelas = basic_candela<int, std::micro>;
    using millicandelas = basic_candela<int, std::milli>;
    using centicandelas = basic_candela<int, std::centi>;
    using decicandelas  = basic_candela<int, std::deci>;
    using candelas      = basic_candela<int, std::ratio<1>>;
    using decacandelas  = basic_candela<int, std::deca>;
    using hectocandelas = basic_candela<int, std::hecto>;
    using kilocandelas  = basic_candela<int, std::kilo>;
    using megacandelas  = basic_candela<int, std::mega>;
    using gigacandelas  = basic_candela<int, std::giga>;
    using teracandelas  = basic_candela<int, std::tera>;
    using petacandelas  = basic_candela<int, std::peta>;
    using exacandelas   = basic_candela<int, std::exa>;

    inline namespace literals {

        inline namespace luminous_intensity_literals {

            [[nodiscard]] constexpr auto operator""_acd(unsigned long long value) -> attocandelas;
            [[nodiscard]] constexpr auto operator""_acd(long double value)
                -> basic_candela<double, std::atto>;
            [[nodiscard]] constexpr auto operator""_fcd(unsigned long long value) -> femtocandelas;
            [[nodiscard]] constexpr auto operator""_fcd(long double value)
                -> basic_candela<double, std::femto>;
            [[nodiscard]] constexpr auto operator""_pcd(unsigned long long value) -> picocandelas;
            [[nodiscard]] constexpr auto operator""_pcd(long double value)
                -> basic_candela<double, std::pico>;
            [[nodiscard]] constexpr auto operator""_ncd(unsigned long long value) -> nanocandelas;
            [[nodiscard]] constexpr auto operator""_ncd(long double value)
                -> basic_candela<double, std::nano>;
            [[nodiscard]] constexpr auto operator""_ucd(unsigned long long value) -> microcandelas;
            [[nodiscard]] constexpr auto operator""_ucd(long double value)
                -> basic_candela<double, std::micro>;
            [[nodiscard]] constexpr auto operator""_mcd(unsigned long long value) -> millicandelas;
            [[nodiscard]] constexpr auto operator""_mcd(long double value)
                -> basic_candela<double, std::milli>;
            [[nodiscard]] constexpr auto operator""_ccd(unsigned long long value) -> centicandelas;
            [[nodiscard]] constexpr auto operator""_ccd(long double value)
                -> basic_candela<double, std::centi>;
            [[nodiscard]] constexpr auto operator""_dcd(unsigned long long value) -> decicandelas;
            [[nodiscard]] constexpr auto operator""_dcd(long double value)
                -> basic_candela<double, std::deci>;
            [[nodiscard]] constexpr auto operator""_cd(unsigned long long value) -> candelas;
            [[nodiscard]] constexpr auto operator""_cd(long double value)
                -> basic_candela<double, std::ratio<1>>;
            [[nodiscard]] constexpr auto operator""_dacd(unsigned long long value) -> decacandelas;
            [[nodiscard]] constexpr auto operator""_dacd(long double value)
                -> basic_candela<double, std::deca>;
            [[nodiscard]] constexpr auto operator""_hcd(unsigned long long value) -> hectocandelas;
            [[nodiscard]] constexpr auto operator""_hcd(long double value)
                -> basic_candela<double, std::hecto>;
            [[nodiscard]] constexpr auto operator""_kcd(unsigned long long value) -> kilocandelas;
            [[nodiscard]] constexpr auto operator""_kcd(long double value)
                -> basic_candela<double, std::kilo>;
            [[nodiscard]] constexpr auto operator""_Mcd(unsigned long long value) -> megacandelas;
            [[nodiscard]] constexpr auto operator""_Mcd(long double value)
                -> basic_candela<double, std::mega>;
            [[nodiscard]] constexpr auto operator""_Gcd(unsigned long long value) -> gigacandelas;
            [[nodiscard]] constexpr auto operator""_Gcd(long double value)
                -> basic_candela<double, std::giga>;
            [[nodiscard]] constexpr auto operator""_Tcd(unsigned long long value) -> teracandelas;
            [[nodiscard]] constexpr auto operator""_Tcd(long double value)
                -> basic_candela<double, std::tera>;
            [[nodiscard]] constexpr auto operator""_Pcd(unsigned long long value) -> petacandelas;
            [[nodiscard]] constexpr auto operator""_Pcd(long double value)
                -> basic_candela<double, std::peta>;
            [[nodiscard]] constexpr auto operator""_Ecd(unsigned long long value) -> exacandelas;
            [[nodiscard]] constexpr auto operator""_Ecd(long double value)
                -> basic_candela<double, std::exa>;

        } // namespace luminous_intensity_literals

    } // namespace literals

    using namespace literals::luminous_intensity_literals;

} // namespace posu::units::si

#include "posu/units/system/si/ipp/luminous_intensity.ipp"

namespace posu::units::si {

    inline namespace references {

        inline namespace luminous_intensity_references {

            inline constexpr auto acd  = 1_acd;
            inline constexpr auto fcd  = 1_fcd;
            inline constexpr auto pcd  = 1_pcd;
            inline constexpr auto ncd  = 1_ncd;
            inline constexpr auto ucd  = 1_ucd;
            inline constexpr auto mcd  = 1_mcd;
            inline constexpr auto ccd  = 1_ccd;
            inline constexpr auto dcd  = 1_dcd;
            inline constexpr auto cd   = 1_cd;
            inline constexpr auto dacd = 1_dacd;
            inline constexpr auto hcd  = 1_hcd;
            inline constexpr auto kcd  = 1_kcd;
            inline constexpr auto Mcd  = 1_Mcd;
            inline constexpr auto Gcd  = 1_Gcd;
            inline constexpr auto Tcd  = 1_Tcd;
            inline constexpr auto Pcd  = 1_Pcd;
            inline constexpr auto Ecd  = 1_Ecd;

        } // namespace luminous_intensity_references

    } // namespace references

} // namespace posu::units::si

#endif // #ifndef POSU_UNITS_SI_LUMINOUS_INTENSITY_HPP
