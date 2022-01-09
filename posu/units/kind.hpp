/**
 * @file posu/units/kind.hpp
 *
 * @brief Header defining a measurement `kind` concept.
 *
 * The Units library uses `kind` types to represent semantically specific measurements of some
 * dimension. This header defines the `kind` concept, some ancillary types, and basic `kind`
 * dimensional analysis operations.
 *
 * Each `kind` represents
 * measurements of a particular dimension, but arbitrary different measurement kinds may associate
 * with the same dimension.
 */

#ifndef POSU_UNITS_KIND_HPP
#define POSU_UNITS_KIND_HPP

#include "posu/units/dimension.hpp"

namespace posu::units {

    /**
     * @brief Customization point for designating custom types as `kind` types.
     *
     * @tparam T The type to designate as a `kind` type.
     */
    template<typename T>
    inline constexpr bool enable_as_kind = false;

    /**
     * @brief Meta-function to extract a type's dimension.
     *
     * @tparam T The type to extract the dimension of.
     *
     * @return Returns the given type's measurement dimension.
     */
    template<typename T>
    using dimension_t = typename T::dimensions;

    /**
     * @brief A measurement kind type.
     *
     * A `kind` type is a `std::string_view` meta-constant designated as a `kind` type via
     * specializing the `enable_as_kind` template. The syntactic requirements give a kind a name
     * string, a unique type in the type system, and an associated dimension. Semantically, each
     * `kind` is a tag type for semantically-distinct measurements of a particular dimension.
     * Arbitrary different measurement kinds may associate with the same dimension.
     *
     * @tparam T The type to check against this concept.
     */
    template<typename T>
    concept kind =
        meta_constant<T, std::string_view> && dimension<dimension_t<T>> && enable_as_kind<T>;

    /**
     * @brief A measurement kind measuring a derived dimension.
     *
     * @tparam T The type to check against this concept.
     */
    template<typename T>
    concept derived_kind = kind<T> && derived_dimension<dimension_t<T>>;

    /**
     * @brief A measurement kind measuring a base dimension.
     *
     * @tparam T The type to check against this concept.
     */
    template<typename T>
    concept base_kind = kind<T> && base_dimension<dimension_t<T>>;

    /**
     * @brief A scaler measurement kind, or dimensionless unit of measurement.
     *
     * @tparam Period A multiplier to apply to the scaler when used as a unit of measurement.
     */
    template<detail::std_ratio Period = std::ratio<1>>
    struct scaler {
        using type       = scaler;           //!< Self type.
        using value_type = std::string_view; //!< Meta-constant value type.
        using dimensions = dimensionless;    //!< Mark this type as dimensionless.
        using kind_type  = scaler; //!< Mark this type as its own `kind` when used as a `unit`.
        using period     = Period; //!< The dimensional multiplier for a dimensionless unit.

        static constexpr auto value = std::string_view{"scaler"}; //!< The kind or unit name.

        /**
         * @name Value Access
         *
         * @brief Obtain this kind or unit's name.
         *
         * @return Returns this kind or unit's name.
         *
         * @{
         */
        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
        //! @}
    };

    /**
     * @brief Tag specialization designating `scaler` as a kind of measurement.
     */
    template<detail::std_ratio Period>
    inline constexpr bool enable_as_kind<scaler<Period>> = true;

    /**
     * @brief An unknown measurement kind or unit of unknown kind.
     *
     * @tparam T      The known unit kind, or kind dimension.
     * @tparam Period A multiplier to apply when used as a unit of measurement.
     */
    template<typename T, detail::std_ratio Period = std::ratio<1>>
        requires(dimension<T> || kind<T>)
    struct unknown;

    template<dimension Dimension>
        requires(!kind<Dimension>)
    struct unknown<Dimension> {
        using type       = unknown;
        using value_type = std::string_view;
        using dimensions = Dimension;

        static constexpr auto value = std::string_view{"unknown"};

        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
    };

    template<typename Dimension>
    inline constexpr bool enable_as_kind<unknown<Dimension>> = true;

    template<kind kind>
    struct is_unknown_kind : public std::false_type {
    };
    template<typename Dimension>
    struct is_unknown_kind<unknown<Dimension>> : public std::true_type {
    };
    template<typename T>
    concept unknown_kind = is_unknown_kind<T>::value;

    namespace detail
    {
        template<typename Lhs, typename Rhs>
        concept kind_compatible_with =
            std::same_as<Lhs, Rhs> || unknown_kind<Lhs> || unknown_kind<Rhs>;

    }

    template<typename Lhs, typename Rhs>
    concept kind_comparable_with = kind<Lhs> && kind<Rhs> &&
        std::same_as<dimension_t<Lhs>, dimension_t<Rhs>> && detail::kind_compatible_with<Lhs, Rhs>;

    template<kind Lhs, kind Rhs>
    struct kind_multiply_result {
        using type = unknown<dimension_multiply<dimension_t<Lhs>, dimension_t<Rhs>>>;
    };

    template<kind Num, kind Den>
    struct kind_divide_result {
        using type = unknown<dimension_divide<dimension_t<Num>, dimension_t<Den>>>;
    };

    template<kind Lhs, kind Rhs>
    using kind_multiply = typename kind_multiply_result<Lhs, Rhs>::type;
    template<kind Lhs, kind Rhs>
    using kind_divide = typename kind_divide_result<Lhs, Rhs>::type;

} // namespace posu::units

#endif // #ifndef POSU_UNITS_KIND_HPP
