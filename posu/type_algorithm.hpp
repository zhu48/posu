#ifndef POSU_TYPE_ALGORITHM_HPP
#define POSU_TYPE_ALGORITHM_HPP

#include "posu/type_list.hpp"

namespace posu {

    template<template<typename> typename Predicate, typename... Types>
    [[nodiscard]] constexpr bool all_of(type_list<Types...> /*unused*/ = {}) noexcept;

    template<template<typename> typename Predicate, typename... Types>
    [[nodiscard]] constexpr bool any_of(type_list<Types...> /*unused*/ = {}) noexcept;

    template<template<typename> typename Predicate, typename... Types>
    [[nodiscard]] constexpr bool none_of(type_list<Types...> /*unused*/ = {}) noexcept;

    template<typename List, template<typename> typename Predicate>
    concept list_with_all = is_type_list_v<List> && all_of<Predicate>(List{});

    template<typename List, template<typename> typename Predicate>
    concept list_with_any = is_type_list_v<List> && any_of<Predicate>(List{});

    template<typename List, template<typename> typename Predicate>
    concept list_with_no = is_type_list_v<List> && none_of<Predicate>(List{});

    template<template<typename> typename Predicate, typename... Types>
    concept matches_all = (Predicate<Types>::value && ...);

    template<template<typename> typename Predicate, typename... Types>
    concept matches_any = (Predicate<Types>::value || ...);

    template<template<typename> typename Predicate, typename... Types>
    concept matches_none = (!Predicate<Types>::value && ...);

} // namespace posu

#include "posu/ipp/type_algorithm.ipp"

#endif // #ifndef POSU_TYPE_ALGORITHM_HPP
