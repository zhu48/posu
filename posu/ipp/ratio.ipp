
template<std::intmax_t Num, std::intmax_t Den, std::intmax_t Exp>
template<std::intmax_t RNum, std::intmax_t RDenom, std::intmax_t RExp>
[[nodiscard]] constexpr auto
posu::ratio<Num, Den, Exp>::operator+(ratio<RNum, RDenom, RExp> rhs) noexcept
{
    constexpr auto s_exp = std::max(exp, rhs.exp);
    using l_norm         = denormalize<ratio, s_exp>;
    using r_norm         = denormalize<ratio<RNum, RDenom, RExp>, s_exp>;
    using s_std =
        std::ratio_add<std::ratio<l_norm::num, l_norm::den>, std::ratio<r_norm::num, r_norm::den>>;

    return normalize<ratio<s_std::num, s_std::den, s_exp>>{};
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
    using reduced = ratio_multiply<Ratio, ratio<1>>;
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
