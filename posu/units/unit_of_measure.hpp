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
    concept multiplier = detail::std_ratio<T> || signed_arithmetic_constant<T>;

    template<typename T>
    concept unit = meta_constant<T, std::string_view> && kind<kind_t<T>> &&
        multiplier<period_t<T>> && enable_as_unit<T>;

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

    template<detail::std_ratio Ratio>
    inline constexpr bool enable_as_unit<scaler<Ratio>> = true;

    template<kind Kind>
    struct unknown<Kind> {
        using type       = unknown;
        using value_type = std::string_view;
        using kind_type  = Kind;
        using dimensions = dimension_t<kind_type>;
        using period     = std::ratio<1>;

        static constexpr auto value = std::string_view{"unknown"};

        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
    };

    template<kind Kind>
    inline constexpr bool enable_as_unit<unknown<Kind>> = true;

    template<unit Lhs, unit Rhs>
    struct unit_multiply_result {
        using type = unknown<kind_multiply<kind_t<Lhs>, kind_t<Rhs>>>;
    };

    template<unit Num, unit Den>
    struct unit_divide_result {
        using type = unknown<kind_divide<kind_t<Num>, kind_t<Den>>>;
    };

    template<unit Lhs, unit Rhs>
    using unit_multiply = typename unit_multiply_result<Lhs, Rhs>::type;
    template<unit Lhs, unit Rhs>
    using unit_divide = typename unit_divide_result<Lhs, Rhs>::type;

} // namespace posu::units

#endif // #ifndef POSU_UNITS_UNIT_OF_MEASURE_HPP
