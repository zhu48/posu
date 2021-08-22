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

    template<>
    inline constexpr bool enable_as_dimension<luminous_intensity> = true;

    template<>
    inline constexpr bool enable_as_kind<luminous_intensity> = true;

} // namespace posu::units

#endif // #ifndef POSU_UNITS_SYSTEM_LUMINOUS_INTENSITY_HPP
