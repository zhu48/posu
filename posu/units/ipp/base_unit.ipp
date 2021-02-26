#include <utility>

template<std::size_t Num, std::size_t Den>
struct posu::units::detail::is_std_ratio<std::ratio<Num, Den>> : std::true_type {
};

[[nodiscard]] constexpr auto
posu::units::detail::to_duration(const base_quantity auto& quantity) noexcept
{
    return quantity.m_duration;
}

template<
    posu::arithmetic                      Rep,
    posu::units::detail::std_ratio        Period,
    posu::meta_constant<std::string_view> Tag>
template<typename Rep2>
    requires(
        std::convertible_to<Rep, const Rep2&> && (std::chrono::treat_as_floating_point_v<Rep> ||
                                                  !std::chrono::treat_as_floating_point_v<Rep2>))
constexpr posu::units::base_unit<Rep, Period, Tag>::base_unit(const Rep2& r) : m_duration(r)
{
}

template<
    posu::arithmetic                      Rep,
    posu::units::detail::std_ratio        Period,
    posu::meta_constant<std::string_view> Tag>
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

template<
    posu::arithmetic                      Rep,
    posu::units::detail::std_ratio        Period,
    posu::meta_constant<std::string_view> Tag>
[[nodiscard]] constexpr auto posu::units::base_unit<Rep, Period, Tag>::count() const noexcept
{
    return m_duration.count();
}

template<
    posu::arithmetic                      Rep,
    posu::units::detail::std_ratio        Period,
    posu::meta_constant<std::string_view> Tag>
template<typename RRep, typename RPeriod>
[[nodiscard]] constexpr auto posu::units::base_unit<Rep, Period, Tag>::operator==(
    const base_unit<RRep, RPeriod, units>& rhs) const noexcept
{
    return m_duration == detail::to_duration(rhs);
}

template<
    posu::arithmetic                      Rep,
    posu::units::detail::std_ratio        Period,
    posu::meta_constant<std::string_view> Tag>
template<typename RRep, typename RPeriod>
[[nodiscard]] constexpr auto posu::units::base_unit<Rep, Period, Tag>::operator<=>(
    const base_unit<RRep, RPeriod, units>& rhs) const noexcept
{
    return m_duration <=> detail::to_duration(rhs);
}

template<
    posu::arithmetic                      Rep,
    posu::units::detail::std_ratio        Period,
    posu::meta_constant<std::string_view> Tag>
[[nodiscard]] constexpr auto posu::units::base_unit<Rep, Period, Tag>::operator+() const noexcept
{
    return base_unit(count());
}

template<
    posu::arithmetic                      Rep,
    posu::units::detail::std_ratio        Period,
    posu::meta_constant<std::string_view> Tag>
[[nodiscard]] constexpr auto posu::units::base_unit<Rep, Period, Tag>::operator-() const noexcept
{
    return base_unit(-count());
}

template<
    posu::arithmetic                      Rep,
    posu::units::detail::std_ratio        Period,
    posu::meta_constant<std::string_view> Tag>
constexpr auto& posu::units::base_unit<Rep, Period, Tag>::operator++() noexcept
{
    ++m_duration;

    return *this;
}

template<
    posu::arithmetic                      Rep,
    posu::units::detail::std_ratio        Period,
    posu::meta_constant<std::string_view> Tag>
constexpr auto posu::units::base_unit<Rep, Period, Tag>::operator++(int) noexcept
{
    const auto old_val = count();

    ++m_duration;

    return base_unit(old_val);
}

template<
    posu::arithmetic                      Rep,
    posu::units::detail::std_ratio        Period,
    posu::meta_constant<std::string_view> Tag>
constexpr auto& posu::units::base_unit<Rep, Period, Tag>::operator--() noexcept
{
    --m_duration;

    return *this;
}

template<
    posu::arithmetic                      Rep,
    posu::units::detail::std_ratio        Period,
    posu::meta_constant<std::string_view> Tag>
constexpr auto posu::units::base_unit<Rep, Period, Tag>::operator--(int) noexcept
{
    const auto old_val = count();

    --m_duration;

    return base_unit(old_val);
}

template<
    posu::arithmetic                      Rep,
    posu::units::detail::std_ratio        Period,
    posu::meta_constant<std::string_view> Tag>
constexpr auto& posu::units::base_unit<Rep, Period, Tag>::operator+=(const base_unit& rhs) noexcept
{
    m_duration += rhs.m_duration;

    return *this;
}

template<
    posu::arithmetic                      Rep,
    posu::units::detail::std_ratio        Period,
    posu::meta_constant<std::string_view> Tag>
constexpr auto& posu::units::base_unit<Rep, Period, Tag>::operator-=(const base_unit& rhs) noexcept
{
    m_duration -= rhs.m_duration;

    return *this;
}

template<
    posu::arithmetic                      Rep,
    posu::units::detail::std_ratio        Period,
    posu::meta_constant<std::string_view> Tag>
constexpr auto& posu::units::base_unit<Rep, Period, Tag>::operator*=(const rep& rhs) noexcept
{
    m_duration *= rhs;

    return *this;
}

template<
    posu::arithmetic                      Rep,
    posu::units::detail::std_ratio        Period,
    posu::meta_constant<std::string_view> Tag>
constexpr auto& posu::units::base_unit<Rep, Period, Tag>::operator/=(const rep& rhs) noexcept
{
    m_duration /= rhs;

    return *this;
}

template<
    posu::arithmetic                      Rep,
    posu::units::detail::std_ratio        Period,
    posu::meta_constant<std::string_view> Tag>
constexpr auto& posu::units::base_unit<Rep, Period, Tag>::operator%=(const rep& rhs) noexcept
{
    m_duration %= rhs;

    return *this;
}

template<
    posu::arithmetic                      Rep,
    posu::units::detail::std_ratio        Period,
    posu::meta_constant<std::string_view> Tag>
constexpr auto& posu::units::base_unit<Rep, Period, Tag>::operator%=(const base_unit& rhs) noexcept
{
    m_duration %= rhs.m_duration;

    return *this;
}

template<posu::units::base_quantity Lhs, posu::units::quantity_of<Lhs> Rhs>
[[nodiscard]] auto posu::units::operator+(const Lhs& lhs, const Rhs& rhs) noexcept
{
    return std::common_type_t<Lhs, Rhs>(
        (detail::to_duration(lhs) + detail::to_duration(rhs)).count());
}

template<posu::units::base_quantity Lhs, posu::units::quantity_of<Lhs> Rhs>
[[nodiscard]] auto posu::units::operator-(const Lhs& lhs, const Rhs& rhs) noexcept
{
    return std::common_type_t<Lhs, Rhs>(
        (detail::to_duration(lhs) - detail::to_duration(rhs)).count());
}

template<posu::arithmetic Lhs, typename Rep, typename Period, typename Units>
[[nodiscard]] auto
posu::units::operator*(const Lhs& lhs, const base_unit<Rep, Period, Units>& rhs) noexcept
{
    return base_unit<std::common_type_t<Lhs, Rep>, Period, Units>(
        (lhs * detail::to_duration(rhs)).count());
}

[[nodiscard]] auto posu::units::operator*(
    const posu::units::base_quantity auto& lhs,
    const arithmetic auto&                 rhs) noexcept
{
    return rhs * lhs;
}

template<posu::units::base_quantity Lhs>
[[nodiscard]] auto posu::units::operator/(const Lhs& lhs, const quantity_of<Lhs> auto& rhs) noexcept
{
    return detail::to_duration(lhs) / detail::to_duration(rhs);
}

template<typename Rep, typename Period, typename Units, posu::arithmetic Rhs>
[[nodiscard]] auto
posu::units::operator/(const base_unit<Rep, Period, Units>& lhs, const Rhs& rhs) noexcept
{
    return base_unit<std::common_type_t<Rep, Rhs>, Period, Units>(lhs.count() / rhs);
}

template<posu::units::base_quantity Lhs, posu::units::quantity_of<Lhs> Rhs>
[[nodiscard]] auto posu::units::operator%(const Lhs& lhs, const Rhs& rhs) noexcept
{
    return std::common_type_t<Lhs, Rhs>(
        (detail::to_duration(lhs) % detail::to_duration(rhs)).count());
}

template<typename Rep, typename Period, typename Units, posu::arithmetic Rhs>
[[nodiscard]] auto
posu::units::operator%(const base_unit<Rep, Period, Units>& lhs, const Rhs& rhs) noexcept
{
    return base_unit<std::common_type_t<Rep, Rhs>, Period, Units>(lhs.count() % rhs);
}
