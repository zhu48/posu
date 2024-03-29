#ifndef POSU_UNITS_SYSTEM_AMOUNT_OF_SUBSTANCE_HPP
#define POSU_UNITS_SYSTEM_AMOUNT_OF_SUBSTANCE_HPP

#include "posu/units/kind.hpp"

namespace posu::units {

    struct amount_of_substance {
        using type       = amount_of_substance;
        using value_type = std::string_view;
        using dimensions = dimensionless;

        static constexpr auto value = std::string_view{"amount of substance"};

        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
    };

    template<>
    inline constexpr bool enable_as_kind<amount_of_substance> = true;

} // namespace posu::units

#endif // #ifndef POSU_UNITS_SYSTEM_AMOUNT_OF_SUBSTANCE_HPP
