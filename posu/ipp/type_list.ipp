
namespace posu {

    namespace detail {

        template<typename... Lists>
        using concatenate_impl_t = typename concatenate_impl<Lists...>::type;

        template<typename... LhsTypes, typename... RhsTypes>
        struct concatenate_impl<type_list<LhsTypes...>, type_list<RhsTypes...>> {
            using type = type_list<LhsTypes..., RhsTypes...>;
        };

        template<typename First, typename Second, typename... Rest>
        struct concatenate_impl<First, Second, Rest...>
            : concatenate_impl<concatenate_impl_t<First, Second>, Rest...> {
        };

    } // namespace detail

    template<typename... Types>
    template<typename... Args>
    [[nodiscard]] constexpr auto type_list<Types...>::make_tuple(Args&&... args) noexcept(
        std::is_nothrow_constructible_v<tuple, Args...>) -> tuple
    {
        return std::make_tuple(std::forward<Args>(args)...);
    }

    template<typename... Types>
    template<typename... Args>
    [[nodiscard]] constexpr auto type_list<Types...>::make_variant(Args&&... args) noexcept(
        std::is_nothrow_constructible_v<variant, Args...>) -> variant
    {
        return variant(std::forward<Args>(args)...);
    }

    template<typename TypeList, typename... Args> // clang-format off
        requires is_type_list_v<TypeList>
    [[nodiscard]] constexpr auto // clang-format on
    make_tuple_from(TypeList /*unused*/, Args&&... args) noexcept(
        std::is_nothrow_constructible_v<tuple_from_t<TypeList>>) -> tuple_from_t<TypeList>
    {
        return TypeList::make_tuple(std::forward<Args>(args)...);
    }

    template<typename TypeList, typename... Args> // clang-format off
        requires is_type_list_v<TypeList>
    [[nodiscard]] constexpr auto // clang-format on
    make_variant_from(TypeList /*unused*/, Args&&... args) noexcept(
        std::is_nothrow_constructible_v<variant_from_t<TypeList>>) -> variant_from_t<TypeList>
    {
        return TypeList::make_variant(std::forward<Args>(args)...);
    }

} // namespace posu
