
namespace posu::units {

    template<
        typename Numerator,
        typename Denominator,
        typename Rep,
        typename Period> // clang-format off
        requires( posu::is_type_list_v<Numerator> && posu::is_type_list_v<Denominator> )
    template<typename Rep2>
        requires(
            std::convertible_to<Rep, const Rep2&> &&
            (
                std::chrono::treat_as_floating_point_v<Rep> ||
                !std::chrono::treat_as_floating_point_v<Rep2>
            )
        )
    constexpr derived_unit<Numerator, Denominator, Rep, Period>::derived_unit( // clang-format on
            const Rep2& r)
        : parent_type(r)
    {
    }

    template<
        typename Num,
        typename Den,
        typename Rep1,
        typename Period1,
        typename Rep2,
        typename Period2>
    [[nodiscard]] constexpr auto operator==(
        const derived_unit<Num, Den, Rep1, Period1>& lhs,
        const derived_unit<Num, Den, Rep2, Period2>& rhs) -> bool
    {
        return static_cast<const std::chrono::duration<Rep1, Period1>&>(lhs) ==
               static_cast<const std::chrono::duration<Rep2, Period2>&>(rhs);
    }

} // namespace posu::units
