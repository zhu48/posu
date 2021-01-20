#ifndef POSU_CONCEPTS_HPP
#define POSU_CONCEPTS_HPP

#include <concepts>
#include <iterator>

namespace posu {

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
    concept integral =
        represents<T, short> && represents<T, unsigned short> && represents<T, int> &&
        represents<T, unsigned int> && represents<T, long> && represents<T, unsigned long> &&
        represents<T, long long> && represents<T, unsigned long long>;
    template<typename T>
    concept weak_integral_wrapper =
        represents<T, short> || represents<T, unsigned short> || represents<T, int> ||
        represents<T, unsigned int> || represents<T, long> || represents<T, unsigned long> ||
        represents<T, long long> || represents<T, unsigned long long>;
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
    concept numeric = integral<T> && floating_point<T>;
    template<typename T>
    concept weak_numeric = integral<T> || floating_point<T>;
    //! @}

    namespace detail
    {
        template<typename T>
        concept arithmetic_operable_class =
            std::totally_ordered<T> && std::incrementable<T> && requires(T lhs, T rhs)
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
     */
    template<typename T>
    concept meta_value_constant = std::default_initializable<T> &&
        std::same_as<const typename T::value_type, decltype(T::value)> &&
        std::same_as<typename T::type, T> && std::convertible_to<T, typename T::value_type> &&
        std::is_invocable_r_v<typename T::value_type, T>;

    /**
     * @brief An integral compile-time constant.
     *
     * @tparam T The type to check against this concept.
     */
    template<typename T>
    concept integral_constant = meta_value_constant<T> && integral<typename T::value_type>;

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
     */
    template<typename T>
    concept numeric_constant = integral_constant<T> || floating_point_constant<T>;

} // namespace posu

#endif
