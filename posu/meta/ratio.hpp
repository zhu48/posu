#ifndef POSU_TYPE_RATIO_HPP
#define POSU_TYPE_RATIO_HPP

#include <type_traits>

#include "posu/meta/list.hpp"

namespace posu::meta {

    template<list_type Numerator = list<>, list_type Denominator = list<>>
    struct ratio;

    namespace detail {

        template<typename T>
        struct is_ratio : std::false_type {
        };

        template<typename Numerator, typename Denominator>
        struct is_ratio<ratio<Numerator, Denominator>> : std::true_type {
        };

    } // namespace detail

    /**
     * @brief An instance of the `ratio` template.
     *
     * @tparam T The type to check against this concept.
     */
    template<typename T>
    concept ratio_type = detail::is_ratio<T>::value;

    namespace detail
    {

        [[nodiscard]] constexpr auto ratio_multiply(
            ratio_type auto lhs,
            ratio_type auto rhs) noexcept;

    } // namespace detail

    /**
     * @brief A ratio between type products.
     *
     * @tparam Numerator   The list of types in the numerator.
     * @tparam Denominator The list of types in the denominator.
     */
    template<list_type Numerator, list_type Denominator>
    struct ratio {
        static constexpr auto num = Numerator{};   //!< The numerator type list.
        static constexpr auto den = Denominator{}; //!< The denominator type list.

        using type = ratio<Numerator, Denominator>; //!< Self-alias.

        /**
         * @brief Multiply two type ratios together.
         *
         * @param lhs The left-hand-side operand.
         * @param rhs The right-hand-side operand.
         *
         * @return Returns the multiplication result.
         */
        [[nodiscard]] friend constexpr auto operator*(ratio lhs, ratio_type auto rhs) noexcept
        {
            return detail::ratio_multiply(lhs, rhs);
        }

        /**
         * @brief Divide one type ratios by another.
         *
         * @param num The type ratio to divide.
         * @param den The type ratio to divide by.
         *
         * @return Returns the division result.
         */
        [[nodiscard]] friend constexpr auto operator/(ratio num, ratio_type auto den) noexcept
        {
            return num * invert(den);
        }

        /**
         * @brief Equality comparison between two type ratios.
         *
         * Two type ratios are equal if, in their reduced forms, each operand's numerator contains
         * the same types as the other's denominator, in any order.
         *
         * @param lhs The left-hand-side comparison operand.
         * @param rhs The right-hand-size comparison operand.
         *
         * @return true  Both type ratios are equivalent.
         * @return false The type ratios are not equivalent.
         */
        [[nodiscard]] friend constexpr bool operator==(ratio lhs, ratio_type auto rhs) noexcept
        {
            return std::same_as<decltype(lhs / rhs), ratio<>>;
        }
    };

    /**
     * @brief Obtain the numerator of the given type ratio.
     *
     * @tparam T The type ratio to get the numerator of.
     */
    template<ratio_type T>
    using numerator = std::remove_const_t<decltype(T::num)>;

    /**
     * @brief Obtain the denominator of the given type ratio.
     *
     * @tparam T The type ratio to get the denominator of.
     */
    template<ratio_type T>
    using denominator = std::remove_const_t<decltype(T::den)>;

    /**
     * @brief Obtain the inverse of the given type ratio.
     *
     * @param r The type ratio to invert.
     *
     * @return Returns the inverted type ratio.
     */
    [[nodiscard]] constexpr auto invert(ratio_type auto r) noexcept;

} // namespace posu::meta

#include "posu/meta/ipp/ratio.ipp"

#endif // #ifndef POSU_TYPE_RATIO_HPP
