#ifndef POSU_UNITS_BASE_UNIT_HPP
#define POSU_UNITS_BASE_UNIT_HPP

#include <chrono>
#include <string_view>

#include "posu/type_ratio.hpp"

#include "posu/units/unit_of_measure.hpp"

namespace posu::units {

    namespace detail {

        template<typename T>
        struct is_std_ratio : std::false_type {
        };

        template<typename T>
        inline constexpr bool is_std_ratio_v = is_std_ratio<T>::value;

        template<typename T>
        concept std_ratio = is_std_ratio_v<T>;

    } // namespace detail

    /**
     * @brief A quanity with a unit-of-measure represented by a tag type.
     *
     * @tparam Rep    The numeric representation type.
     * @tparam Period The ratio with respect to the unit quantity type.
     * @tparam Unit   The quantity's measurement unit.
     */
    template<arithmetic Rep, detail::std_ratio Period, unit Unit>
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

    /**
     * @brief A quantity's numeric representation type.
     *
     * @tparam T The quantity type.
     */
    template<quantity_of_measure T>
    using rep_t = typename T::rep;

    /**
     * @brief A quantity's to-base-amount ratio.
     *
     * @tparam T The quantity type.
     */
    template<quantity_of_measure T>
    using period_t = typename T::period;

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
        [[nodiscard]] constexpr auto to_duration(const quantity_of_measure auto& quant) noexcept;

        template<kind Kind>
        inline constexpr bool implicit_chrono = false;

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

    template<arithmetic Rep, detail::std_ratio Period, unit Unit>
    class quantity {
    public:
        using rep        = Rep;                    //!< The numeric representation type.
        using period     = Period;                 //!< The ratio with respect to the unit quantity.
        using unit_type  = Unit;                   //!< The quantity units of measure.
        using kind_type  = kind_t<unit_type>;      //!< The quantity kind.
        using dimensions = dimension_t<kind_type>; //!< The quantity dimension.

    private:
        using chrono_type = std::chrono::duration<rep, period>;
        using chrono_ref  = chrono_type&;
        using chrono_cref = const chrono_type&;

    public:
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
                ((std::ratio_divide<Period2, Period>::den == 1) &&
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
        constexpr quantity(const std::chrono::duration<rep, period>& d) noexcept
            requires(detail::implicit_chrono<kind_type>);
        [[nodiscard]] constexpr operator chrono_cref() const noexcept
            requires(detail::implicit_chrono<kind_type>);
        [[nodiscard]] constexpr operator chrono_ref() noexcept
            requires(detail::implicit_chrono<kind_type>);
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
            return std::common_type_t<quantity, std::remove_cvref_t<decltype(rhs)>>(
                (lhs.m_duration + detail::to_duration(rhs)).count());
        }

        [[nodiscard]] friend constexpr auto
        operator-(const quantity& lhs, const quantity_of<unit_type> auto& rhs) noexcept
        {
            return std::common_type_t<quantity, std::remove_cvref_t<decltype(rhs)>>(
                (lhs.m_duration - detail::to_duration(rhs)).count());
        }

        [[nodiscard]] friend constexpr auto
        operator*(const arithmetic auto& lhs, const quantity& rhs) noexcept
        {
            using lhs_type = std::remove_cvref_t<decltype(lhs)>;

            return quantity<std::common_type_t<lhs_type, rep>, period, unit_type>(
                (lhs * detail::to_duration(rhs)).count());
        }

        [[nodiscard]] friend constexpr auto
        operator*(const quantity& lhs, const arithmetic auto& rhs) noexcept
        {
            return rhs * lhs;
        }

        [[nodiscard]] friend constexpr auto
        operator/(const quantity& lhs, const quantity_of<unit_type> auto& rhs) noexcept
        {
            using rep = decltype(lhs.m_duration / detail::to_duration(rhs));

            return quantity<rep, std::ratio<1>, scaler>(lhs.m_duration / detail::to_duration(rhs));
        }

        [[nodiscard]] friend constexpr auto
        operator/(const quantity& lhs, const arithmetic auto& rhs) noexcept
        {
            using rhs_type = std::remove_cvref_t<decltype(rhs)>;

            return quantity<std::common_type_t<rep, rhs_type>, period, unit_type>(
                lhs.count() / rhs);
        }

        [[nodiscard]] friend constexpr auto
        operator%(const quantity& lhs, const quantity_of<unit_type> auto& rhs) noexcept
        {
            return std::common_type_t<quantity, std::remove_cvref_t<decltype(rhs)>>(
                (lhs.m_duration % detail::to_duration(rhs)).count());
        }

        [[nodiscard]] friend constexpr auto
        operator%(const quantity& lhs, const arithmetic auto& rhs) noexcept
        {
            using rhs_type = std::remove_cvref_t<decltype(rhs)>;

            return quantity<std::common_type_t<rep, rhs_type>, period, unit_type>(
                lhs.count() % rhs);
        }

        //! @}

        [[nodiscard]] friend constexpr bool operator==(const quantity& lhs, const Rep& rhs) noexcept
            requires quantity_of<quantity, scaler>
        {
            return quantity_cast<quantity<Rep, std::ratio<1>, unit_type>>(lhs).count() == rhs;
        }

        [[nodiscard]] friend constexpr auto operator<=>(
            const quantity& lhs,
            const Rep&      rhs) noexcept requires quantity_of<quantity, scaler>
        {
            return lhs.m_duration.count() <=> rhs;
        }

        template<typename Rep2, typename Period2>
        [[nodiscard]] friend constexpr bool
        operator==(const quantity& lhs, const std::chrono::duration<Rep2, Period2>& rhs) noexcept
            requires(detail::implicit_chrono<kind_type>)
        {
            return lhs.m_duration == rhs;
        }

        template<typename Rep2, typename Period2>
        [[nodiscard]] friend constexpr auto
        operator<=>(const quantity& lhs, const std::chrono::duration<Rep2, Period2>& rhs) noexcept
            requires(detail::implicit_chrono<kind_type>)
        {
            return lhs.m_duration <=> rhs;
        }

    private : using underlying_type = std::chrono::duration<Rep, Period>;
        underlying_type m_duration;
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
 * @tparam RRep    The numeric representation type of the right-hand-side quantity type.
 * @tparam RPeriod The to-unit-quantity ratio of the right-hand-side quantity type.
 * @tparam Kind   The units-of-measure tag type.
 */
template<typename LRep, typename LPeriod, typename RRep, typename RPeriod, typename Unit>
struct std::common_type<
    posu::units::quantity<LRep, LPeriod, Unit>,
    posu::units::quantity<RRep, RPeriod, Unit>> {
    //! The common quantity type.
    using type = posu::units::quantity<
        std::common_type_t<LRep, RRep>,
        typename std::common_type_t<
            std::chrono::duration<LRep, LPeriod>,
            std::chrono::duration<RRep, RPeriod>>::period,
        Unit>;
};

#include "posu/units/ipp/base_unit.ipp"

#endif // #ifndef POSU_UNITS_BASE_UNIT_HPP
