#ifndef POSU_UNITS_SYSTEM_TIME_HPP
#define POSU_UNITS_SYSTEM_TIME_HPP

#include "posu/units/kind.hpp"

namespace posu::units {

    struct time {
        using type       = time;
        using value_type = std::string_view;
        using dimensions = type;

        static constexpr auto value = std::string_view{"time"};

        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
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
