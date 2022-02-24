#ifndef POSU_UNITS_SYSTEM_LUMINOUS_INTENSITY_HPP
#define POSU_UNITS_SYSTEM_LUMINOUS_INTENSITY_HPP

#include "posu/units/kind.hpp"

namespace posu::units {

    struct luminous_intensity : public make_dimension<luminous_intensity, "luminous intensity"> {
        using dimensions = type;
    };

    template<>
    inline constexpr bool enable_as_dimension<luminous_intensity> = true;

    template<>
    inline constexpr bool enable_as_kind<luminous_intensity> = true;

} // namespace posu::units

#endif // #ifndef POSU_UNITS_SYSTEM_LUMINOUS_INTENSITY_HPP
