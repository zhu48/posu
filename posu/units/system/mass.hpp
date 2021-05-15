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

} // namespace posu::units

template<>
inline constexpr bool posu::units::enable_as_dimension<posu::units::mass> = true;

template<>
inline constexpr bool posu::units::enable_as_kind<posu::units::mass> = true;

#endif // #ifndef POSU_UNITS_SYSTEM_MASS_HPP
