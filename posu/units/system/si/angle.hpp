#ifndef POSU_UNITS_SYSTEM_SI_ANGLE_HPP
#define POSU_UNITS_SYSTEM_SI_ANGLE_HPP

#include "posu/units/system/angle.hpp"

#include "posu/units/system/si/length.hpp"

namespace posu::units::si {

    struct angle : public posu::units::angle {
        using type      = angle;
        using kind_type = posu::units::angle;
        using period    = std::ratio<1>;
    };

} // namespace posu::units::si

namespace posu::units {

    template<>
    inline constexpr bool enable_as_unit<si::angle> = true;

} // namespace posu::units

namespace posu::units::si {

    template<typename Rep, typename Period>
    using basic_radian = quantity<Rep, Period, angle>;

    using attoradians  = basic_radian<int, std::atto>;
    using femtoradians = basic_radian<int, std::femto>;
    using picoradians  = basic_radian<int, std::pico>;
    using nanoradians  = basic_radian<int, std::nano>;
    using microradians = basic_radian<int, std::micro>;
    using milliradians = basic_radian<int, std::milli>;
    using centiradians = basic_radian<int, std::centi>;
    using deciradians  = basic_radian<int, std::deci>;
    using radians      = basic_radian<int, std::ratio<1>>;
    using decaradians  = basic_radian<int, std::deca>;
    using hectoradians = basic_radian<int, std::hecto>;
    using kiloradians  = basic_radian<int, std::kilo>;
    using megaradians  = basic_radian<int, std::mega>;
    using gigaradians  = basic_radian<int, std::giga>;
    using teraradians  = basic_radian<int, std::tera>;
    using petaradians  = basic_radian<int, std::peta>;
    using exaradians   = basic_radian<int, std::exa>;

    inline namespace literals {

        inline namespace angle_literals {

            [[nodiscard]] constexpr auto operator""_arad(unsigned long long value) -> attoradians;
            [[nodiscard]] constexpr auto operator""_arad(long double value)
                -> basic_radian<double, std::atto>;
            [[nodiscard]] constexpr auto operator""_frad(unsigned long long value) -> femtoradians;
            [[nodiscard]] constexpr auto operator""_frad(long double value)
                -> basic_radian<double, std::femto>;
            [[nodiscard]] constexpr auto operator""_prad(unsigned long long value) -> picoradians;
            [[nodiscard]] constexpr auto operator""_prad(long double value)
                -> basic_radian<double, std::pico>;
            [[nodiscard]] constexpr auto operator""_nrad(unsigned long long value) -> nanoradians;
            [[nodiscard]] constexpr auto operator""_nrad(long double value)
                -> basic_radian<double, std::nano>;
            [[nodiscard]] constexpr auto operator""_urad(unsigned long long value) -> microradians;
            [[nodiscard]] constexpr auto operator""_urad(long double value)
                -> basic_radian<double, std::micro>;
            [[nodiscard]] constexpr auto operator""_mrad(unsigned long long value) -> milliradians;
            [[nodiscard]] constexpr auto operator""_mrad(long double value)
                -> basic_radian<double, std::milli>;
            [[nodiscard]] constexpr auto operator""_crad(unsigned long long value) -> centiradians;
            [[nodiscard]] constexpr auto operator""_crad(long double value)
                -> basic_radian<double, std::centi>;
            [[nodiscard]] constexpr auto operator""_drad(unsigned long long value) -> deciradians;
            [[nodiscard]] constexpr auto operator""_drad(long double value)
                -> basic_radian<double, std::deci>;
            [[nodiscard]] constexpr auto operator""_rad(unsigned long long value) -> radians;
            [[nodiscard]] constexpr auto operator""_rad(long double value)
                -> basic_radian<double, std::ratio<1>>;
            [[nodiscard]] constexpr auto operator""_darad(unsigned long long value) -> decaradians;
            [[nodiscard]] constexpr auto operator""_darad(long double value)
                -> basic_radian<double, std::deca>;
            [[nodiscard]] constexpr auto operator""_hrad(unsigned long long value) -> hectoradians;
            [[nodiscard]] constexpr auto operator""_hrad(long double value)
                -> basic_radian<double, std::hecto>;
            [[nodiscard]] constexpr auto operator""_krad(unsigned long long value) -> kiloradians;
            [[nodiscard]] constexpr auto operator""_krad(long double value)
                -> basic_radian<double, std::kilo>;
            [[nodiscard]] constexpr auto operator""_Mrad(unsigned long long value) -> megaradians;
            [[nodiscard]] constexpr auto operator""_Mrad(long double value)
                -> basic_radian<double, std::mega>;
            [[nodiscard]] constexpr auto operator""_Grad(unsigned long long value) -> gigaradians;
            [[nodiscard]] constexpr auto operator""_Grad(long double value)
                -> basic_radian<double, std::giga>;
            [[nodiscard]] constexpr auto operator""_Trad(unsigned long long value) -> teraradians;
            [[nodiscard]] constexpr auto operator""_Trad(long double value)
                -> basic_radian<double, std::tera>;
            [[nodiscard]] constexpr auto operator""_Prad(unsigned long long value) -> petaradians;
            [[nodiscard]] constexpr auto operator""_Prad(long double value)
                -> basic_radian<double, std::peta>;
            [[nodiscard]] constexpr auto operator""_Erad(unsigned long long value) -> exaradians;
            [[nodiscard]] constexpr auto operator""_Erad(long double value)
                -> basic_radian<double, std::exa>;

        } // namespace angle_literals

    } // namespace literals

    using namespace literals::angle_literals;

} // namespace posu::units::si

#include "posu/units/system/si/ipp/angle.ipp"

namespace posu::units::si {

    inline namespace references {

        inline namespace angle_references {

            inline constexpr auto arad  = 1_arad;
            inline constexpr auto frad  = 1_frad;
            inline constexpr auto prad  = 1_prad;
            inline constexpr auto nrad  = 1_nrad;
            inline constexpr auto urad  = 1_urad;
            inline constexpr auto mrad  = 1_mrad;
            inline constexpr auto crad  = 1_crad;
            inline constexpr auto drad  = 1_drad;
            inline constexpr auto rad   = 1_rad;
            inline constexpr auto darad = 1_darad;
            inline constexpr auto hrad  = 1_hrad;
            inline constexpr auto krad  = 1_krad;
            inline constexpr auto Mrad  = 1_Mrad;
            inline constexpr auto Grad  = 1_Grad;
            inline constexpr auto Trad  = 1_Trad;
            inline constexpr auto Prad  = 1_Prad;
            inline constexpr auto Erad  = 1_Erad;

        } // namespace angle_references

    } // namespace references

} // namespace posu::units::si

#endif // #ifndef POSU_UNITS_SYSTEM_SI_ANGLE_HPP
