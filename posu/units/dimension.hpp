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

    namespace detail
    {

        template<typename T, basic_string_literal Name>
        struct make_string_constant {
            using type       = T;
            using value_type = std::string_view;

            static constexpr auto value = value_type{Name};

            [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
            [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
        };

        [[nodiscard]] constexpr auto unwrap_dimension(dimension auto dim) noexcept;
        template<base_dimension Dim>
        [[nodiscard]] constexpr auto unwrap_dimension(meta::ratio<meta::list<Dim>> dim) noexcept;
        [[nodiscard]] constexpr auto unwrap_dimension(meta::ratio<> dim) noexcept;

    } // namespace detail

    template<typename T, basic_string_literal Name>
    struct make_dimension : public detail::make_string_constant<T, Name>,
                            public detail::dimension_base {
        [[nodiscard]] friend constexpr auto
        operator*(make_dimension /*unused*/, base_dimension auto rhs) noexcept
        {
            return meta::ratio<meta::list<T, decltype(rhs)>>{};
        }

        [[nodiscard]] friend constexpr auto
        operator*(make_dimension /*unused*/, derived_dimension auto rhs) noexcept
        {
            return meta::ratio<meta::list<T>>{} * rhs;
        }

        [[nodiscard]] friend constexpr auto
        operator*(derived_dimension auto lhs, make_dimension rhs) noexcept
        {
            return rhs * lhs;
        }

        [[nodiscard]] friend constexpr auto
        operator/(make_dimension /*unused*/, base_dimension auto rhs) noexcept
        {
            return meta::ratio<meta::list<T>, meta::list<decltype(rhs)>>{};
        }

        [[nodiscard]] friend constexpr auto
        operator/(make_dimension /*unused*/, derived_dimension auto rhs) noexcept
        {
            return meta::ratio<meta::list<T>>{} / rhs;
        }

        [[nodiscard]] friend constexpr auto
        operator/(derived_dimension auto lhs, make_dimension /*unused*/) noexcept
        {
            return lhs / meta::ratio<meta::list<T>>{};
        }
    };

    struct dimensionless : public make_dimension<dimensionless, "dimensionless"> {
    };

} // namespace posu::units

#endif // #ifndef POSU_UNITS_DIMENSION_HPP
