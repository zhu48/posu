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

} // namespace posu::units

template<>
inline constexpr bool posu::units::enable_as_dimension<posu::units::time> = true;

template<>
inline constexpr bool posu::units::enable_as_kind<posu::units::time> = true;

#endif // #ifndef POSU_UNITS_SYSTEM_TIME_HPP
