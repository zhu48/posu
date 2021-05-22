
[[nodiscard]] constexpr auto posu::units::operator*(
    const quantity_of_measure auto& lhs,
    const quantity_of_measure auto& rhs) noexcept
{
    using lhs_type  = std::remove_cvref_t<decltype(lhs)>;
    using rhs_type  = std::remove_cvref_t<decltype(rhs)>;
    using rep       = std::common_type_t<typename lhs_type::rep, typename rhs_type::rep>;
    using period    = std::ratio_multiply<typename lhs_type::period, typename rhs_type::period>;
    using unit_type = unit_multiply<unit_t<lhs_type>, unit_t<rhs_type>>;

    return quantity<rep, period, unit_type>(lhs.count() * rhs.count());
}

[[nodiscard]] constexpr auto posu::units::operator/(
    const quantity_of_measure auto& lhs,
    const quantity_of_measure auto& rhs) noexcept
{
    using lhs_type  = std::remove_cvref_t<decltype(lhs)>;
    using rhs_type  = std::remove_cvref_t<decltype(rhs)>;
    using rep       = std::common_type_t<typename lhs_type::rep, typename rhs_type::rep>;
    using period    = std::ratio_divide<typename lhs_type::period, typename rhs_type::period>;
    using unit_type = unit_divide<unit_t<lhs_type>, unit_t<rhs_type>>;

    return quantity<rep, period, unit_type>(lhs.count() / rhs.count());
}

template<posu::units::quantity_of_measure Quantity>
[[nodiscard]] constexpr auto
posu::units::operator/(const rep_t<Quantity>& lhs, const Quantity& rhs) noexcept
{
    using rep       = rep_t<Quantity>;
    using period    = std::ratio_divide<std::ratio<1>, typename Quantity::period>;
    using unit_type = unit_divide<scaler, unit_t<Quantity>>;

    return quantity<rep, period, unit_type>(lhs / rhs.count());
}
