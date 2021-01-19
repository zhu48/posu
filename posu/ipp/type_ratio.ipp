
namespace posu {

    namespace detail {

        template<typename Lhs, typename Rhs, std::size_t I = 0>
        struct ratio_reduce_impl : private ratio_reduce_impl<Lhs, Rhs, I + 1> {
        private:
            using parent_type   = ratio_reduce_impl<Lhs, Rhs, I + 1>;
            using parent_type_t = typename parent_type::type;

            using lhs = typename parent_type_t::num;
            using rhs = typename parent_type_t::den;

            static constexpr auto llast_idx_in_rhs = find<rhs, std::tuple_element_t<I, lhs>>::value;

        public:
            using type = std::conditional_t<
                llast_idx_in_rhs == std::tuple_size_v<rhs>,
                type_ratio<lhs, rhs>,
                type_ratio<remove<lhs, I>, remove<rhs, llast_idx_in_rhs>>>;
        };

        template<typename... LhsTypes, typename Rhs>
            requires(sizeof...(LhsTypes) != 0 && !std::same_as<Rhs, type_list<>>)
        struct ratio_reduce_impl<type_list<LhsTypes...>, Rhs, sizeof...(LhsTypes)> {
        private:
            using lhs = type_list<LhsTypes...>;

            static constexpr auto lfirst_idx_in_rhs = find<Rhs, first<lhs>>::value;

        public:
            using type = std::conditional_t<
                lfirst_idx_in_rhs == std::tuple_size_v<Rhs>,
                type_ratio<lhs, Rhs>,
                type_ratio<pop_front<lhs>, remove<Rhs, lfirst_idx_in_rhs>>>;
        };

        template<std::size_t I>
        struct ratio_reduce_impl<type_list<>, type_list<>, I> {
            using type = type_ratio<>;
        };

        template<typename Lhs, std::size_t I>
            requires(!std::same_as<Lhs, type_list<>>)
        struct ratio_reduce_impl<Lhs, type_list<>, I> {
            using type = type_ratio<Lhs>;
        };

        template<typename Rhs, std::size_t I>
            requires(!std::same_as<Rhs, type_list<>>)
        struct ratio_reduce_impl<type_list<>, Rhs, I> {
            using type = type_ratio<type_list<>, Rhs>;
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
