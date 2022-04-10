
namespace posu::units::detail {

    template<dimension T>
    [[nodiscard]] constexpr auto unwrap_dimension(T /*unused*/) noexcept
    {
        return T{};
    }

    template<base_dimension T>
    [[nodiscard]] constexpr auto unwrap_dimension(meta::ratio<meta::list<T>> /*unused*/) noexcept
    {
        return T{};
    }

    [[nodiscard]] constexpr auto unwrap_dimension(meta::ratio<meta::list<>> /*unused*/) noexcept
    {
        return dimensionless{};
    }

    [[nodiscard]] constexpr auto remove_dimensionless(meta::list_type auto list) noexcept
    {
        constexpr auto pos = meta::find<dimensionless>(list);
        if constexpr(pos < list.size()) {
            return meta::remove<pos>(list);
        }
        else {
            return list;
        }
    }

    template<dimension Dimension>
    constexpr auto make_meta_ratio(Dimension dim) noexcept
    {
        if constexpr(std::same_as<Dimension, dimensionless>) {
            return meta::ratio<>{};
        }
        else if constexpr(base_dimension<Dimension>) {
            return meta::ratio<meta::list<Dimension>>{};
        }
        else {
            return meta::ratio<
                decltype(remove_dimensionless(dim.num)),
                decltype(remove_dimensionless(dim.den))>{};
        }
    }

    [[nodiscard]] constexpr auto
    dimension_multiply_impl(dimension auto lhs, dimension auto rhs) noexcept
    {
        return make_meta_ratio(lhs) * make_meta_ratio(rhs);
    }

    template<dimension Den>
    [[nodiscard]] constexpr auto dimension_divide_impl(dimension auto num, Den den) noexcept
    {
        if constexpr(base_dimension<Den>) {
            return dimension_multiply_impl(num, meta::invert(meta::ratio<meta::list<Den>>{}));
        }
        else {
            return dimension_multiply_impl(num, meta::invert(den));
        }
    }

} // namespace posu::units::detail

[[nodiscard]] constexpr auto
posu::units::detail::dimension_multiply(dimension auto lhs, dimension auto rhs) noexcept
{
    return unwrap_dimension(dimension_multiply_impl(lhs, rhs));
}

[[nodiscard]] constexpr auto
posu::units::detail::dimension_divide(dimension auto num, dimension auto den) noexcept
{
    return unwrap_dimension(dimension_divide_impl(num, den));
}
