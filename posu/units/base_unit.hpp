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
    template<arithmetic Rep, ratio_type Period, unit Unit>
    struct is_quantity<quantity<Rep, Period, Unit>> : public std::true_type {
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

    /**
     * @brief A quantity of the given category.
     *
     * @tparam T        The quantity type.
     * @tparam Kind     The quanitty measurement kind to check against.
     * @tparam Unit     The quantity unit-of-measure to check against.
     * @tparam Category The quantity unit or kind to check against.
     */
    template<typename T, typename Kind>
    concept quantity_of_kind = quantity_of_measure<T> && std::same_as<kind_t<T>, Kind>;
    template<typename T, typename Unit>
    concept quantity_of_units = quantity_of_measure<T> && std::same_as<unit_t<T>, Unit>;
    template<typename T, typename Category>
    concept quantity_of = quantity_of_kind<T, Category> || quantity_of_units<T, Category>;
    //! @}

    /**
     * @brief A quantity category type.
     *
     * A quantity categorizes into kinds of measurement, and also units-of-measure.
     *
     * @tparam T The type to check against this concept.
     */
    template<typename T>
    concept quantity_category = kind<T> || unit<T>;

    namespace detail
    {

        template<typename T>
        concept quantity_comparable_specification = quantity_of_measure<T> || quantity_category<T>;

    }

    /**
     * @brief A quantity comparable against the given quantity or quantity category.
     *
     * A quantity may be compared against quantities of categories with the same dimensions.
     *
     * @tparam T The quantity type to check comparability against.
     * @tparam U The quantity or quantity categor to check comparability against.
     */
    template<typename T, typename U>
    concept quantity_comparable_with =
        quantity_of_measure<T> && detail::quantity_comparable_specification<U> &&
        std::same_as<dimension_t<T>, dimension_t<U>>;

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
         * @name Relational Operators
         *
         * @brief Compare two quantities of the same kind.
         *
         * @param lhs The left-hand-side quantity operand to compare.
         * @param rhs The right-hand-side quantity operand to compare.
         *
         * @return Returns the comparison result.
         *
         * @{
         */
        [[nodiscard]] friend constexpr bool
        operator==(const quantity& lhs, quantity_of<kind_type> auto const& rhs) noexcept
        {
            return lhs.compare_equal(rhs);
        }
        [[nodiscard]] friend constexpr auto
        operator<=>(const quantity& lhs, quantity_of<kind_type> auto const& rhs) noexcept
        {
            return lhs.compare_three_way(rhs);
        }
        //! @}

        /**
         * @name Duration Relational Operators
         *
         * @brief Compare a duration quantity to an `std::chrono` duration.
         *
         * @tparam Duration The duration type to compare against.
         *
         * @param lhs The `posu::units` duration to compare.
         * @param rhs The `std::chrono` duration to compare.
         *
         * @return Returns the comparison result.
         *
         * @{
         */
        template<detail::std_chrono_duration Duration>
        [[nodiscard]] friend constexpr bool
        operator==(const quantity& lhs, const Duration& rhs) noexcept
            requires(detail::implicit_chrono<kind_type>)
        {
            return lhs == detail::equivalent_quantity<Duration, kind_type>{rhs.count()};
        }
        template<detail::std_chrono_duration Duration>
        [[nodiscard]] friend constexpr auto
        operator<=>(const quantity& lhs, const Duration& rhs) noexcept
            requires(detail::implicit_chrono<kind_type>)
        {
            return lhs <=> detail::equivalent_quantity<Duration, kind_type>{rhs.count()};
        }
        //! @}

        /**
         * @name Scaler Relational Operators
         *
         * @brief Compare a scaler quantity to a number of its representation type.
         *
         * @param lhs The scaler quantity to compare.
         * @param rhs The number to compare.
         *
         * @return Returns the comparison result.
         *
         * @{
         */
        [[nodiscard]] friend constexpr bool
        operator==(const quantity& lhs, const Rep& rhs) noexcept requires scaler_kind<kind_type>
        {
            return lhs == quantity<Rep, ratio<1>, scaler<>>{rhs};
        }
        [[nodiscard]] friend constexpr auto
        operator<=>(const quantity& lhs, const Rep& rhs) noexcept requires scaler_kind<kind_type>
        {
            return lhs <=> quantity<Rep, ratio<1>, scaler<>>{rhs};
        }
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
        operator+(const quantity& lhs, const quantity_of<kind_type> auto& rhs) noexcept
        {
            return lhs.add(rhs);
        }
        [[nodiscard]] friend constexpr auto
        operator-(const quantity& lhs, const quantity_of<kind_type> auto& rhs) noexcept
        {
            return lhs.subtract(rhs);
        }
        [[nodiscard]] friend constexpr auto
        operator*(const arithmetic auto& lhs, const quantity& rhs) noexcept
        {
            return rhs.multiply(lhs);
        }
        [[nodiscard]] friend constexpr auto
        operator*(const quantity& lhs, const arithmetic auto& rhs) noexcept
        {
            return rhs * lhs;
        }
        [[nodiscard]] friend constexpr auto
        operator/(const quantity& lhs, const quantity_of<kind_type> auto& rhs) noexcept
        {
            return lhs.divide(rhs);
        }
        [[nodiscard]] friend constexpr auto
        operator/(const quantity& lhs, const arithmetic auto& rhs) noexcept
        {
            return lhs.divide(rhs);
        }
        [[nodiscard]] friend constexpr auto
        operator%(const quantity& lhs, const quantity_of<unit_type> auto& rhs) noexcept
        {
            return lhs.modulo(rhs);
        }
        [[nodiscard]] friend constexpr auto
        operator%(const quantity& lhs, const arithmetic auto& rhs) noexcept
        {
            return lhs.modulo(rhs);
        }
        //! @}

    private:
        [[nodiscard]] constexpr bool
        compare_equal(quantity_of<kind_type> auto const& rhs) const noexcept;
        [[nodiscard]] constexpr auto
        compare_three_way(quantity_of<kind_type> auto const& rhs) const noexcept;
        [[nodiscard]] constexpr auto add(const quantity_of<kind_type> auto& rhs) const noexcept;
        [[nodiscard]] constexpr auto
        subtract(const quantity_of<kind_type> auto& rhs) const noexcept;
        [[nodiscard]] constexpr auto multiply(const arithmetic auto& rhs) const noexcept;
        template<typename Quantity>
        [[nodiscard]] constexpr auto divide(const Quantity& rhs) const noexcept
            requires(quantity_of<Quantity, kind_type>);
        [[nodiscard]] constexpr auto divide(const arithmetic auto& rhs) const noexcept;
        template<typename Quantity>
        [[nodiscard]] constexpr auto modulo(const Quantity& rhs) const noexcept
            requires(quantity_of<Quantity, kind_type>);
        [[nodiscard]] constexpr auto modulo(const arithmetic auto& rhs) const noexcept;

        rep m_count;
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
