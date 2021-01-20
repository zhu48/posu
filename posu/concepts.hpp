#ifndef POSU_CONCEPTS_HPP
#define POSU_CONCEPTS_HPP

#include <concepts>

namespace posu {

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
    concept integral_constant = meta_value_constant<T> && std::integral<typename T::value_type>;

    /**
     * @brief A floating point compile-time constant.
     *
     * @tparam T The type to check against this concept.
     */
    template<typename T>
    concept floating_point_constant =
        meta_value_constant<T> && std::floating_point<typename T::value_type>;

    /**
     * @brief A numeric compile-time constant.
     *
     * @tparam T The type to check against this concept.
     */
    template<typename T>
    concept numeric_constant = integral_constant<T> || floating_point_constant<T>;

} // namespace posu

#endif
