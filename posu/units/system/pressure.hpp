#ifndef POSU_UNITS_SYSTEM_PRESSURE_HPP
#define POSU_UNITS_SYSTEM_PRESSURE_HPP

#include "posu/units/derived_unit.hpp"

#include "posu/units/system/force.hpp"
#include "posu/units/system/length.hpp"

namespace posu::units {

    struct pressure {
        using type       = pressure;
        using value_type = std::string_view;
        using dimensions = dimension_divide<
            dimension_t<force>,
            dimension_multiply<dimension_t<length>, dimension_t<length>>>;

        static constexpr auto value = std::string_view{"pressure"};

        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
    };

} // namespace posu::units

template<>
inline constexpr bool posu::units::enable_as_kind<posu::units::pressure> = true;

#endif // #ifndef POSU_UNITS_SYSTEM_PRESSURE_HPP
