#ifndef POSU_UNITS_SYSTEM_SI_ANGLE_HPP
#define POSU_UNITS_SYSTEM_SI_ANGLE_HPP

#include "posu/units/system/angle.hpp"

#include "posu/units/system/si/length.hpp"

namespace posu::units::si {

    struct angle : public posu::units::angle {
        using type      = angle;
        using kind_type = posu::units::angle;
        using period    = ratio<1>;
    };

} // namespace posu::units::si

namespace posu::units {

    template<>
    inline constexpr bool enable_as_unit<si::angle> = true;

} // namespace posu::units

namespace posu::units::si {

    template<typename Rep, typename Period>
    using basic_radian = quantity<Rep, Period, angle>;

    using attoradians  = basic_radian<int, atto>;
    using femtoradians = basic_radian<int, femto>;
    using picoradians  = basic_radian<int, pico>;
    using nanoradians  = basic_radian<int, nano>;
    using microradians = basic_radian<int, micro>;
    using milliradians = basic_radian<int, milli>;
    using centiradians = basic_radian<int, centi>;
    using deciradians  = basic_radian<int, deci>;
    using radians      = basic_radian<int, ratio<1>>;
    using decaradians  = basic_radian<int, deca>;
    using hectoradians = basic_radian<int, hecto>;
    using kiloradians  = basic_radian<int, kilo>;
    using megaradians  = basic_radian<int, mega>;
    using gigaradians  = basic_radian<int, giga>;
    using teraradians  = basic_radian<int, tera>;
    using petaradians  = basic_radian<int, peta>;
    using exaradians   = basic_radian<int, exa>;

    inline namespace literals {

        inline namespace angle_literals {

            [[nodiscard]] constexpr auto operator""_arad(unsigned long long value) -> attoradians;
            [[nodiscard]] constexpr auto operator""_arad(long double value)
                -> basic_radian<double, atto>;
            [[nodiscard]] constexpr auto operator""_frad(unsigned long long value) -> femtoradians;
            [[nodiscard]] constexpr auto operator""_frad(long double value)
                -> basic_radian<double, femto>;
            [[nodiscard]] constexpr auto operator""_prad(unsigned long long value) -> picoradians;
            [[nodiscard]] constexpr auto operator""_prad(long double value)
                -> basic_radian<double, pico>;
            [[nodiscard]] constexpr auto operator""_nrad(unsigned long long value) -> nanoradians;
            [[nodiscard]] constexpr auto operator""_nrad(long double value)
                -> basic_radian<double, nano>;
            [[nodiscard]] constexpr auto operator""_urad(unsigned long long value) -> microradians;
            [[nodiscard]] constexpr auto operator""_urad(long double value)
                -> basic_radian<double, micro>;
            [[nodiscard]] constexpr auto operator""_mrad(unsigned long long value) -> milliradians;
            [[nodiscard]] constexpr auto operator""_mrad(long double value)
                -> basic_radian<double, milli>;
            [[nodiscard]] constexpr auto operator""_crad(unsigned long long value) -> centiradians;
            [[nodiscard]] constexpr auto operator""_crad(long double value)
                -> basic_radian<double, centi>;
            [[nodiscard]] constexpr auto operator""_drad(unsigned long long value) -> deciradians;
            [[nodiscard]] constexpr auto operator""_drad(long double value)
                -> basic_radian<double, deci>;
            [[nodiscard]] constexpr auto operator""_rad(unsigned long long value) -> radians;
            [[nodiscard]] constexpr auto operator""_rad(long double value)
                -> basic_radian<double, ratio<1>>;
            [[nodiscard]] constexpr auto operator""_darad(unsigned long long value) -> decaradians;
            [[nodiscard]] constexpr auto operator""_darad(long double value)
                -> basic_radian<double, deca>;
            [[nodiscard]] constexpr auto operator""_hrad(unsigned long long value) -> hectoradians;
            [[nodiscard]] constexpr auto operator""_hrad(long double value)
                -> basic_radian<double, hecto>;
            [[nodiscard]] constexpr auto operator""_krad(unsigned long long value) -> kiloradians;
            [[nodiscard]] constexpr auto operator""_krad(long double value)
                -> basic_radian<double, kilo>;
            [[nodiscard]] constexpr auto operator""_Mrad(unsigned long long value) -> megaradians;
            [[nodiscard]] constexpr auto operator""_Mrad(long double value)
                -> basic_radian<double, mega>;
            [[nodiscard]] constexpr auto operator""_Grad(unsigned long long value) -> gigaradians;
            [[nodiscard]] constexpr auto operator""_Grad(long double value)
                -> basic_radian<double, giga>;
            [[nodiscard]] constexpr auto operator""_Trad(unsigned long long value) -> teraradians;
            [[nodiscard]] constexpr auto operator""_Trad(long double value)
                -> basic_radian<double, tera>;
            [[nodiscard]] constexpr auto operator""_Prad(unsigned long long value) -> petaradians;
            [[nodiscard]] constexpr auto operator""_Prad(long double value)
                -> basic_radian<double, peta>;
            [[nodiscard]] constexpr auto operator""_Erad(unsigned long long value) -> exaradians;
            [[nodiscard]] constexpr auto operator""_Erad(long double value)
                -> basic_radian<double, exa>;

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
