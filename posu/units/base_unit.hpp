#ifndef POSU_UNITS_BASE_UNIT_HPP
#define POSU_UNITS_BASE_UNIT_HPP

#include <chrono>

namespace posu::units {

    template<typename Rep, typename Period, typename Tag>
        requires(std::integral<Rep> || std::floating_point<Rep>)
    class base_unit : private std::chrono::duration<Rep, Period> {
    private:
        using parent_type = std::chrono::duration<Rep, Period>;

    public:
        using typename parent_type::period;
        using typename parent_type::rep;

        using units = Tag;

        template<typename Rep2>
            requires(
                std::convertible_to<Rep, const Rep2&> &&
                (std::chrono::treat_as_floating_point_v<Rep> ||
                 !std::chrono::treat_as_floating_point_v<Rep2>))
        constexpr explicit base_unit(const Rep2& r);

        template<typename Rep2, typename Period2>
            requires(
                std::chrono::treat_as_floating_point_v<Rep> ||
                ((std::ratio_divide<Period2, Period>::den == 1) &&
                 !std::chrono::treat_as_floating_point_v<Rep2>))
        constexpr base_unit(const base_unit<Rep2, Period2, Tag>& d);

        using parent_type::count;

        template<typename Rep1, typename Period1, typename Rep2, typename Period2, typename TypeTag>
        friend constexpr auto operator==(
            const base_unit<Rep1, Period1, TypeTag>& lhs,
            const base_unit<Rep2, Period2, TypeTag>& rhs) -> bool;
    };

    /**
     * @brief Check whether a type specializes the `base_unit` template or not.
     *
     * @tparam T The type to check.
     *
     * @{
     */
    template<typename T>
    struct is_base_quantity : std::false_type {
    };
    template<typename Rep, typename Ratio, typename Tag>
    struct is_base_quantity<base_unit<Rep, Ratio, Tag>> : std::true_type {
    };
    template<typename T>
    inline constexpr bool is_base_quantity_v = is_base_quantity<T>::value;
    template<typename T>
    concept base_quantity = is_base_quantity_v<T>;
    //! @}

} // namespace posu::units

#include "posu/units/ipp/base_unit.ipp"

#endif // #ifndef POSU_UNITS_BASE_UNIT_HPP
