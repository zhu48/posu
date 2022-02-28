
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

    template<std::size_t Offset, std::size_t... I>
    [[nodiscard]] constexpr auto offset(std::index_sequence<I...> /*unused*/) noexcept
    {
        return std::index_sequence<(I + Offset)...>{};
    }

    template<typename T, std::size_t I = 0, list_type List>
    [[nodiscard]] constexpr auto find_impl(List l) noexcept
    {
        if constexpr(I == l.size()) {
            return I;
        }
        else if constexpr(std::same_as<at<List, I>, T>) {
            return I;
        }
        else {
            return find_impl<T, I + 1>(l);
        }
    }

    template<std::size_t Limit, std::size_t... I>
    [[nodiscard]] constexpr auto
    decrement_all_greater_equal(std::index_sequence<I...> /*unused*/) noexcept
    {
        return std::index_sequence<((I >= Limit) ? (I - 1) : I)...>{};
    }

    template<std::size_t First, std::size_t... Rest>
    [[nodiscard]] constexpr auto
    remove_impl(list_type auto l, std::index_sequence<First, Rest...> i) noexcept
    {
        if constexpr(i.size() == 1) {
            return concatenate(first<First>(l), take_range<First + 1, l.size()>(l));
        }
        else {
            return remove(
                remove<First>(l),
                decrement_all_greater_equal<First>(std::index_sequence<Rest...>{}));
        }
    }

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

template<posu::meta::list_type List, std::size_t... I>
[[nodiscard]] constexpr auto
posu::meta::take(List /*unused*/, std::index_sequence<I...> /*unused*/) noexcept
    requires((I < List::size()) && ...)
{
    return list<at<List, I>...>{};
}

template<std::size_t Begin, std::size_t End>
[[nodiscard]] constexpr auto posu::meta::take_range(list_type auto l) noexcept
    requires((Begin <= decltype(l)::size()) && (End <= decltype(l)::size()) && (Begin <= End))
{
    return take(l, detail::offset<Begin>(std::make_index_sequence<End - Begin>{}));
}

template<std::size_t N, typename... T>
[[nodiscard]] constexpr auto posu::meta::first(list<T...> l) noexcept
    requires(N <= list<T...>::size())
{
    return take(l, std::make_index_sequence<N>{});
}

template<std::size_t N>
[[nodiscard]] constexpr auto posu::meta::last(list_type auto l) noexcept requires(N <= l.size())
{
    return take_range<l.size() - N, l.size()>(l);
}

template<typename T>
[[nodiscard]] constexpr auto posu::meta::find(list_type auto l) noexcept
{
    return detail::find_impl<T>(l);
}

template<std::size_t I, typename T>
[[nodiscard]] constexpr auto posu::meta::insert(list_type auto l) noexcept requires(I <= l.size())
{
    return concatenate(first<I>(l), push_front<T>(last<l.size() - I>(l)));
}

template<std::size_t... I>
[[nodiscard]] constexpr auto
posu::meta::remove(list_type auto l, std::index_sequence<I...> i) noexcept
    requires((I < decltype(l)::size()) && ...)
{
    if constexpr(i.size() == 0) {
        return l;
    }
    else {
        return detail::remove_impl(l, i);
    }
}

template<typename T>
[[nodiscard]] constexpr bool posu::meta::contains(list_type auto l) noexcept
{
    return find<T>(l) != l.size();
}

template<std::size_t Begin, std::size_t End>
[[nodiscard]] constexpr auto posu::meta::remove_range(
    list_type auto l,
    std::integral_constant<std::size_t, Begin> /*unused*/,
    std::integral_constant<std::size_t, End> /*unused*/) noexcept
    requires((Begin <= End) && (End <= l.size()))
{
    return concatenate(first<Begin>(l), last<l.size() - End - 1>(l));
}

template<posu::meta::list_type TypeList, typename... Args>
[[nodiscard]] constexpr auto posu::meta::make_tuple_from(
    TypeList /*unused*/,
    Args&&... args) noexcept(std::is_nothrow_constructible_v<tuple_from<TypeList>, Args...>)
    -> tuple_from<TypeList>
{
    return TypeList::make_tuple(std::forward<Args>(args)...);
}

template<posu::meta::list_type TypeList, typename... Args>
[[nodiscard]] constexpr auto posu::meta::make_variant_from(
    TypeList /*unused*/,
    Args&&... args) noexcept(std::is_nothrow_constructible_v<variant_from<TypeList>, Args...>)
    -> variant_from<TypeList>
{
    return TypeList::make_variant(std::forward<Args>(args)...);
}
