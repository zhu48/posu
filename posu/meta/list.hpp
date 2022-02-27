#ifndef POSU_TYPE_LIST_HPP
#define POSU_TYPE_LIST_HPP

#include <functional>
#include <tuple>
#include <variant>

namespace posu::meta {

    /**
     * @brief A compile-time meta-range of types.
     *
     * @tparam Types The types in the type list.
     */
    template<typename... Types>
    struct list {
    public:
        using size_type  = decltype(sizeof...(Types));    //!< Unsigned number-of-elements type.
        using ssize_type = std::make_signed_t<size_type>; //!< Signed number-of-elements type.

        /**
         * @brief Query the number of elements in the list.
         *
         * @return Returns the requested list size information.
         *
         * @{
         */
        [[nodiscard]] static constexpr auto size() noexcept { return sizeof...(Types); }
        [[nodiscard]] static constexpr auto ssize() noexcept { return ssize_type{size()}; }
        [[nodiscard]] static constexpr bool empty() noexcept { return size() == 0; }
        //! @}

        /**
         * @brief The tuple type that has the listed types as its elements.
         */
        using tuple = std::tuple<Types...>;

        /**
         * @brief The variant type that has the listed types as its alternatives.
         */
        using variant = std::variant<Types...>;

        /**
         * @brief The type at the given index in the range.
         *
         * @tparam I The index of the type to access.
         */
        template<std::size_t I>
            requires(I < size())
        using at = std::tuple_element_t<I, tuple>;

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

        /**
         * @brief Equality comparison operator.
         *
         * @tparam T The types in the list to compare against.
         *
         * @param lhs The left-hand-side comparison operand.
         * @param rhs The right-hand-side comparison operand.
         */
        template<typename... T>
        [[nodiscard]] friend constexpr bool operator==(list /*lhs*/, list<T...> /*rhs*/) noexcept
        {
            return std::same_as<list, list<T...>>;
        }
    };

} // namespace posu::meta

namespace std {

    /**
     * `std::tuple_size` specialization for `posu::meta::list`.
     *
     * @tparam T The type list's elements.
     */
    template<typename... T>
    struct tuple_size<posu::meta::list<T...>> : std::integral_constant<std::size_t, sizeof...(T)> {
    };

    /**
     * @brief `std::tuple_element` specialization for `posu::meta::list`.
     *
     * @tparam I The index of the element to get.
     * @tparam T The types in the type list.
     */
    template<size_t I, typename... T>
    struct tuple_element<I, posu::meta::list<T...>> : std::tuple_element<I, std::tuple<T...>> {
    };

} // namespace std

namespace posu::meta {

    namespace detail {

        template<typename T>
        struct is_list : std::false_type {
        };

        template<typename... Types>
        struct is_list<list<Types...>> : std::true_type {
        };

    } // namespace detail

    /**
     * @brief T type that instantiates `list`.
     *
     * @tparam T The type to check against this concept.
     */
    template<typename T>
    concept list_type = detail::is_list<T>::value;

    namespace detail
    {

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
        [[nodiscard]] constexpr auto find_impl_fn() noexcept->std::size_t;

        template<typename List, typename T>
        using find_impl = std::integral_constant<std::size_t, find_impl_fn<List, T>()>;

        template<typename List, std::size_t I, typename T>
        struct insert_impl;

        template<typename List, std::size_t I>
        struct remove_impl;

    } // namespace detail

    /**
     * @brief Concatenate multiple `list`s into a single `list`.
     *
     * @param part The lists to concatenate together.
     */
    [[nodiscard]] constexpr auto concatenate(list_type auto... part) noexcept;

    /**
     * @brief Prepend a type to a `list`.
     *
     * @param T      The type to prepend to the list.
     * @param Listed The types already in the list to push into.
     *
     * @param l The list to push a new type into.
     *
     * @return Returns a list with the new type added to the front.
     */
    template<typename T, typename... Listed>
    [[nodiscard]] constexpr auto push_front(list<Listed...> l) noexcept;

    /**
     * @brief Append a type to a `list`.
     *
     * @param T      The type to prepend to the list.
     * @param Listed The types already in the list to push into.
     *
     * @param l The list to push a new type into.
     *
     * @return Returns a list with the new type added to the back.
     */
    template<typename T, typename... Listed>
    [[nodiscard]] constexpr auto push_back(list<Listed...> l) noexcept;

    /**
     * @brief Remove the first type in a `list`.
     *
     * @tparam List The list to pop a type from.
     */
    template<list_type List>
    using pop_front = typename detail::pop_front_impl<List>::type;

    /**
     * @brief Remove the last type in a `list`.
     *
     * @tparam List The list to pop a type from.
     */
    template<list_type List>
    using pop_back = typename detail::pop_back_impl<List>::type;

    /**
     * @brief Get the first `I` elements of the given list as a `list`.
     *
     * @tparam List The list get the first types of.
     * @tparam I    The number of elements to get.
     */
    template<list_type List, std::size_t I = 0>
        requires(I <= List::size())
    using first = typename detail::first_impl<List, I>::type;

    /**
     * @brief Get the last `I` elements of the given list as a `list`.
     *
     * @tparam List The list get the last types of.
     * @tparam I    The number of elements to get.
     */
    template<list_type List, std::size_t I = 0>
        requires(I <= List::size())
    using last = typename detail::last_impl<List, I>::type;

    /**
     * @brief Get the number of elements in the given type list.
     *
     * @tparam List The list to get an element of.
     *
     * @{
     */
    template<list_type List>
    using size = std::integral_constant<typename List::size_type, List::size()>;
    template<list_type List>
    using ssize = std::integral_constant<typename List::ssize_type, List::ssize()>;
    template<typename List>
    inline constexpr auto size_v = size<List>::value;
    template<typename List>
    inline constexpr auto ssize_v = ssize<List>::value;
    //! @}

    /**
     * @brief Check whether the given type list is empty or not.
     *
     * @tparam List The list to check the emptiness of.
     *
     * @{
     */
    template<list_type List>
    using empty = std::bool_constant<List::empty()>;
    template<typename List>
    inline constexpr auto empty_v = List::empty();
    //! @}

    /**
     * @brief Get the type at the given index in the type list.
     *
     * @tparam List The list to get an element of.
     * @tparam I    The index of the list element to get.
     */
    template<list_type List, std::size_t I>
        requires(I < List::size())
    using at = typename List::template at<I>;

    /**
     * @brief Get the first type in the type list.
     *
     * @tparam List The list to get the first element of.
     */
    template<list_type List>
        requires(!List::empty())
    using front = at<List, 0>;

    /**
     * @brief Get the last type in the type list.
     *
     * @tparam List The list to get the last element of.
     */
    template<list_type List>
        requires(!List::empty())
    using back = at<List, List::size() - 1>;

    /**
     * @brief Find the index of the first ocurrence of the given type.
     *
     * @tparam List The list to find the given type in.
     * @tparam T    The type to find in the given list.
     *
     * @{
     */
    template<list_type List, typename T>
    using find = typename detail::find_impl<List, T>::type;
    template<typename List, typename T>
    inline constexpr auto find_v = find<List, T>::value;
    //! @}

    /**
     * @brief Insert the given type into the given type list at the given index.
     *
     * @tparam List The list to insert a type into.
     * @tparam I    The index to insert a new type at.
     * @tparam T    The type to insert.
     */
    template<list_type List, std::size_t I, typename T>
        requires(I <= List::size())
    using insert = typename detail::insert_impl<List, I, T>::type;

    /**
     * @brief Remove the type at the givien position in the type list.
     *
     * @tparam List The list to remove a type from.
     * @tparam I    The index of the type to remove.
     */
    template<list_type List, std::size_t I>
        requires(I < List::size())
    using remove = typename detail::remove_impl<List, I>::type;

    /**
     * @brief Check whether or not the given type exists in the given type list.
     *
     * @tparam List The list to check for the given type in.
     * @tparam T    The type to check the existence of in the given list.
     *
     * @{
     */
    template<typename List, typename T>
    struct contains
        : public std::bool_constant<std::less{}(find<List, T>::value, List::size::value)> {
    };
    template<typename List, typename T>
    inline constexpr auto contains_v = contains<List, T>::value;
    //! @}

    /**
     * @brief Transform a `list` to its corresponding tuple type.
     *
     * @tparam TypeList The list to transform.
     *
     * @{
     */
    template<list_type TypeList>
    struct tuple_from {
        using type = typename TypeList::tuple;
    };
    template<typename TypeList>
    using tuple_from_t = typename tuple_from<TypeList>::type;
    //! @}

    /**
     * @brief Transform a `list` to its corresponding variant type.
     *
     * @tparam TypeList The list to transform.
     *
     * @{
     */
    template<list_type TypeList>
    struct variant_from {
        using type = typename TypeList::variant;
    };
    template<typename TypeList>
    using variant_from_t = typename variant_from<TypeList>::type;
    //! @}

    /**
     * @brief Construct a tuple from its corresponding `list`.
     *
     * @tparam TypeList The list to construct a tuple from.
     * @tparam Args The types of arguments to forward to the tuple constructor.
     * @param list The type list object.
     * @param args The arguments to forward to the tuple constructor.
     * @return Returns the constructed tuple.
     */
    template<list_type TypeList, typename... Args>
    [[nodiscard]] constexpr auto make_tuple_from(TypeList list, Args&&... args) noexcept(
        std::is_nothrow_constructible_v<tuple_from_t<TypeList>>) -> tuple_from_t<TypeList>;

    /**
     * @brief Construct a variant from its corresponding `list`.
     *
     * @tparam TypeList The list to construct a variant from.
     * @tparam Args The types of arguments to forward to the variant constructor.
     * @param list The type list object.
     * @param args The arguments to forward to the variant constructor.
     * @return Returns the constructed variant.
     */
    template<list_type TypeList, typename... Args>
    [[nodiscard]] constexpr auto make_variant_from(TypeList list, Args&&... args) noexcept(
        std::is_nothrow_constructible_v<variant_from_t<TypeList>>) -> variant_from_t<TypeList>;

} // namespace posu::meta

#include "posu/meta/ipp/list.ipp"

#endif // #ifndef POSU_TYPE_LIST_HPP
