
namespace posu::meta::detail {

    template<list_type Num, list_type Den>
    struct ratio_info {
        using ratio_t = ratio<Num, Den>;

        static constexpr auto num = Num{};
        static constexpr auto den = Den{};

        constexpr ratio_info() noexcept = default;
        constexpr ratio_info(Num /*unused*/, Den /*unused*/) noexcept : ratio_info{} {}
    };

    template<list_type Num, list_type Den>
    [[nodiscard]] constexpr auto make_ratio(ratio_info<Num, Den> /*unused*/) noexcept
    {
        return ratio<Num, Den>{};
    }

    template<std::size_t I, list_type Num>
    [[nodiscard]] constexpr auto ratio_reduce_left_index(Num num, list_type auto den) noexcept
    {
        if constexpr(num.empty() || den.empty()) {
            return ratio_info(num, den);
        }
        else {
            constexpr auto pos = find<at<Num, I>>(den);
            if constexpr(pos < den.size()) {
                return ratio_info(remove<I>(num), remove<pos>(den));
            }
            else {
                return ratio_info(num, den);
            }
        }
    }

    template<std::size_t I>
    [[nodiscard]] constexpr auto ratio_reduce_impl(list_type auto num, list_type auto den) noexcept
    {
        if constexpr(num.empty() || den.empty()) {
            return ratio_info(num, den);
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

} // namespace posu::meta::detail

[[nodiscard]] constexpr auto
posu::meta::detail::ratio_reduce(list_type auto num, list_type auto den) noexcept
{
    return ratio_reduce_impl<num.size()>(num, den);
}

[[nodiscard]] constexpr auto
posu::meta::detail::ratio_multiply(ratio_type auto lhs, ratio_type auto rhs) noexcept
{
    return detail::make_ratio(
        detail::ratio_reduce(concatenate(lhs.num, rhs.num), concatenate(lhs.den, rhs.den)));
}

[[nodiscard]] constexpr auto posu::meta::invert(ratio_type auto r) noexcept
{
    return detail::make_ratio(detail::ratio_info(r.den, r.num));
}
