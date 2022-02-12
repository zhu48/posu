
template<std::intmax_t Num, std::intmax_t Den, std::intmax_t Exp>
[[nodiscard]] constexpr auto
posu::ratio<Num, Den, Exp>::operator+(posu::ratio_type auto rhs) noexcept
{
    constexpr auto s_exp = (exp + rhs.exp) / 2;
    using l_norm         = denormalize<ratio, s_exp>;
    using r_norm         = denormalize<decltype(rhs), s_exp>;
    using s_std =
        std::ratio_add<std::ratio<l_norm::num, l_norm::den>, std::ratio<r_norm::num, r_norm::den>>;

    return normalize<ratio<s_std::num, s_std::den, s_exp>>{};
}

template<std::intmax_t Num, std::intmax_t Den, std::intmax_t Exp>
[[nodiscard]] constexpr auto
posu::ratio<Num, Den, Exp>::operator-(posu::ratio_type auto rhs) noexcept
{
    constexpr auto s_exp = (exp + rhs.exp) / 2;
    using l_norm         = denormalize<ratio, s_exp>;
    using r_norm         = denormalize<decltype(rhs), s_exp>;
    using s_std          = std::
        ratio_subtract<std::ratio<l_norm::num, l_norm::den>, std::ratio<r_norm::num, r_norm::den>>;

    return normalize<ratio<s_std::num, s_std::den, s_exp>>{};
}

template<std::intmax_t Num, std::intmax_t Den, std::intmax_t Exp>
[[nodiscard]] constexpr auto
posu::ratio<Num, Den, Exp>::operator*(posu::ratio_type auto rhs) noexcept
{
    using std_l = std::ratio<num, den>;
    using std_r = std::ratio<rhs.num, rhs.den>;
    using prod  = std::ratio_multiply<std_l, std_r>;

    return normalize<ratio<prod::num, prod::den, exp + rhs.exp>>{};
}

template<std::intmax_t Num, std::intmax_t Den, std::intmax_t Exp>
[[nodiscard]] constexpr auto
posu::ratio<Num, Den, Exp>::operator/(posu::ratio_type auto rhs) noexcept
{
    using std_l = std::ratio<num, den>;
    using std_r = std::ratio<rhs.num, rhs.den>;
    using prod  = std::ratio_divide<std_l, std_r>;

    return normalize<ratio<prod::num, prod::den, exp - rhs.exp>>{};
}

template<posu::ratio_type Ratio, std::intmax_t NewExp>
[[nodiscard]] constexpr auto posu::detail::denormalize() noexcept
{
    if constexpr(Ratio::exp > NewExp) {
        return denormalize<ratio<Ratio::num * 10, Ratio::den, Ratio::exp - 1>, NewExp>();
    }
    else if constexpr(Ratio::exp < NewExp) {
        return denormalize<ratio<Ratio::num, Ratio::den * 10, Ratio::exp + 1>, NewExp>();
    }
    else {
        return Ratio{};
    }
}

template<posu::ratio_type Ratio>
[[nodiscard]] constexpr auto posu::detail::normalize() noexcept
{
    using std_ratio   = std::ratio<Ratio::num, Ratio::den>;
    using std_reduced = std::ratio_multiply<std_ratio, std::ratio<1>>;

    using reduced = ratio<std_reduced::num, std_reduced::den, Ratio::exp>;
    if constexpr(!(reduced::num % 10)) {
        return normalize<ratio<reduced::num / 10, reduced::den, reduced::exp + 1>>();
    }
    else if constexpr(!(reduced::den % 10)) {
        return normalize<ratio<reduced::num, reduced::den / 10, reduced::exp - 1>>();
    }
    else {
        return reduced{};
    }
}
