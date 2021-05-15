
[[nodiscard]] constexpr auto posu::units::operator*(
    const quantity_of_measure auto& lhs,
    const quantity_of_measure auto& rhs) noexcept
{
    using lhs_type  = std::remove_cvref_t<decltype(lhs)>;
    using rhs_type  = std::remove_cvref_t<decltype(rhs)>;
    using rep       = std::common_type_t<typename lhs_type::rep, typename rhs_type::rep>;
    using period    = std::ratio_multiply<typename lhs_type::period, typename rhs_type::period>;
    using kind_type = kind_multiply<kind_t<lhs_type>, kind_t<rhs_type>>;

    return quantity<rep, period, kind_type>(lhs.count() * rhs.count());
}

[[nodiscard]] constexpr auto posu::units::operator/(
    const quantity_of_measure auto& lhs,
    const quantity_of_measure auto& rhs) noexcept
{
    using lhs_type  = std::remove_cvref_t<decltype(lhs)>;
    using rhs_type  = std::remove_cvref_t<decltype(rhs)>;
    using rep       = std::common_type_t<typename lhs_type::rep, typename rhs_type::rep>;
    using period    = std::ratio_divide<typename lhs_type::period, typename rhs_type::period>;
    using kind_type = kind_divide<kind_t<lhs_type>, kind_t<rhs_type>>;

    return quantity<rep, period, kind_type>(lhs.count() / rhs.count());
}
