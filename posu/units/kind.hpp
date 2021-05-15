#ifndef POSU_UNITS_KIND_HPP
#define POSU_UNITS_KIND_HPP

#include "posu/units/dimension.hpp"

namespace posu::units {

    template<typename T>
    inline constexpr bool enable_as_kind = false;

    template<typename T>
    using dimension_t = typename T::dimensions;

    template<typename T>
    concept kind =
        meta_constant<T, std::string_view> && dimension<dimension_t<T>> && enable_as_kind<T>;

    struct scaler {
        using type       = scaler;
        using value_type = std::string_view;
        using dimensions = dimensionless;

        static constexpr auto value = std::string_view{"scaler"};

        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
    };

    template<dimension Dimension>
    struct unknown {
        using type       = unknown;
        using value_type = std::string_view;
        using dimensions = Dimension;

        static constexpr auto value = std::string_view{"unknown"};

        [[nodiscard]] constexpr auto operator()() const noexcept { return value; }
        [[nodiscard]] constexpr      operator value_type() const noexcept { return value; }
    };

    template<kind kind>
    struct is_unknown_kind : public std::false_type {
    };
    template<typename T>
    concept unknown_kind = is_unknown_kind<T>::value;

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
    using kind_divide = typename kind_multiply_result<Lhs, Rhs>::type;

} // namespace posu::units

template<>
inline constexpr bool posu::units::enable_as_kind<posu::units::scaler> = true;
template<posu::units::dimension Dimension>
inline constexpr bool posu::units::enable_as_kind<posu::units::unknown<Dimension>> = true;

#include "posu/units/ipp/kind.ipp"

#endif // #ifndef POSU_UNITS_KIND_HPP
