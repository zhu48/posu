#ifndef POSU_UNITS_SYSTEM_AREA_HPP
#define POSU_UNITS_SYSTEM_AREA_HPP

#include "posu/units/derived_unit.hpp"

#include "posu/units/system/length.hpp"

namespace posu::units {

    struct area {
        using type       = area;
        using value_type = std::string_view;
        using dimensions = dimension_multiply<length, length>;

        static constexpr auto value = std::string_view{"area"};

        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
    };

} // namespace posu::units

template<>
inline constexpr bool posu::units::enable_as_kind<posu::units::area> = true;

#endif // #ifndef POSU_UNITS_SYSTEM_AREA_HPP
