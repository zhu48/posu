#ifndef POSU_UNITS_UNIT_OF_MEASURE_HPP
#define POSU_UNITS_UNIT_OF_MEASURE_HPP

#include "posu/units/kind.hpp"

namespace posu::units {

    template<typename T>
    inline constexpr bool enable_as_unit = false;

    /**
     * @brief A quantity's numeric representation type.
     *
     * @tparam T The quantity type.
     */
    template<typename T>
    using rep_t = typename T::rep;

    /**
     * @brief A quantity's to-base-amount ratio.
     *
     * @tparam T The quantity type.
     */
    template<typename T>
    using period_t = typename T::period;

    template<typename T>
    using kind_t = typename T::kind_type;

    template<typename T>
    concept unit = meta_constant<T, std::string_view> && kind<kind_t<T>> &&
        ratio_type<period_t<T>> && enable_as_unit<T>;

    /**
     * @brief A unit-of-measure derived from base units.
     *
     * @tparam T The type to check against this concept.
     *
     * @{
     */
    template<typename T>
    concept derived_unit = unit<T> && derived_kind<kind_t<T>>;
    template<typename T>
    struct is_derived_unit : public std::bool_constant<derived_kind<T>> {
    };
    //! @}

    /**
     * @brief A quantity of the given kind.
     *
     * @tparam T    The quantity type.
     * @tparam Kind The quantity kind to check against.
     */
    template<typename T, typename Kind>
    concept unit_of = unit<T> && std::same_as<kind_t<T>, Kind>;

    /**
     * @brief A base unit-of-measure.
     *
     * @tparam T The type to check against this concept.
     *
     * @{
     */
    template<typename T>
    concept base_unit = unit<T> && base_kind<kind_t<T>>;
    template<typename T>
    struct is_base_unit : public std::bool_constant<base_kind<T>> {
    };
    //! @}

    template<typename Lhs, typename Rhs>
    concept unit_comparable_with =
        unit<Lhs> && unit<Rhs> && kind_comparable_with<kind_t<Lhs>, kind_t<Rhs>>;

    /**
     * @brief Create a base tag type defining a unit of measure wit the given name, kind, and ratio.
     *
     * This CRTP base class template provides a convenience mechanism for creating unit of measure
     * tag types with all of the required members.
     *
     * @tparam T     The created  unit of measure tag type.
     * @tparam Name  The name of the new unit of measure.
     * @tparam Kind  The measurement kind of the new unit of measure.
     * @tparam Ratio The to-base-units ratio of the new unit of measure.
     */
    template<typename T, basic_string_literal Name, kind Kind, ratio_type Ratio = ratio<1>>
    struct make_unit : public detail::make_string_constant<T, Name> {
        using kind_type = Kind;  //!< The measurement kind of the new unit of measure.
        using period    = Ratio; //!< The to0base-units ratio of the new unit of measure.
    };

    /**
     * @brief Tag type for unitless quantities.
     *
     * @tparam Ratio The to-base-units scaler ratio.
     */
    template<ratio_type Ratio = ratio<1>>
    struct unitless : public make_unit<unitless<Ratio>, "unitless", scaler, Ratio> {
    };

    /**
     * @brief Designate `unitless` as a unit of measure tag type.
     *
     * @tparam Ratio The to-base-units scaler ratio.
     */
    template<ratio_type Ratio>
    inline constexpr bool enable_as_unit<unitless<Ratio>> = true;

    /**
     * @brief Tag type for quantities with unknown units of measure.
     *
     * @tparam Kind   The measurement kind associated with the quantity.
     * @tparam Period The to-base-units ratio associated with the quantity.
     */
    template<kind Kind, ratio_type Period = ratio<1>>
    struct unknown_unit : public make_unit<unknown_unit<Kind, Period>, "unknown", Kind, Period> {
    };

    /**
     * @brief Designate `unknown_unit` as a unit of measure tag type.
     *
     * @tparam Kind   The measurement kind associated with the quantity.
     * @tparam Period The to-base-units ratio associated with the quantity.
     */
    template<kind Kind, ratio_type Period>
    inline constexpr bool enable_as_unit<unknown_unit<Kind, Period>> = true;

    /**
     * @brief Multiply two units of measure together.
     *
     * @tparam Lhs The left-hand-side unit tag type.
     * @tparam Rhs The right-hand-side unit tag type.
     */
    template<unit Lhs, unit Rhs>
    using unit_multiply = unknown_unit<
        kind_multiply<kind_t<Lhs>, kind_t<Rhs>>,
        ratio_multiply<period_t<Lhs>, period_t<Rhs>>>;

    /**
     * @brief Divide one unit of measure into another.
     *
     * @tparam Lhs The left-hand-side unit tag type.
     * @tparam Rhs The right-hand-side unit tag type.
     */
    template<unit Num, unit Den>
    using unit_divide = unknown_unit<
        kind_divide<kind_t<Num>, kind_t<Den>>,
        ratio_divide<period_t<Num>, period_t<Den>>>;

    template<unit Lhs, unit Rhs>
    struct common_unit_result {
        using type = unknown_unit<
            common_kind<kind_t<Lhs>, kind_t<Rhs>>,
            common_ratio<period_t<Lhs>, period_t<Rhs>>>;
    };

    template<unit Lhs, unit Rhs>
    using common_unit = typename common_unit_result<Lhs, Rhs>::type;

} // namespace posu::units

#endif // #ifndef POSU_UNITS_UNIT_OF_MEASURE_HPP
