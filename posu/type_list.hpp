#ifndef POSU_TYPE_LIST_HPP
#define POSU_TYPE_LIST_HPP

#include <tuple>
#include <variant>

namespace posu {

    template<typename... Types>
    struct type_list {
    public:
        template<std::size_t I>
        using at = std::tuple_element_t<I, std::tuple<Types...>>;

        using size  = std::integral_constant<std::size_t, sizeof...(Types)>;
        using empty = std::bool_constant<size::value == 0>;

        using front = at<0>;
        using back  = at<size::value - 1>;

        using tuple   = std::tuple<Types...>;
        using variant = std::variant<Types...>;

        template<typename... Args>
        [[nodiscard]] static constexpr auto
        make_tuple(Args&&... args) noexcept(std::is_nothrow_constructible_v<tuple, Args...>)
            -> tuple;

        template<typename... Args>
        [[nodiscard]] static constexpr auto
        make_variant(Args&&... args) noexcept(std::is_nothrow_constructible_v<variant, Args...>)
            -> variant;
    };

    template<typename T>
    struct is_type_list : std::false_type {
    };

    template<typename... Types>
    struct is_type_list<type_list<Types...>> : std::true_type {
    };

    template<typename T>
    inline constexpr bool is_type_list_v = is_type_list<T>::value;

    template<typename TypeList> // clang-format off
        requires is_type_list_v<TypeList>
    struct tuple_from { // clang-format on
        using type = typename TypeList::tuple;
    };

    template<typename TypeList>
    using tuple_from_t = typename tuple_from<TypeList>::type;

    template<typename TypeList> // clang-format off
        requires is_type_list_v<TypeList>
    struct variant_from { // clang-format on
        using type = typename TypeList::variant;
    };

    template<typename TypeList>
    using variant_from_t = typename variant_from<TypeList>::type;

    template<typename TypeList, typename... Args> // clang-format off
        requires is_type_list_v<TypeList>
    [[nodiscard]] constexpr auto make_tuple_from(TypeList list, Args&&... args) // clang-format on
        noexcept(std::is_nothrow_constructible_v<tuple_from_t<TypeList>>) -> tuple_from_t<TypeList>;

    template<typename TypeList, typename... Args> // clang-format off
        requires is_type_list_v<TypeList>
    [[nodiscard]] constexpr auto make_variant_from(TypeList list, Args&&... args) // clang-format on
        noexcept(std::is_nothrow_constructible_v<variant_from_t<TypeList>>)
            -> variant_from_t<TypeList>;

} // namespace posu

#include "posu/ipp/type_list.ipp"

#endif // #ifndef POSU_TYPE_LIST_HPP
