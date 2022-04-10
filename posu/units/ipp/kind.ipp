
namespace posu::units::detail {

    template<kind Kind>
    [[nodiscard]] constexpr auto dimension_of(Kind /*unused*/) noexcept
    {
        return dimension_t<Kind>{};
    }

    template<dimension Dimension>
    [[nodiscard]] constexpr auto make_kind(Dimension /*unused*/) noexcept
    {
        if constexpr(std::same_as<Dimension, dimensionless>) {
            return scaler{};
        }
        else {
            return unknown_kind<Dimension>{};
        }
    }

} // namespace posu::units::detail

[[nodiscard]] constexpr auto
posu::units::detail::kind_multiply_impl(kind auto lhs, kind auto rhs) noexcept
{
    return make_kind(dimension_multiply(dimension_of(lhs), dimension_of(rhs)));
}

[[nodiscard]] constexpr auto
posu::units::detail::kind_divide_impl(kind auto lhs, kind auto rhs) noexcept
{
    return make_kind(dimension_divide(dimension_of(lhs), dimension_of(rhs)));
}

// [[nodiscard]] constexpr auto posu::units::detail::kind_common_impl(kind auto lhs, kind auto rhs)
// noexcept
// {
// }
