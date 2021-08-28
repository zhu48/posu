#ifndef POSU_UNITS_SYSTEM_VELOCITY_HPP
#define POSU_UNITS_SYSTEM_VELOCITY_HPP

#include "posu/units/derived_unit.hpp"

#include "posu/units/system/length.hpp"
#include "posu/units/system/time.hpp"

namespace posu::units {

    struct velocity {
        using type       = velocity;
        using value_type = std::string_view;
        using dimensions = meta::ratio<meta::list<length>, meta::list<time>>;

        static constexpr auto value = std::string_view{"velocity"};

        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
    };

    template<>
    inline constexpr bool enable_as_kind<velocity> = true;

    template<>
    struct kind_multiply_result<velocity, time> {
        using type = length;
    };

    template<>
    struct kind_multiply_result<time, velocity> {
        using type = length;
    };

    template<>
    struct kind_divide_result<length, time> {
        using type = velocity;
    };

} // namespace posu::units

#endif // #ifndef POSU_UNITS_SYSTEM_VELOCITY_HPP
