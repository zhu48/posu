#ifndef POSU_UNITS_SYSTEM_SI_SOLID_ANGLE_HPP
#define POSU_UNITS_SYSTEM_SI_SOLID_ANGLE_HPP

#include "posu/units/base_unit.hpp"

#include "posu/units/system/solid_angle.hpp"

#include "posu/units/system/si/angle.hpp"

namespace posu::units::si {

    struct solid_angle : public posu::units::solid_angle {
        using type      = solid_angle;
        using kind_type = posu::units::solid_angle;
        using period    = ratio<1>;
    };

} // namespace posu::units::si

namespace posu::units {

    template<>
    inline constexpr bool enable_as_unit<si::solid_angle> = true;

    template<>
    struct unit_multiply_result<si::angle, si::angle> {
        using type = si::solid_angle;
    };

    template<>
    struct unit_divide_result<si::solid_angle, si::angle> {
        using type = si::angle;
    };

} // namespace posu::units

namespace posu::units::si {

    template<typename Rep, typename Period>
    using basic_steradian = quantity<Rep, Period, solid_angle>;

    using attosteradians  = basic_steradian<int, atto>;
    using femtosteradians = basic_steradian<int, femto>;
    using picosteradians  = basic_steradian<int, pico>;
    using nanosteradians  = basic_steradian<int, nano>;
    using microsteradians = basic_steradian<int, micro>;
    using millisteradians = basic_steradian<int, milli>;
    using centisteradians = basic_steradian<int, centi>;
    using decisteradians  = basic_steradian<int, deci>;
    using steradians      = basic_steradian<int, ratio<1>>;
    using decasteradians  = basic_steradian<int, deca>;
    using hectosteradians = basic_steradian<int, hecto>;
    using kilosteradians  = basic_steradian<int, kilo>;
    using megasteradians  = basic_steradian<int, mega>;
    using gigasteradians  = basic_steradian<int, giga>;
    using terasteradians  = basic_steradian<int, tera>;
    using petasteradians  = basic_steradian<int, peta>;
    using exasteradians   = basic_steradian<int, exa>;

    inline namespace literals {

        inline namespace solid_angle_literals {

            [[nodiscard]] constexpr auto operator""_asr(unsigned long long value) -> attosteradians;
            [[nodiscard]] constexpr auto operator""_asr(long double value)
                -> basic_steradian<double, atto>;
            [[nodiscard]] constexpr auto operator""_fsr(unsigned long long value)
                -> femtosteradians;
            [[nodiscard]] constexpr auto operator""_fsr(long double value)
                -> basic_steradian<double, femto>;
            [[nodiscard]] constexpr auto operator""_psr(unsigned long long value) -> picosteradians;
            [[nodiscard]] constexpr auto operator""_psr(long double value)
                -> basic_steradian<double, pico>;
            [[nodiscard]] constexpr auto operator""_nsr(unsigned long long value) -> nanosteradians;
            [[nodiscard]] constexpr auto operator""_nsr(long double value)
                -> basic_steradian<double, nano>;
            [[nodiscard]] constexpr auto operator""_usr(unsigned long long value)
                -> microsteradians;
            [[nodiscard]] constexpr auto operator""_usr(long double value)
                -> basic_steradian<double, micro>;
            [[nodiscard]] constexpr auto operator""_msr(unsigned long long value)
                -> millisteradians;
            [[nodiscard]] constexpr auto operator""_msr(long double value)
                -> basic_steradian<double, milli>;
            [[nodiscard]] constexpr auto operator""_csr(unsigned long long value)
                -> centisteradians;
            [[nodiscard]] constexpr auto operator""_csr(long double value)
                -> basic_steradian<double, centi>;
            [[nodiscard]] constexpr auto operator""_dsr(unsigned long long value) -> decisteradians;
            [[nodiscard]] constexpr auto operator""_dsr(long double value)
                -> basic_steradian<double, deci>;
            [[nodiscard]] constexpr auto operator""_sr(unsigned long long value) -> steradians;
            [[nodiscard]] constexpr auto operator""_sr(long double value)
                -> basic_steradian<double, ratio<1>>;
            [[nodiscard]] constexpr auto operator""_dasr(unsigned long long value)
                -> decasteradians;
            [[nodiscard]] constexpr auto operator""_dasr(long double value)
                -> basic_steradian<double, deca>;
            [[nodiscard]] constexpr auto operator""_hsr(unsigned long long value)
                -> hectosteradians;
            [[nodiscard]] constexpr auto operator""_hsr(long double value)
                -> basic_steradian<double, hecto>;
            [[nodiscard]] constexpr auto operator""_ksr(unsigned long long value) -> kilosteradians;
            [[nodiscard]] constexpr auto operator""_ksr(long double value)
                -> basic_steradian<double, kilo>;
            [[nodiscard]] constexpr auto operator""_Msr(unsigned long long value) -> megasteradians;
            [[nodiscard]] constexpr auto operator""_Msr(long double value)
                -> basic_steradian<double, mega>;
            [[nodiscard]] constexpr auto operator""_Gsr(unsigned long long value) -> gigasteradians;
            [[nodiscard]] constexpr auto operator""_Gsr(long double value)
                -> basic_steradian<double, giga>;
            [[nodiscard]] constexpr auto operator""_Tsr(unsigned long long value) -> terasteradians;
            [[nodiscard]] constexpr auto operator""_Tsr(long double value)
                -> basic_steradian<double, tera>;
            [[nodiscard]] constexpr auto operator""_Psr(unsigned long long value) -> petasteradians;
            [[nodiscard]] constexpr auto operator""_Psr(long double value)
                -> basic_steradian<double, peta>;
            [[nodiscard]] constexpr auto operator""_Esr(unsigned long long value) -> exasteradians;
            [[nodiscard]] constexpr auto operator""_Esr(long double value)
                -> basic_steradian<double, exa>;

        } // namespace solid_angle_literals

    } // namespace literals

    using namespace literals::solid_angle_literals;

} // namespace posu::units::si

#include "posu/units/system/si/ipp/solid_angle.ipp"

namespace posu::units::si {

    inline namespace references {

        inline namespace solid_angle_references {

            inline constexpr auto asr  = 1_asr;
            inline constexpr auto fsr  = 1_fsr;
            inline constexpr auto psr  = 1_psr;
            inline constexpr auto nsr  = 1_nsr;
            inline constexpr auto usr  = 1_usr;
            inline constexpr auto msr  = 1_msr;
            inline constexpr auto csr  = 1_csr;
            inline constexpr auto dsr  = 1_dsr;
            inline constexpr auto sr   = 1_sr;
            inline constexpr auto dasr = 1_dasr;
            inline constexpr auto hsr  = 1_hsr;
            inline constexpr auto ksr  = 1_ksr;
            inline constexpr auto Msr  = 1_Msr;
            inline constexpr auto Gsr  = 1_Gsr;
            inline constexpr auto Tsr  = 1_Tsr;
            inline constexpr auto Psr  = 1_Psr;
            inline constexpr auto Esr  = 1_Esr;

        } // namespace solid_angle_references

    } // namespace references

} // namespace posu::units::si

#endif // #ifndef POSU_UNITS_SYSTEM_SI_SOLID_ANGLE_HPP
