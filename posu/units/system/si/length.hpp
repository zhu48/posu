#ifndef POSU_UNITS_SI_LENGTH_HPP
#define POSU_UNITS_SI_LENGTH_HPP

#include "posu/units/base_unit.hpp"

#include "posu/units/system/length.hpp"

namespace posu::units::si {

    struct length : public posu::units::length {
        using type      = length;
        using kind_type = posu::units::length;
        using period    = std::ratio<1>;
    };

} // namespace posu::units::si

namespace posu::units {

    template<>
    inline constexpr bool enable_as_unit<si::length> = true;

}

namespace posu::units::si {

    template<typename Rep, typename Period>
    using basic_meter = quantity<Rep, Period, length>;

    using attometers  = basic_meter<int, std::atto>;
    using femtometers = basic_meter<int, std::femto>;
    using picometers  = basic_meter<int, std::pico>;
    using nanometers  = basic_meter<int, std::nano>;
    using micrometers = basic_meter<int, std::micro>;
    using millimeters = basic_meter<int, std::milli>;
    using centimeters = basic_meter<int, std::centi>;
    using decimeters  = basic_meter<int, std::deci>;
    using meters      = basic_meter<int, std::ratio<1>>;
    using decameters  = basic_meter<int, std::deca>;
    using hectometers = basic_meter<int, std::hecto>;
    using kilometers  = basic_meter<int, std::kilo>;
    using megameters  = basic_meter<int, std::mega>;
    using gigameters  = basic_meter<int, std::giga>;
    using terameters  = basic_meter<int, std::tera>;
    using petameters  = basic_meter<int, std::peta>;
    using exameters   = basic_meter<int, std::exa>;

    inline namespace literals {

        inline namespace length_literals {

            [[nodiscard]] constexpr auto operator""_am(unsigned long long value) -> attometers;
            [[nodiscard]] constexpr auto operator""_am(long double value)
                -> basic_meter<double, std::atto>;
            [[nodiscard]] constexpr auto operator""_fm(unsigned long long value) -> femtometers;
            [[nodiscard]] constexpr auto operator""_fm(long double value)
                -> basic_meter<double, std::femto>;
            [[nodiscard]] constexpr auto operator""_pm(unsigned long long value) -> picometers;
            [[nodiscard]] constexpr auto operator""_pm(long double value)
                -> basic_meter<double, std::pico>;
            [[nodiscard]] constexpr auto operator""_nm(unsigned long long value) -> nanometers;
            [[nodiscard]] constexpr auto operator""_nm(long double value)
                -> basic_meter<double, std::nano>;
            [[nodiscard]] constexpr auto operator""_um(unsigned long long value) -> micrometers;
            [[nodiscard]] constexpr auto operator""_um(long double value)
                -> basic_meter<double, std::micro>;
            [[nodiscard]] constexpr auto operator""_mm(unsigned long long value) -> millimeters;
            [[nodiscard]] constexpr auto operator""_mm(long double value)
                -> basic_meter<double, std::milli>;
            [[nodiscard]] constexpr auto operator""_cm(unsigned long long value) -> centimeters;
            [[nodiscard]] constexpr auto operator""_cm(long double value)
                -> basic_meter<double, std::centi>;
            [[nodiscard]] constexpr auto operator""_dm(unsigned long long value) -> decimeters;
            [[nodiscard]] constexpr auto operator""_dm(long double value)
                -> basic_meter<double, std::deci>;
            [[nodiscard]] constexpr auto operator""_m(unsigned long long value) -> meters;
            [[nodiscard]] constexpr auto operator""_m(long double value)
                -> basic_meter<double, std::ratio<1>>;
            [[nodiscard]] constexpr auto operator""_dam(unsigned long long value) -> decameters;
            [[nodiscard]] constexpr auto operator""_dam(long double value)
                -> basic_meter<double, std::deca>;
            [[nodiscard]] constexpr auto operator""_hm(unsigned long long value) -> hectometers;
            [[nodiscard]] constexpr auto operator""_hm(long double value)
                -> basic_meter<double, std::hecto>;
            [[nodiscard]] constexpr auto operator""_km(unsigned long long value) -> kilometers;
            [[nodiscard]] constexpr auto operator""_km(long double value)
                -> basic_meter<double, std::kilo>;
            [[nodiscard]] constexpr auto operator""_Mm(unsigned long long value) -> megameters;
            [[nodiscard]] constexpr auto operator""_Mm(long double value)
                -> basic_meter<double, std::mega>;
            [[nodiscard]] constexpr auto operator""_Gm(unsigned long long value) -> gigameters;
            [[nodiscard]] constexpr auto operator""_Gm(long double value)
                -> basic_meter<double, std::giga>;
            [[nodiscard]] constexpr auto operator""_Tm(unsigned long long value) -> terameters;
            [[nodiscard]] constexpr auto operator""_Tm(long double value)
                -> basic_meter<double, std::tera>;
            [[nodiscard]] constexpr auto operator""_Pm(unsigned long long value) -> petameters;
            [[nodiscard]] constexpr auto operator""_Pm(long double value)
                -> basic_meter<double, std::peta>;
            [[nodiscard]] constexpr auto operator""_Em(unsigned long long value) -> exameters;
            [[nodiscard]] constexpr auto operator""_Em(long double value)
                -> basic_meter<double, std::exa>;

        } // namespace length_literals

    } // namespace literals

    using namespace literals::length_literals;

} // namespace posu::units::si

#include "posu/units/system/si/ipp/length.ipp"

namespace posu::units::si {

    inline namespace references {

        inline namespace length_references {

            inline constexpr auto am  = 1_am;
            inline constexpr auto fm  = 1_fm;
            inline constexpr auto pm  = 1_pm;
            inline constexpr auto nm  = 1_nm;
            inline constexpr auto um  = 1_um;
            inline constexpr auto mm  = 1_mm;
            inline constexpr auto cm  = 1_cm;
            inline constexpr auto dm  = 1_dm;
            inline constexpr auto m   = 1_m;
            inline constexpr auto dam = 1_dam;
            inline constexpr auto hm  = 1_hm;
            inline constexpr auto km  = 1_km;
            inline constexpr auto Mm  = 1_Mm;
            inline constexpr auto Gm  = 1_Gm;
            inline constexpr auto Tm  = 1_Tm;
            inline constexpr auto Pm  = 1_Pm;
            inline constexpr auto Em  = 1_Em;

        } // namespace length_references

    } // namespace references

} // namespace posu::units::si

#endif // #ifndef POSU_UNITS_SI_LENGTH_HPP
