#include <utility>

template<std::intmax_t Num, std::intmax_t Den>
struct posu::units::detail::is_std_ratio<std::ratio<Num, Den>> : std::true_type {
};

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::unit Unit>
struct posu::units::is_quantity<posu::units::quantity<Rep, Period, Unit>> : public std::true_type {
};

[[nodiscard]] constexpr auto
posu::units::detail::to_duration(const quantity_of_measure auto& quant) noexcept
{
    using quant_t = std::remove_cvref_t<decltype(quant)>;

    return std::chrono::duration<rep_t<quant_t>, typename quant_t::period>(quant.count());
}

template<posu::units::quantity_of_measure To, posu::units::quantity_of_measure From>
    requires(posu::units::quantity_comparable_with<To, From>)
[[nodiscard]] constexpr auto posu::units::quantity_cast(const From& quant) noexcept -> To
{
    using to_rep        = rep_t<To>;
    using to_period     = typename To::period;
    using to_underlying = std::chrono::duration<to_rep, to_period>;

    return To(std::chrono::duration_cast<to_underlying>(detail::to_duration(quant)).count());
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::unit Unit>
template<typename Rep2>
    requires(
        std::convertible_to<Rep, const Rep2&> && (std::chrono::treat_as_floating_point_v<Rep> ||
                                                  !std::chrono::treat_as_floating_point_v<Rep2>))
constexpr posu::units::quantity<Rep, Period, Unit>::quantity(const Rep2& r) : m_duration(r)
{
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::unit Unit>
template<typename Rep2, typename Period2, posu::units::unit_comparable_with<Unit> Unit2>
    requires(
        std::chrono::treat_as_floating_point_v<Rep> ||
        ((std::ratio_divide<Period2, Period>::den == 1) &&
         !std::chrono::treat_as_floating_point_v<Rep2>))
constexpr posu::units::quantity<Rep, Period, Unit>::quantity(
    const quantity<Rep2, Period2, Unit2>& d)
    : m_duration{detail::to_duration(d)}
{
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::unit Unit>
[[nodiscard]] constexpr auto posu::units::quantity<Rep, Period, Unit>::count() const noexcept
{
    return m_duration.count();
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::unit Unit>
template<typename RRep, typename RPeriod, posu::units::unit_of<posu::units::kind_t<Unit>> RUnit>
[[nodiscard]] constexpr bool posu::units::quantity<Rep, Period, Unit>::operator==(
    const quantity<RRep, RPeriod, RUnit>& rhs) const noexcept
{
    return m_duration == detail::to_duration(rhs);
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::unit Unit>
template<typename RRep, typename RPeriod, posu::units::unit_of<posu::units::kind_t<Unit>> RUnit>
[[nodiscard]] constexpr auto posu::units::quantity<Rep, Period, Unit>::operator<=>(
    const quantity<RRep, RPeriod, RUnit>& rhs) const noexcept
{
    return m_duration <=> detail::to_duration(rhs);
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::unit Unit>
[[nodiscard]] constexpr auto posu::units::quantity<Rep, Period, Unit>::operator+() const noexcept
{
    return quantity(count());
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::unit Unit>
[[nodiscard]] constexpr auto posu::units::quantity<Rep, Period, Unit>::operator-() const noexcept
{
    return quantity(-count());
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::unit Unit>
constexpr auto& posu::units::quantity<Rep, Period, Unit>::operator++() noexcept
{
    ++m_duration;

    return *this;
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::unit Unit>
constexpr auto posu::units::quantity<Rep, Period, Unit>::operator++(int) noexcept
{
    const auto old_val = count();

    ++m_duration;

    return quantity(old_val);
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::unit Unit>
constexpr auto& posu::units::quantity<Rep, Period, Unit>::operator--() noexcept
{
    --m_duration;

    return *this;
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::unit Unit>
constexpr auto posu::units::quantity<Rep, Period, Unit>::operator--(int) noexcept
{
    const auto old_val = count();

    --m_duration;

    return quantity(old_val);
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::unit Unit>
constexpr auto& posu::units::quantity<Rep, Period, Unit>::operator+=(const quantity& rhs) noexcept
{
    m_duration += rhs.m_duration;

    return *this;
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::unit Unit>
constexpr auto& posu::units::quantity<Rep, Period, Unit>::operator-=(const quantity& rhs) noexcept
{
    m_duration -= rhs.m_duration;

    return *this;
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::unit Unit>
constexpr auto& posu::units::quantity<Rep, Period, Unit>::operator*=(const rep& rhs) noexcept
{
    m_duration *= rhs;

    return *this;
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::unit Unit>
constexpr auto& posu::units::quantity<Rep, Period, Unit>::operator/=(const rep& rhs) noexcept
{
    m_duration /= rhs;

    return *this;
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::unit Unit>
constexpr auto& posu::units::quantity<Rep, Period, Unit>::operator%=(const rep& rhs) noexcept
{
    m_duration %= rhs;

    return *this;
}

template<posu::arithmetic Rep, posu::units::detail::std_ratio Period, posu::units::unit Unit>
constexpr auto& posu::units::quantity<Rep, Period, Unit>::operator%=(const quantity& rhs) noexcept
{
    m_duration %= rhs.m_duration;

    return *this;
}

template<posu::units::quantity_category Category>
[[nodiscard]] constexpr auto
posu::units::of(const quantity_comparable_with<Category> auto& quant) noexcept
{
    using from_type = std::remove_cvref_t<decltype(quant)>;
    using rep       = rep_t<from_type>;
    using period    = typename from_type::period;

    if constexpr(unit<Category>) {
        return quantity_cast<quantity<rep, period, Category>>(quant);
    }
    else {
        return quantity_cast<quantity<rep, period, unknown<Category>>>(quant);
    }
}
