#ifndef POSU_UNITS_SYSTEM_ACCELERATION_HPP
#define POSU_UNITS_SYSTEM_ACCELERATION_HPP

#include "posu/units/system/velocity.hpp"

namespace posu::units {

    struct acceleration {
        using type       = acceleration;
        using value_type = std::string_view;
        using dimensions = decltype(length{} / (time{} * time{}));

        static constexpr auto value = std::string_view{"acceleration"};

        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
    };

    template<>
    inline constexpr bool enable_as_kind<acceleration> = true;

    template<>
    struct kind_multiply_result<acceleration, time> {
        using type = velocity;
    };

    template<>
    struct kind_multiply_result<time, acceleration> {
        using type = velocity;
    };

    template<>
    struct kind_divide_result<velocity, time> {
        using type = acceleration;
    };

} // namespace posu::units

#endif // #ifndef POSU_UNITS_SYSTEM_ACCELERATION_HPP
