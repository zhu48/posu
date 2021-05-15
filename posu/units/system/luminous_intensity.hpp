#ifndef POSU_UNITS_SYSTEM_LUMINOUS_INTENSITY_HPP
#define POSU_UNITS_SYSTEM_LUMINOUS_INTENSITY_HPP

#include "posu/units/kind.hpp"

namespace posu::units {

    struct luminous_intensity {
        using type       = luminous_intensity;
        using value_type = std::string_view;
        using dimensions = type;

        static constexpr auto value = std::string_view{"luminous intensity"};

        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
    };

} // namespace posu::units

template<>
inline constexpr bool posu::units::enable_as_dimension<posu::units::luminous_intensity> = true;

template<>
inline constexpr bool posu::units::enable_as_kind<posu::units::luminous_intensity> = true;

#endif // #ifndef POSU_UNITS_SYSTEM_LUMINOUS_INTENSITY_HPP
