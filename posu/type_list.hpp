#ifndef POSU_TYPE_LIST_HPP
#define POSU_TYPE_LIST_HPP

#include <tuple>
#include <variant>

namespace posu {

    /**
     * @brief A compile-time meta-range of types.
     *
     * @tparam Types The types in the type list.
     */
    template<typename... Types>
    struct type_list {
    public:
        /**
         * @brief The type at the given index in the range.
         *
         * @tparam I The index of the type to access.
         */
        template<std::size_t I>
        using at = std::tuple_element_t<I, std::tuple<Types...>>;

        /**
         * @brief The number of elements in the list.
         */
        using size = std::integral_constant<std::size_t, sizeof...(Types)>;

        /**
         * @brief Whether the list is empty or not.
         */
        using empty = std::bool_constant<size::value == 0>;

        /**
         * @brief The first type in the list.
         */
        using front = at<0>;

        /**
         * @brief The last type in the list.
         */
        using back = at<size::value - 1>;

        /**
         * @brief The tuple type that has the listed types as its elements.
         */
        using tuple = std::tuple<Types...>;

        /**
         * @brief The variant type that has the listed types as its alternatives.
         */
        using variant = std::variant<Types...>;

        /**
         * @brief Construct an object of the corresponding tuple type.
         *
         * @tparam Args The types of arguments to forward to the tuple constructor.
         * @param args The arguments to forward to the tuple constructor.
         * @return Returns the constructed tuple.
         */
        template<typename... Args>
        [[nodiscard]] static constexpr auto
        make_tuple(Args&&... args) noexcept(std::is_nothrow_constructible_v<tuple, Args...>)
            -> tuple;

        /**
         * @brief Construct an object of the corresponding variant type.
         *
         * @tparam Args The types of arguments to forward to the variant constructor.
         * @param args The arguments to forward to the variant constructor.
         * @return Returns the constructed variant.
         */
        template<typename... Args>
        [[nodiscard]] static constexpr auto
        make_variant(Args&&... args) noexcept(std::is_nothrow_constructible_v<variant, Args...>)
            -> variant;
    };

} // namespace posu

namespace std {

    /**
     * `std::tuple_size` specialization for `posu::type_list`.
     *
     * @tparam T The type list's elements.
     */
    template<typename... T>
    struct tuple_size<posu::type_list<T...>> : std::integral_constant<std::size_t, sizeof...(T)> {
    };

    /**
     * @brief `std::tuple_element` specialization for `posu::type_list`.
     *
     * @tparam I The index of the element to get.
     * @tparam T The types in the type list.
     */
    template<size_t I, typename... T>
    struct tuple_element<I, posu::type_list<T...>> : std::tuple_element<I, std::tuple<T...>> {
    };

} // namespace std

namespace posu {

    /**
     * @brief Traits template to detect whether a type specializes `type_list` or not.
     * @{
     */
    //! @tparam T The type to check.
    template<typename T>
    struct is_type_list : std::false_type {
    };
    //! @tparam Types The types in the type list.
    template<typename... Types>
    struct is_type_list<type_list<Types...>> : std::true_type {
    };
    //! @}

    /**
     * @brief Traits constant indicating whether or not a type specializes `type_list`.
     *
     * @tparam T The type to check.
     */
    template<typename T>
    inline constexpr bool is_type_list_v = is_type_list<T>::value;

    namespace detail {

        template<typename... Lists>
        struct concatenate_impl;

        template<typename List, typename T>
        struct prepend_impl;

        template<typename List, typename T>
        struct append_impl;

        template<typename List>
        struct pop_front_impl;

        template<typename List>
        struct pop_back_impl;

        template<typename List, typename IndexSequence>
        struct take_items;

        template<std::size_t Offset, typename IndexSequence>
        struct add_offset;

        template<std::size_t Offset, std::size_t... Values>
        struct add_offset<Offset, std::index_sequence<Values...>> {
            using type = std::index_sequence<(Values + Offset)...>;
        };

        template<std::size_t Offset, typename IndexSequence>
        using add_offset_t = typename add_offset<Offset, IndexSequence>::type;

        template<typename List, std::size_t I>
        using first_impl = take_items<List, std::make_index_sequence<I>>;

        template<typename List, std::size_t I>
        using last_impl = take_items<
            List,
            add_offset_t<std::tuple_size_v<List> - I, std::make_index_sequence<I>>>;

        template<typename List, typename T, std::size_t I = 0>
        [[nodiscard]] constexpr auto find_impl_fn() noexcept -> std::size_t;

        template<typename List, typename T>
        using find_impl = std::integral_constant<std::size_t, find_impl_fn<List, T>()>;

        template<typename List, std::size_t I, typename T>
        struct insert_impl;

        template<typename List, std::size_t I>
        struct remove_impl;

    } // namespace detail

    /**
     * @brief Concatenate multiple `type_list`s into a single `type_list`.
     *
     * @tparam Lists The lists to concatenate together.
     */
    template<typename... Lists> // clang-format off
        requires( is_type_list_v<Lists> && ... )
    using concatenate = typename detail::concatenate_impl<Lists...>::type; // clang-format on

    /**
     * @brief Prepend a type to a `type_list`.
     *
     * @tparam List The list to prepend a type to.
     * @tparam Type The type to prepend to the list. If `Type` is an single-element list
     *              `type_list<T>`, prepends `T` instead.
     */
    template<typename List, typename Type> // clang-format off
        requires( is_type_list_v<List> )
    using push_front = typename detail::prepend_impl<List, Type>::type; // clang-format on

    /**
     * @brief Append a type to a `type_list`.
     *
     * @tparam List The list to append a type to.
     * @tparam Type The type to append to the list. If `Type` is an single-element list
     *              `type_list<T>`, appends `T` instead.
     */
    template<typename List, typename Type> // clang-format off
        requires( is_type_list_v<List> )
    using push_back = typename detail::append_impl<List, Type>::type; // clang-format on

    /**
     * @brief Remove the first type in a `type_list`.
     *
     * @tparam List The list to pop a type from.
     */
    template<typename List> // clang-format off
        requires( is_type_list_v<List> )
    using pop_front = typename detail::pop_front_impl<List>::type; // clang-format on

    /**
     * @brief Remove the last type in a `type_list`.
     *
     * @tparam List The list to pop a type from.
     */
    template<typename List> // clang-format off
        requires( is_type_list_v<List> )
    using pop_back = typename detail::pop_back_impl<List>::type; // clang-format on

    /**
     * @brief Get the first `I` elements of the given list as a `type_list`.
     *
     * @tparam List The list get the first types of.
     * @tparam I    The number of elements to get.
     */
    template<typename List, std::size_t I = 0> // clang-format off
        requires( is_type_list_v<List> && I <= typename List::size() )
    using first = typename detail::first_impl<List, I>::type; // clang-format on

    /**
     * @brief Get the last `I` elements of the given list as a `type_list`.
     *
     * @tparam List The list get the last types of.
     * @tparam I    The number of elements to get.
     */
    template<typename List, std::size_t I = 0> // clang-format off
        requires( is_type_list_v<List> && I <= typename List::size() )
    using last = typename detail::last_impl<List, I>::type; // clang-format on

    /**
     * @brief Find the index of the first ocurrence of the given type.
     *
     * @tparam List The list to find the given type in.
     * @tparam T    The type to find in the given list.
     */
    template<typename List, typename T> // clang-format off
        requires( is_type_list_v<List> )
    using find = typename detail::find_impl<List, T>::type; // clang-format on

    /**
     * @brief Insert the given type into the given type list at the given index.
     *
     * @tparam List The list to insert a type into.
     * @tparam I    The index to insert a new type at.
     * @tparam T    The type to insert.
     */
    template<typename List, std::size_t I, typename T> // clang-format off
        requires( is_type_list_v<List> && I <= typename List::size() )
    using insert = typename detail::insert_impl<List, I, T>::type; // clang-format off

    /**
     * @brief Remove the type at the givien position in the type list.
     * 
     * @tparam List The list to remove a type from.
     * @tparam I    The index of the type to remove.
     */
    template<typename List, std::size_t I> // clang-format off
        requires( is_type_list_v<List> && I < typename List::size() )
    using remove = typename detail::remove_impl<List, I>::type; // clang-format off

    /**
     * @brief Transform a `type_list` to its corresponding tuple type.
     *
     * @tparam TypeList The list to transform.
     *
     * @{
     */
    template<typename TypeList> // clang-format off
        requires is_type_list_v<TypeList>
    struct tuple_from { // clang-format on
        using type = typename TypeList::tuple;
    };
    template<typename TypeList>
    using tuple_from_t = typename tuple_from<TypeList>::type;
    //! @}

    /**
     * @brief Transform a `type_list` to its corresponding variant type.
     *
     * @tparam TypeList The list to transform.
     *
     * @{
     */
    template<typename TypeList> // clang-format off
        requires is_type_list_v<TypeList>
    struct variant_from { // clang-format on
        using type = typename TypeList::variant;
    };
    template<typename TypeList>
    using variant_from_t = typename variant_from<TypeList>::type;
    //! @}

    /**
     * @brief Construct a tuple from its corresponding `type_list`.
     *
     * @tparam TypeList The list to construct a tuple from.
     * @tparam Args The types of arguments to forward to the tuple constructor.
     * @param list The type list object.
     * @param args The arguments to forward to the tuple constructor.
     * @return Returns the constructed tuple.
     */
    template<typename TypeList, typename... Args> // clang-format off
        requires is_type_list_v<TypeList>
    [[nodiscard]] constexpr auto make_tuple_from(TypeList list, Args&&... args) // clang-format on
        noexcept(std::is_nothrow_constructible_v<tuple_from_t<TypeList>>) -> tuple_from_t<TypeList>;

    /**
     * @brief Construct a variant from its corresponding `type_list`.
     *
     * @tparam TypeList The list to construct a variant from.
     * @tparam Args The types of arguments to forward to the variant constructor.
     * @param list The type list object.
     * @param args The arguments to forward to the variant constructor.
     * @return Returns the constructed variant.
     */
    template<typename TypeList, typename... Args> // clang-format off
        requires is_type_list_v<TypeList>
    [[nodiscard]] constexpr auto make_variant_from(TypeList list, Args&&... args) // clang-format on
        noexcept(std::is_nothrow_constructible_v<variant_from_t<TypeList>>)
            -> variant_from_t<TypeList>;

} // namespace posu

#include "posu/ipp/type_list.ipp"

#endif // #ifndef POSU_TYPE_LIST_HPP
