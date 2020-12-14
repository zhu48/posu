
namespace posu::units {

    template<typename Rep, typename Period, typename Tag> // clang-format off
        requires( std::integral<Rep> || std::floating_point<Rep> )
    template<typename Rep2>
        requires(
            std::convertible_to<Rep, const Rep2&> &&
            (
                std::chrono::treat_as_floating_point_v<Rep> ||
                !std::chrono::treat_as_floating_point_v<Rep2>
            )
        )
    constexpr base_unit<Rep, Period, Tag>::base_unit( const Rep2& r ) : // clang-format on
          parent_type(r)
    {
    }

    template<typename Rep1, typename Period1, typename Rep2, typename Period2, typename TypeTag>
    [[nodiscard]] constexpr auto operator==(
        const base_unit<Rep1, Period1, TypeTag>& lhs, const base_unit<Rep2, Period2, TypeTag>& rhs)
        -> bool
    {
        return static_cast<const std::chrono::duration<Rep1, Period1>&>(lhs) ==
               static_cast<const std::chrono::duration<Rep2, Period2>&>(rhs);
    }

    template<typename Rep1, typename Period1, typename Rep2, typename Period2, typename TypeTag>
    [[nodiscard]] constexpr auto operator!=(
        const base_unit<Rep1, Period1, TypeTag>& lhs, const base_unit<Rep2, Period2, TypeTag>& rhs)
        -> bool
    {
        return static_cast<const std::chrono::duration<Rep1, Period1>&>(lhs) !=
               static_cast<const std::chrono::duration<Rep2, Period2>&>(rhs);
    }

} // namespace posu::units
