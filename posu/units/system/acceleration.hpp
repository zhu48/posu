#ifndef POSU_UNITS_SYSTEM_ACCELERATION_HPP
#define POSU_UNITS_SYSTEM_ACCELERATION_HPP

#include "posu/units/derived_unit.hpp"

#include "posu/units/system/velocity.hpp"

namespace posu::units {

    struct acceleration {
        using type       = acceleration;
        using value_type = std::string_view;
        using dimensions = dimension_divide<length, dimension_multiply<time, time>>;

        static constexpr auto value = std::string_view{"acceleration"};

        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
    };

} // namespace posu::units

template<>
inline constexpr bool posu::units::enable_as_kind<posu::units::acceleration> = true;

template<>
struct posu::units::kind_multiply_result<posu::units::acceleration, posu::units::time> {
    using type = velocity;
};

template<>
struct posu::units::kind_multiply_result<posu::units::time, posu::units::acceleration> {
    using type = velocity;
};

template<>
struct posu::units::kind_divide_result<posu::units::velocity, posu::units::time> {
    using type = acceleration;
};

#endif // #ifndef POSU_UNITS_SYSTEM_ACCELERATION_HPP
