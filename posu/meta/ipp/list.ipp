
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

    template<typename... Types, typename T>
    struct prepend_impl<list<Types...>, T> {
        using type = decltype(concatenate(list<T>{}, list<Types...>{}));
    };

    template<typename... Types, typename T>
    struct prepend_impl<list<Types...>, list<T>> {
        using type = decltype(concatenate(list<T>{}, list<Types...>{}));
    };

    template<typename... Types, typename T>
    struct append_impl<list<Types...>, T> {
        using type = decltype(concatenate(list<Types...>{}, list<T>{}));
    };

    template<typename... Types, typename T>
    struct append_impl<list<Types...>, list<T>> {
        using type = decltype(concatenate(list<Types...>{}, list<T>{}));
    };

    template<typename First, typename... Rest>
    struct pop_front_impl<list<First, Rest...>> {
        using type = list<Rest...>;
    };

    template<typename Type>
    struct pop_back_impl<list<Type>> {
        using type = list<>;
    };

    template<typename First, typename Second>
    struct pop_back_impl<list<First, Second>> {
        using type = list<First>;
    };

    template<typename First, typename... Rest>
    struct pop_back_impl<list<First, Rest...>> : prepend_impl<pop_back<list<Rest...>>, First> {
    };

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
            push_back<first<List, I>, T>{},
            last<List, std::tuple_size_v<List> - I>{}));
    };

    template<typename List, std::size_t I>
    struct remove_impl {
        using type = decltype(concatenate(
            first<List, I>{},
            pop_front<last<List, std::tuple_size_v<List> - I>>{}));
    };

    template<typename List>
    struct remove_impl<List, 0> {
        using type = pop_front<List>;
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
