#ifndef POSU_UNITS_BASE_UNIT_HPP
#define POSU_UNITS_BASE_UNIT_HPP

#include <chrono>
#include <string_view>

#include "posu/concepts.hpp"
#include "posu/type_ratio.hpp"

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
     * @brief A tag type denoting a unit of measure.
     *
     * @tparam T The type to check against this concept.
     */
    template<typename T>
    concept units = meta_constant<T, std::string_view>;
    template<typename T>
    struct is_units : public std::bool_constant<units<T>> {
    };
    template<typename T>
    inline constexpr bool is_units_v = units<T>;
    //! @}

    /**
     * @brief A unit-of-measure derived from base units.
     *
     * @tparam T The type to check against this concept.
     *
     * @{
     */
    template<typename T>
    concept derived_units =
        units<T> && std::same_as<T, typename T::type> && meta_ratio<typename T::derivation>;
    template<typename T>
    struct is_derived_units : public std::bool_constant<derived_units<T>> {
    };
    template<typename T>
    inline constexpr bool is_derived_units_v = derived_units<T>;
    //! @}

    /**
     * @brief A base unit-of-measure.
     *
     * @tparam T The type to check against this concept.
     *
     * @{
     */
    template<typename T>
    concept base_units = units<T> && !derived_units<T>;
    template<typename T>
    struct is_base_units : public std::bool_constant<base_units<T>> {
    };
    template<typename T>
    inline constexpr bool is_base_units_v = is_base_units<T>::value;
    //! @}

    /**
     * @brief A quanity with a unit-of-measure represented by a tag type.
     *
     * @tparam Rep    The numeric representation type.
     * @tparam Period The ratio with respect to the unit quantity type.
     * @tparam Tag    The tag type representing this quantity's units.
     */
    template<arithmetic Rep, detail::std_ratio Period, typename Tag>
        requires(units<Tag>)
    class base_unit;

    /**
     * @brief Check whether a type specializes the `base_unit` template or not.
     *
     * @tparam T The type to check.
     *
     * @{
     */
    template<typename T>
    struct is_base_quantity : std::false_type {
    };
    template<typename Rep, typename Ratio, typename Tag>
    struct is_base_quantity<base_unit<Rep, Ratio, Tag>> : std::true_type {
    };
    template<typename T>
    inline constexpr bool is_base_quantity_v = is_base_quantity<T>::value;
    template<typename T>
    concept base_quantity = is_base_quantity_v<T>;
    //! @}

    /**
     * @brief Base unit tag type template.
     *
     * @tparam UnitsString The unit string.
     */
    template<const char* const UnitsString>
    struct base_unit_tag {
        using type       = base_unit_tag<UnitsString>; //!< Self-type.
        using value_type = std::string_view;           //!< The unit string literal type.

        static constexpr auto value = std::string_view{UnitsString}; //!< The unit string literal.

        /**
         * @brief Obtain the wrapped unit string literal.
         *
         * @return Returns the wrapped unit string literal.
         */
        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }

        /**
         * @brief Conversion to wrapped unit string literal.
         *
         * @return Returns the wrapped unit string literal.
         */
        [[nodiscard]] constexpr operator value_type() const noexcept { return value; }
    };

    template<typename T>
    struct derivation_traits;

    template<meta_constant<std::string_view> T>
    struct derivation_traits<T> {
    public:
        using units      = T;
        using derivation = type_ratio<type_list<T>>;

        static constexpr auto units_string = units::value;
    };

    template<meta_constant<std::string_view> T>
    struct derivation_traits<type_ratio<type_list<T>>> {
    public:
        using units      = T;
        using derivation = type_ratio<type_list<T>>;

        static constexpr auto units_string = units::value;
    };

    /**
     * @brief A quantity with a base unit-of-measure.
     *
     * @tparam T The type to check against this concept.
     */
    template<typename T>
    concept quantity = base_quantity<T> && units<typename T::units>;

    /**
     * @brief Check whether a quantity has the given units or not.
     *
     * @tparam T     The quantity type to check.
     * @tparam Units The units tag type to check for.
     *
     * @{
     */
    template<typename T, typename Units>
    concept quantity_of = quantity<T> &&
        (std::same_as<Units, typename T::units> ||
         (quantity<Units> && std::same_as<typename T::units, typename Units::units>));
    template<typename T, typename Units>
    struct is_quantity_of : std::bool_constant<quantity_of<T, Units>> {
    };
    template<typename T, typename Units>
    inline constexpr bool is_quantity_of_v = is_quantity_of<T, Units>::value;
    //! @}

    /**
     * @brief A derived unit tag type equivalent to a base unit tag type.
     *
     * @tparam T The type to compare against this concept.
     *
     * @{
     */
    template<typename T>
    concept base_unit_equivalent =
        derived_units<T> && one_constant<size<typename T::derivation::num>> &&
        empty_v<typename T::derivation::den> && base_units<typename T::derivation::num::front>;
    template<typename T>
    struct is_base_unit_equivalent : public std::bool_constant<base_unit_equivalent<T>> {
    };
    template<typename T>
    inline constexpr bool is_base_unit_equivalent_v = base_unit_equivalent<T>;
    //! @}

    /**
     * @brief Comparison between two unit derivations.
     *
     * @tparam Lhs The left-hand-side derivation type.
     * @tparam Rhs The right-hand-side derivation type.
     *
     * @{
     */
    template<typename Lhs, typename Rhs>
    concept derivation_equal_to =
        meta_ratio<Lhs> && meta_ratio<Rhs> && std::same_as<type_ratio<>, ratio_divide<Lhs, Rhs>>;
    template<meta_ratio Lhs, meta_ratio Rhs>
    struct is_derivation_equal : public std::bool_constant<derivation_equal_to<Lhs, Rhs>> {
    };
    template<meta_ratio Lhs, meta_ratio Rhs>
    inline constexpr bool is_derivation_equal_v = derivation_equal_to<Lhs, Rhs>;
    //! @}

    template<typename Lhs, typename Rhs>
    concept units_equal_to =
        derivation_equal_to<typename Lhs::derivation, typename Rhs::derivation>;
    template<typename Lhs, typename Rhs>
    struct is_units_equal : public std::bool_constant<units_equal_to<Lhs, Rhs>> {
    };
    template<typename Lhs, typename Rhs>
    inline constexpr bool is_units_equal_v = units_equal_to<Lhs, Rhs>;

    namespace detail {

        [[nodiscard]] constexpr auto to_duration(const base_quantity auto& quantity) noexcept;

    }

    template<arithmetic Rep, detail::std_ratio Period, typename Tag>
        requires(units<Tag>)
    class base_unit {
    public:
        using rep    = Rep;    //!< The numeric representation type.
        using period = Period; //!< The ratio with respect to the unit quantity type.
        using units  = Tag;    //!< The tag type representing this quantity's units.

        /**
         * @brief Defaulted default constructor.
         */
        constexpr base_unit() noexcept = default;

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
        constexpr explicit base_unit(const Rep2& r);

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
        constexpr base_unit(const base_unit<Rep2, Period2, Tag>& d);

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
        template<typename RRep, typename RPeriod, base_units RUnits>
            requires(base_units<units>&& meta_equal_to<units, RUnits>)
        [[nodiscard]] constexpr auto
        operator==(const base_unit<RRep, RPeriod, RUnits>& rhs) const noexcept;
        template<typename RRep, typename RPeriod, units_equal_to<units> RUnits>
        [[nodiscard]] constexpr auto
        operator==(const base_unit<RRep, RPeriod, RUnits>& rhs) const noexcept;
        template<typename RRep, typename RPeriod, base_units RUnits>
            requires(base_units<units>&& meta_equal_to<units, RUnits>)
        [[nodiscard]] constexpr auto
        operator<=>(const base_unit<RRep, RPeriod, RUnits>& rhs) const noexcept;
        template<typename RRep, typename RPeriod, units_equal_to<units> RUnits>
        [[nodiscard]] constexpr auto
        operator<=>(const base_unit<RRep, RPeriod, RUnits>& rhs) const noexcept;
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
        constexpr auto& operator+=(const base_unit& rhs) noexcept;
        constexpr auto& operator-=(const base_unit& rhs) noexcept;
        constexpr auto& operator*=(const rep& rhs) noexcept;
        constexpr auto& operator/=(const rep& rhs) noexcept;
        constexpr auto& operator%=(const rep& rhs) noexcept;
        constexpr auto& operator%=(const base_unit& rhs) noexcept;
        //! @}

    private:
        using underlying_type = std::chrono::duration<Rep, Period>;

        friend constexpr auto detail::to_duration(const base_quantity auto& quantity) noexcept;

        underlying_type m_duration;
    };

    /**
     * @name Arithmetic Operators
     *
     * @brief Arithmetic operations on base-unit quantities.
     *
     * @tparam Lhs    The type of the left-hand-side operand.
     * @tparam Rhs    The type of the right-hand-side operand.
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
    template<base_quantity Lhs, quantity_of<Lhs> Rhs>
    [[nodiscard]] auto operator+(const Lhs& lhs, const Rhs& rhs) noexcept;
    template<base_quantity Lhs, quantity_of<Lhs> Rhs>
    [[nodiscard]] auto operator-(const Lhs& lhs, const Rhs& rhs) noexcept;
    template<arithmetic Lhs, typename Rep, typename Period, typename Units>
    [[nodiscard]] auto operator*(const Lhs& lhs, const base_unit<Rep, Period, Units>& rhs) noexcept;
    [[nodiscard]] auto
    operator*(const base_quantity auto& lhs, const arithmetic auto& rhs) noexcept;
    template<base_quantity Lhs>
    [[nodiscard]] auto operator/(const Lhs& lhs, const quantity_of<Lhs> auto& rhs) noexcept;
    template<typename Rep, typename Period, typename Units, arithmetic Rhs>
    [[nodiscard]] auto operator/(const base_unit<Rep, Period, Units>& lhs, const Rhs& rhs) noexcept;
    template<base_quantity Lhs, quantity_of<Lhs> Rhs>
    [[nodiscard]] auto operator%(const Lhs& lhs, const Rhs& rhs) noexcept;
    template<typename Rep, typename Period, typename Units, arithmetic Rhs>
    [[nodiscard]] auto operator%(const base_unit<Rep, Period, Units>& lhs, const Rhs& rhs) noexcept;
    //! @}

} // namespace posu::units

/**
 * @brief Specialization for finding the common type of two base quantities with the same units.
 *
 * @tparam LRep    The numeric representation type of the left-hand-side quantity type.
 * @tparam LPeriod The to-unit-quantity ratio of the left-hand-side quantity type.
 * @tparam RRep    The numeric representation type of the right-hand-side quantity type.
 * @tparam RPeriod The to-unit-quantity ratio of the right-hand-side quantity type.
 * @tparam Units   The units-of-measure tag type.
 */
template<typename LRep, typename LPeriod, typename RRep, typename RPeriod, typename Units>
struct std::common_type<
    posu::units::base_unit<LRep, LPeriod, Units>,
    posu::units::base_unit<RRep, RPeriod, Units>> {
    //! The common quantity type.
    using type = posu::units::base_unit<
        std::common_type_t<LRep, RRep>,
        typename std::common_type_t<
            std::chrono::duration<LRep, LPeriod>,
            std::chrono::duration<RRep, RPeriod>>::period,
        Units>;
};

#include "posu/units/ipp/base_unit.ipp"

#endif // #ifndef POSU_UNITS_BASE_UNIT_HPP
