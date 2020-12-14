#ifndef POSU_UNITS_BASE_UNIT_HPP
#define POSU_UNITS_BASE_UNIT_HPP

#include <chrono>

namespace posu::units {

    template<typename Rep, typename Period, typename Tag> // clang-format off
        requires( std::integral<Rep> || std::floating_point<Rep> )
    class base_unit : private std::chrono::duration<Rep, Period> { // clang-format on
    private:
        using parent_type = std::chrono::duration<Rep, Period>;

    public:
        using typename parent_type::rep;

        template<typename Rep2> // clang-format off
            requires(
                std::convertible_to<Rep, const Rep2&> &&
                (
                    std::chrono::treat_as_floating_point_v<Rep> ||
                    !std::chrono::treat_as_floating_point_v<Rep2>
                )
            )
        constexpr explicit base_unit( const Rep2& r ); // clang-format on

        template<typename Rep2, typename Period2> // clang-format off
            requires(
                std::chrono::treat_as_floating_point_v<Rep> ||
                (
                    (std::ratio_divide<Period2, Period>::den == 1) &&
                    !std::chrono::treat_as_floating_point_v<Rep2>
                )
            )
        constexpr base_unit( const base_unit<Rep2, Period2, Tag>& d ); // clang-format on

        template<typename Rep1, typename Period1, typename Rep2, typename Period2, typename TypeTag>
        friend constexpr auto operator==(
            const base_unit<Rep1, Period1, TypeTag>& lhs,
            const base_unit<Rep2, Period2, TypeTag>& rhs) -> bool;
        template<typename Rep1, typename Period1, typename Rep2, typename Period2, typename TypeTag>
        friend constexpr auto operator!=(
            const base_unit<Rep1, Period1, TypeTag>& lhs,
            const base_unit<Rep2, Period2, TypeTag>& rhs) -> bool;
    };

} // namespace posu::units

#include "posu/units/ipp/base_unit.ipp"

#endif // #ifndef POSU_UNITS_BASE_UNIT_HPP
