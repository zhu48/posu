
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

    template<typename Lhs, typename Rhs, std::size_t I>
    using ratio_reduce_left_index_t = decltype(ratio_reduce_left_index<I>(Lhs{}, Rhs{}));

    template<typename Lhs, typename Rhs, std::size_t LhsSize = size(Lhs{}), std::size_t I = 0>
    struct ratio_reduce_impl;

    template<typename Lhs, typename Rhs, std::size_t LhsSize, std::size_t I>
        requires(I < LhsSize)
    struct ratio_reduce_impl<Lhs, Rhs, LhsSize, I>
        : private ratio_reduce_impl<Lhs, Rhs, LhsSize, I + 1> {
    private:
        using parent_type   = ratio_reduce_impl<Lhs, Rhs, LhsSize, I + 1>;
        using parent_type_t = typename parent_type::type;

        using lhs = typename parent_type_t::num;
        using rhs = typename parent_type_t::den;

    public:
        using type = ratio_reduce_left_index_t<lhs, rhs, I>;
    };

    template<typename Lhs, typename Rhs, std::size_t LhsSize, std::size_t I>
        requires(I == LhsSize)
    struct ratio_reduce_impl<Lhs, Rhs, LhsSize, I> {
        using type = ratio<Lhs, Rhs>;
    };

    template<typename Lhs, typename Rhs>
    using ratio_reduce_impl_t = typename ratio_reduce_impl<Lhs, Rhs>::type;

    template<
        typename... NumLhsTypes,
        typename... DenLhsTypes,
        typename... NumRhsTypes,
        typename... DenRhsTypes>
    struct ratio_multiply_impl<
        ratio<list<NumLhsTypes...>, list<DenLhsTypes...>>,
        ratio<list<NumRhsTypes...>, list<DenRhsTypes...>>> {
        using type = ratio_reduce_impl_t<
            list<NumLhsTypes..., NumRhsTypes...>,
            list<DenLhsTypes..., DenRhsTypes...>>;
    };

} // namespace posu::meta::detail

template<posu::meta::ratio_type Lhs, posu::meta::ratio_type Rhs>
[[nodiscard]] constexpr bool
posu::meta::detail::ratio_equal(Lhs /*unused*/, Rhs /*unused*/) noexcept
{
    return std::same_as<ratio_divide<Lhs, Rhs>, ratio<>>;
}
