
namespace posu::units::detail {

    template<unit Unit>
    using as_unknown = unknown<kind_t<Unit>, period_t<Unit>>;

    template<unit Lhs, unit Rhs>
    using unknown_quantity_multiply = unit_multiply<as_unknown<Lhs>, as_unknown<Rhs>>;
    template<unit Lhs, unit Rhs>
    using unknown_quantity_divide = unit_divide<as_unknown<Lhs>, as_unknown<Rhs>>;

    template<unit Unit, unit Lhs, unit Rhs>
    using multiply_scaler =
        ratio_divide<period_t<unknown_quantity_multiply<Lhs, Rhs>>, period_t<Unit>>;
    template<unit Unit, unit Lhs, unit Rhs>
    using divide_scaler = ratio_divide<period_t<unknown_quantity_divide<Lhs, Rhs>>, period_t<Unit>>;

    template<quantity_of_measure Lhs, quantity_of_measure Rhs>
    struct quantity_multiply_result {
        using rep       = std::common_type_t<rep_t<Lhs>, rep_t<Rhs>>;
        using unit_type = unit_multiply<unit_t<Lhs>, unit_t<Rhs>>;
        using period    = ratio_multiply<
            ratio_multiply<period_t<Lhs>, period_t<Rhs>>,
            multiply_scaler<unit_type, unit_t<Lhs>, unit_t<Rhs>>>;

        using type = quantity<rep, period, unit_type>;
    };

    template<quantity_of_measure Lhs, quantity_of_measure Rhs>
    struct quantity_divide_result {
        using rep       = std::common_type_t<rep_t<Lhs>, rep_t<Rhs>>;
        using unit_type = unit_divide<unit_t<Lhs>, unit_t<Rhs>>;
        using period    = ratio_multiply<
            ratio_divide<period_t<Lhs>, period_t<Rhs>>,
            divide_scaler<unit_type, unit_t<Lhs>, unit_t<Rhs>>>;

        using type = quantity<rep, period, unit_type>;
    };

    template<typename Lhs, typename Rhs>
    using quantity_multiply = typename quantity_multiply_result<Lhs, Rhs>::type;
    template<typename Lhs, typename Rhs>
    using quantity_divide = typename quantity_divide_result<Lhs, Rhs>::type;

} // namespace posu::units::detail

[[nodiscard]] constexpr auto posu::units::operator*(
    const quantity_of_measure auto& lhs,
    const quantity_of_measure auto& rhs) noexcept
{
    using lhs_type = std::remove_cvref_t<decltype(lhs)>;
    using rhs_type = std::remove_cvref_t<decltype(rhs)>;

    return detail::quantity_multiply<lhs_type, rhs_type>(lhs.count() * rhs.count());
}

[[nodiscard]] constexpr auto posu::units::operator/(
    const quantity_of_measure auto& lhs,
    const quantity_of_measure auto& rhs) noexcept
{
    using lhs_type = std::remove_cvref_t<decltype(lhs)>;
    using rhs_type = std::remove_cvref_t<decltype(rhs)>;

    return detail::quantity_divide<lhs_type, rhs_type>(lhs.count() / rhs.count());
}

template<posu::units::quantity_of_measure Quantity>
[[nodiscard]] constexpr auto
posu::units::operator/(const rep_t<Quantity>& lhs, const Quantity& rhs) noexcept
{
    return quantity<rep_t<Quantity>, ratio<1>, scaler<>>(lhs) / rhs;
}
