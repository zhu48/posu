#ifndef POSU_UNITS_DIMENSION_HPP
#define POSU_UNITS_DIMENSION_HPP

#include <string_view>

#include "posu/concepts.hpp"
#include "posu/string_literal.hpp"

#include "posu/meta/algorithm.hpp"
#include "posu/meta/ratio.hpp"

namespace posu::units {

    namespace detail {

        struct dimension_base {
        };

        template<typename T, basic_string_literal Name>
        struct make_string_constant {
            using type       = T;
            using value_type = std::string_view;

            static constexpr auto value = value_type{Name};

            [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
            [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
        };

    } // namespace detail

    template<typename T>
    inline constexpr bool enable_as_dimension = std::derived_from<T, detail::dimension_base>;

    template<typename T>
    concept base_dimension = meta_constant<T, std::string_view> && enable_as_dimension<T>;

    namespace detail
    {

        template<typename T>
        struct is_base_dimension : public std::bool_constant<base_dimension<T>> {
        };

    } // namespace detail

    template<typename T>
    concept derived_dimension = meta::ratio_type<T> && meta::all_of<detail::is_base_dimension>(
        T::num) && meta::all_of<detail::is_base_dimension>(T::den);

    template<typename T>
    concept dimension = base_dimension<T> || derived_dimension<T>;

    template<typename T, basic_string_literal Name>
    struct make_dimension : public detail::make_string_constant<T, Name>,
                            public detail::dimension_base {
        template<typename RType, basic_string_literal RName>
        [[nodiscard]] friend constexpr bool
        operator==(make_dimension /*unused*/, make_dimension<RType, RName> /*unused*/) noexcept
        {
            return std::same_as<T, RType>;
        }
    };

    struct dimensionless : public make_dimension<dimensionless, "dimensionless"> {
    };

    namespace detail {

        template<dimension T>
        struct unwrap_dimension_type {
            using type = T;
        };

        template<base_dimension T>
        struct unwrap_dimension_type<meta::ratio<meta::list<T>>> {
            using type = T;
        };

        template<>
        struct unwrap_dimension_type<meta::ratio<meta::list<>>> {
            using type = dimensionless;
        };

        template<dimension T>
        using unwrap_dimension = typename unwrap_dimension_type<T>::type;

        template<dimension Lhs, dimension Rhs>
        [[nodiscard]] constexpr auto dimension_multiply_impl() noexcept
        {
            if constexpr(std::same_as<Lhs, dimensionless> && std::same_as<Rhs, dimensionless>) {
                return dimensionless{};
            }
            else if constexpr(std::same_as<Lhs, dimensionless>) {
                return Rhs{};
            }
            else if constexpr(std::same_as<Rhs, dimensionless>) {
                return Lhs{};
            }
            else if constexpr(base_dimension<Lhs> && base_dimension<Rhs>) {
                return meta::ratio<meta::list<Lhs, Rhs>>{};
            }
            else if constexpr(base_dimension<Lhs> && derived_dimension<Rhs>) {
                return meta::ratio<meta::list<Lhs>>{} * Rhs{};
            }
            else if constexpr(derived_dimension<Lhs> && base_dimension<Rhs>) {
                return Lhs{} * meta::ratio<meta::list<Rhs>>{};
            }
            else {
                return Lhs{} * Rhs{};
            }
        }

        template<dimension Lhs, dimension Rhs>
        [[nodiscard]] constexpr auto dimension_divide_impl() noexcept
        {
            if constexpr(base_dimension<Rhs>) {
                return dimension_multiply_impl<
                    Lhs,
                    decltype(meta::invert(meta::ratio<meta::list<Rhs>>{}))>();
            }
            else {
                return dimension_multiply_impl<Lhs, decltype(meta::invert(Rhs{}))>();
            }
        }

    } // namespace detail

    template<dimension Lhs, dimension Rhs>
    using dimension_multiply =
        detail::unwrap_dimension<decltype(detail::dimension_multiply_impl<Lhs, Rhs>())>;
    template<dimension Lhs, dimension Rhs>
    using dimension_divide =
        detail::unwrap_dimension<decltype(detail::dimension_divide_impl<Lhs, Rhs>())>;

} // namespace posu::units

#endif // #ifndef POSU_UNITS_DIMENSION_HPP
