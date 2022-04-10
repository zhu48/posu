#ifndef POSU_UNITS_SYSTEM_SOLID_ANGLE_HPP
#define POSU_UNITS_SYSTEM_SOLID_ANGLE_HPP

#include "posu/units/derived_unit.hpp"

#include "posu/units/system/angle.hpp"

namespace posu::units {

    struct solid_angle {
        using type       = solid_angle;
        using value_type = std::string_view;
        using dimensions = decltype(dimension_t<angle>{} * dimension_t<angle>{});

        static constexpr auto value = std::string_view{"solid_angle"};

        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
    };

    template<>
    inline constexpr bool enable_as_kind<solid_angle> = true;

    template<>
    struct kind_multiply_result<angle, angle> {
        using type = solid_angle;
    };

    template<>
    struct kind_divide_result<solid_angle, angle> {
        using type = angle;
    };

} // namespace posu::units

#endif // #ifndef POSU_UNITS_SYSTEM_SOLID_ANGLE_HPP
