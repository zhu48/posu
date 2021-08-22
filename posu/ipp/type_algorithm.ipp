
template<template<typename> typename Predicate, typename... Types>
[[nodiscard]] constexpr bool posu::all_of(type_list<Types...> /*unused*/) noexcept
{
    return std::conjunction_v<Predicate<Types>...>;
}

template<template<typename> typename Predicate, typename... Types>
[[nodiscard]] constexpr bool posu::any_of(type_list<Types...> /*unused*/) noexcept
{
    return std::disjunction_v<Predicate<Types>...>;
}

template<template<typename> typename Predicate, typename... Types>
[[nodiscard]] constexpr bool posu::none_of(type_list<Types...> /*unused*/) noexcept
{
    return !any_of<Predicate, type_list<Types...>>();
}
