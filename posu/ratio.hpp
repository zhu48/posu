#ifndef POSU_RATIO_HPP
#define POSU_RATIO_HPP

#include <numeric>
#include <ratio>

#include "posu/concepts.hpp"

namespace posu {

    /**
     * @brief Extended ratio with base-10 exponent.
     *
     * @tparam Num   Ratio numerator.
     * @tparam Denom Ratio denominator.
     * @tparam Exp   Ratio base-10 exponent.
     */
    template<std::intmax_t Num, std::intmax_t Denom = 1, std::intmax_t Exp = 0>
    struct ratio;

    namespace detail {

        template<typename T>
        struct is_ratio : public std::false_type {
        };

        template<std::intmax_t Num, std::intmax_t Denom, std::intmax_t Exp>
        struct is_ratio<ratio<Num, Denom, Exp>> : public std::true_type {
        };

        template<typename T>
        struct is_std_ratio : public std::false_type {
        };

        template<std::intmax_t Num, std::intmax_t Den>
        struct is_std_ratio<std::ratio<Num, Den>> : public std::true_type {
        };

        template<typename T>
        concept ratio_type = is_ratio<T>::value;

        template<std::intmax_t Num, std::intmax_t Den, std::intmax_t Exp, std::intmax_t NewExp>
        [[nodiscard]] constexpr auto denormalize() noexcept;
        template<std::intmax_t Num, std::intmax_t Den, std::intmax_t Exp>
        [[nodiscard]] constexpr auto normalize() noexcept;
        [[nodiscard]] constexpr auto common(ratio_type auto lhs, ratio_type auto rhs) noexcept;
        [[nodiscard]] constexpr auto multiply(ratio_type auto lhs, arithmetic auto rhs) noexcept;

    } // namespace detail

    /**
     * @brief Check whether the given type is a specialization of `posu::ratio` or not.
     *
     * @tparam T The type to check as a specialization of `posu::ratio`.
     */
    using detail::ratio_type;

    template<std::intmax_t Num, std::intmax_t Denom, std::intmax_t Exp>
    struct ratio {
        static constexpr auto num = detail::normalize<Num, Denom, Exp>().num; //!< Numerator.
        static constexpr auto den = detail::normalize<Num, Denom, Exp>().den; //!< Denominator.
        static constexpr auto exp = detail::normalize<Num, Denom, Exp>().exp; //!< Base-10 exponent.

        using type = ratio<num, den, exp>; //!< Reduced type.

        /**
         * @name Arithmetic Operators
         *
         * @brief Ratio arithmetic operations.
         *
         * @param rhs The right-hand-side argument.
         *
         * @return Returns the operation result.
         *
         * @{
         */
        [[nodiscard]] constexpr auto        operator+(ratio_type auto rhs) const noexcept;
        [[nodiscard]] constexpr auto        operator-(ratio_type auto rhs) const noexcept;
        [[nodiscard]] constexpr auto        operator*(ratio_type auto rhs) const noexcept;
        [[nodiscard]] constexpr auto        operator/(ratio_type auto rhs) const noexcept;
        [[nodiscard]] friend constexpr auto operator+(ratio lhs, numeric auto rhs) noexcept
        {
            return (decltype(rhs){1} * lhs) + rhs;
        }
        [[nodiscard]] friend constexpr auto operator+(numeric auto lhs, ratio rhs) noexcept
        {
            return rhs + lhs;
        }
        [[nodiscard]] friend constexpr auto operator-(ratio lhs, numeric auto rhs) noexcept
        {
            return (decltype(rhs){1} * lhs) - rhs;
        }
        [[nodiscard]] friend constexpr auto operator-(numeric auto lhs, ratio rhs) noexcept
        {
            return lhs - (decltype(lhs){1} * rhs);
        }
        [[nodiscard]] friend constexpr auto operator*(ratio lhs, numeric auto rhs) noexcept
        {
            return detail::multiply(lhs, rhs);
        }
        [[nodiscard]] friend constexpr auto operator*(numeric auto lhs, ratio rhs) noexcept
        {
            return detail::multiply(rhs, lhs);
        }
        [[nodiscard]] friend constexpr auto operator/(numeric auto lhs, ratio rhs) noexcept
        {
            return detail::multiply(lhs, ratio<rhs.den, rhs.num, -rhs.exp>{});
        }
        //! @}

        /**
         * @name Comparison Operators
         *
         * @brief Compare the value of this ratio against another ratio.
         *
         * @param rhs The ratio to compare against.
         *
         * @return Returns the comparison result.
         *
         * @{
         */
        [[nodiscard]] constexpr bool operator==(ratio_type auto rhs) const noexcept;
        [[nodiscard]] constexpr auto operator<=>(ratio_type auto rhs) const noexcept;
        //! @}
    };

    /**
     * @brief Adjust the ratio's representation to maximally reduce its mantissa fraction.
     *
     * @tparam Ratio The ratio to normalize.
     */
    template<ratio_type Ratio>
    using normalize = typename Ratio::type;

    /**
     * @brief Denormalize a ratio so its exponent is the given value.
     *
     * @tparam Ratio  The ratio to denormalize.
     * @tparam NewExp The exponent to assign to the resulting ratio.
     */
    template<ratio_type Ratio, std::intmax_t NewExp>
    using denormalize = ratio<
        detail::denormalize<Ratio::num, Ratio::den, Ratio::exp, NewExp>().num,
        detail::denormalize<Ratio::num, Ratio::den, Ratio::exp, NewExp>().den,
        detail::denormalize<Ratio::num, Ratio::den, Ratio::exp, NewExp>().exp>;

    /**
     * @brief Add two ratios;
     *
     * @tparam Lhs The left-hand-side ratio.
     * @tparam Rhs The right-hand-side ratio.
     */
    template<ratio_type Lhs, ratio_type Rhs>
    using ratio_add = decltype(Lhs{} + Rhs{});

    /**
     * @brief Subtract a ratio from another.
     *
     * @tparam Lhs The ratio to subtract from.
     * @tparam Rhs The amount to subtract.
     */
    template<ratio_type Lhs, ratio_type Rhs>
    using ratio_subtract = decltype(Lhs{} - Rhs{});

    /**
     * @brief Multiply two ratio objects.
     *
     * @tparam Lhs The left-hand-side ratio.
     * @tparam Rhs The right-hand-side ratio.
     */
    template<ratio_type Lhs, ratio_type Rhs>
    using ratio_multiply = decltype(Lhs{} * Rhs{});

    /**
     * @brief Ratio comparison.
     *
     * @tparam Lhs The left-hand-side operand.
     * @tparam Rhs The right-hand-side operand.
     *
     * @{
     */

    template<ratio_type Lhs, ratio_type Rhs>
    struct ratio_equal : public std::bool_constant<Lhs{} == Rhs{}> {
    };

    template<ratio_type Lhs, ratio_type Rhs>
    struct ratio_not_equal : public std::bool_constant<Lhs{} != Rhs{}> {
    };

    template<ratio_type Lhs, ratio_type Rhs>
    struct ratio_less : public std::bool_constant<(Lhs{} < Rhs{})> {
    };

    template<ratio_type Lhs, ratio_type Rhs>
    struct ratio_less_equal : public std::bool_constant<Lhs{} <= Rhs{}> {
    };

    template<ratio_type Lhs, ratio_type Rhs>
    struct ratio_greater : public std::bool_constant<(Lhs{} > Rhs{})> {
    };

    template<ratio_type Lhs, ratio_type Rhs>
    struct ratio_greater_equal : public std::bool_constant<Lhs{} >= Rhs{}> {
    };

    //! @}

    /**
     * @brief Divide two ratio objects.
     *
     * @tparam Lhs The left-hand-side ratio.
     * @tparam Rhs The right-hand-side ratio.
     */
    template<ratio_type Lhs, ratio_type Rhs>
    using ratio_divide = decltype(Lhs{} / Rhs{});

    using yocto = ratio<1, 1, -24>; //!< SI `yocto` ratio.
    using zepto = ratio<1, 1, -21>; //!< SI `zepto` ratio.
    using atto  = ratio<1, 1, -18>; //!< SI `atto` ratio.
    using femto = ratio<1, 1, -15>; //!< SI `femto` ratio.
    using pico  = ratio<1, 1, -12>; //!< SI `pico` ratio.
    using nano  = ratio<1, 1, -9>;  //!< SI `nano` ratio.
    using micro = ratio<1, 1, -6>;  //!< SI `micro` ratio.
    using milli = ratio<1, 1, -3>;  //!< SI `milli` ratio.
    using centi = ratio<1, 1, -2>;  //!< SI `centi` ratio.
    using deci  = ratio<1, 1, -1>;  //!< SI `deci` ratio.
    using deca  = ratio<1, 1, 1>;   //!< SI `deca` ratio.
    using hecto = ratio<1, 1, 2>;   //!< SI `hecto` ratio.
    using kilo  = ratio<1, 1, 3>;   //!< SI `kilo` ratio.
    using mega  = ratio<1, 1, 6>;   //!< SI `mega` ratio.
    using giga  = ratio<1, 1, 9>;   //!< SI `giga` ratio.
    using tera  = ratio<1, 1, 12>;  //!< SI `tera` ratio.
    using peta  = ratio<1, 1, 15>;  //!< SI `peta` ratio.
    using exa   = ratio<1, 1, 18>;  //!< SI `exa` ratio.
    using zetta = ratio<1, 1, 21>;  //!< SI `zetta` ratio.
    using yotta = ratio<1, 1, 24>;  //!< SI `yotta` ratio.

    /**
     * @brief Convert from `std::ratio` to `posu::ratio`.
     *
     * @tparam Ratio The `std::ratio` type to convert from.
     */
    template<typename Ratio>
        requires(detail::is_std_ratio<Ratio>::value)
    using make_ratio = ratio<Ratio::num, Ratio::den>;

    /**
     * @brief Compute a common ratio type between the two given ratio types.
     *
     * Both operand ratios are integer multiples of the resulting ratio.
     *
     * @tparam Lhs The left-hand-side operand.
     * @tparam Rhs The right-hand-side operand.
     */
    template<ratio_type Lhs, ratio_type Rhs>
    using common_ratio = decltype(detail::common(Lhs{}, Rhs{}));

} // namespace posu

template<
    std::intmax_t LNum,
    std::intmax_t LDen,
    std::intmax_t LExp,
    std::intmax_t RNum,
    std::intmax_t RDen,
    std::intmax_t RExp>
struct std::common_type<posu::ratio<LNum, LDen, LExp>, posu::ratio<RNum, RDen, RExp>> {
    using type = posu::common_ratio<posu::ratio<LNum, LDen, LExp>, posu::ratio<RNum, RDen, RExp>>;
};

#include "posu/ipp/ratio.ipp"

#endif // #ifndef POSU_RATIO_HPP
