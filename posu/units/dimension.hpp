#ifndef POSU_UNITS_DIMENSION_HPP
#define POSU_UNITS_DIMENSION_HPP

#include <string_view>

#include "posu/concepts.hpp"
#include "posu/string_literal.hpp"

#include "posu/meta/algorithm.hpp"
#include "posu/meta/ratio.hpp"

namespace posu::units {

    template<typename T>
    inline constexpr bool enable_as_dimension = false;

    namespace detail {

        template<typename T, basic_string_literal Name>
        struct make_string_constant {
            using type       = T;
            using value_type = std::string_view;

            static constexpr auto value = value_type{Name};

            [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
            [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
        };

    } // namespace detail

    template<typename T, basic_string_literal Name>
    using make_dimension = detail::make_string_constant<T, Name>;

    template<typename T>
    concept base_dimension = meta_constant<T, std::string_view> && enable_as_dimension<T>;

    template<typename T>
    struct is_base_dimension : public std::bool_constant<base_dimension<T>> {
    };

    template<typename T>
    concept derived_dimension = meta::ratio_type<T> &&
        meta::all_of<is_base_dimension>(T::num) && meta::all_of<is_base_dimension>(T::den);

    template<typename T>
    concept dimension = base_dimension<T> || derived_dimension<T>;

    struct dimensionless : public make_dimension<dimensionless, "dimensionless"> {
    };

    template<>
    inline constexpr bool enable_as_dimension<posu::units::dimensionless> = true;

    namespace detail {

        [[nodiscard]] constexpr auto
        dimension_multiply(dimension auto lhs, dimension auto rhs) noexcept;
        [[nodiscard]] constexpr auto
        dimension_divide(dimension auto num, dimension auto den) noexcept;

    } // namespace detail

    template<dimension Lhs, dimension Rhs>
    using dimension_multiply = decltype(detail::dimension_multiply(Lhs{}, Rhs{}));
    template<dimension Num, dimension Den>
    using dimension_divide = decltype(detail::dimension_divide(Num{}, Den{}));

} // namespace posu::units

#include "posu/units/ipp/dimension.ipp"

#endif // #ifndef POSU_UNITS_DIMENSION_HPP
