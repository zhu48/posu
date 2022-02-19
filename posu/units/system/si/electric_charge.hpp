#ifndef POSU_UNITS_SYSTEM_SI_ELECTRIC_CHARGE_HPP
#define POSU_UNITS_SYSTEM_SI_ELECTRIC_CHARGE_HPP

#include "posu/units/system/electric_charge.hpp"

#include "posu/units/system/si/electric_current.hpp"
#include "posu/units/system/si/time.hpp"

namespace posu::units::si {

    struct electric_charge : public posu::units::electric_charge {
        using type      = electric_charge;
        using kind_type = posu::units::electric_charge;
        using period    = ratio<1>;
    };

} // namespace posu::units::si

namespace posu::units {

    template<>
    inline constexpr bool enable_as_unit<si::electric_charge> = true;

} // namespace posu::units

namespace posu::units::si {

    template<typename Rep, typename Period>
    using basic_coulomb = quantity<Rep, Period, electric_charge>;

    using attocoulombs  = basic_coulomb<int, atto>;
    using femtocoulombs = basic_coulomb<int, femto>;
    using picocoulombs  = basic_coulomb<int, pico>;
    using nanocoulombs  = basic_coulomb<int, nano>;
    using microcoulombs = basic_coulomb<int, micro>;
    using millicoulombs = basic_coulomb<int, milli>;
    using centicoulombs = basic_coulomb<int, centi>;
    using decicoulombs  = basic_coulomb<int, deci>;
    using coulombs      = basic_coulomb<int, ratio<1>>;
    using decacoulombs  = basic_coulomb<int, deca>;
    using hectocoulombs = basic_coulomb<int, hecto>;
    using kilocoulombs  = basic_coulomb<int, kilo>;
    using megacoulombs  = basic_coulomb<int, mega>;
    using gigacoulombs  = basic_coulomb<int, giga>;
    using teracoulombs  = basic_coulomb<int, tera>;
    using petacoulombs  = basic_coulomb<int, peta>;
    using exacoulombs   = basic_coulomb<int, exa>;

    inline namespace literals {

        inline namespace electric_charge_literals {

            [[nodiscard]] constexpr auto operator""_aC(unsigned long long value) -> attocoulombs;
            [[nodiscard]] constexpr auto operator""_aC(long double value)
                -> basic_coulomb<double, atto>;
            [[nodiscard]] constexpr auto operator""_fC(unsigned long long value) -> femtocoulombs;
            [[nodiscard]] constexpr auto operator""_fC(long double value)
                -> basic_coulomb<double, femto>;
            [[nodiscard]] constexpr auto operator""_pC(unsigned long long value) -> picocoulombs;
            [[nodiscard]] constexpr auto operator""_pC(long double value)
                -> basic_coulomb<double, pico>;
            [[nodiscard]] constexpr auto operator""_nC(unsigned long long value) -> nanocoulombs;
            [[nodiscard]] constexpr auto operator""_nC(long double value)
                -> basic_coulomb<double, nano>;
            [[nodiscard]] constexpr auto operator""_uC(unsigned long long value) -> microcoulombs;
            [[nodiscard]] constexpr auto operator""_uC(long double value)
                -> basic_coulomb<double, micro>;
            [[nodiscard]] constexpr auto operator""_mC(unsigned long long value) -> millicoulombs;
            [[nodiscard]] constexpr auto operator""_mC(long double value)
                -> basic_coulomb<double, milli>;
            [[nodiscard]] constexpr auto operator""_cC(unsigned long long value) -> centicoulombs;
            [[nodiscard]] constexpr auto operator""_cC(long double value)
                -> basic_coulomb<double, centi>;
            [[nodiscard]] constexpr auto operator""_dC(unsigned long long value) -> decicoulombs;
            [[nodiscard]] constexpr auto operator""_dC(long double value)
                -> basic_coulomb<double, deci>;
            [[nodiscard]] constexpr auto operator""_C(unsigned long long value) -> coulombs;
            [[nodiscard]] constexpr auto operator""_C(long double value)
                -> basic_coulomb<double, ratio<1>>;
            [[nodiscard]] constexpr auto operator""_daC(unsigned long long value) -> decacoulombs;
            [[nodiscard]] constexpr auto operator""_daC(long double value)
                -> basic_coulomb<double, deca>;
            [[nodiscard]] constexpr auto operator""_hC(unsigned long long value) -> hectocoulombs;
            [[nodiscard]] constexpr auto operator""_hC(long double value)
                -> basic_coulomb<double, hecto>;
            [[nodiscard]] constexpr auto operator""_kC(unsigned long long value) -> kilocoulombs;
            [[nodiscard]] constexpr auto operator""_kC(long double value)
                -> basic_coulomb<double, kilo>;
            [[nodiscard]] constexpr auto operator""_MC(unsigned long long value) -> megacoulombs;
            [[nodiscard]] constexpr auto operator""_MC(long double value)
                -> basic_coulomb<double, mega>;
            [[nodiscard]] constexpr auto operator""_GC(unsigned long long value) -> gigacoulombs;
            [[nodiscard]] constexpr auto operator""_GC(long double value)
                -> basic_coulomb<double, giga>;
            [[nodiscard]] constexpr auto operator""_TC(unsigned long long value) -> teracoulombs;
            [[nodiscard]] constexpr auto operator""_TC(long double value)
                -> basic_coulomb<double, tera>;
            [[nodiscard]] constexpr auto operator""_PC(unsigned long long value) -> petacoulombs;
            [[nodiscard]] constexpr auto operator""_PC(long double value)
                -> basic_coulomb<double, peta>;
            [[nodiscard]] constexpr auto operator""_EC(unsigned long long value) -> exacoulombs;
            [[nodiscard]] constexpr auto operator""_EC(long double value)
                -> basic_coulomb<double, exa>;

        } // namespace electric_charge_literals

    } // namespace literals

    using namespace literals::electric_charge_literals;

} // namespace posu::units::si

#include "posu/units/system/si/ipp/electric_charge.ipp"

namespace posu::units::si {

    inline namespace references {

        inline namespace electric_charge_references {

            inline constexpr auto aC  = 1_aC;
            inline constexpr auto fC  = 1_fC;
            inline constexpr auto pC  = 1_pC;
            inline constexpr auto nC  = 1_nC;
            inline constexpr auto uC  = 1_uC;
            inline constexpr auto mC  = 1_mC;
            inline constexpr auto cC  = 1_cC;
            inline constexpr auto dC  = 1_dC;
            inline constexpr auto C   = 1_C;
            inline constexpr auto daC = 1_daC;
            inline constexpr auto hC  = 1_hC;
            inline constexpr auto kC  = 1_kC;
            inline constexpr auto MC  = 1_MC;
            inline constexpr auto GC  = 1_GC;
            inline constexpr auto TC  = 1_TC;
            inline constexpr auto PC  = 1_PC;
            inline constexpr auto EC  = 1_EC;

        } // namespace electric_charge_references

    } // namespace references

} // namespace posu::units::si

#endif // #ifndef POSU_UNITS_SYSTEM_SI_ELECTRIC_CHARGE_HPP
