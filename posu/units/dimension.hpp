/**
 * @file posu/units/dimension.hpp
 *
 * @brief Header defining the unit `dimension` concept.
 *
 * The Units library uses `dimension` types as basic building blocks for defining unit systems, and
 * atomic units of dimensional analysis. This header defines the `dimension` concept, and the basic
 * operations of multiplying and dividing dimensions.
 */

#ifndef POSU_UNITS_DIMENSION_HPP
#define POSU_UNITS_DIMENSION_HPP

#include <string_view>

#include "posu/concepts.hpp"
#include "posu/type_algorithm.hpp"
#include "posu/type_ratio.hpp"

namespace posu::units {

    /**
     * @brief Customization point for designating custom types as `dimension` types.
     *
     * @tparam T The type to designate as a `dimension` type.
     */
    template<typename T>
    inline constexpr bool enable_as_dimension = false;

    /**
     * @brief A singular base dimension type.
     *
     * A base dimension is a `std::string_view` meta-constant designated as a dimension type via
     * specializing the `enable_as_dimension` template. The syntactic requirements only give a
     * dimension a name string, and a unique type in the type system. Semantically, a `dimension` is
     * a tag type for a particular measurable base dimension, such as time, length, or mass.
     *
     * @tparam T The type to check against this concept.
     */
    template<typename T>
    concept base_dimension = meta_constant<T, std::string_view> && enable_as_dimension<T>;

    /**
     * @brief Meta-function for checking a type against the `base_dimension` concept.
     *
     * This meta-functino exists for passing into other meta-functions as template template
     * arguments.
     *
     * @tparam T The type to check against the `base_dimension` concept.
     */
    template<typename T>
    struct is_base_dimension : public std::bool_constant<base_dimension<T>> {
    };

    /**
     * @brief A derived dimension type.
     *
     * A derived dimension results from multiplying and dividing other dimensions. Library users
     * shall only form derived dimension types via the `dimension_multiply` and `dimension_divide`
     * meta-functions provided by this library. Semantically, a `derived_dimension` is a tag type
     * for a particular measureable derived dimension, such as velocity, area, or frequency.
     *
     * @tparam T A type to check against this concept.
     */
    template<typename T>
    concept derived_dimension = is_type_ratio_v<T> && posu::all_of<is_base_dimension>(
        typename T::num{}) && posu::all_of<is_base_dimension>(typename T::den{});

    /**
     * @brief A dimension of measurement.
     *
     * A `dimension` type is a base or derived dimension tag. Each tag type represents one
     * particular measureable dimension.
     *
     * @tparam T The type to check against this concept.
     */
    template<typename T>
    concept dimension = base_dimension<T> || derived_dimension<T>;

    /**
     * @brief Tag type for dimensionless kinds of measurements, such as amount and angle.
     */
    struct dimensionless {
        using type       = dimensionless;    //!< Self type.
        using value_type = std::string_view; //!< Meta-constant value type.

        static constexpr auto value = std::string_view{"dimensionless"}; //!< Dimension name.

        /**
         * @name Value Access
         *
         * @brief Obtain this dimension's name.
         *
         * @return Returns this dimension's name.
         *
         * @{
         */
        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
        //! @}
    };

    /**
     * @brief Tag specialization designating `dimensionless` as a base pseudo-dimension.
     */
    template<>
    inline constexpr bool enable_as_dimension<posu::units::dimensionless> = true;

    namespace detail {

        template<dimension T>
        struct unwrap_dimension_type {
            using type = T;
        };

        template<dimension T>
        using unwrap_dimension = typename unwrap_dimension_type<T>::type;

        template<dimension Lhs, dimension Rhs>
        [[nodiscard]] constexpr auto dimension_multiply_impl() noexcept;
        template<dimension Lhs, dimension Rhs>
        [[nodiscard]] constexpr auto dimension_divide_impl() noexcept;

        template<typename T>
        struct is_std_ratio : std::false_type {
        };

        template<typename T>
        inline constexpr bool is_std_ratio_v = is_std_ratio<T>::value;

        template<typename T>
        concept std_ratio = is_std_ratio_v<T>;

    } // namespace detail

    /**
     * @defgroup POSU_UNIS_DIM_OPS Dimension Operators
     *
     * @brief Meta-functions for multiplying and dividing dimensions.
     *
     * These functions generate a dimension tag type given two dimensions to multiply together or
     * divide by. If the operands cancel out with each other, the operation generates
     * `dimensionless`.
     *
     * @tparam Lhs The left-hand-side dimension operand.
     * @tparam Rhs The right-hand-side dimension operand.
     *
     * @return Returns the dimensions resulting from the operation.
     *
     * @{
     */
    template<dimension Lhs, dimension Rhs>
    using dimension_multiply =
        detail::unwrap_dimension<decltype(detail::dimension_multiply_impl<Lhs, Rhs>())>;
    template<dimension Lhs, dimension Rhs>
    using dimension_divide =
        detail::unwrap_dimension<decltype(detail::dimension_divide_impl<Lhs, Rhs>())>;
    //! @}

} // namespace posu::units

#include "posu/units/ipp/dimension.ipp"

#endif // #ifndef POSU_UNITS_DIMENSION_HPP
