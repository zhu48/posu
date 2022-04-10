#ifndef POSU_CONCEPTS_HPP
#define POSU_CONCEPTS_HPP

#include <cstddef>
#include <cstdint>

#include <concepts>
#include <iterator>

namespace posu {

    template<typename T>
    concept weakly_incrementable = std::default_initializable<T> && std::movable<T> && requires(T i)
    {
        // clang-format off
        { ++i } -> std::same_as<T&>;
        i++;
        // clang-format on
    };

    template<typename T>
    concept incrementable = std::regular<T> && weakly_incrementable<T> && requires(T i)
    {
        // clang-format off
        { i++ } -> std::same_as<T>;
        // clang-format on
    };

    /**
     * @brief A type that represents values of another type.
     *
     * @tparam T     The type to check against this concept.
     * @tparam Value The type to be represented by another type.
     */
    template<typename T, typename Value>
    concept represents = std::constructible_from<T, Value> && std::constructible_from<Value, T> &&
        std::assignable_from<T&, Value>;

    /**
     * @brief A type representing an integral value.
     *
     * The weak version only needs to represent a single integral type.
     *
     * @tparam T The type to check against this concept.
     *
     * @{
     */
    template<typename T>
    concept signed_integral = represents<T, short> && represents<T, int> && represents<T, long> &&
        represents<T, long long>;
    template<typename T>
    concept unsigned_integral = represents<T, unsigned short> && represents<T, unsigned int> &&
        represents<T, unsigned long> && represents<T, unsigned long long>;
    template<typename T>
    concept integral = signed_integral<T> && unsigned_integral<T>;
    template<typename T>
    concept weak_signed_integral = represents<T, short> || represents<T, int> ||
        represents<T, long> || represents<T, long long>;
    template<typename T>
    concept weak_unsigned_integral = represents<T, unsigned short> || represents<T, unsigned int> ||
        represents<T, unsigned long> || represents<T, unsigned long long>;
    template<typename T>
    concept weak_integral = weak_signed_integral<T> || weak_unsigned_integral<T>;
    //! @}

    /**
     * @brief A type representing a floating-point value.
     *
     * The weak version only needs to represent a single floating point type.
     *
     * @tparam T The type to check against this concept.
     *
     * @{
     */
    template<typename T>
    concept floating_point =
        represents<T, float> && represents<T, double> && represents<T, long double>;
    template<typename T>
    concept weak_floating_point =
        represents<T, float> || represents<T, double> || represents<T, long double>;
    //! @}

    /**
     * @brief A type representing a numeric value.
     *
     * The weak version only needs to represent a single numeric type.
     *
     * @tparam T The type to check against this concept.
     *
     * @{
     */
    template<typename T>
    concept signed_numeric = signed_integral<T> && floating_point<T>;
    template<typename T>
    concept unsigned_numeric = unsigned_integral<T>;
    template<typename T>
    concept numeric = signed_numeric<T> && unsigned_numeric<T>;
    template<typename T>
    concept weak_signed_numeric = weak_signed_integral<T> || weak_floating_point<T>;
    template<typename T>
    concept weak_unsigned_numeric = weak_unsigned_integral<T>;
    template<typename T>
    concept weak_numeric = weak_signed_numeric<T> || weak_unsigned_numeric<T>;
    //! @}

    namespace detail
    {
        template<typename T>
        concept arithmetic_operable_class =
            std::totally_ordered<T> && incrementable<T> && requires(T lhs, T rhs)
        {
            // clang-format off
            // decrement operators
            { --lhs } -> std::same_as<T&>;
            { lhs-- } -> std::same_as<T>;
            // unary sign operators
            { +lhs } -> std::same_as<T>;
            { -lhs } -> std::same_as<T>;
            // binary arithmetic operators
            { lhs += rhs } -> std::same_as<T&>;
            { lhs +  rhs } -> std::same_as<T>;
            { lhs -= rhs } -> std::same_as<T&>;
            { lhs -  rhs } -> std::same_as<T>;
            { lhs *= rhs } -> std::same_as<T&>;
            { lhs *  rhs } -> std::same_as<T>;
            { lhs /= rhs } -> std::same_as<T&>;
            { lhs /  rhs } -> std::same_as<T>;
            { lhs %= rhs } -> std::same_as<T&>;
            { lhs %  rhs } -> std::same_as<T>;
            // clang-format on
        };

    } // namespace detail

    /**
     * @brief A type that supports arithmetic operators.
     *
     * @tparam T The type to check against this concept.
     */
    template<typename T>
    concept arithmetic_operable =
        std::integral<T> || std::floating_point<T> || detail::arithmetic_operable_class<T>;

    /**
     * @brief Numeric arithmetic types.
     *
     * @tparam T The type to check against this concept.
     *
     * @{
     */
    template<typename T>
    concept signed_arithmetic = signed_numeric<T> && arithmetic_operable<T>;
    template<typename T>
    concept unsigned_arithmetic = unsigned_numeric<T> && arithmetic_operable<T>;
    template<typename T>
    concept integral_arithmetic = integral<T> && arithmetic_operable<T>;
    template<typename T>
    concept floating_point_arithmetic = floating_point<T> && arithmetic_operable<T>;
    template<typename T>
    concept arithmetic = numeric<T> && arithmetic_operable<T>;
    //! @}

    /**
     * @brief A type wrapping a compile-time constant.
     *
     * Modeled after `std::integral_constant`.
     *
     * @tparam T The type to check against this concept.
     *
     * @{
     */
    template<typename T>
    concept meta_value_constant = std::default_initializable<T> &&
        std::same_as<const typename T::value_type, decltype(T::value)> &&
        std::same_as<typename T::type, T> && std::convertible_to<T, typename T::value_type> &&
        std::is_invocable_r_v<typename T::value_type, T>;
    //! @tparam Value The constant value type.
    template<typename T, typename Value>
    concept meta_constant = meta_value_constant<T> && std::same_as<Value, typename T::value_type>;
    //! @}

    /**
     * @brief Fundamental, basic, and fixed-width numeric constants.
     *
     * @tparam T The type to check against this concept.
     *
     * @{
     */
    template<typename T>
    concept bool_constant = meta_constant<T, bool>;
    template<typename T>
    concept float_constant = meta_constant<T, float>;
    template<typename T>
    concept double_constant = meta_constant<T, double>;
    template<typename T>
    concept long_double_constant = meta_constant<T, long double>;
    template<typename T>
    concept size_constant = meta_constant<T, std::size_t>;
    template<typename T>
    concept ptrdiff_constant = meta_constant<T, std::ptrdiff_t>;
    template<typename T>
    concept byte_constant = meta_constant<T, std::byte>;
#ifdef UINT8_MAX
    template<typename T>
    concept uint8_constant = meta_constant<T, std::uint8_t>;
#endif
#ifdef INT8_MAX
    template<typename T>
    concept int8_constant = meta_constant<T, std::int8_t>;
#endif
    template<typename T>
    concept uint_fast8_constant = meta_constant<T, std::uint_fast8_t>;
    template<typename T>
    concept int_fast8_constant = meta_constant<T, std::int_fast8_t>;
    template<typename T>
    concept uint_least8_constant = meta_constant<T, std::uint_least8_t>;
    template<typename T>
    concept int_least8_constant = meta_constant<T, std::int_least8_t>;
#ifdef UINT16_MAX
    template<typename T>
    concept uint16_constant = meta_constant<T, std::uint16_t>;
#endif
#ifdef INT16_MAX
    template<typename T>
    concept int16_constant = meta_constant<T, std::int16_t>;
#endif
    template<typename T>
    concept uint_fast16_constant = meta_constant<T, std::uint_fast16_t>;
    template<typename T>
    concept int_fast16_constant = meta_constant<T, std::int_fast16_t>;
    template<typename T>
    concept uint_least16_constant = meta_constant<T, std::uint_least16_t>;
    template<typename T>
    concept int_least16_constant = meta_constant<T, std::int_least16_t>;
#ifdef UINT32_MAX
    template<typename T>
    concept uint32_constant = meta_constant<T, std::uint32_t>;
#endif
#ifdef INT32_MAX
    template<typename T>
    concept int32_constant = meta_constant<T, std::int32_t>;
#endif
    template<typename T>
    concept uint_fast32_constant = meta_constant<T, std::uint_fast32_t>;
    template<typename T>
    concept int_fast32_constant = meta_constant<T, std::int_fast32_t>;
    template<typename T>
    concept uint_least32_constant = meta_constant<T, std::uint_least32_t>;
    template<typename T>
    concept int_least32_constant = meta_constant<T, std::int_least32_t>;
#ifdef UINT64_MAX
    template<typename T>
    concept uint64_constant = meta_constant<T, std::uint64_t>;
#endif
#ifdef INT64_MAX
    template<typename T>
    concept int64_constant = meta_constant<T, std::int64_t>;
#endif
    template<typename T>
    concept uint_fast64_constant = meta_constant<T, std::uint_fast64_t>;
    template<typename T>
    concept int_fast64_constant = meta_constant<T, std::int_fast64_t>;
    template<typename T>
    concept uint_least64_constant = meta_constant<T, std::uint_least64_t>;
    template<typename T>
    concept int_least64_constant = meta_constant<T, std::int_least64_t>;
    template<typename T>
    concept uintptr_constant = meta_constant<T, std::uintptr_t>;
#ifdef INTPTR_MAX
    template<typename T>
    concept intptr_constant = meta_constant<T, std::intptr_t>;
#endif
    template<typename T>
    concept uintmax_constant = meta_constant<T, std::uintmax_t>;
    template<typename T>
    concept intmax_constant = meta_constant<T, std::intmax_t>;
    //! @}

    /**
     * @brief An integral compile-time constant.
     *
     * @tparam T The type to check against this concept.
     *
     * @{
     */
    template<typename T>
    concept signed_integral_constant =
        meta_value_constant<T> && signed_integral<typename T::value_type>;
    template<typename T>
    concept unsigned_integral_constant =
        meta_value_constant<T> && unsigned_integral<typename T::value_type>;
    template<typename T>
    concept integral_constant = meta_value_constant<T> && integral<typename T::value_type>;
    //! @}

    /**
     * @brief A floating point compile-time constant.
     *
     * @tparam T The type to check against this concept.
     */
    template<typename T>
    concept floating_point_constant =
        meta_value_constant<T> && floating_point<typename T::value_type>;

    /**
     * @brief A numeric compile-time constant.
     *
     * @tparam T The type to check against this concept.
     *
     * @{
     */
    template<typename T>
    concept signed_numeric_constant = signed_integral_constant<T> || floating_point_constant<T>;
    template<typename T>
    concept unsigned_numeric_constant = unsigned_integral_constant<T>;
    template<typename T>
    concept numeric_constant = integral_constant<T> || floating_point_constant<T>;
    //! @}

    /**
     * @brief An arithmetic compile-time constant.
     *
     * @tparam T The type to check against this concept.
     *
     * @{
     */
    template<typename T>
    concept signed_arithmetic_constant =
        meta_value_constant<T> && signed_arithmetic<typename T::value_type>;
    template<typename T>
    concept unsigned_arithmetic_constant =
        meta_value_constant<T> && unsigned_arithmetic<typename T::value_type>;
    template<typename T>
    concept arithmetic_constant = meta_value_constant<T> && arithmetic<typename T::value_type>;
    //! @}

    /**
     * @brief Specific value constants.
     *
     * @tparam T The type to check against this concept.
     *
     * @{
     */
    template<typename T>
    concept zero_constant = meta_value_constant<T> && T::value == 0;
    template<typename T>
    concept one_constant = meta_value_constant<T> && T::value == 1;
    template<typename T>
    concept true_constant = bool_constant<T> && T::value;
    template<typename T>
    concept false_constant = bool_constant<T> && !T::value;
    //! @}

    /**
     * @brief Equality comparison between meta-constants using their underlying values.
     *
     * @tparam Lhs The left-hand-side meta-constant type.
     * @tparam Rhs The right-hand-side meta-constant type.
     *
     * @{
     */
    template<typename Lhs, typename Rhs>
    concept meta_equal_to = Lhs::value == Rhs::value;
    template<typename Lhs, typename Rhs>
    struct is_meta_equal : public std::bool_constant<meta_equal_to<Lhs, Rhs>> {
    };
    template<typename Lhs, typename Rhs>
    inline constexpr bool is_meta_equal_v = meta_equal_to<Lhs, Rhs>;
    //! @}

} // namespace posu

#endif
