
namespace posu::units::detail {

    template<typename T>
    struct units_ratio_type {
        using type = type_ratio<type_list<T>, type_list<>>;
    };

    template<typename T>
        requires(meta_ratio<T>)
    struct units_ratio_type<T> {
        using type = T;
    };

    template<typename T>
        requires(derived_units<T>)
    struct units_ratio_type<T> : public units_ratio_type<typename T::derivation> {
    };

    template<typename T>
    using units_ratio_type_t = typename units_ratio_type<T>::type;

    inline constexpr char empty_string[] = "";

} // namespace posu::units::detail

template<posu::units::quantity Lhs, posu::units::quantity Rhs>
[[nodiscard]] auto posu::units::operator*(const Lhs& lhs, const Rhs& rhs) noexcept
{
    using rep        = std::common_type_t<typename Lhs::rep, typename Rhs::rep>;
    using period     = std::ratio_multiply<typename Lhs::period, typename Rhs::period>;
    using derivation = ratio_multiply<
        detail::units_ratio_type_t<typename Lhs::units>,
        detail::units_ratio_type_t<typename Rhs::units>>;
    using units = derived_unit_tag<derivation, detail::empty_string>;

    return derived_unit<rep, period, units>(lhs.count() * rhs.count());
}

template<posu::units::quantity Lhs, posu::units::quantity Rhs>
[[nodiscard]] auto posu::units::operator/(const Lhs& lhs, const Rhs& rhs) noexcept
{
    using rep        = std::common_type_t<typename Lhs::rep, typename Rhs::rep>;
    using period     = std::ratio_divide<typename Lhs::period, typename Rhs::period>;
    using derivation = ratio_divide<
        detail::units_ratio_type_t<typename Lhs::units>,
        detail::units_ratio_type_t<typename Rhs::units>>;
    using units = derived_unit_tag<derivation, detail::empty_string>;

    return derived_unit<rep, period, units>(lhs.count() / rhs.count());
}
