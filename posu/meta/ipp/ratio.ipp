
namespace posu::meta::detail {

    template<list_type Num, list_type Den>
    [[nodiscard]] constexpr auto make_ratio(Num /*unused*/, Den /*unused*/) noexcept
    {
        return ratio<Num, Den>{};
    }

    template<std::size_t I, list_type Num>
    [[nodiscard]] constexpr auto ratio_reduce_left_index(Num num, list_type auto den) noexcept
    {
        if constexpr(num.empty() || den.empty()) {
            return make_ratio(num, den);
        }
        else {
            constexpr auto pos = find<at<Num, I>>(den);
            if constexpr(pos < den.size()) {
                return make_ratio(remove<I>(num), remove<pos>(den));
            }
            else {
                return make_ratio(num, den);
            }
        }
    }

    template<std::size_t I>
    [[nodiscard]] constexpr auto ratio_reduce_impl(list_type auto num, list_type auto den) noexcept
    {
        if constexpr(num.empty() || den.empty()) {
            return make_ratio(num, den);
        }
        else if constexpr(I == num.size()) {
            return ratio_reduce_impl<I - 1>(num, den);
        }
        else {
            constexpr auto reduced = ratio_reduce_left_index<I>(num, den);
            if constexpr(I == 0) {
                return reduced;
            }
            else {
                return ratio_reduce_impl<I - 1>(reduced.num, reduced.den);
            }
        }
    }

    [[nodiscard]] constexpr auto ratio_reduce(list_type auto num, list_type auto den) noexcept
    {
        return ratio_reduce_impl<num.size()>(num, den);
    }

} // namespace posu::meta::detail

[[nodiscard]] constexpr auto
posu::meta::detail::ratio_multiply(ratio_type auto lhs, ratio_type auto rhs) noexcept
{
    return detail::ratio_reduce(concatenate(lhs.num, rhs.num), concatenate(lhs.den, rhs.den));
}

[[nodiscard]] constexpr auto posu::meta::invert(ratio_type auto r) noexcept
{
    return detail::make_ratio(r.den, r.num);
}
