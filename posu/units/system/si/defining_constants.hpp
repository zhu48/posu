#ifndef POSU_UNITS_SYSTEM_SI_DEFINING_CONSTANTS_HPP
#define POSU_UNITS_SYSTEM_SI_DEFINING_CONSTANTS_HPP

#include "posu/units/system/si/frequency.hpp"
#include "posu/units/system/si/length.hpp"
#include "posu/units/system/si/time.hpp"

namespace posu::units::si {

    inline constexpr auto cs_133_hyperfine_freq = 9'192'631'770_Hz;
    inline constexpr auto speed_of_light        = 299'792'458_m / s;

} // namespace posu::units::si

#endif // #ifndef POSU_UNITS_SYSTEM_SI_DEFINING_CONSTANTS_HPP
