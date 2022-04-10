
[[nodiscard]] constexpr auto posu::units::detail::unwrap_dimension(base_dimension auto dim) noexcept
{
    return dim;
}

[[nodiscard]] constexpr auto
posu::units::detail::unwrap_dimension(derived_dimension auto dim) noexcept
{
    if constexpr(dim == meta::ratio<>{}) {
        return dimensionless{};
    }
    else if constexpr((dim.num.size() == 1) && (dim.den.empty())) {
        return meta::front<std::remove_const_t<decltype(dim.num)>>{};
    }
    else {
        return dim;
    }
}
