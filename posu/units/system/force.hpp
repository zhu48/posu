#ifndef POSU_UNITS_SYSTEM_FORCE_HPP
#define POSU_UNITS_SYSTEM_FORCE_HPP

#include "posu/units/system/acceleration.hpp"
#include "posu/units/system/mass.hpp"

namespace posu::units {

    struct force {
        using type       = force;
        using value_type = std::string_view;
        using dimensions = dimension_multiply<dimension_t<mass>, dimension_t<acceleration>>;

        static constexpr auto value = std::string_view{"force"};

        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
    };

    template<>
    inline constexpr bool enable_as_kind<force> = true;

    template<>
    struct kind_multiply_result<mass, acceleration> {
        using type = force;
    };

    template<>
    struct kind_multiply_result<acceleration, mass> {
        using type = force;
    };

    template<>
    struct kind_divide_result<force, acceleration> {
        using type = mass;
    };

    template<>
    struct kind_divide_result<force, mass> {
        using type = acceleration;
    };

} // namespace posu::units

#endif // #ifndef POSU_UNITS_SYSTEM_FORCE_HPP
