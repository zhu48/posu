
namespace posu::detail {

    struct ratio_info {
        std::intmax_t num;
        std::intmax_t den{1};
        std::intmax_t exp{0};
    };

} // namespace posu::detail

template<std::intmax_t Num, std::intmax_t Den, std::intmax_t Exp>
[[nodiscard]] constexpr auto posu::ratio<Num, Den, Exp>::operator+(ratio_type auto rhs) noexcept
{
    constexpr auto s_exp = (exp + rhs.exp) / 2;

    constexpr auto l = detail::denormalize<num, den, exp, s_exp>();
    constexpr auto r = detail::denormalize<rhs.num, rhs.den, rhs.exp, s_exp>();
    constexpr auto s = std::ratio_add<std::ratio<l.num, l.den>, std::ratio<r.num, r.den>>{};

    return normalize<ratio<s.num, s.den, s_exp>>{};
}

template<std::intmax_t Num, std::intmax_t Den, std::intmax_t Exp>
[[nodiscard]] constexpr auto posu::ratio<Num, Den, Exp>::operator-(ratio_type auto rhs) noexcept
{
    constexpr auto s_exp = (exp + rhs.exp) / 2;

    constexpr auto l = detail::denormalize<num, den, exp, s_exp>();
    constexpr auto r = detail::denormalize<rhs.num, rhs.den, rhs.exp, s_exp>();
    constexpr auto s = std::ratio_subtract<std::ratio<l.num, l.den>, std::ratio<r.num, r.den>>{};

    return normalize<ratio<s.num, s.den, s_exp>>{};
}

template<std::intmax_t Num, std::intmax_t Den, std::intmax_t Exp>
[[nodiscard]] constexpr auto posu::ratio<Num, Den, Exp>::operator*(ratio_type auto rhs) noexcept
{
    using std_l = std::ratio<num, den>;
    using std_r = std::ratio<rhs.num, rhs.den>;
    using prod  = std::ratio_multiply<std_l, std_r>;

    return normalize<ratio<prod::num, prod::den, exp + rhs.exp>>{};
}

template<std::intmax_t Num, std::intmax_t Den, std::intmax_t Exp>
[[nodiscard]] constexpr auto posu::ratio<Num, Den, Exp>::operator/(ratio_type auto rhs) noexcept
{
    using std_l = std::ratio<num, den>;
    using std_r = std::ratio<rhs.num, rhs.den>;
    using prod  = std::ratio_divide<std_l, std_r>;

    return normalize<ratio<prod::num, prod::den, exp - rhs.exp>>{};
}

template<std::intmax_t Num, std::intmax_t Den, std::intmax_t Exp, std::intmax_t NewExp>
[[nodiscard]] constexpr auto posu::detail::denormalize() noexcept
{
    if constexpr(Exp > NewExp) {
        return denormalize<Num * 10, Den, Exp - 1, NewExp>();
    }
    else if constexpr(Exp < NewExp) {
        return denormalize<Num, Den * 10, Exp + 1, NewExp>();
    }
    else {
        return ratio_info{Num, Den, Exp};
    }
}

template<std::intmax_t Num, std::intmax_t Den, std::intmax_t Exp>
[[nodiscard]] constexpr auto posu::detail::normalize() noexcept
{
    using std_ratio = typename std::ratio<Num, Den>::type;
    if constexpr(std_ratio::num == 0) {
        return ratio_info{0};
    }
    else if constexpr(!(std_ratio::num % 10)) {
        return normalize<std_ratio::num / 10, std_ratio::den, Exp + 1>();
    }
    else if constexpr(!(std_ratio::den % 10)) {
        return normalize<std_ratio::num, std_ratio::den / 10, Exp - 1>();
    }
    else {
        return ratio_info{Num, Den, Exp};
    }
}
