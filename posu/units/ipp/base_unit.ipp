
template<posu::units::quantity_of_measure To, posu::units::quantity_of_measure From>
    requires(posu::units::quantity_comparable_with<To, From>)
[[nodiscard]] constexpr auto posu::units::quantity_cast(const From& quantity) noexcept -> To
{
    constexpr auto from_ratio = period_t<From>{} * period_t<unit_t<From>>{};
    constexpr auto to_ratio   = period_t<To>{} * period_t<unit_t<To>>{};
    constexpr auto conv_ratio = from_ratio / to_ratio;

    return To{static_cast<rep_t<To>>(quantity.count() * conv_ratio)};
}

template<posu::arithmetic Rep, posu::ratio_type Period, posu::units::unit Unit>
template<typename Rep2>
    requires(
        std::convertible_to<Rep, const Rep2&> && (std::chrono::treat_as_floating_point_v<Rep> ||
                                                  !std::chrono::treat_as_floating_point_v<Rep2>))
constexpr posu::units::quantity<Rep, Period, Unit>::quantity(const Rep2& r)
    : m_count{static_cast<rep>(r)}
{
}

template<posu::arithmetic Rep, posu::ratio_type Period, posu::units::unit Unit>
template<typename Rep2, typename Period2, posu::units::unit_comparable_with<Unit> Unit2>
    requires(
        std::chrono::treat_as_floating_point_v<Rep> ||
        ((posu::ratio_divide<Period2, Period>::den == 1) &&
         (posu::ratio_divide<Period2, Period>::exp >= 0) &&
         !std::chrono::treat_as_floating_point_v<Rep2>))
constexpr posu::units::quantity<Rep, Period, Unit>::quantity(
    const quantity<Rep2, Period2, Unit2>& d)
    : m_count{quantity_cast<quantity>(d).count()}
{
}

template<posu::arithmetic Rep, posu::ratio_type Period, posu::units::unit Unit>
template<posu::units::detail::std_chrono_duration T>
constexpr posu::units::quantity<Rep, Period, Unit>::quantity(const T& d) noexcept
    requires(detail::implicit_chrono<kind_type>)
    : quantity{quantity_cast<quantity>(detail::equivalent_quantity<T, kind_type>(d))}
{
}

template<posu::arithmetic Rep, posu::ratio_type Period, posu::units::unit Unit>
template<posu::units::detail::std_chrono_duration T>
[[nodiscard]] constexpr posu::units::quantity<Rep, Period, Unit>::operator T() const noexcept
    requires(detail::implicit_chrono<kind_type>)
{
    return T{quantity_cast<detail::equivalent_chrono<quantity>>(*this).count()};
}

template<posu::arithmetic Rep, posu::ratio_type Period, posu::units::unit Unit>
[[nodiscard]] constexpr auto posu::units::quantity<Rep, Period, Unit>::count() const noexcept
{
    return m_count;
}

template<posu::arithmetic Rep, posu::ratio_type Period, posu::units::unit Unit>
[[nodiscard]] constexpr bool posu::units::quantity<Rep, Period, Unit>::compare_equal(
    quantity_of<kind_type> auto const& rhs) const noexcept
{
    using common_type = std::common_type_t<quantity, std::remove_cvref_t<decltype(rhs)>>;

    return quantity_cast<common_type>(*this).count() == quantity_cast<common_type>(rhs).count();
}

template<posu::arithmetic Rep, posu::ratio_type Period, posu::units::unit Unit>
[[nodiscard]] constexpr auto posu::units::quantity<Rep, Period, Unit>::compare_three_way(
    quantity_of<kind_type> auto const& rhs) const noexcept
{
    using common_type = std::common_type_t<quantity, std::remove_cvref_t<decltype(rhs)>>;

    return quantity_cast<common_type>(*this).count() <=> quantity_cast<common_type>(rhs).count();
}

template<posu::arithmetic Rep, posu::ratio_type Period, posu::units::unit Unit>
[[nodiscard]] constexpr auto posu::units::quantity<Rep, Period, Unit>::operator+() const noexcept
{
    return quantity(count());
}

template<posu::arithmetic Rep, posu::ratio_type Period, posu::units::unit Unit>
[[nodiscard]] constexpr auto posu::units::quantity<Rep, Period, Unit>::operator-() const noexcept
{
    return quantity(-count());
}

template<posu::arithmetic Rep, posu::ratio_type Period, posu::units::unit Unit>
constexpr auto& posu::units::quantity<Rep, Period, Unit>::operator++() noexcept
{
    ++m_count;

    return *this;
}

template<posu::arithmetic Rep, posu::ratio_type Period, posu::units::unit Unit>
constexpr auto posu::units::quantity<Rep, Period, Unit>::operator++(int) noexcept
{
    const auto old_val = count();

    ++m_count;

    return quantity(old_val);
}

template<posu::arithmetic Rep, posu::ratio_type Period, posu::units::unit Unit>
constexpr auto& posu::units::quantity<Rep, Period, Unit>::operator--() noexcept
{
    --m_count;

    return *this;
}

template<posu::arithmetic Rep, posu::ratio_type Period, posu::units::unit Unit>
constexpr auto posu::units::quantity<Rep, Period, Unit>::operator--(int) noexcept
{
    const auto old_val = count();

    --m_count;

    return quantity(old_val);
}

template<posu::arithmetic Rep, posu::ratio_type Period, posu::units::unit Unit>
constexpr auto& posu::units::quantity<Rep, Period, Unit>::operator+=(const quantity& rhs) noexcept
{
    m_count += rhs.m_count;

    return *this;
}

template<posu::arithmetic Rep, posu::ratio_type Period, posu::units::unit Unit>
constexpr auto& posu::units::quantity<Rep, Period, Unit>::operator-=(const quantity& rhs) noexcept
{
    m_count -= rhs.m_count;

    return *this;
}

template<posu::arithmetic Rep, posu::ratio_type Period, posu::units::unit Unit>
constexpr auto& posu::units::quantity<Rep, Period, Unit>::operator*=(const rep& rhs) noexcept
{
    m_count *= rhs;

    return *this;
}

template<posu::arithmetic Rep, posu::ratio_type Period, posu::units::unit Unit>
constexpr auto& posu::units::quantity<Rep, Period, Unit>::operator/=(const rep& rhs) noexcept
{
    m_count /= rhs;

    return *this;
}

template<posu::arithmetic Rep, posu::ratio_type Period, posu::units::unit Unit>
constexpr auto& posu::units::quantity<Rep, Period, Unit>::operator%=(const rep& rhs) noexcept
{
    m_count %= rhs;

    return *this;
}

template<posu::arithmetic Rep, posu::ratio_type Period, posu::units::unit Unit>
constexpr auto& posu::units::quantity<Rep, Period, Unit>::operator%=(const quantity& rhs) noexcept
{
    m_count %= rhs.m_count;

    return *this;
}

template<posu::arithmetic Rep, posu::ratio_type Period, posu::units::unit Unit>
constexpr auto
posu::units::quantity<Rep, Period, Unit>::add(const quantity_of<kind_type> auto& rhs) const noexcept
{
    using common_type = std::common_type_t<quantity, std::remove_cvref_t<decltype(rhs)>>;

    const auto l = quantity_cast<common_type>(*this);
    const auto r = quantity_cast<common_type>(rhs);

    return common_type{l.count() + r.count()};
}

template<posu::arithmetic Rep, posu::ratio_type Period, posu::units::unit Unit>
constexpr auto posu::units::quantity<Rep, Period, Unit>::subtract(
    const quantity_of<kind_type> auto& rhs) const noexcept
{
    using common_type = std::common_type_t<quantity, std::remove_cvref_t<decltype(rhs)>>;

    const auto l = quantity_cast<common_type>(*this);
    const auto r = quantity_cast<common_type>(rhs);

    return common_type{l.count() - r.count()};
}

template<posu::arithmetic Rep, posu::ratio_type Period, posu::units::unit Unit>
constexpr auto
posu::units::quantity<Rep, Period, Unit>::multiply(const arithmetic auto& rhs) const noexcept
{
    using common_rep = decltype(count() * rhs);

    return quantity<common_rep, period, unit_type>(count() * rhs);
}

template<posu::arithmetic Rep, posu::ratio_type Period, posu::units::unit Unit>
template<typename Quantity>
constexpr auto posu::units::quantity<Rep, Period, Unit>::divide(const Quantity& rhs) const noexcept
    requires(quantity_of<Quantity, kind_type>)
{
    using div_period = ratio_divide<period, period_t<Quantity>>;
    using div_unit   = scaler<ratio_divide<period_t<unit_type>, period_t<unit_t<Quantity>>>>;
    constexpr auto div_scaler = div_period{} * period_t<div_unit>{};
    if constexpr(div_scaler >= ratio<1>{}) {
        using common_type = std::common_type_t<quantity, Quantity>;

        const auto l = quantity_cast<common_type>(*this);
        const auto r = quantity_cast<common_type>(rhs);

        return quantity<rep_t<common_type>, ratio<1>, scaler<>>(l.count() / r.count());
    }
    else {
        using div_rep  = std::common_type_t<rep, rep_t<Quantity>>;
        using div_type = quantity<div_rep, div_period, div_unit>;

        return div_type{count() / rhs.count()};
    }
}

template<posu::arithmetic Rep, posu::ratio_type Period, posu::units::unit Unit>
constexpr auto
posu::units::quantity<Rep, Period, Unit>::divide(const arithmetic auto& rhs) const noexcept
{
    using common_rep = std::remove_cvref_t<decltype(count() / rhs)>;

    return quantity<common_rep, period, unit_type>(count() / rhs);
}

template<posu::arithmetic Rep, posu::ratio_type Period, posu::units::unit Unit>
template<typename Quantity>
constexpr auto posu::units::quantity<Rep, Period, Unit>::modulo(const Quantity& rhs) const noexcept
    requires(quantity_of<Quantity, kind_type>)
{
    using common_type = std::common_type_t<quantity, Quantity>;

    const auto l = quantity_cast<common_type>(*this);
    const auto r = quantity_cast<common_type>(rhs);

    return common_type{l.count() % r.count()};
}

template<posu::arithmetic Rep, posu::ratio_type Period, posu::units::unit Unit>
constexpr auto
posu::units::quantity<Rep, Period, Unit>::modulo(const arithmetic auto& rhs) const noexcept
{
    using common_rep = decltype(count() % rhs);

    return quantity<common_rep, period, unit_type>{count() % rhs};
}

template<posu::units::quantity_category Category>
[[nodiscard]] constexpr auto
posu::units::of(const quantity_comparable_with<Category> auto& quant) noexcept
{
    using from_type   = std::remove_cvref_t<decltype(quant)>;
    using rep         = rep_t<from_type>;
    using from_period = period_t<from_type>;

    if constexpr(unit<Category>) {
        using period = ratio_multiply<
            from_period,
            ratio_divide<period_t<unit_t<from_type>>, period_t<Category>>>;

        return quantity_cast<quantity<rep, period, Category>>(quant);
    }
    else {
        return quantity_cast<quantity<rep, from_period, unknown<Category>>>(quant);
    }
}
