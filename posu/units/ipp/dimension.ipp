
[[nodiscard]] constexpr auto posu::units::unwrap_dimension(dimension auto dim) noexcept
{
    return dim;
}

template<base_dimension Dim>
[[nodiscard]] constexpr auto
posu::units::unwrap_dimension(meta::ratio<meta::list<Dim>> /*unused*/) noexcept
{
    return Dim{};
}

[[nodiscard]] constexpr auto posu::units::unwrap_dimension(meta::ratio<> /*unused*/) noexcept
{
    return dimensionless{};
}
