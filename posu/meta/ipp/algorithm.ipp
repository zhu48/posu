
template<template<typename> typename Predicate, typename... Types>
[[nodiscard]] constexpr bool posu::meta::all_of(list<Types...> /*unused*/) noexcept
{
    return std::conjunction_v<Predicate<Types>...>;
}

template<template<typename> typename Predicate, typename... Types>
[[nodiscard]] constexpr bool posu::meta::any_of(list<Types...> /*unused*/) noexcept
{
    return std::disjunction_v<Predicate<Types>...>;
}

template<template<typename> typename Predicate, typename... Types>
[[nodiscard]] constexpr bool posu::meta::none_of(list<Types...> /*unused*/) noexcept
{
    return !any_of<Predicate, list<Types...>>();
}
