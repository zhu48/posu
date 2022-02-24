#ifndef POSU_UNITS_SYSTEM_ELECTRIC_CURRENT_HPP
#define POSU_UNITS_SYSTEM_ELECTRIC_CURRENT_HPP

#include "posu/units/kind.hpp"

namespace posu::units {

    struct electric_current : public make_dimension<"electric current"> {
        using type       = electric_current;
        using dimensions = type;
    };

    template<>
    inline constexpr bool enable_as_dimension<electric_current> = true;

    template<>
    inline constexpr bool enable_as_kind<electric_current> = true;

} // namespace posu::units

#endif // #ifndef POSU_UNITS_SYSTEM_ELECTRIC_CURRENT_HPP
