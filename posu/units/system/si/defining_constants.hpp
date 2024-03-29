#ifndef POSU_UNITS_SYSTEM_SI_DEFINING_CONSTANTS_HPP
#define POSU_UNITS_SYSTEM_SI_DEFINING_CONSTANTS_HPP

#include "posu/units/system/si/amount_of_substance.hpp"
#include "posu/units/system/si/electric_charge.hpp"
#include "posu/units/system/si/energy.hpp"
#include "posu/units/system/si/frequency.hpp"
#include "posu/units/system/si/length.hpp"
#include "posu/units/system/si/luminous_flux.hpp"
#include "posu/units/system/si/power.hpp"
#include "posu/units/system/si/thermodynamic_temperature.hpp"
#include "posu/units/system/si/time.hpp"

namespace posu::units::si {

    inline constexpr auto cs_133_hyperfine_freq = 9'192'631'770_Hz;
    inline constexpr auto speed_of_light        = 299'792'458_m / s;
    inline constexpr auto planck_constant       = 6.626'070'15e-34_J * s;
    inline constexpr auto elementary_charge     = 1.602'176'634e-19_C;
    inline constexpr auto boltzmann_constant    = 1.380'649e-23_J / K;
    inline constexpr auto avogadro_constant     = 6.022'146'76e23 / 1.0_mol;
    inline constexpr auto lum_efficacy_540_Thz  = 683_lm / W;

} // namespace posu::units::si

#endif // #ifndef POSU_UNITS_SYSTEM_SI_DEFINING_CONSTANTS_HPP
