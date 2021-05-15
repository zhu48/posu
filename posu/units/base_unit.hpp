#ifndef POSU_UNITS_BASE_UNIT_HPP
#define POSU_UNITS_BASE_UNIT_HPP

#include <chrono>
#include <string_view>

#include "posu/type_ratio.hpp"
#include "posu/units/kind.hpp"

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
     * @brief A unit-of-measure derived from base units.
     *
     * @tparam T The type to check against this concept.
     *
     * @{
     */
    template<typename T>
    concept derived_kind = kind<T> && derived_dimension<dimension_t<T>>;
    template<typename T>
    struct is_derived_kind : public std::bool_constant<derived_kind<T>> {
    };
    //! @}

    /**
     * @brief A base unit-of-measure.
     *
     * @tparam T The type to check against this concept.
     *
     * @{
     */
    template<typename T>
    concept base_kind = kind<T> && base_dimension<dimension_t<T>>;
    template<typename T>
    struct is_base_kind : public std::bool_constant<base_kind<T>> {
    };
    //! @}

    namespace detail {

        template<typename Lhs, typename Rhs>
        concept kind_compatible_with =
            std::same_as<Lhs, Rhs> || unknown_kind<Lhs> || unknown_kind<Rhs>;

    }

    template<typename Lhs, typename Rhs>
    concept kind_comparable_with = kind<Lhs> && kind<Rhs> &&
        std::same_as<dimension_t<Lhs>, dimension_t<Rhs>> && detail::kind_compatible_with<Lhs, Rhs>;

    /**
     * @brief A quanity with a unit-of-measure represented by a tag type.
     *
     * @tparam Rep    The numeric representation type.
     * @tparam Period The ratio with respect to the unit quantity type.
     * @tparam Kind   The quantity's measurement kind.
     */
    template<arithmetic Rep, detail::std_ratio Period, kind Kind>
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
     * @brief A quantity's quantity kind type.
     *
     * @tparam T The quantity type.
     */
    template<quantity_of_measure T>
    using kind_t = typename T::kind_type;

    /**
     * @brief A quantity of the given kind.
     *
     * @tparam T    The quantity type.
     * @tparam Kind The quantity kind to check against.
     */
    template<typename T, typename Kind>
    concept quantity_of = quantity_of_measure<T> && std::same_as<kind_t<T>, Kind>;

    namespace detail
    {
        [[nodiscard]] constexpr auto to_duration(const quantity_of_measure auto& quant) noexcept;

    } // namespace detail

    template<arithmetic Rep, detail::std_ratio Period, kind Kind>
    class quantity {
    public:
        using rep        = Rep;                    //!< The numeric representation type.
        using period     = Period;                 //!< The ratio with respect to the unit quantity.
        using kind_type  = Kind;                   //!< The quantity kind.
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
        template<typename Rep2, typename Period2>
            requires(
                std::chrono::treat_as_floating_point_v<Rep> ||
                ((std::ratio_divide<Period2, Period>::den == 1) &&
                 !std::chrono::treat_as_floating_point_v<Rep2>))
        constexpr quantity(const quantity<Rep2, Period2, kind_type>& d);

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
         *
         * @param rhs The quantity to compare against.
         *
         * @return Returns the comparison result.
         *
         * @{
         */
        template<typename RRep, typename RPeriod, typename RKind>
            requires(std::same_as<kind_type, RKind> || unknown_kind<RKind>)
        [[nodiscard]] constexpr bool
        operator==(const quantity<RRep, RPeriod, RKind>& rhs) const noexcept;
        template<typename RRep, typename RPeriod, typename RKind>
            requires(std::same_as<kind_type, RKind> || unknown_kind<RKind>)
        [[nodiscard]] constexpr auto
        operator<=>(const quantity<RRep, RPeriod, RKind>& rhs) const noexcept;
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

    private:
        using underlying_type = std::chrono::duration<Rep, Period>;

        friend constexpr auto detail::to_duration(const quantity_of_measure auto& quant) noexcept;

        friend constexpr bool operator==(const quantity& lhs, const Rep& rhs) noexcept requires
            quantity_of<quantity, scaler>
        {
            return lhs.m_duration.count() == rhs;
        }

        friend constexpr bool operator==(const Rep& rhs, const quantity& lhs) noexcept requires
            quantity_of<quantity, scaler>
        {
            return lhs == rhs.m_duration.count();
        }

        friend constexpr bool operator<=>(const quantity& lhs, const Rep& rhs) noexcept requires
            quantity_of<quantity, scaler>
        {
            return lhs.m_duration.count() <=> rhs;
        }

        friend constexpr bool operator<=>(const Rep& rhs, const quantity& lhs) noexcept requires
            quantity_of<quantity, scaler>
        {
            return lhs <=> rhs.m_duration.count();
        }

        underlying_type m_duration;
    };

    /**
     * @name Arithmetic Operators
     *
     * @brief Arithmetic operations on base-unit quantities.
     *
     * @tparam Lhs    The type of the left-hand-side operand.
     * @tparam Rep    The quantity type's numeric representation type.
     * @tparam Period The quantity type's to-unit-quantity ratio.
     * @tparam Units  The quantity type's units-of-measure tag type.
     *
     * @param lhs The left-hand-side operand.
     * @param rhs The right-hand-side operand.
     *
     * @return Returns the arithmeitc operation result.
     *
     * @{
     */
    template<quantity_of_measure Lhs>
    [[nodiscard]] constexpr auto
    operator+(const Lhs& lhs, const quantity_of<kind_t<Lhs>> auto& rhs) noexcept;
    template<quantity_of_measure Lhs>
    [[nodiscard]] constexpr auto
    operator-(const Lhs& lhs, const quantity_of<kind_t<Lhs>> auto& rhs) noexcept;
    [[nodiscard]] constexpr auto
    operator*(const arithmetic auto& lhs, const quantity_of_measure auto& rhs) noexcept;
    [[nodiscard]] constexpr auto
    operator*(const quantity_of_measure auto& lhs, const arithmetic auto& rhs) noexcept;
    template<quantity_of_measure Lhs>
    [[nodiscard]] constexpr auto
    operator/(const Lhs& lhs, const quantity_of<kind_t<Lhs>> auto& rhs) noexcept;
    [[nodiscard]] constexpr auto
    operator/(const quantity_of_measure auto& lhs, const arithmetic auto& rhs) noexcept;
    template<quantity_of_measure Lhs>
    [[nodiscard]] constexpr auto
    operator%(const Lhs& lhs, const quantity_of<kind_t<Lhs>> auto& rhs) noexcept;
    [[nodiscard]] constexpr auto
    operator%(const quantity_of_measure auto& lhs, const arithmetic auto& rhs) noexcept;
    //! @}

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
template<typename LRep, typename LPeriod, typename RRep, typename RPeriod, typename Kind>
struct std::common_type<
    posu::units::quantity<LRep, LPeriod, Kind>,
    posu::units::quantity<RRep, RPeriod, Kind>> {
    //! The common quantity type.
    using type = posu::units::quantity<
        std::common_type_t<LRep, RRep>,
        typename std::common_type_t<
            std::chrono::duration<LRep, LPeriod>,
            std::chrono::duration<RRep, RPeriod>>::period,
        Kind>;
};

#include "posu/units/ipp/base_unit.ipp"

#endif // #ifndef POSU_UNITS_BASE_UNIT_HPP
