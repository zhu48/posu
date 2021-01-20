
namespace posu {

    namespace detail {

        template<typename Lhs, typename Rhs, std::size_t I>
        struct ratio_reduce_left_index;

        template<typename Lhs, typename Rhs, std::size_t I>
            requires(
                !std::same_as<Lhs, type_list<>> && !std::same_as<Rhs, type_list<>> &&
                !contains_v<Rhs, at<Lhs, I>>)
        struct ratio_reduce_left_index<Lhs, Rhs, I> {
            using type = type_ratio<Lhs, Rhs>;
        };

        template<typename Lhs, typename Rhs, std::size_t I>
            requires(
                !std::same_as<Lhs, type_list<>> && !std::same_as<Rhs, type_list<>> &&
                contains_v<Rhs, at<Lhs, I>>)
        struct ratio_reduce_left_index<Lhs, Rhs, I> {
            using type = type_ratio<remove<Lhs, I>, remove<Rhs, find_v<Rhs, at<Lhs, I>>>>;
        };

        template<std::size_t I>
        struct ratio_reduce_left_index<type_list<>, type_list<>, I> {
            using type = type_ratio<>;
        };

        template<typename Lhs, std::size_t I>
            requires(!std::same_as<Lhs, type_list<>>)
        struct ratio_reduce_left_index<Lhs, type_list<>, I> {
            using type = type_ratio<Lhs>;
        };

        template<typename Rhs, std::size_t I>
            requires(!std::same_as<Rhs, type_list<>>)
        struct ratio_reduce_left_index<type_list<>, Rhs, I> {
            using type = type_ratio<type_list<>, Rhs>;
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
            using type = type_ratio<Lhs, Rhs>;
        };

        template<typename Lhs, typename Rhs>
        using ratio_reduce_impl_t = typename ratio_reduce_impl<Lhs, Rhs>::type;

        template<
            typename... NumLhsTypes,
            typename... DenLhsTypes,
            typename... NumRhsTypes,
            typename... DenRhsTypes>
        struct ratio_multiply_impl<
            type_ratio<type_list<NumLhsTypes...>, type_list<DenLhsTypes...>>,
            type_ratio<type_list<NumRhsTypes...>, type_list<DenRhsTypes...>>> {
            using type = ratio_reduce_impl_t<
                type_list<NumLhsTypes..., NumRhsTypes...>,
                type_list<DenLhsTypes..., DenRhsTypes...>>;
        };

    } // namespace detail

} // namespace posu
