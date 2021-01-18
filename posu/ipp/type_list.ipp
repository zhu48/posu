
namespace posu {

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

    template<typename TypeList, typename... Args>
        requires is_type_list_v<TypeList>
    [[nodiscard]] constexpr auto make_tuple_from(TypeList /*unused*/, Args&&... args) noexcept(
        std::is_nothrow_constructible_v<tuple_from_t<TypeList>>) -> tuple_from_t<TypeList>
    {
        return TypeList::make_tuple(std::forward<Args>(args)...);
    }

    template<typename TypeList, typename... Args>
        requires is_type_list_v<TypeList>
    [[nodiscard]] constexpr auto make_variant_from(TypeList /*unused*/, Args&&... args) noexcept(
        std::is_nothrow_constructible_v<variant_from_t<TypeList>>) -> variant_from_t<TypeList>
    {
        return TypeList::make_variant(std::forward<Args>(args)...);
    }

} // namespace posu
