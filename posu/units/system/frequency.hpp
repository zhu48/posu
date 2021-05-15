#ifndef POSU_UNITS_SYSTEM_FREQUENCY_HPP
#define POSU_UNITS_SYSTEM_FREQUENCY_HPP

#include "posu/units/derived_unit.hpp"

#include "posu/units/system/time.hpp"

namespace posu::units {

    struct frequency {
        using type       = frequency;
        using value_type = std::string_view;
        using dimensions = type_ratio<type_list<>, type_list<time>>;

        static constexpr auto value = std::string_view{"frequency"};

        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
    };

} // namespace posu::units

template<>
inline constexpr bool posu::units::enable_as_kind<posu::units::frequency> = true;

template<>
struct posu::units::kind_multiply_result<posu::units::frequency, posu::units::time> {
    using type = scaler;
};

template<>
struct posu::units::kind_multiply_result<posu::units::time, posu::units::frequency> {
    using type = scaler;
};

template<>
struct posu::units::kind_divide_result<posu::units::scaler, posu::units::time> {
    using type = frequency;
};

#endif // #ifndef POSU_UNITS_SYSTEM_FREQUENCY_HPP
