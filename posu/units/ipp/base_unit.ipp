#include <utility>

template<std::size_t Num, std::size_t Den>
struct posu::units::detail::is_std_ratio<std::ratio<Num, Den>> : std::true_type {
};

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::kind Kind>
struct posu::units::is_quantity<posu::units::quantity<Rep, Period, Kind>> : public std::true_type {
};

[[nodiscard]] constexpr auto
posu::units::detail::to_duration(const quantity_of_measure auto& quant) noexcept
{
    return quant.m_duration;
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::kind Kind>
template<typename Rep2>
    requires(
        std::convertible_to<Rep, const Rep2&> && (std::chrono::treat_as_floating_point_v<Rep> ||
                                                  !std::chrono::treat_as_floating_point_v<Rep2>))
constexpr posu::units::quantity<Rep, Period, Kind>::quantity(const Rep2& r) : m_duration(r)
{
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::kind Kind>
template<typename Rep2, typename Period2>
    requires(
        std::chrono::treat_as_floating_point_v<Rep> ||
        ((std::ratio_divide<Period2, Period>::den == 1) &&
         !std::chrono::treat_as_floating_point_v<Rep2>))
constexpr posu::units::quantity<Rep, Period, Kind>::quantity(const quantity<Rep2, Period2, Kind>& d)
    : m_duration{detail::to_duration(d)}
{
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::kind Kind>
[[nodiscard]] constexpr auto posu::units::quantity<Rep, Period, Kind>::count() const noexcept
{
    return m_duration.count();
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::kind Kind>
template<typename RRep, typename RPeriod, typename RKind>
    requires(std::same_as<Kind, RKind> || posu::units::unknown_kind<RKind>)
[[nodiscard]] constexpr bool posu::units::quantity<Rep, Period, Kind>::operator==(
    const quantity<RRep, RPeriod, RKind>& rhs) const noexcept
{
    return m_duration == detail::to_duration(rhs);
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::kind Kind>
template<typename RRep, typename RPeriod, typename RKind>
    requires(std::same_as<Kind, RKind> || posu::units::unknown_kind<RKind>)
[[nodiscard]] constexpr auto posu::units::quantity<Rep, Period, Kind>::operator<=>(
    const quantity<RRep, RPeriod, RKind>& rhs) const noexcept
{
    return m_duration <=> detail::to_duration(rhs);
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::kind Kind>
[[nodiscard]] constexpr auto posu::units::quantity<Rep, Period, Kind>::operator+() const noexcept
{
    return quantity(count());
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::kind Kind>
[[nodiscard]] constexpr auto posu::units::quantity<Rep, Period, Kind>::operator-() const noexcept
{
    return quantity(-count());
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::kind Kind>
constexpr auto& posu::units::quantity<Rep, Period, Kind>::operator++() noexcept
{
    ++m_duration;

    return *this;
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::kind Kind>
constexpr auto posu::units::quantity<Rep, Period, Kind>::operator++(int) noexcept
{
    const auto old_val = count();

    ++m_duration;

    return quantity(old_val);
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::kind Kind>
constexpr auto& posu::units::quantity<Rep, Period, Kind>::operator--() noexcept
{
    --m_duration;

    return *this;
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::kind Kind>
constexpr auto posu::units::quantity<Rep, Period, Kind>::operator--(int) noexcept
{
    const auto old_val = count();

    --m_duration;

    return quantity(old_val);
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::kind Kind>
constexpr auto& posu::units::quantity<Rep, Period, Kind>::operator+=(const quantity& rhs) noexcept
{
    m_duration += rhs.m_duration;

    return *this;
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::kind Kind>
constexpr auto& posu::units::quantity<Rep, Period, Kind>::operator-=(const quantity& rhs) noexcept
{
    m_duration -= rhs.m_duration;

    return *this;
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::kind Kind>
constexpr auto& posu::units::quantity<Rep, Period, Kind>::operator*=(const rep& rhs) noexcept
{
    m_duration *= rhs;

    return *this;
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::kind Kind>
constexpr auto& posu::units::quantity<Rep, Period, Kind>::operator/=(const rep& rhs) noexcept
{
    m_duration /= rhs;

    return *this;
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::kind Kind>
constexpr auto& posu::units::quantity<Rep, Period, Kind>::operator%=(const rep& rhs) noexcept
{
    m_duration %= rhs;

    return *this;
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::kind Kind>
constexpr auto& posu::units::quantity<Rep, Period, Kind>::operator%=(const quantity& rhs) noexcept
{
    m_duration %= rhs.m_duration;

    return *this;
}

template<posu::units::quantity_of_measure Lhs>
[[nodiscard]] constexpr auto
posu::units::operator+(const Lhs& lhs, const quantity_of<kind_t<Lhs>> auto& rhs) noexcept
{
    return std::common_type_t<Lhs, std::remove_cvref_t<decltype(rhs)>>(
        (detail::to_duration(lhs) + detail::to_duration(rhs)).count());
}

template<posu::units::quantity_of_measure Lhs>
[[nodiscard]] constexpr auto
posu::units::operator-(const Lhs& lhs, const quantity_of<kind_t<Lhs>> auto& rhs) noexcept
{
    return std::common_type_t<Lhs, std::remove_cvref_t<decltype(rhs)>>(
        (detail::to_duration(lhs) - detail::to_duration(rhs)).count());
}

[[nodiscard]] constexpr auto posu::units::operator*(
    const posu::arithmetic auto&                 lhs,
    const posu::units::quantity_of_measure auto& rhs) noexcept
{
    using lhs_type = std::remove_cvref_t<decltype(lhs)>;
    using rhs_type = std::remove_cvref_t<decltype(rhs)>;

    return quantity<
        std::common_type_t<lhs_type, typename rhs_type::rep>,
        typename rhs_type::period,
        kind_t<rhs_type>>((lhs * detail::to_duration(rhs)).count());
}

[[nodiscard]] constexpr auto posu::units::operator*(
    const posu::units::quantity_of_measure auto& lhs,
    const posu::arithmetic auto&                 rhs) noexcept
{
    return rhs * lhs;
}

template<posu::units::quantity_of_measure Lhs>
[[nodiscard]] constexpr auto
posu::units::operator/(const Lhs& lhs, const quantity_of<kind_t<Lhs>> auto& rhs) noexcept
{
    using rep = decltype(detail::to_duration(lhs) / detail::to_duration(rhs));

    return quantity<rep, std::ratio<1>, scaler>(
        detail::to_duration(lhs) / detail::to_duration(rhs));
}

[[nodiscard]] constexpr auto
posu::units::operator/(const quantity_of_measure auto& lhs, const arithmetic auto& rhs) noexcept
{
    using lhs_type = std::remove_cvref_t<decltype(lhs)>;
    using rep      = typename lhs_type::rep;
    using period   = typename lhs_type::period;
    using rhs_type = std::remove_cvref_t<decltype(rhs)>;

    return quantity<std::common_type_t<rep, rhs_type>, period, kind_t<lhs_type>>(lhs.count() / rhs);
}

template<posu::units::quantity_of_measure Lhs>
[[nodiscard]] constexpr auto
posu::units::operator%(const Lhs& lhs, const quantity_of<kind_t<Lhs>> auto& rhs) noexcept
{
    return std::common_type_t<Lhs, std::remove_cvref_t<decltype(rhs)>>(
        (detail::to_duration(lhs) % detail::to_duration(rhs)).count());
}

[[nodiscard]] constexpr auto
posu::units::operator%(const quantity_of_measure auto& lhs, const arithmetic auto& rhs) noexcept
{
    using lhs_type = std::remove_cvref_t<decltype(lhs)>;
    using rep      = typename lhs_type::rep;
    using period   = typename lhs_type::period;
    using rhs_type = std::remove_cvref_t<decltype(rhs)>;

    return quantity<std::common_type_t<rep, rhs_type>, period, kind_t<lhs_type>>(lhs.count() % rhs);
}
