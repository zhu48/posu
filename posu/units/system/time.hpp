#ifndef POSU_UNITS_SYSTEM_TIME_HPP
#define POSU_UNITS_SYSTEM_TIME_HPP

#include "posu/units/kind.hpp"

namespace posu::units {

    struct time : public make_dimension<"time"> {
        using type       = time;
        using dimensions = type;
    };

    template<>
    inline constexpr bool enable_as_dimension<time> = true;

    template<>
    inline constexpr bool enable_as_kind<time> = true;

    namespace detail {

        template<>
        inline constexpr bool implicit_chrono<time> = true;

    }

} // namespace posu::units

#endif // #ifndef POSU_UNITS_SYSTEM_TIME_HPP
