#ifndef POSU_UNITS_SYSTEM_MASS_HPP
#define POSU_UNITS_SYSTEM_MASS_HPP

#include "posu/units/kind.hpp"

namespace posu::units {

    struct mass : public make_dimension<mass, "mass"> {
        using dimensions = type;
    };

    template<>
    inline constexpr bool enable_as_dimension<mass> = true;

    template<>
    inline constexpr bool enable_as_kind<mass> = true;

} // namespace posu::units

#endif // #ifndef POSU_UNITS_SYSTEM_MASS_HPP
