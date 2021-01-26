#include <utility>

[[nodiscard]] constexpr auto
posu::units::detail::to_duration(const base_quantity auto& quantity) noexcept
{
    return quantity.m_duration;
}

template<typename Rep, typename Period, typename Tag>
    requires(posu::arithmetic<Rep>)
template<typename Rep2>
    requires(
        std::convertible_to<Rep, const Rep2&> && (std::chrono::treat_as_floating_point_v<Rep> ||
                                                  !std::chrono::treat_as_floating_point_v<Rep2>))
constexpr posu::units::base_unit<Rep, Period, Tag>::base_unit(const Rep2& r) : m_duration(r)
{
}

template<typename Rep, typename Period, typename Tag>
    requires(posu::arithmetic<Rep>)
template<typename Rep2, typename Period2>
    requires(
        std::chrono::treat_as_floating_point_v<Rep> ||
        ((std::ratio_divide<Period2, Period>::den == 1) &&
         !std::chrono::treat_as_floating_point_v<Rep2>))
constexpr posu::units::base_unit<Rep, Period, Tag>::base_unit(
    const base_unit<Rep2, Period2, Tag>& d)
    : m_duration{detail::to_duration(d)}
{
}

template<typename Rep, typename Period, typename Tag>
    requires(posu::arithmetic<Rep>)
[[nodiscard]] constexpr auto posu::units::base_unit<Rep, Period, Tag>::count() const noexcept
{
    return m_duration.count();
}

template<typename Rep, typename Period, typename Tag>
    requires(posu::arithmetic<Rep>)
template<typename RRep, typename RPeriod>
[[nodiscard]] constexpr auto posu::units::base_unit<Rep, Period, Tag>::operator==(
    const base_unit<RRep, RPeriod, units>& rhs) const noexcept
{
    return m_duration == detail::to_duration(rhs);
}

template<typename Rep, typename Period, typename Tag>
    requires(posu::arithmetic<Rep>)
template<typename RRep, typename RPeriod>
[[nodiscard]] constexpr auto posu::units::base_unit<Rep, Period, Tag>::operator<=>(
    const base_unit<RRep, RPeriod, units>& rhs) const noexcept
{
    return m_duration <=> detail::to_duration(rhs);
}
