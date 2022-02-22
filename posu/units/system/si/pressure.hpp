#ifndef POSU_UNITS_SYSTEM_SI_PRESSURE_HPP
#define POSU_UNITS_SYSTEM_SI_PRESSURE_HPP

#include "posu/units/base_unit.hpp"

#include "posu/units/system/pressure.hpp"

#include "posu/units/system/si/force.hpp"
#include "posu/units/system/si/length.hpp"

namespace posu::units::si {

    struct pressure : public posu::units::pressure {
        using type      = pressure;
        using kind_type = posu::units::pressure;
        using period    = kilo;
    };

} // namespace posu::units::si

template<>
inline constexpr bool posu::units::enable_as_unit<posu::units::si::pressure> = true;

namespace posu::units::si {

    template<typename Rep, typename Period>
    using basic_pascal = quantity<Rep, Period, pressure>;

    using attopascals  = basic_pascal<int, atto>;
    using femtopascals = basic_pascal<int, femto>;
    using picopascals  = basic_pascal<int, pico>;
    using nanopascals  = basic_pascal<int, nano>;
    using micropascals = basic_pascal<int, micro>;
    using millipascals = basic_pascal<int, milli>;
    using centipascals = basic_pascal<int, centi>;
    using decipascals  = basic_pascal<int, deci>;
    using pascals      = basic_pascal<int, ratio<1>>;
    using decapascals  = basic_pascal<int, deca>;
    using hectopascals = basic_pascal<int, hecto>;
    using kilopascals  = basic_pascal<int, kilo>;
    using megapascals  = basic_pascal<int, mega>;
    using gigapascals  = basic_pascal<int, giga>;
    using terapascals  = basic_pascal<int, tera>;
    using petapascals  = basic_pascal<int, peta>;
    using exapascals   = basic_pascal<int, exa>;

    inline namespace literals {

        inline namespace pressure_literals {

            [[nodiscard]] constexpr auto operator""_aPa(unsigned long long value) -> attopascals;
            [[nodiscard]] constexpr auto operator""_aPa(long double value)
                -> basic_pascal<double, atto>;
            [[nodiscard]] constexpr auto operator""_fPa(unsigned long long value) -> femtopascals;
            [[nodiscard]] constexpr auto operator""_fPa(long double value)
                -> basic_pascal<double, femto>;
            [[nodiscard]] constexpr auto operator""_pPa(unsigned long long value) -> picopascals;
            [[nodiscard]] constexpr auto operator""_pPa(long double value)
                -> basic_pascal<double, pico>;
            [[nodiscard]] constexpr auto operator""_nPa(unsigned long long value) -> nanopascals;
            [[nodiscard]] constexpr auto operator""_nPa(long double value)
                -> basic_pascal<double, nano>;
            [[nodiscard]] constexpr auto operator""_uPa(unsigned long long value) -> micropascals;
            [[nodiscard]] constexpr auto operator""_uPa(long double value)
                -> basic_pascal<double, micro>;
            [[nodiscard]] constexpr auto operator""_mPa(unsigned long long value) -> millipascals;
            [[nodiscard]] constexpr auto operator""_mPa(long double value)
                -> basic_pascal<double, milli>;
            [[nodiscard]] constexpr auto operator""_cPa(unsigned long long value) -> centipascals;
            [[nodiscard]] constexpr auto operator""_cPa(long double value)
                -> basic_pascal<double, centi>;
            [[nodiscard]] constexpr auto operator""_dPa(unsigned long long value) -> decipascals;
            [[nodiscard]] constexpr auto operator""_dPa(long double value)
                -> basic_pascal<double, deci>;
            [[nodiscard]] constexpr auto operator""_Pa(unsigned long long value) -> pascals;
            [[nodiscard]] constexpr auto operator""_Pa(long double value)
                -> basic_pascal<double, ratio<1>>;
            [[nodiscard]] constexpr auto operator""_daPa(unsigned long long value) -> decapascals;
            [[nodiscard]] constexpr auto operator""_daPa(long double value)
                -> basic_pascal<double, deca>;
            [[nodiscard]] constexpr auto operator""_hPa(unsigned long long value) -> hectopascals;
            [[nodiscard]] constexpr auto operator""_hPa(long double value)
                -> basic_pascal<double, hecto>;
            [[nodiscard]] constexpr auto operator""_kPa(unsigned long long value) -> kilopascals;
            [[nodiscard]] constexpr auto operator""_kPa(long double value)
                -> basic_pascal<double, kilo>;
            [[nodiscard]] constexpr auto operator""_MPa(unsigned long long value) -> megapascals;
            [[nodiscard]] constexpr auto operator""_MPa(long double value)
                -> basic_pascal<double, mega>;
            [[nodiscard]] constexpr auto operator""_GPa(unsigned long long value) -> gigapascals;
            [[nodiscard]] constexpr auto operator""_GPa(long double value)
                -> basic_pascal<double, giga>;
            [[nodiscard]] constexpr auto operator""_TPa(unsigned long long value) -> terapascals;
            [[nodiscard]] constexpr auto operator""_TPa(long double value)
                -> basic_pascal<double, tera>;
            [[nodiscard]] constexpr auto operator""_PPa(unsigned long long value) -> petapascals;
            [[nodiscard]] constexpr auto operator""_PPa(long double value)
                -> basic_pascal<double, peta>;
            [[nodiscard]] constexpr auto operator""_EPa(unsigned long long value) -> exapascals;
            [[nodiscard]] constexpr auto operator""_EPa(long double value)
                -> basic_pascal<double, exa>;

        } // namespace pressure_literals

    } // namespace literals

    using namespace literals::pressure_literals;

} // namespace posu::units::si

#include "posu/units/system/si/ipp/pressure.ipp"

namespace posu::units::si {

    inline namespace references {

        inline namespace pressure_references {

            inline constexpr auto aPa  = 1_aPa;
            inline constexpr auto fPa  = 1_fPa;
            inline constexpr auto pPa  = 1_pPa;
            inline constexpr auto nPa  = 1_nPa;
            inline constexpr auto uPa  = 1_uPa;
            inline constexpr auto mPa  = 1_mPa;
            inline constexpr auto cPa  = 1_cPa;
            inline constexpr auto dPa  = 1_dPa;
            inline constexpr auto Pa   = 1_Pa;
            inline constexpr auto daPa = 1_daPa;
            inline constexpr auto hPa  = 1_hPa;
            inline constexpr auto kPa  = 1_kPa;
            inline constexpr auto MPa  = 1_MPa;
            inline constexpr auto GPa  = 1_GPa;
            inline constexpr auto TPa  = 1_TPa;
            inline constexpr auto PPa  = 1_PPa;
            inline constexpr auto EPa  = 1_EPa;

        } // namespace pressure_references

    } // namespace references

} // namespace posu::units::si

#endif // #ifndef POSU_UNITS_SYSTEM_SI_PRESSURE_HPP
