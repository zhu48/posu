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

        template<typename T>
        concept base_derivation_ratio =
            (T::num.size() == 1) && T::den.empty() && meta::ratio_type<T>;

        template<typename T>
        concept basic_derivation = requires(T deriv)
        {
            // clang-format off
            { deriv() } -> meta::ratio_type;
            // clang-format on
        };

        template<typename T>
        concept base_derivation = basic_derivation<T> && requires(T t)
        {
            // clang-format off
            { t() } -> base_derivation_ratio;
            // clang-format on
        };

        template<typename T, typename Base>
        concept base_derivation_of = base_derivation<T> &&
            std::same_as<Base, meta::front<std::remove_const_t<decltype(T{}().num)>>>;

    } // namespace detail

    template<typename T>
    inline constexpr bool enable_as_dimension = std::derived_from<T, detail::dimension_base>;

    namespace detail {

        template<typename T>
        concept basic_dimension = meta_constant<T, std::string_view> && enable_as_dimension<T> &&
            requires(T dim)
        {
            // clang-format off
            { dim.deriv } -> basic_derivation;
            // clang-format on
        };

    } // namespace detail

    template<typename T>
    concept base_dimension = detail::basic_dimension<T> &&
        detail::base_derivation_of<std::remove_cvref_t<decltype(T::deriv)>, T>;

    namespace detail
    {

        template<typename T>
        struct is_base_dimension : public std::bool_constant<base_dimension<T>> {
        };

        template<typename T>
        concept derived_derivation =
            basic_derivation<T> && meta::all_of<is_base_dimension>(T{}().num) &&
            meta::all_of<is_base_dimension>(T{}().den) && !base_derivation<T>;

    } // namespace detail

    template<typename T>
    concept derived_dimension = detail::basic_dimension<T> &&
        detail::derived_derivation<std::remove_cvref_t<decltype(T::deriv)>>;

    template<typename T>
    concept dimension = base_dimension<T> || derived_dimension<T>;

    template<meta::ratio_type Derivation>
    struct derivation {
        constexpr derivation() noexcept = default;
        constexpr derivation(Derivation /*unused*/) noexcept {}

        [[nodiscard]] constexpr auto operator()() const noexcept { return Derivation{}; }

        template<meta::ratio_type RDim>
        [[nodiscard]] friend constexpr bool
        operator==(derivation lhs, derivation<RDim> rhs) noexcept
        {
            return lhs() == rhs();
        }
    };

    template<typename Dimension>
    struct derivation<meta::ratio<meta::list<Dimension>>> {
        constexpr derivation() noexcept = default;
        constexpr derivation(Dimension /*unused*/) noexcept {}
        constexpr derivation(meta::ratio<meta::list<Dimension>> /*unused*/) noexcept {}

        [[nodiscard]] constexpr auto operator()() const noexcept
        {
            return meta::ratio<meta::list<Dimension>>{};
        }

        template<meta::ratio_type RDim>
        [[nodiscard]] friend constexpr bool
        operator==(derivation lhs, derivation<RDim> rhs) noexcept
        {
            return lhs() == rhs();
        }
    };

    template<base_dimension Dimension>
    derivation(Dimension) -> derivation<meta::ratio<meta::list<Dimension>>>;

    template<
        typename T,
        basic_string_literal Name,
        derivation           Derivation = derivation<meta::ratio<meta::list<T>>>{}>
    struct make_dimension : public detail::make_string_constant<T, Name>,
                            public detail::dimension_base {
        static constexpr auto deriv = Derivation;

        template<typename RType, basic_string_literal RName, derivation RDeriv>
        [[nodiscard]] friend constexpr bool
        operator==(make_dimension lhs, make_dimension<RType, RName, RDeriv> rhs) noexcept
        {
            return lhs.deriv() == rhs.deriv();
        }
    };

    struct dimensionless : public make_dimension<dimensionless, "dimensionless"> {
    };

    template<derivation Derivation>
    struct unknown_dimension
        : public make_dimension<unknown_dimension<Derivation>, "unknown", Derivation> {
    };

    namespace detail {

        template<meta::ratio_type Deriv>
        [[nodiscard]] constexpr auto wrap_dimension(Deriv deriv) noexcept
        {
            if constexpr(deriv == meta::ratio<>{}) {
                return dimensionless{};
            }
            else if constexpr(base_derivation_ratio<Deriv>) {
                return meta::front<std::remove_const_t<decltype(deriv.num)>>{};
            }
            else {
                return unknown_dimension<Deriv{}>{};
            }
        }

        [[nodiscard]] constexpr auto
        dimension_multiply_impl(dimension auto lhs, dimension auto rhs) noexcept
        {
            return wrap_dimension(lhs.deriv() * rhs.deriv());
        }

        [[nodiscard]] constexpr auto
        dimension_divide_impl(dimension auto lhs, dimension auto rhs) noexcept
        {
            return wrap_dimension(lhs.deriv() / rhs.deriv());
        }

    } // namespace detail

    template<dimension Lhs, dimension Rhs>
    using dimension_multiply = decltype(detail::dimension_multiply_impl(Lhs{}, Rhs{}));
    template<dimension Lhs, dimension Rhs>
    using dimension_divide = decltype(detail::dimension_divide_impl(Lhs{}, Rhs{}));

} // namespace posu::units

#endif // #ifndef POSU_UNITS_DIMENSION_HPP
