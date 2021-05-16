#ifndef POSU_TYPE_RATIO_HPP
#define POSU_TYPE_RATIO_HPP

#include <type_traits>

#include "posu/type_list.hpp"

namespace posu {

    /**
     * @brief A ratio between type products.
     *
     * @tparam Numerator   The list of types in the numerator.
     * @tparam Denominator The list of types in the denominator.
     */
    template<typename Numerator = type_list<>, typename Denominator = type_list<>>
    struct type_ratio {
        using num = Numerator;   //!< The numerator type list.
        using den = Denominator; //!< The denominator type list.

        using type = type_ratio<num, den>; //!< Self-alias.
    };

    /**
     * @brief Traits template to detect whether a type specializes `type_list` or not.
     * @{
     */
    //! @tparam T The type to check.
    template<typename T>
    struct is_type_ratio : std::false_type {
    };
    //! @tparam Types The types in the type list.
    template<typename Numerator, typename Denominator>
    struct is_type_ratio<type_ratio<Numerator, Denominator>> : std::true_type {
    };
    template<typename T>
    inline constexpr bool is_type_ratio_v = is_type_ratio<T>::value;
    template<typename T>
    concept meta_ratio = is_type_ratio_v<T>;
    //! @}

    /**
     * @brief Obtain the numerator of the given type ratio.
     *
     * @tparam T The type ratio to get the numerator of.
     */
    template<typename T>
        requires(is_type_ratio_v<T>)
    using numerator = typename T::num;

    /**
     * @brief Obtain the denominator of the given type ratio.
     *
     * @tparam T The type ratio to get the denominator of.
     */
    template<typename T>
        requires(is_type_ratio_v<T>)
    using denominator = typename T::den;

    /**
     * @brief Obtain the inverse of the given type ratio.
     *
     * @tparam T The type ratio to get the inverse of.
     */
    template<typename T>
        requires(is_type_ratio_v<T>)
    using inverse = type_ratio<denominator<T>, numerator<T>>;

    namespace detail {

        template<typename Lhs, typename Rhs>
        struct ratio_multiply_impl;

    } // namespace detail

    template<meta_ratio Ratio>
    using ratio_invert = type_ratio<typename Ratio::den, typename Ratio::num>;

    /**
     * @brief Multiply two type ratios together.
     *
     * @tparam Lhs The left-hand-size operand.
     * @tparam Rhs The right-hand-side operand.
     */
    template<typename Lhs, typename Rhs>
    using ratio_multiply = typename detail::ratio_multiply_impl<Lhs, Rhs>::type;

    /**
     * @brief Divide one type ratios by another.
     *
     * @tparam Dividend The type ratio to divide.
     * @tparam Divisor  The type ratio to divide by.
     */
    template<typename Dividend, typename Divisor>
    using ratio_divide = ratio_multiply<Dividend, inverse<Divisor>>;

} // namespace posu

#include "posu/ipp/type_ratio.ipp"

#endif // #ifndef POSU_TYPE_RATIO_HPP
