#ifndef POSU_TYPE_ALGORITHM_HPP
#define POSU_TYPE_ALGORITHM_HPP

#include "posu/meta/list.hpp"

namespace posu::meta {

    template<template<typename> typename Predicate, typename... Types>
    [[nodiscard]] constexpr bool all_of(list<Types...> /*unused*/ = {}) noexcept;

    template<template<typename> typename Predicate, typename... Types>
    [[nodiscard]] constexpr bool any_of(list<Types...> /*unused*/ = {}) noexcept;

    template<template<typename> typename Predicate, typename... Types>
    [[nodiscard]] constexpr bool none_of(list<Types...> /*unused*/ = {}) noexcept;

    template<typename List, template<typename> typename Predicate>
    concept list_with_all = is_list_v<List> && all_of<Predicate>(List{});

    template<typename List, template<typename> typename Predicate>
    concept list_with_any = is_list_v<List> && any_of<Predicate>(List{});

    template<typename List, template<typename> typename Predicate>
    concept list_with_no = is_list_v<List> && none_of<Predicate>(List{});

    template<template<typename> typename Predicate, typename... Types>
    concept matches_all = (Predicate<Types>::value && ...);

    template<template<typename> typename Predicate, typename... Types>
    concept matches_any = (Predicate<Types>::value || ...);

    template<template<typename> typename Predicate, typename... Types>
    concept matches_none = (!Predicate<Types>::value && ...);

} // namespace posu::meta

#include "posu/meta/ipp/algorithm.ipp"

#endif // #ifndef POSU_TYPE_ALGORITHM_HPP
