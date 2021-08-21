#ifndef POSU_UNITS_SYSTEM_SI_DEFINING_CONSTANTS_HPP
#define POSU_UNITS_SYSTEM_SI_DEFINING_CONSTANTS_HPP

#include "posu/units/system/si/energy.hpp"
#include "posu/units/system/si/frequency.hpp"
#include "posu/units/system/si/length.hpp"
#include "posu/units/system/si/time.hpp"

namespace posu::units::si {

    inline constexpr auto cs_133_hyperfine_freq = 9'192'631'770_Hz;
    inline constexpr auto speed_of_light        = 299'792'458_m / s;
    inline constexpr auto planck_constant       = 6.626'070'15e-34_J * s;

} // namespace posu::units::si

#endif // #ifndef POSU_UNITS_SYSTEM_SI_DEFINING_CONSTANTS_HPP
