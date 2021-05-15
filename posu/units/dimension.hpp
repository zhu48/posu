#ifndef POSU_UNITS_DIMENSION_HPP
#define POSU_UNITS_DIMENSION_HPP

#include <string_view>

#include "posu/concepts.hpp"
#include "posu/type_algorithm.hpp"
#include "posu/type_ratio.hpp"

namespace posu::units {

    template<typename T>
    inline constexpr bool enable_as_dimension = false;

    template<typename T>
    concept base_dimension = meta_constant<T, std::string_view> && enable_as_dimension<T>;

    template<typename T>
    struct is_base_dimension : public std::bool_constant<base_dimension<T>> {
    };

    template<typename T>
    concept derived_dimension = is_type_ratio_v<T> && posu::all_of<is_base_dimension>(
        typename T::num{}) && posu::all_of<is_base_dimension>(typename T::den{});

    template<typename T>
    concept dimension = base_dimension<T> || derived_dimension<T>;

    struct dimensionless {
        using type       = dimensionless;
        using value_type = std::string_view;

        static constexpr auto value = std::string_view{"dimensionless"};

        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
    };

    namespace detail {

        template<dimension Lhs, dimension Rhs>
        [[nodiscard]] constexpr auto dimension_multiply_impl() noexcept
        {
            if constexpr(base_dimension<Lhs> && base_dimension<Rhs>) {
                return type_ratio<type_list<Lhs, Rhs>>{};
            }
            else if constexpr(base_dimension<Lhs> && derived_dimension<Rhs>) {
                return ratio_multiply<type_ratio<type_list<Lhs>>, Rhs>{};
            }
            else if constexpr(derived_dimension<Lhs> && base_dimension<Rhs>) {
                return ratio_multiply<Lhs, type_ratio<type_list<Rhs>>>{};
            }
            else {
                return ratio_multiply<Lhs, Rhs>{};
            }
        }

        template<dimension Lhs, dimension Rhs>
        [[nodiscard]] constexpr auto dimension_divide_impl() noexcept
        {
            if constexpr(base_dimension<Rhs>) {
                return ratio_divide<Lhs, type_ratio<type_list<Rhs>>>{};
            }
            else {
                return ratio_divide<Lhs, Rhs>{};
            }
        }

    } // namespace detail

    template<dimension Lhs, dimension Rhs>
    using dimension_multiply = decltype(detail::dimension_multiply_impl<Lhs, Rhs>());
    template<dimension Lhs, dimension Rhs>
    using dimension_divide = decltype(detail::dimension_divide_impl<Lhs, Rhs>());

} // namespace posu::units

template<>
inline constexpr bool posu::units::enable_as_dimension<posu::units::dimensionless> = true;

#endif // #ifndef POSU_UNITS_DIMENSION_HPP
