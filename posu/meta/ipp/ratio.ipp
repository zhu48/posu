
namespace posu::meta {

    namespace detail {

        template<typename Lhs, typename Rhs, std::size_t I>
        struct ratio_reduce_left_index;

        template<typename Lhs, typename Rhs, std::size_t I>
            requires(
                !std::same_as<Lhs, list<>> && !std::same_as<Rhs, list<>> &&
                !contains_v<Rhs, at<Lhs, I>>)
        struct ratio_reduce_left_index<Lhs, Rhs, I> {
            using type = ratio<Lhs, Rhs>;
        };

        template<typename Lhs, typename Rhs, std::size_t I>
            requires(
                !std::same_as<Lhs, list<>> && !std::same_as<Rhs, list<>> &&
                contains_v<Rhs, at<Lhs, I>>)
        struct ratio_reduce_left_index<Lhs, Rhs, I> {
            using type = ratio<remove<Lhs, I>, remove<Rhs, find_v<Rhs, at<Lhs, I>>>>;
        };

        template<std::size_t I>
        struct ratio_reduce_left_index<list<>, list<>, I> {
            using type = ratio<>;
        };

        template<typename Lhs, std::size_t I>
            requires(!std::same_as<Lhs, list<>>)
        struct ratio_reduce_left_index<Lhs, list<>, I> {
            using type = ratio<Lhs>;
        };

        template<typename Rhs, std::size_t I>
            requires(!std::same_as<Rhs, list<>>)
        struct ratio_reduce_left_index<list<>, Rhs, I> {
            using type = ratio<list<>, Rhs>;
        };

        template<typename Lhs, typename Rhs, std::size_t I>
        using ratio_reduce_left_index_t = typename ratio_reduce_left_index<Lhs, Rhs, I>::type;

        template<typename Lhs, typename Rhs, std::size_t LhsSize = size_v<Lhs>, std::size_t I = 0>
        struct ratio_reduce_impl;

        template<typename Lhs, typename Rhs, std::size_t LhsSize, std::size_t I>
            requires((I < LhsSize))
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
            requires((I == LhsSize))
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

    } // namespace detail

} // namespace posu::meta
