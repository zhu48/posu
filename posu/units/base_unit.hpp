#ifndef POSU_UNITS_BASE_UNIT_HPP
#define POSU_UNITS_BASE_UNIT_HPP

#include <chrono>
#include <string_view>
#include <utility>

#include "posu/meta/ratio.hpp"
#include "posu/units/unit_of_measure.hpp"

namespace posu::units {

    /**
     * @brief A quanity with a unit-of-measure represented by a tag type.
     *
     * @tparam Rep    The numeric representation type.
     * @tparam Period The ratio with respect to the unit quantity type.
     * @tparam Unit   The quantity's measurement unit.
     */
    template<arithmetic Rep, ratio_type Period, unit Unit>
    class quantity;

    /**
     * @brief Concept for a quantity type.
     *
     * @tparam T The type to check againt the concept.
     *
     * @{
     */

    template<typename T>
    struct is_quantity : public std::false_type {
    };

    template<typename T>
    inline constexpr bool is_quantity_v = is_quantity<T>::value;

    template<typename T>
    concept quantity_of_measure = is_quantity_v<T>;

    //! @}

    /**
     * @brief A quantity's units of measure type.
     *
     * @tparam T The quantity type.
     */
    template<quantity_of_measure T>
    using unit_t = typename T::unit_type;

    template<typename T, typename Kind>
    concept quantity_of_kind = quantity_of_measure<T> && std::same_as<kind_t<T>, Kind>;

    template<typename T, typename Unit>
    concept quantity_of_units = quantity_of_measure<T> && std::same_as<unit_t<T>, Unit>;

    /**
     * @brief A quantity of the given category.
     *
     * @tparam T        The quantity type.
     * @tparam Category The quantity unit or kind to check against.
     */
    template<typename T, typename Category>
    concept quantity_of = quantity_of_kind<T, Category> || quantity_of_units<T, Category>;

    template<typename T>
    concept quantity_category = kind<T> || unit<T>;

    template<typename T, typename U>
    concept quantity_comparable_with =
        quantity_of_measure<T> && std::same_as<dimension_t<T>, dimension_t<U>>;

    namespace detail
    {
        template<typename T>
        struct is_std_chrono_duration : public std::false_type {
        };
        template<typename Rep, typename Period>
        struct is_std_chrono_duration<std::chrono::duration<Rep, Period>> : public std::true_type {
        };
        template<typename T>
        concept std_chrono_duration = is_std_chrono_duration<T>::value;

        template<kind Kind>
        inline constexpr bool implicit_chrono = false;

        template<quantity_of_measure T>
            requires(implicit_chrono<kind_t<T>>)
        using count_multiplier = ratio_multiply<period_t<T>, period_t<unit_t<T>>>;

        template<quantity_of_measure T>
            requires(implicit_chrono<kind_t<T>>)
        using equivalent_chrono = std::chrono::duration<rep_t<T>, count_multiplier<T>>;

        template<std_chrono_duration T, kind Kind>
        using equivalent_quantity =
            quantity<rep_t<T>, ratio<period_t<T>::num, period_t<T>::den>, unknown<Kind>>;

        template<typename To, typename From>
        concept chrono_convertible_from = quantity_of_measure<To> && std_chrono_duration<From> &&
            implicit_chrono<kind_t<To>> && std::convertible_to<From, equivalent_chrono<To>>;

        template<typename From, typename To>
        concept chrono_convertible_to = quantity_of_measure<From> && std_chrono_duration<To> &&
            implicit_chrono<kind_t<From>> && std::convertible_to<equivalent_chrono<From>, To>;

    } // namespace detail

    /**
     * @brief Explicit, possibly lossy, cast between quantities with the same dimensions.
     *
     * @tparam To   The quantity to convert to.
     * @tparam From The quantity to convert from.
     */
    template<quantity_of_measure To, quantity_of_measure From>
        requires(quantity_comparable_with<To, From>)
    [[nodiscard]] constexpr auto quantity_cast(const From& quant) noexcept -> To;

    template<arithmetic Rep, ratio_type Period, unit Unit>
    class quantity {
    public:
        using rep        = Rep;                    //!< The numeric representation type.
        using period     = Period;                 //!< The ratio with respect to the unit quantity.
        using unit_type  = Unit;                   //!< The quantity units of measure.
        using kind_type  = kind_t<unit_type>;      //!< The quantity kind.
        using dimensions = dimension_t<kind_type>; //!< The quantity dimension.

        /**
         * @brief Defaulted default constructor.
         */
        constexpr quantity() noexcept = default;

        /**
         * @brief Construct a quantity with the given number of ticks.
         *
         * @tparam Rep2 The numeric tick type.
         *
         * @param r The number of ticks to initialize this quantity with.
         */
        template<typename Rep2>
            requires(
                std::convertible_to<Rep, const Rep2&> &&
                (std::chrono::treat_as_floating_point_v<Rep> ||
                 !std::chrono::treat_as_floating_point_v<Rep2>))
        constexpr explicit quantity(const Rep2& r);

        /**
         * @brief Construct a quantity by converting from a different quantity with the same units.
         *
         * @tparam Rep2    The numeric representation type of the other quantity.
         * @tparam Period2 The to-unit-quantity ratio of the other quantity.
         *
         * @param d The quantity to convert from.
         */
        template<typename Rep2, typename Period2, unit_comparable_with<unit_type> Unit2>
            requires(
                std::chrono::treat_as_floating_point_v<Rep> ||
                ((ratio_divide<Period2, Period>::den == 1) &&
                 (ratio_divide<Period2, Period>::exp >= 0) &&
                 !std::chrono::treat_as_floating_point_v<Rep2>))
        explicit(!std::same_as<unit_type, Unit2>) constexpr quantity(
            const quantity<Rep2, Period2, Unit2>& d);

        /**
         * @brief Implicit conversion to and from `std::chrono::duration` for time quantities.
         *
         * @param d The `std::chrono::duration` type to convert from.
         *
         * @return Conversion operators return a reference to the underlying duration type.
         *
         * @{
         */
        template<detail::std_chrono_duration T>
        explicit(!detail::chrono_convertible_to<T, quantity>) constexpr quantity(
            const T& d) noexcept requires(detail::implicit_chrono<kind_type>);
        template<detail::std_chrono_duration T>
        [[nodiscard]] explicit(!detail::chrono_convertible_from<T, quantity>) constexpr
        operator T() const noexcept requires(detail::implicit_chrono<kind_type>);
        //! @}

        /**
         * @brief Obtain the number of ticks this quantity has.
         *
         * @return Returns this quantity's numeric amount.
         */
        [[nodiscard]] constexpr auto count() const noexcept;

        /**
         * @brief Comparison operators.
         *
         * @tparam RRep    The numeric representation type of the quantity to compare against.
         * @tparam RPeriod The to-unit-quantity ratio of the quantity to compare against.
         * @tparam RUnit   The units of the quantity to compare against.
         *
         * @param rhs The quantity to compare against.
         *
         * @return Returns the comparison result.
         *
         * @{
         */
        template<typename RRep, typename RPeriod, unit_of<kind_type> RUnit>
        [[nodiscard]] constexpr bool
        operator==(const quantity<RRep, RPeriod, RUnit>& rhs) const noexcept;
        template<typename RRep, typename RPeriod, unit_of<kind_type> RUnit>
        [[nodiscard]] constexpr auto
        operator<=>(const quantity<RRep, RPeriod, RUnit>& rhs) const noexcept;
        //! @}

        /**
         * @name Unary Arithetic Operators
         *
         * @brief Unary plus and minus, pre- and post-increment and decrement.
         *
         * @return Unary plus and minus return the result by copy.
         * @return Pre-increment and pre-decrement return self-reference.
         * @return Post-increment and post-decrement return the original value by copy.
         *
         * @{
         */
        [[nodiscard]] constexpr auto operator+() const noexcept;
        [[nodiscard]] constexpr auto operator-() const noexcept;
        constexpr auto&              operator++() noexcept;
        constexpr auto               operator++(int) noexcept;
        constexpr auto&              operator--() noexcept;
        constexpr auto               operator--(int) noexcept;
        //! @}

        /**
         * @name Arithmetic Assignment Operators
         *
         * @brief Arithmetic assignment operators.
         *
         * @param rhs The right-hand-side operand.
         *
         * @return Returns self-reference.
         *
         * @{
         */
        constexpr auto& operator+=(const quantity& rhs) noexcept;
        constexpr auto& operator-=(const quantity& rhs) noexcept;
        constexpr auto& operator*=(const rep& rhs) noexcept;
        constexpr auto& operator/=(const rep& rhs) noexcept;
        constexpr auto& operator%=(const rep& rhs) noexcept;
        constexpr auto& operator%=(const quantity& rhs) noexcept;
        //! @}

        /**
         * @name Arithmetic Operators
         *
         * @brief Arithmetic operations on base-unit quantities.
         *
         * @param lhs The left-hand-side operand.
         * @param rhs The right-hand-side operand.
         *
         * @return Returns the arithmeitc operation result.
         *
         * @{
         */

        [[nodiscard]] friend constexpr auto
        operator+(const quantity& lhs, const quantity_of<unit_type> auto& rhs) noexcept
        {
            using common_type = std::common_type_t<quantity, std::remove_cvref_t<decltype(rhs)>>;

            const auto l = quantity_cast<common_type>(lhs);
            const auto r = quantity_cast<common_type>(rhs);

            return common_type{l.count() + r.count()};
        }

        [[nodiscard]] friend constexpr auto
        operator-(const quantity& lhs, const quantity_of<unit_type> auto& rhs) noexcept
        {
            using common_type = std::common_type_t<quantity, std::remove_cvref_t<decltype(rhs)>>;

            const auto l = quantity_cast<common_type>(lhs);
            const auto r = quantity_cast<common_type>(rhs);

            return common_type{l.count() - r.count()};
        }

        [[nodiscard]] friend constexpr auto
        operator*(const arithmetic auto& lhs, const quantity& rhs) noexcept
        {
            using common_rep = decltype(lhs * rhs.count());

            return quantity<common_rep, period, unit_type>(lhs * rhs.count());
        }

        [[nodiscard]] friend constexpr auto
        operator*(const quantity& lhs, const arithmetic auto& rhs) noexcept
        {
            return rhs * lhs;
        }

        template<quantity_of<unit_type> Quantity>
        [[nodiscard]] friend constexpr auto
        operator/(const quantity& lhs, const Quantity& rhs) noexcept
        {
            using div_period = ratio_divide<period, period_t<Quantity>>;
            using div_unit = scaler<ratio_divide<period_t<unit_type>, period_t<unit_t<Quantity>>>>;
            constexpr auto div_scaler = div_period{} * period_t<div_unit>{};
            if constexpr(div_scaler >= ratio<1>{}) {
                using common_type = std::common_type_t<quantity, Quantity>;

                const auto l = quantity_cast<common_type>(lhs);
                const auto r = quantity_cast<common_type>(rhs);

                return quantity<rep_t<common_type>, ratio<1>, scaler<>>(l.count() / r.count());
            }
            else {
                using div_rep  = std::common_type_t<rep, rep_t<Quantity>>;
                using div_type = quantity<div_rep, div_period, div_unit>;

                return div_type{lhs.count() / rhs.count()};
            }
        }

        [[nodiscard]] friend constexpr auto
        operator/(const quantity& lhs, const arithmetic auto& rhs) noexcept
        {
            using common_rep = decltype(lhs.count() / rhs);

            return quantity<common_rep, period, unit_type>(lhs.count() / rhs);
        }

        template<quantity_of<unit_type> Quantity>
        [[nodiscard]] friend constexpr auto
        operator%(const quantity& lhs, const Quantity& rhs) noexcept
        {
            using common_type = std::common_type_t<quantity, Quantity>;

            const auto l = quantity_cast<common_type>(lhs);
            const auto r = quantity_cast<common_type>(rhs);

            return common_type{l.count() % r.count()};
        }

        [[nodiscard]] friend constexpr auto
        operator%(const quantity& lhs, const arithmetic auto& rhs) noexcept
        {
            using common_rep = decltype(lhs.count() % rhs);

            return quantity<common_rep, period, unit_type>{lhs.count() % rhs};
        }

        //! @}

        [[nodiscard]] friend constexpr bool
        operator==(const quantity& lhs, const Rep& rhs) noexcept requires scaler_kind<kind_type>
        {
            return lhs == quantity<Rep, ratio<1>, scaler<>>{rhs};
        }

        [[nodiscard]] friend constexpr auto
        operator<=>(const quantity& lhs, const Rep& rhs) noexcept requires scaler_kind<kind_type>
        {
            return lhs.m_duration.count() <=> rhs;
        }

        template<typename Rep2, typename Period2>
        [[nodiscard]] friend constexpr bool
        operator==(const quantity& lhs, const std::chrono::duration<Rep2, Period2>& rhs) noexcept
            requires(detail::implicit_chrono<kind_type>)
        {
            using rhs_period = ratio<Period2::num, Period2::den>;
            using rhs_unit   = unknown<kind_t<unit_type>>;

            return lhs == quantity<Rep2, rhs_period, rhs_unit>{rhs.count()};
        }

        template<typename Rep2, typename Period2>
        [[nodiscard]] friend constexpr auto
        operator<=>(const quantity& lhs, const std::chrono::duration<Rep2, Period2>& rhs) noexcept
            requires(detail::implicit_chrono<kind_type>)
        {
            using rhs_period = ratio<Period2::num, Period2::den>;
            using rhs_unit   = unknown<kind_t<unit_type>>;

            return lhs <=> quantity<Rep2, rhs_period, rhs_unit>{rhs.count()};
        }

    private : rep m_count;
    };

    /**
     * @brief Lock a quantity into the given category.
     *
     * This function fails to compile if the given quantity has incompatible categories.
     *
     * @tparam Category The category to lock the given quantity into.
     *
     * @param quant The quantity to lock into the given category.
     *
     * @return Returns the given quantity, locked into the given category.
     */
    template<quantity_category Category>
    [[nodiscard]] constexpr auto of(const quantity_comparable_with<Category> auto& quant) noexcept;

} // namespace posu::units

/**
 * @brief Specialization for finding the common type of two base quantities with the same units.
 *
 * @tparam LRep    The numeric representation type of the left-hand-side quantity type.
 * @tparam LPeriod The to-unit-quantity ratio of the left-hand-side quantity type.
 * @tparam LUnit   The units-of-measure tag type of the left-hand-side quantity type.
 * @tparam RRep    The numeric representation type of the right-hand-side quantity type.
 * @tparam RPeriod The to-unit-quantity ratio of the right-hand-side quantity type.
 * @tparam RUnit   The units-of-measure tag type of the right-hand-side quantity type.
 */
template<
    typename LRep,
    typename LPeriod,
    typename RRep,
    typename RPeriod,
    typename LUnit,
    typename RUnit>
    requires(posu::units::unit_comparable_with<LUnit, RUnit>)
struct std::common_type<
    posu::units::quantity<LRep, LPeriod, LUnit>,
    posu::units::quantity<RRep, RPeriod, RUnit>> {
    //! The common quantity type.
    using type = posu::units::quantity<
        std::common_type_t<LRep, RRep>,
        std::common_type_t<LPeriod, RPeriod>,
        posu::units::common_unit<LUnit, RUnit>>;
};

#include "posu/units/ipp/base_unit.ipp"

#endif // #ifndef POSU_UNITS_BASE_UNIT_HPP
