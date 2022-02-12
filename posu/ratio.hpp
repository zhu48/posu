#ifndef POSU_RATIO_HPP
#define POSU_RATIO_HPP

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
         * @brief Ratio multiplication and division.
         *
         * @param lhs The left-hand-side argument.
         * @param rhs The right-hand-side argument.
         *
         * @return Returns the operation result.
         *
         * @{
         */

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

    } // namespace detail

    /**
     * @brief Check whether the given type is a specialization of `posu::ratio` or not.
     *
     * @tparam T The type to check as a specialization of `posu::ratio`.
     */
    template<typename T>
    concept ratio_type = detail::is_ratio<T>::value;

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
        requires(detail::std_ratio<Ratio>::value)
    using make_ratio = ratio<Ratio::num, Ratio::den>;

    /**
     * @brief Minimize the exponent portion of the given ratio.
     *
     * @tparam Ratio The ratio to normalize.
     *
     * @{
     */

    template<ratio_type Ratio>
    struct normalize_result {
        using type = Ratio; //!< The normalized ratio type.
    };

    template<ratio_type Ratio>
    using normalize = typename normalize_result<ratio_multiply<Ratio, ratio<1>>>::type;

    template<ratio_type Ratio>
        requires((Ratio::exp > 0) && (Ratio::den >= 10) && ((Ratio::den % 10) == 0))
    struct normalize_result<Ratio> {
        using type = normalize<ratio<Ratio::num, (Ratio::den / 10), (Ratio::exp - 1)>>;
    };

    template<ratio_type Ratio>
        requires((Ratio::exp < 0) && (Ratio::num >= 10) && ((Ratio::num % 10) == 0))
    struct normalize_result<Ratio> {
        using type = normalize<ratio<(Ratio::num / 10), Ratio::den, (Ratio::exp + 1)>>;
    };

    //! @}

} // namespace posu

#endif // #ifndef POSU_RATIO_HPP
