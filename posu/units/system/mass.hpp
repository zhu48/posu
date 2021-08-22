#ifndef POSU_UNITS_SYSTEM_MASS_HPP
#define POSU_UNITS_SYSTEM_MASS_HPP

#include "posu/units/kind.hpp"

namespace posu::units {

    struct mass {
        using type       = mass;
        using value_type = std::string_view;
        using dimensions = type;

        static constexpr auto value = std::string_view{"mass"};

        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
    };

    template<>
    inline constexpr bool enable_as_dimension<mass> = true;

    template<>
    inline constexpr bool enable_as_kind<mass> = true;

} // namespace posu::units

#endif // #ifndef POSU_UNITS_SYSTEM_MASS_HPP
