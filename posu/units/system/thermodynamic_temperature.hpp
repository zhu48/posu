#ifndef POSU_UNITS_SYSTEM_THERMODYNAMIC_TEMPERATURE_HPP
#define POSU_UNITS_SYSTEM_THERMODYNAMIC_TEMPERATURE_HPP

#include "posu/units/kind.hpp"

namespace posu::units {

    struct thermodynamic_temperature {
        using type       = thermodynamic_temperature;
        using value_type = std::string_view;
        using dimensions = type;

        static constexpr auto value = std::string_view{"thermodynamic temperature"};

        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
    };

    template<>
    inline constexpr bool enable_as_dimension<thermodynamic_temperature> = true;

    template<>
    inline constexpr bool enable_as_kind<thermodynamic_temperature> = true;

} // namespace posu::units

#endif // #ifndef POSU_UNITS_SYSTEM_THERMODYNAMIC_TEMPERATURE_HPP
