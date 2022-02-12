#ifndef POSU_RATIO_HPP
#define POSU_RATIO_HPP

#include <algorithm>
#include <numeric>
#include <ratio>

namespace posu {

    /**
     * @brief Extended ratio with base-10 exponent.
     *
     * @tparam Num   Ratio numerator.
     * @tparam Denom Ratio denominator.
     * @tparam Exp   Ratio base-10 exponent.
     */
    template<std::intmax_t Num, std::intmax_t Denom = 1, std::intmax_t Exp = 0>
    struct ratio {
        static constexpr auto num = std::ratio<Num, Denom>::num; //!< Numerator.
        static constexpr auto den = std::ratio<Num, Denom>::den; //!< Denominator.
        static constexpr auto exp = Exp;                         //!< Base-10 exponent.

        using type = ratio<num, den, exp>; //!< Reduced type.

        /**
         * @name Arithmetic Operators
         *
         * @brief Ratio arithmetic operations.
         *
         * @param lhs The left-hand-side argument.
         * @param rhs The right-hand-side argument.
         *
         * @return Returns the operation result.
         *
         * @{
         */

        template<std::intmax_t RNum, std::intmax_t RDenom, std::intmax_t RExp>
        [[nodiscard]] constexpr auto operator+(ratio<RNum, RDenom, RExp> rhs) noexcept;

        template<std::intmax_t RNum, std::intmax_t RDenom, std::intmax_t RExp>
        [[nodiscard]] friend constexpr auto
        operator*(ratio lhs, ratio<RNum, RDenom, RExp> rhs) noexcept
        {
            using std_l = std::ratio<lhs.num, lhs.den>;
            using std_r = std::ratio<rhs.num, rhs.den>;
            using prod  = std::ratio_multiply<std_l, std_r>;

            return ratio<prod::num, prod::den, Exp + RExp>{};
        }

        template<std::intmax_t RNum, std::intmax_t RDenom, std::intmax_t RExp>
        [[nodiscard]] friend constexpr auto
        operator/(ratio lhs, ratio<RNum, RDenom, RExp> rhs) noexcept
        {
            using std_l = std::ratio<lhs.num, lhs.den>;
            using std_r = std::ratio<rhs.num, rhs.den>;
            using prod  = std::ratio_divide<std_l, std_r>;

            return ratio<prod::num, prod::den, Exp - RExp>{};
        }

        //! @}
    };

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

        template<ratio_type Ratio, std::intmax_t NewExp>
        [[nodiscard]] constexpr auto denormalize() noexcept;
        template<ratio_type Ratio>
        [[nodiscard]] constexpr auto normalize() noexcept;

    } // namespace detail

    /**
     * @brief Check whether the given type is a specialization of `posu::ratio` or not.
     *
     * @tparam T The type to check as a specialization of `posu::ratio`.
     */
    using detail::ratio_type;

    /**
     * @brief Adjust the ratio's representation to maximally reduce its mantissa fraction.
     *
     * @tparam Ratio The ratio to normalize.
     */
    template<ratio_type Ratio>
    using normalize = decltype(detail::normalize<Ratio>());

    /**
     * @brief Denormalize a ratio so its exponent is the given value.
     *
     * @tparam Ratio  The ratio to denormalize.
     * @tparam NewExp The exponent to assign to the resulting ratio.
     */
    template<ratio_type Ratio, std::intmax_t NewExp>
    using denormalize = decltype(detail::denormalize<Ratio, NewExp>());

    /**
     * @brief Add two ratios;
     *
     * @tparam Lhs The left-hand-side ratio.
     * @tparam Rhs The right-hand-side ratio.
     */
    template<ratio_type Lhs, ratio_type Rhs>
    using ratio_add = decltype(Lhs{} + Rhs{});

    /**
     * @brief Multiply two ratio objects.
     *
     * @tparam Lhs The left-hand-side ratio.
     * @tparam Rhs The right-hand-side ratio.
     */
    template<ratio_type Lhs, ratio_type Rhs>
    using ratio_multiply = decltype(Lhs{} * Rhs{});

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
     *
     * @{
     */

    template<ratio_type Lhs, ratio_type Rhs>
    struct common_ratio_result {
        using lhs = normalize<Lhs>;
        using rhs = normalize<Rhs>;

        using type = ratio<std::gcd(lhs::num, rhs::num), std::lcm(lhs::den, rhs::den)>;
    };

    template<ratio_type Lhs, ratio_type Rhs>
    using common_ratio = typename common_ratio_result<Lhs, Rhs>::type;

    //! @}

} // namespace posu

template<posu::ratio_type Lhs, posu::ratio_type Rhs>
struct std::common_type<Lhs, Rhs> {
    using type = posu::common_ratio<Lhs, Rhs>;
};

#include "posu/ipp/ratio.ipp"

#endif // #ifndef POSU_RATIO_HPP
