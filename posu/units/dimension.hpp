#ifndef POSU_UNITS_DIMENSION_HPP
#define POSU_UNITS_DIMENSION_HPP

#include <string_view>

#include "posu/concepts.hpp"

#include "posu/meta/algorithm.hpp"
#include "posu/meta/ratio.hpp"

namespace posu::units {

    template<typename T>
    inline constexpr bool enable_as_dimension = false;

    template<typename T>
    concept base_dimension = meta_constant<T, std::string_view> && enable_as_dimension<T>;

    template<typename T>
    struct is_base_dimension : public std::bool_constant<base_dimension<T>> {
    };

    template<typename T>
    concept derived_dimension = meta::is_ratio_v<T> && meta::all_of<is_base_dimension>(
        typename T::num{}) && meta::all_of<is_base_dimension>(typename T::den{});

    template<typename T>
    concept dimension = base_dimension<T> || derived_dimension<T>;

    struct dimensionless {
        using type       = dimensionless;
        using value_type = std::string_view;

        static constexpr auto value = std::string_view{"dimensionless"};

        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
    };

    template<>
    inline constexpr bool enable_as_dimension<posu::units::dimensionless> = true;

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
                return meta::ratio_multiply<meta::ratio<meta::list<Lhs>>, Rhs>{};
            }
            else if constexpr(derived_dimension<Lhs> && base_dimension<Rhs>) {
                return meta::ratio_multiply<Lhs, meta::ratio<meta::list<Rhs>>>{};
            }
            else {
                return meta::ratio_multiply<Lhs, Rhs>{};
            }
        }

        template<dimension Lhs, dimension Rhs>
        [[nodiscard]] constexpr auto dimension_divide_impl() noexcept
        {
            if constexpr(base_dimension<Rhs>) {
                return dimension_multiply_impl<
                    Lhs,
                    meta::ratio_invert<meta::ratio<meta::list<Rhs>>>>();
            }
            else {
                return dimension_multiply_impl<Lhs, meta::ratio_invert<Rhs>>();
            }
        }

        template<typename T>
        struct is_std_ratio : std::false_type {
        };

        template<std::intmax_t Num, std::intmax_t Den>
        struct is_std_ratio<std::ratio<Num, Den>> : std::true_type {
        };

        template<typename T>
        inline constexpr bool is_std_ratio_v = is_std_ratio<T>::value;

        template<typename T>
        concept std_ratio = is_std_ratio_v<T>;

    } // namespace detail

    template<dimension Lhs, dimension Rhs>
    using dimension_multiply =
        detail::unwrap_dimension<decltype(detail::dimension_multiply_impl<Lhs, Rhs>())>;
    template<dimension Lhs, dimension Rhs>
    using dimension_divide =
        detail::unwrap_dimension<decltype(detail::dimension_divide_impl<Lhs, Rhs>())>;

} // namespace posu::units

#endif // #ifndef POSU_UNITS_DIMENSION_HPP
