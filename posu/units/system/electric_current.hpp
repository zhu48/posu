#ifndef POSU_UNITS_SYSTEM_ELECTRIC_CURRENT_HPP
#define POSU_UNITS_SYSTEM_ELECTRIC_CURRENT_HPP

#include "posu/units/kind.hpp"

namespace posu::units {

    struct electric_current {
        using type       = electric_current;
        using value_type = std::string_view;
        using dimensions = type;

        static constexpr auto value = std::string_view{"electric current"};

        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
    };

    template<>
    inline constexpr bool enable_as_dimension<electric_current> = true;

    template<>
    inline constexpr bool enable_as_kind<electric_current> = true;

} // namespace posu::units

#endif // #ifndef POSU_UNITS_SYSTEM_ELECTRIC_CURRENT_HPP
