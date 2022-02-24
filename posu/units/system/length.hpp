#ifndef POSU_UNITS_SYSTEM_LENGTH_HPP
#define POSU_UNITS_SYSTEM_LENGTH_HPP

#include "posu/units/kind.hpp"

namespace posu::units {

    struct length : public make_dimension<length, "name"> {
        using dimensions = type;
    };

    template<>
    inline constexpr bool enable_as_dimension<length> = true;

    template<>
    inline constexpr bool enable_as_kind<length> = true;

} // namespace posu::units

#endif // #ifndef POSU_UNITS_SYSTEM_LENGTH_HPP
