#ifndef POSU_UNITS_SYSTEM_ELECTRIC_CHARGE_HPP
#define POSU_UNITS_SYSTEM_ELECTRIC_CHARGE_HPP

#include "posu/units/derived_unit.hpp"

#include "posu/units/system/electric_current.hpp"
#include "posu/units/system/time.hpp"

namespace posu::units {

    struct electric_charge {
        using type       = electric_charge;
        using value_type = std::string_view;
        using dimensions = decltype(electric_current{} * time{});

        static constexpr auto value = std::string_view{"electric_charge"};

        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
    };

    template<>
    inline constexpr bool enable_as_kind<electric_charge> = true;

    template<>
    struct kind_multiply_result<electric_current, time> {
        using type = electric_charge;
    };

    template<>
    struct kind_divide_result<electric_charge, time> {
        using type = electric_current;
    };

    template<>
    struct kind_divide_result<electric_charge, electric_current> {
        using type = time;
    };

} // namespace posu::units

#endif // #ifndef POSU_UNITS_SYSTEM_ELECTRIC_CHARGE_HPP
