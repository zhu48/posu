
namespace posu::units::detail {

    template<base_dimension T>
    struct unwrap_dimension_type<type_ratio<type_list<T>>> {
        using type = T;
    };

    template<>
    struct unwrap_dimension_type<type_ratio<type_list<>>> {
        using type = dimensionless;
    };

    template<std::intmax_t Num, std::intmax_t Den>
    struct is_std_ratio<std::ratio<Num, Den>> : std::true_type {
    };

} // namespace posu::units::detail

template<posu::units::dimension Lhs, posu::units::dimension Rhs>
[[nodiscard]] constexpr auto posu::units::detail::dimension_multiply_impl() noexcept
{
    if constexpr(std::same_as<Lhs, dimensionless> && std::same_as<Rhs, dimensionless>) {
        return dimensionless{};
    }
    else if constexpr(std::same_as<Lhs, dimensionless>) {
        return Rhs{};
    }
    else if constexpr(std::same_as<Rhs, dimensionless>) {
        return Lhs{};
    }
    else if constexpr(base_dimension<Lhs> && base_dimension<Rhs>) {
        return type_ratio<type_list<Lhs, Rhs>>{};
    }
    else if constexpr(base_dimension<Lhs> && derived_dimension<Rhs>) {
        return ratio_multiply<type_ratio<type_list<Lhs>>, Rhs>{};
    }
    else if constexpr(derived_dimension<Lhs> && base_dimension<Rhs>) {
        return ratio_multiply<Lhs, type_ratio<type_list<Rhs>>>{};
    }
    else {
        return ratio_multiply<Lhs, Rhs>{};
    }
}

template<posu::units::dimension Lhs, posu::units::dimension Rhs>
[[nodiscard]] constexpr auto posu::units::detail::dimension_divide_impl() noexcept
{
    if constexpr(base_dimension<Rhs>) {
        return dimension_multiply_impl<Lhs, ratio_invert<type_ratio<type_list<Rhs>>>>();
    }
    else {
        return dimension_multiply_impl<Lhs, ratio_invert<Rhs>>();
    }
}
