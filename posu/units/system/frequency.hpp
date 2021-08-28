#ifndef POSU_UNITS_SYSTEM_FREQUENCY_HPP
#define POSU_UNITS_SYSTEM_FREQUENCY_HPP

#include "posu/units/derived_unit.hpp"

#include "posu/units/system/time.hpp"

namespace posu::units {

    struct frequency {
        using type       = frequency;
        using value_type = std::string_view;
        using dimensions = meta::ratio<meta::list<>, meta::list<time>>;

        static constexpr auto value = std::string_view{"frequency"};

        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
    };

    template<>
    inline constexpr bool enable_as_kind<frequency> = true;

    template<>
    struct kind_multiply_result<frequency, time> {
        using type = scaler<>;
    };

    template<>
    struct kind_multiply_result<time, frequency> {
        using type = scaler<>;
    };

    template<>
    struct kind_divide_result<scaler<>, time> {
        using type = frequency;
    };

} // namespace posu::units

#endif // #ifndef POSU_UNITS_SYSTEM_FREQUENCY_HPP
