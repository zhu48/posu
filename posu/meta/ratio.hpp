#ifndef POSU_TYPE_RATIO_HPP
#define POSU_TYPE_RATIO_HPP

#include <type_traits>

#include "posu/meta/list.hpp"

namespace posu::meta {

    /**
     * @brief A ratio between type products.
     *
     * @tparam Numerator   The list of types in the numerator.
     * @tparam Denominator The list of types in the denominator.
     */
    template<typename Numerator = list<>, typename Denominator = list<>>
    struct ratio {
        using num = Numerator;   //!< The numerator type list.
        using den = Denominator; //!< The denominator type list.

        using type = ratio<num, den>; //!< Self-alias.
    };

    /**
     * @brief Traits template to detect whether a type specializes `type_list` or not.
     * @{
     */
    //! @tparam T The type to check.
    template<typename T>
    struct is_ratio : std::false_type {
    };
    //! @tparam Types The types in the type list.
    template<typename Numerator, typename Denominator>
    struct is_ratio<ratio<Numerator, Denominator>> : std::true_type {
    };
    template<typename T>
    inline constexpr bool is_ratio_v = is_ratio<T>::value;
    template<typename T>
    concept ratio_type = is_ratio_v<T>;
    //! @}

    /**
     * @brief Obtain the numerator of the given type ratio.
     *
     * @tparam T The type ratio to get the numerator of.
     */
    template<typename T>
        requires(is_ratio_v<T>)
    using numerator = typename T::num;

    /**
     * @brief Obtain the denominator of the given type ratio.
     *
     * @tparam T The type ratio to get the denominator of.
     */
    template<typename T>
        requires(is_ratio_v<T>)
    using denominator = typename T::den;

    /**
     * @brief Obtain the inverse of the given type ratio.
     *
     * @tparam T The type ratio to get the inverse of.
     */
    template<typename T>
        requires(is_ratio_v<T>)
    using inverse = ratio<denominator<T>, numerator<T>>;

    namespace detail {

        template<typename Lhs, typename Rhs>
        struct ratio_multiply_impl;

    } // namespace detail

    template<ratio_type Ratio>
    using ratio_invert = ratio<typename Ratio::den, typename Ratio::num>;

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

} // namespace posu::meta

#include "posu/meta/ipp/ratio.ipp"

#endif // #ifndef POSU_TYPE_RATIO_HPP