#ifndef POSU_UNITS_SYSTEM_VELOCITY_HPP
#define POSU_UNITS_SYSTEM_VELOCITY_HPP

#include "posu/units/derived_unit.hpp"

#include "posu/units/system/length.hpp"
#include "posu/units/system/time.hpp"

namespace posu::units {

    struct velocity {
        using type       = velocity;
        using value_type = std::string_view;
        using dimensions = type_ratio<type_list<length>, type_list<time>>;

        static constexpr auto value = std::string_view{"velocity"};

        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
    };

} // namespace posu::units

template<>
inline constexpr bool posu::units::enable_as_kind<posu::units::velocity> = true;

template<>
struct posu::units::kind_multiply_result<posu::units::velocity, posu::units::time> {
    using type = length;
};

template<>
struct posu::units::kind_multiply_result<posu::units::time, posu::units::velocity> {
    using type = length;
};

template<>
struct posu::units::kind_divide_result<posu::units::length, posu::units::time> {
    using type = velocity;
};

#endif // #ifndef POSU_UNITS_SYSTEM_VELOCITY_HPP
