#ifndef POSU_UTILITY_HPP
#define POSU_UTILITY_HPP

#include <functional>
#include <tuple>

namespace posu {

    /**
     * Apply the given *Callable* to the given tuples' elements.
     *
     * Invoke the *Callable* with the first elements of each tuple, then the
     * second elements of each tuple, then the third elements of each tuple,
     * etc. Effectively calls
     *
     * @code
     *
     * f( std::get<0>(tuple0), std::get<0>(tuple1), ... );
     * f( std::get<1>(tuple0), std::get<1>(tuple1), ... );
     * // ...
     *
     * @endcode
     *
     * in order. The tuples need not have the same number of elements. The given
     * *Callable* is applied only to the first `n` elements of the tuples, where
     * `n` is the least number of elements any of the tuples has.
     *
     * This function is exception-neutral.
     *
     * @tparam F     The *Callable* type to apply to the given tuples.
     * @tparam Tuple The tuple types to apply the given *Callable* to.
     *
     * @param f     The *Callable* object to apply to the given tuples.
     * @param tuple The tuples to apply the given *Callable* object to.
     */
    template<typename F, typename... Tuple>
    constexpr void for_each(F&& f, Tuple&&... tuple);

    /**
     * Create a tuple-like object by applying `f` to the given tuple's elements.
     *
     * Performs the same operations as `posu::for_each`, and additionally
     * returns uses results of the `f` invocations to construct an object of
     * type `T`. Effectively returns
     *
     * @code
     *
     * T(
     *     f( std::get<0>(tuple0), std::get<0>(tuple1), ... ),
     *     f( std::get<0>(tuple0), std::get<0>(tuple1), ... ),
     *     ...
     * );
     *
     * @endcode
     *
     * @tparam T     The type of object to return.
     * @tparam F     The *Callable* type to apply to the given tuples.
     * @tparam Tuple The tuple types to apply the given *Callable* to.
     *
     * @param f     The *Callable* object to apply to the given tuples.
     * @param tuple The tuples to apply the given *Callable* object to.
     *
     * @return Returns a `T` object constructed from the `f` invocations.
     */
    template<typename T, typename F, typename... Tuple>
        requires(std::less_equal{}(
            std::tuple_size_v<T>,
            std::tuple_size_v<std::remove_cvref_t<Tuple>>)&&...)
    [[nodiscard]] constexpr auto make_from_for_each(F&& f, Tuple&&... tuple) -> T;

    /**
     * @brief Explicit forwarding cast.
     *
     * @tparam T The non-`cv`-qualified, non-reference type to cast to.
     * @tparam U The type to forward.
     *
     * @param u The value to forward and cast.
     *
     * @return Returns the cast result, preserving `cv`-qualifications and value category.
     *
     * @{
     */
    template<typename T, typename U>
        requires(
            !std::is_const_v<std::remove_reference_t<U>> &&
            !std::is_volatile_v<std::remove_reference_t<U>> && std::is_lvalue_reference_v<U&&>)
    [[nodiscard]] constexpr auto forward_as(U&& u) noexcept -> T&;
    template<typename T, typename U>
        requires(
            std::is_const_v<std::remove_reference_t<U>> &&
            !std::is_volatile_v<std::remove_reference_t<U>> && std::is_lvalue_reference_v<U&&>)
    [[nodiscard]] constexpr auto forward_as(U&& u) noexcept -> const T&;
    template<typename T, typename U>
        requires(
            !std::is_const_v<std::remove_reference_t<U>> &&
            std::is_volatile_v<std::remove_reference_t<U>> && std::is_lvalue_reference_v<U&&>)
    [[nodiscard]] constexpr auto forward_as(U&& u) noexcept -> volatile T&;
    template<typename T, typename U>
        requires(std::is_const_v<std::remove_reference_t<U>>&& std::is_volatile_v<
                 std::remove_reference_t<U>>&& std::is_lvalue_reference_v<U&&>)
    [[nodiscard]] constexpr auto forward_as(U&& u) noexcept -> const volatile T&;
    template<typename T, typename U>
        requires(
            !std::is_const_v<std::remove_reference_t<U>> &&
            !std::is_volatile_v<std::remove_reference_t<U>> && std::is_rvalue_reference_v<U&&>)
    [[nodiscard]] constexpr auto forward_as(U&& u) noexcept -> T&&;
    template<typename T, typename U>
        requires(
            std::is_const_v<std::remove_reference_t<U>> &&
            !std::is_volatile_v<std::remove_reference_t<U>> && std::is_rvalue_reference_v<U&&>)
    [[nodiscard]] constexpr auto forward_as(U&& u) noexcept -> const T&&;
    template<typename T, typename U>
        requires(
            !std::is_const_v<std::remove_reference_t<U>> &&
            std::is_volatile_v<std::remove_reference_t<U>> && std::is_rvalue_reference_v<U&&>)
    [[nodiscard]] constexpr auto forward_as(U&& u) noexcept -> volatile T&&;
    template<typename T, typename U>
        requires(std::is_const_v<std::remove_reference_t<U>>&& std::is_volatile_v<
                 std::remove_reference_t<U>>&& std::is_rvalue_reference_v<U&&>)
    [[nodiscard]] constexpr auto forward_as(U&& u) noexcept -> const volatile T&&;
    //! @}

} // namespace posu

#include "posu/ipp/utility.ipp"

#endif // #ifndef POSU_UTILITY_HPP
