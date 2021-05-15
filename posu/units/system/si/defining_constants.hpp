#ifndef POSU_UNITS_SYSTEM_SI_DEFINING_CONSTANTS_HPP
#define POSU_UNITS_SYSTEM_SI_DEFINING_CONSTANTS_HPP

#include "posu/units/system/si/frequency.hpp"
#include "posu/units/system/si/speed.hpp"

namespace posu::units::si {

    inline constexpr auto speed_of_light        = 299'792'458_m_per_sec;
    inline constexpr auto cs_133_hyperfine_freq = 9'192'631'770_Hz;

} // namespace posu::units::si

#endif // #ifndef POSU_UNITS_SYSTEM_SI_DEFINING_CONSTANTS_HPP
