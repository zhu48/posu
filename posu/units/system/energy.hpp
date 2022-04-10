#ifndef POSU_UNITS_SYSTEM_ENERGY_HPP
#define POSU_UNITS_SYSTEM_ENERGY_HPP

#include "posu/units/system/force.hpp"

namespace posu::units {

    struct energy {
        using type       = energy;
        using value_type = std::string_view;
        using dimensions = decltype(dimension_t<force>{} * dimension_t<length>{});

        static constexpr auto value = std::string_view{"energy"};

        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
    };

    template<>
    inline constexpr bool enable_as_kind<energy> = true;

} // namespace posu::units

#endif // #ifndef POSU_UNITS_SYSTEM_ENERGY_HPP
