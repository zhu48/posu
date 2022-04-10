
namespace posu::units::detail {

    template<unit Unit>
    [[nodiscard]] constexpr auto kind_of(Unit /*unused*/) noexcept
    {
        return kind_t<Unit>{};
    }

    template<unit Unit>
    [[nodiscard]] constexpr auto period_of(Unit /*unused*/) noexcept
    {
        return period_t<Unit>{};
    }

    template<kind Kind, ratio_type Ratio>
    [[nodiscard]] constexpr auto make_unit(Kind /*unused*/, Ratio /*unused*/) noexcept
    {
        if constexpr(std::same_as<Kind, scaler>) {
            return unitless<Ratio>{};
        }
        else {
            return unknown_unit<Kind, Ratio>{};
        }
    }

} // namespace posu::units::detail

[[nodiscard]] constexpr auto
posu::units::detail::unit_multiply_impl(unit auto lhs, unit auto rhs) noexcept
{
    return make_unit(
        kind_multiply_impl(kind_of(lhs), kind_of(rhs)),
        period_of(lhs) * period_of(rhs));
}

[[nodiscard]] constexpr auto
posu::units::detail::unit_divide_impl(unit auto num, unit auto den) noexcept
{
    return make_unit(kind_divide_impl(kind_of(num), kind_of(den)), period_of(num) / period_of(den));
}

// [[nodiscard]] constexpr auto posu::units::detail::unit_common_impl(unit auto lhs, unit auto rhs)
// noexcept
// {
// }
