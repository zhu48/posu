#ifndef POSU_UNITS_SYSTEM_THERMODYNAMIC_TEMPERATURE_HPP
#define POSU_UNITS_SYSTEM_THERMODYNAMIC_TEMPERATURE_HPP

#include "posu/units/kind.hpp"

namespace posu::units {

    struct thermodynamic_temperature : public make_dimension<"thermodynamic temperature"> {
        using type       = thermodynamic_temperature;
        using dimensions = type;
    };

    template<>
    inline constexpr bool enable_as_dimension<thermodynamic_temperature> = true;

    template<>
    inline constexpr bool enable_as_kind<thermodynamic_temperature> = true;

} // namespace posu::units

#endif // #ifndef POSU_UNITS_SYSTEM_THERMODYNAMIC_TEMPERATURE_HPP
