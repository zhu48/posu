#ifndef POSU_TYPE_RATIO_HPP
#define POSU_TYPE_RATIO_HPP

#include <type_traits>

#include "posu/type_list.hpp"

namespace posu {

    template<typename Numerator, typename Denominator = type_list<>>
    struct type_ratio {
        using num = Numerator;
        using den = Denominator;

        using type = type_ratio<num, den>;
    };

    namespace detail {

        template<typename Lhs, typename Rhs>
        struct ratio_multiply_impl;

    } // namespace detail

    template<typename Lhs, typename Rhs>
    using ratio_multiply = typename detail::ratio_multiply_impl<Lhs, Rhs>::type;

} // namespace posu

#include "posu/ipp/type_ratio.ipp"

#endif // #ifndef POSU_TYPE_RATIO_HPP
