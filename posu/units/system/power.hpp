#ifndef POSU_UNITS_SYSTEM_POWER_HPP
#define POSU_UNITS_SYSTEM_POWER_HPP

#include "posu/units/derived_unit.hpp"

#include "posu/units/system/energy.hpp"
#include "posu/units/system/time.hpp"

namespace posu::units {

    struct power {
        using type       = power;
        using value_type = std::string_view;
        using dimensions = decltype(dimension_t<energy>{} / dimension_t<time>{});

        static constexpr auto value = std::string_view{"power"};

        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
    };

    template<>
    inline constexpr bool enable_as_kind<power> = true;

} // namespace posu::units

#endif // #ifndef POSU_UNITS_SYSTEM_POWER_HPP
