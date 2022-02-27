
namespace posu::meta::detail {

    template<list_type Num, list_type Den>
    [[nodiscard]] constexpr auto make_ratio(Num /*unused*/, Den /*unused*/) noexcept
    {
        return ratio<Num, Den>{};
    }

    template<std::size_t I, list_type Num, list_type Den>
    [[nodiscard]] constexpr auto ratio_reduce_left_index(Num num, Den den) noexcept
    {
        if constexpr(num.empty() || den.empty()) {
            return make_ratio(num, den);
        }
        else {
            constexpr auto pos = find<at<Num, I>>(Den{});
            if constexpr(pos < den.size()) {
                return make_ratio(remove<I>(Num{}), remove<pos>(Den{}));
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
            using reduced = decltype(ratio_reduce_left_index<I>(num, den));
            if constexpr(I == 0) {
                return make_ratio(numerator<reduced>{}, denominator<reduced>{});
            }
            else {
                return ratio_reduce_impl<I - 1>(numerator<reduced>{}, denominator<reduced>{});
            }
        }
    }

    [[nodiscard]] constexpr auto ratio_reduce(list_type auto num, list_type auto den) noexcept
    {
        return ratio_reduce_impl<num.size()>(num, den);
    }

    template<
        typename... NumLhsTypes,
        typename... DenLhsTypes,
        typename... NumRhsTypes,
        typename... DenRhsTypes>
    struct ratio_multiply_impl<
        ratio<list<NumLhsTypes...>, list<DenLhsTypes...>>,
        ratio<list<NumRhsTypes...>, list<DenRhsTypes...>>> {
        using type = decltype(ratio_reduce(
            list<NumLhsTypes..., NumRhsTypes...>{},
            list<DenLhsTypes..., DenRhsTypes...>{}));
    };

} // namespace posu::meta::detail

template<posu::meta::ratio_type Lhs, posu::meta::ratio_type Rhs>
[[nodiscard]] constexpr bool
posu::meta::detail::ratio_equal(Lhs /*unused*/, Rhs /*unused*/) noexcept
{
    return std::same_as<ratio_divide<Lhs, Rhs>, ratio<>>;
}

[[nodiscard]] constexpr auto posu::meta::invert(ratio_type auto r) noexcept
{
    return detail::make_ratio(r.den, r.num);
}
