#ifndef POSU_UNITS_SYSTEM_ANGLE_HPP
#define POSU_UNITS_SYSTEM_ANGLE_HPP

#include "posu/units/derived_unit.hpp"

#include "posu/units/system/length.hpp"

namespace posu::units {

    struct angle {
        using type       = angle;
        using value_type = std::string_view;
        using dimensions = decltype(length{} / length{});

        static constexpr auto value = std::string_view{"angle"};

        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
    };

    template<>
    inline constexpr bool enable_as_kind<angle> = true;

} // namespace posu::units

#endif // #ifndef POSU_UNITS_SYSTEM_ANGLE_HPP
