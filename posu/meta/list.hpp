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

    /**
     * @brief Concatenate multiple `list`s into a single `list`.
     *
     * @param part The lists to concatenate together.
     *
     * @return Returns the resulting concatenated list.
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
     * @param l The list to pop a type from.
     *
     * @return Returns the given list without the first element.
     */
    [[nodiscard]] constexpr auto pop_front(list_type auto l) noexcept;

    /**
     * @brief Remove the last type in a `list`.
     *
     * @param l The list to pop a type from.
     *
     * @return Returns the given list without the last element.
     */
    [[nodiscard]] constexpr auto pop_back(list_type auto l) noexcept;

    /**
     * @brief Create a new list containing the elements at the given indices of the given list.
     *
     * @tparam List The list to take items from.
     * @tparam I    The indices to take from the given list at.
     *
     * @param l The list to take items from.
     * @param i The indices to take from the given list at.
     *
     * @return Returns the created list.
     */
    template<list_type List, std::size_t... I>
    [[nodiscard]] constexpr auto take(List l, std::index_sequence<I...> i = {}) noexcept
        requires((I < List::size()) && ...);

    /**
     * @brief Extract a sub-list from the given list.
     *
     * @tparam Begin The starting index of the sub-list.
     * @tparam End   The one-past-the-ending index of the sub-list.
     *
     * @param l The list to take a sub-list of.
     *
     * @return Returns the sub-list.
     */
    template<std::size_t Begin, std::size_t End>
    [[nodiscard]] constexpr auto take_range(list_type auto l) noexcept
        requires((Begin <= decltype(l)::size()) && (End <= decltype(l)::size()) && (Begin <= End));

    /**
     * @brief Get the first `I` elements of the given list as a `list`.
     *
     * @tparam List The list get the first types of.
     * @tparam I    The number of elements to get.
     */
    template<std::size_t N, typename... T>
    [[nodiscard]] constexpr auto first(list<T...> l) noexcept requires(N <= list<T...>::size());

    /**
     * @brief Get the last `I` elements of the given list as a `list`.
     *
     * @tparam List The list get the last types of.
     * @tparam I    The number of elements to get.
     */
    template<std::size_t N>
    [[nodiscard]] constexpr auto last(list_type auto l) noexcept requires(N <= l.size());

    /**
     * @brief Obtain the number of elements in the given list as an unsigned integer.
     *
     * @param l The list to obtain the size of.
     *
     * @return Returns the size of the given list.
     */
    [[nodiscard]] constexpr auto size(list_type auto l) noexcept { return l.size(); }

    /**
     * @brief Obtain the number of elements in the given list as a signed integer.
     *
     * @param l The list to obtain the size of.
     *
     * @return Returns the size of the given list.
     */
    [[nodiscard]] constexpr auto ssize(list_type auto l) noexcept { return l.ssize(); }

    /**
     * @brief Check whether the given list has elements or not.
     *
     * @param l The list to check the emptiness ofl.
     *
     * @retval true  The given list has no elements.
     * @retval false The given list has elements.
     */
    [[nodiscard]] constexpr bool empty(list_type auto l) noexcept { return l.empty(); }

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
     * @tparam T The type to find in the given list.
     *
     * @param l The list to search for the given type in.
     *
     * @return Returns the index of the given type in the given list, or `l.size()` if not found.
     */
    template<typename T>
    [[nodiscard]] constexpr auto find(list_type auto l) noexcept;

    /**
     * @brief Insert the given type into the given type list at the given index.
     *
     * @tparam I    The index to insert a new type at.
     * @tparam T    The type to insert.
     *
     * @param l The list to insert into.
     *
     * @return Returns the list with the newly-inserted element.
     */
    template<std::size_t I, typename T>
    [[nodiscard]] constexpr auto insert(list_type auto l) noexcept requires(I <= l.size());

    /**
     * @brief Remove the types at the given positions in the type list.
     *
     * @tparam I he indices of the elements to remove.
     *
     * @param l The list to remove elements from.
     * @param i The indices of the elements to remove.
     *
     * @return Returns a list with the elemenst at the given indices removed.
     */
    template<std::size_t... I>
    [[nodiscard]] constexpr auto remove(list_type auto l, std::index_sequence<I...> i = {}) noexcept
        requires((I < decltype(l)::size()) && ...);

    /**
     * @brief Remove a range of elements from the given type list.
     *
     * @tparam Begin The starting index of the range to remove.
     * @tparam End   The one-past-the-ending index of the range to remove.
     *
     * @param l     The list to remove a range from.
     * @param begin The starting index of the range to remove.
     * @param end   The one-past-the-ending index of the range to remove.
     *
     * @return Returns a list with the given range removed.
     */
    template<std::size_t Begin, std::size_t End>
    [[nodiscard]] constexpr auto remove_range(
        list_type auto                             l,
        std::integral_constant<std::size_t, Begin> begin = {},
        std::integral_constant<std::size_t, End>   end   = {}) noexcept
        requires((Begin <= End) && (End <= l.size()));

    /**
     * @brief Check whether or not the given type exists in the given type list.
     *
     * @tparam T The type to check the existence of in the given list.
     *
     * @param l The list to check for the given type in.
     *
     * @retval true  The given list contains the given type.
     * @retval false The given list does not contain the given type.
     */
    template<typename T>
    [[nodiscard]] constexpr bool contains(list_type auto l) noexcept;

    /**
     * @brief Obtain a tuple type that has members of the types in the given type list.
     *
     * @tparam TypeList The list to obtain the corresponding tuple type of.
     */
    template<typename TypeList>
    using tuple_from = typename TypeList::tuple;

    /**
     * @brief Obtain a variant type that can hold all the types in the given type list.
     *
     * @tparam TypeList The list to obtain the corresponding variant type of.
     */
    template<list_type TypeList>
    using variant_from = typename TypeList::variant;

    /**
     * @brief Construct a tuple from its corresponding `list`.
     *
     * @tparam TypeList The list to construct a tuple from.
     * @tparam Args     The types of arguments to forward to the tuple constructor.
     *
     * @param list The type list object.
     * @param args The arguments to forward to the tuple constructor.
     *
     * @return Returns the constructed tuple.
     */
    template<list_type TypeList, typename... Args>
    [[nodiscard]] constexpr auto make_tuple_from(TypeList list, Args&&... args) noexcept(
        std::is_nothrow_constructible_v<tuple_from<TypeList>, Args...>) -> tuple_from<TypeList>;

    /**
     * @brief Construct a variant from its corresponding `list`.
     *
     * @tparam TypeList The list to construct a variant from.
     * @tparam Args     The types of arguments to forward to the variant constructor.
     *
     * @param list The type list object.
     * @param args The arguments to forward to the variant constructor.
     *
     * @return Returns the constructed variant.
     */
    template<list_type TypeList, typename... Args>
    [[nodiscard]] constexpr auto make_variant_from(TypeList list, Args&&... args) noexcept(
        std::is_nothrow_constructible_v<variant_from<TypeList>, Args...>) -> variant_from<TypeList>;

} // namespace posu::meta

#include "posu/meta/ipp/list.ipp"

#endif // #ifndef POSU_TYPE_LIST_HPP
