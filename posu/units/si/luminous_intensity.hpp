#ifndef POSU_UNITS_SI_LUMINOUS_INTENSITY_HPP
#define POSU_UNITS_SI_LUMINOUS_INTENSITY_HPP

#include "posu/units/base_unit.hpp"

namespace posu::units {

    struct luminous_intensity_tag {
        using type       = luminous_intensity_tag;
        using value_type = std::string_view;

        static constexpr auto value = std::string_view{"candela"};

        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
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

    using namespace literals::luminous_intensity_literals;

} // namespace posu::units

#include "posu/units/si/ipp/luminous_intensity.ipp"

#endif // #ifndef POSU_UNITS_SI_LUMINOUS_INTENSITY_HPP
