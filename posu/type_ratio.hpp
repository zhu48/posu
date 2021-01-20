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

    namespace detail {

        template<typename Lhs, typename Rhs>
        struct ratio_multiply_impl;

    } // namespace detail

    /**
     * @brief Multiply two type ratios together.
     *
     * @tparam Lhs The left-hand-size operand.
     * @tparam Rhs The right-hand-side operand.
     */
    template<typename Lhs, typename Rhs>
    using ratio_multiply = typename detail::ratio_multiply_impl<Lhs, Rhs>::type;

} // namespace posu

#include "posu/ipp/type_ratio.ipp"

#endif // #ifndef POSU_TYPE_RATIO_HPP
