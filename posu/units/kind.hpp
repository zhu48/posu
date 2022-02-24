#ifndef POSU_UNITS_KIND_HPP
#define POSU_UNITS_KIND_HPP

#include "posu/ratio.hpp"

#include "posu/units/dimension.hpp"

namespace posu::units {

    template<typename T>
    inline constexpr bool enable_as_kind = false;

    template<typename T>
    using dimension_t = typename T::dimensions;

    template<typename T>
    concept kind =
        meta_constant<T, std::string_view> && dimension<dimension_t<T>> && enable_as_kind<T>;

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

    /**
     * @brief Create a base tag type defining a measurement kind with the given name and dimensions.
     *
     * This CRTP base class template provides a convenience mechanism for creating measurement kind
     * tag types with all of the required members.
     *
     * @tparam T         The created measurement kind tag type.
     * @tparam Name      The name of the new measurement kind.
     * @tparam Dimension The dimensions of the new measurement kind.
     */
    template<typename T, basic_string_literal Name, dimension Dimension>
    struct make_kind : public detail::make_string_constant<T, Name> {
        using dimensions = Dimension; //!< The dimensions of the new measurement kind.
    };

    /**
     * @brief Tag type representing scaler measurement kinds.
     */
    struct scaler : public make_kind<scaler, "scaler", dimensionless> {
    };

    /**
     * @brief Designate `scaler` as a measurement kind tag type.
     */
    template<>
    inline constexpr bool enable_as_kind<scaler> = true;

    /**
     * @brief Tag type representing measurements of unknown kind with the given dimensions.
     *
     * @tparam Dimension The dimensions of the measurement.
     */
    template<dimension Dimension>
    struct unknown_kind : public make_kind<unknown_kind<Dimension>, "unknown", Dimension> {
    };

    /**
     * @brief Designate `unknown_kind` as a measurement kind tag type.
     *
     * @tparam Dimension The dimensions of the measurement.
     */
    template<typename Dimension>
    inline constexpr bool enable_as_kind<unknown_kind<Dimension>> = true;

    namespace detail {

        template<typename Lhs, typename Rhs>
        concept kind_compatible_with =
            std::same_as<Lhs, Rhs> || std::same_as<Lhs, unknown_kind<dimension_t<Rhs>>> ||
            std::same_as<Rhs, unknown_kind<dimension_t<Lhs>>>;

    } // namespace detail

    template<typename Lhs, typename Rhs>
    concept kind_comparable_with = kind<Lhs> && kind<Rhs> && detail::kind_compatible_with<Lhs, Rhs>;

    template<kind Lhs, kind Rhs>
    struct kind_multiply_result {
        using type = unknown_kind<dimension_multiply<dimension_t<Lhs>, dimension_t<Rhs>>>;
    };

    template<kind Num, kind Den>
    struct kind_divide_result {
        using type = unknown_kind<dimension_divide<dimension_t<Num>, dimension_t<Den>>>;
    };

    template<kind Lhs, kind Rhs>
    using kind_multiply = typename kind_multiply_result<Lhs, Rhs>::type;
    template<kind Lhs, kind Rhs>
    using kind_divide = typename kind_divide_result<Lhs, Rhs>::type;

    template<kind Lhs, kind_comparable_with<Lhs> Rhs>
    struct common_kind_result {
        using type = unknown_kind<dimension_t<Rhs>>;
    };

    template<kind Kind>
    struct common_kind_result<Kind, Kind> {
        using type = Kind;
    };

    template<kind Lhs, kind Rhs>
    using common_kind = typename common_kind_result<Lhs, Rhs>::type;

} // namespace posu::units

#endif // #ifndef POSU_UNITS_KIND_HPP
