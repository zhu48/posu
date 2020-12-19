#ifndef POSU_UNITS_DERIVED_UNIT_HPP
#define POSU_UNITS_DERIVED_UNIT_HPP

#include "posu/type_list.hpp"
#include "posu/units/base_unit.hpp"

namespace posu::units {

    template<
        typename Numerator,
        typename Denominator,
        typename Rep,
        typename Period> // clang-format off
        requires( posu::is_type_list_v<Numerator> && posu::is_type_list_v<Denominator> )
    class derived_unit : private std::chrono::duration<Rep, Period> { // clang-format on
    private:
        using parent_type = std::chrono::duration<Rep, Period>;

    public:
        template<typename Rep2> // clang-format off
            requires(
                std::convertible_to<Rep, const Rep2&> &&
                (
                    std::chrono::treat_as_floating_point_v<Rep> ||
                    !std::chrono::treat_as_floating_point_v<Rep2>
                )
            )
        constexpr explicit derived_unit( const Rep2& r ); // clang-format on

        template<
            typename Num,
            typename Den,
            typename Rep1,
            typename Period1,
            typename Rep2,
            typename Period2>
        friend constexpr auto operator==(
            const derived_unit<Num, Den, Rep1, Period1>& lhs,
            const derived_unit<Num, Den, Rep2, Period2>& rhs) -> bool;
    };

} // namespace posu::units

#include "posu/units/ipp/derived_unit.ipp"

#endif // #ifndef POSU_UNITS_DERIVED_UNIT_HPP
