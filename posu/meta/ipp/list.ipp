
namespace posu::meta::detail {

    [[nodiscard]] constexpr auto concatenate_impl(list_type auto l) noexcept { return l; }

    template<typename... LTypes, typename... RTypes>
    [[nodiscard]] constexpr auto concatenate_impl(
        list<LTypes...> /*unused*/,
        list<RTypes...> /*unused*/,
        list_type auto... part) noexcept
    {
        return concatenate_impl(list<LTypes..., RTypes...>{}, part...);
    }

    template<typename First, typename... Rest>
    [[nodiscard]] constexpr auto pop_front_impl(list<First, Rest...> /*unused*/) noexcept
    {
        return list<Rest...>{};
    }

    template<typename First, typename Second, typename... Rest>
    [[nodiscard]] constexpr auto pop_back_impl(list<First, Second, Rest...> /*unused*/) noexcept
    {
        return push_front<First>(pop_back(list<Second, Rest...>{}));
    }

    template<typename List, std::size_t... I>
    struct take_items<List, std::index_sequence<I...>> {
        using type = list<typename List::template at<I>...>;
    };

    template<typename List, typename T, std::size_t I>
    [[nodiscard]] constexpr auto find_impl_fn() noexcept -> std::size_t
    {
        if constexpr(I < std::tuple_size_v<List>) {
            if constexpr(std::same_as<std::tuple_element_t<I, List>, T>) {
                return I;
            }
            else {
                return find_impl_fn<List, T, I + 1>();
            }
        }

        return I;
    }

    template<typename List, std::size_t I, typename T>
    struct insert_impl {
        using type = decltype(concatenate(
            push_back<T>(first<List, I>{}),
            last<List, std::tuple_size_v<List> - I>{}));
    };

    template<typename List, std::size_t I>
    struct remove_impl {
        using type = decltype(concatenate(
            first<List, I>{},
            pop_front(last<List, std::tuple_size_v<List> - I>{})));
    };

    template<typename List>
    struct remove_impl<List, 0> {
        using type = decltype(pop_front(List{}));
    };

} // namespace posu::meta::detail

template<typename... Types>
template<typename... Args>
[[nodiscard]] constexpr auto posu::meta::list<Types...>::make_tuple(Args&&... args) noexcept(
    std::is_nothrow_constructible_v<tuple, Args...>) -> tuple
{
    return std::make_tuple(std::forward<Args>(args)...);
}

template<typename... Types>
template<typename... Args>
[[nodiscard]] constexpr auto posu::meta::list<Types...>::make_variant(Args&&... args) noexcept(
    std::is_nothrow_constructible_v<variant, Args...>) -> variant
{
    return variant(std::forward<Args>(args)...);
}

[[nodiscard]] constexpr auto posu::meta::concatenate(list_type auto... part) noexcept
{
    return detail::concatenate_impl(part...);
}

template<typename T, typename... Listed>
[[nodiscard]] constexpr auto posu::meta::push_front(list<Listed...> /*unused*/) noexcept
{
    return list<T, Listed...>{};
}

template<typename T, typename... Listed>
[[nodiscard]] constexpr auto posu::meta::push_back(list<Listed...> /*unused*/) noexcept
{
    return list<Listed..., T>{};
}

[[nodiscard]] constexpr auto posu::meta::pop_front(list_type auto l) noexcept
{
    if constexpr(l.empty()) {
        return l;
    }
    else {
        return detail::pop_front_impl(l);
    }
}

[[nodiscard]] constexpr auto posu::meta::pop_back(list_type auto l) noexcept
{
    if constexpr(l.empty()) {
        return l;
    }
    else if constexpr(l.size() == 1) {
        return list<>{};
    }
    else {
        return detail::pop_back_impl(l);
    }
}

template<posu::meta::list_type TypeList, typename... Args>
[[nodiscard]] constexpr auto posu::meta::make_tuple_from(
    TypeList /*unused*/,
    Args&&... args) noexcept(std::is_nothrow_constructible_v<tuple_from_t<TypeList>>)
    -> tuple_from_t<TypeList>
{
    return TypeList::make_tuple(std::forward<Args>(args)...);
}

template<posu::meta::list_type TypeList, typename... Args>
[[nodiscard]] constexpr auto posu::meta::make_variant_from(
    TypeList /*unused*/,
    Args&&... args) noexcept(std::is_nothrow_constructible_v<variant_from_t<TypeList>>)
    -> variant_from_t<TypeList>
{
    return TypeList::make_variant(std::forward<Args>(args)...);
}
