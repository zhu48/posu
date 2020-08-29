#ifndef POSU_VMATH_HPP
#define POSU_VMATH_HPP

#include <concepts>
#include <stdexcept>
#include <tuple>

namespace posu::vmath {

    class not_pure_diagonal : public std::runtime_error {
    public:
        not_pure_diagonal(const std::string& what_arg);
        not_pure_diagonal(const char* what_arg);
    };

    template<typename... T> // clang-format off
        requires((std::integral<T> || std::floating_point<T>) && ...)
    class arith_tuple { // clang-format on
    public:
        using scaler_type = std::common_type_t<T...>;

        constexpr arith_tuple() = default;

        constexpr arith_tuple(scaler_type n) noexcept;
        constexpr arith_tuple(T... n) noexcept requires(sizeof...(T) != 1);

        constexpr auto operator=(scaler_type n) noexcept -> arith_tuple&;

        [[nodiscard]] constexpr auto operator+(arith_tuple rhs) const noexcept
            -> arith_tuple;
        [[nodiscard]] constexpr auto operator+(scaler_type rhs) const noexcept
            -> arith_tuple;
        [[nodiscard]] constexpr auto operator-(arith_tuple rhs) const noexcept
            -> arith_tuple;
        [[nodiscard]] constexpr auto operator-(scaler_type rhs) const noexcept
            -> arith_tuple;
        [[nodiscard]] constexpr auto operator*(scaler_type rhs) const noexcept
            -> arith_tuple;
        [[nodiscard]] constexpr auto operator/(scaler_type rhs) const noexcept
            -> arith_tuple;
        [[nodiscard]] constexpr auto operator+=(arith_tuple rhs) noexcept
            -> arith_tuple&;
        [[nodiscard]] constexpr auto operator+=(scaler_type rhs) noexcept
            -> arith_tuple&;
        [[nodiscard]] constexpr auto operator-=(arith_tuple rhs) noexcept
            -> arith_tuple&;
        [[nodiscard]] constexpr auto operator-=(scaler_type rhs) noexcept
            -> arith_tuple&;
        [[nodiscard]] constexpr auto operator*=(scaler_type rhs) noexcept
            -> arith_tuple&;
        [[nodiscard]] constexpr auto operator/=(scaler_type rhs) noexcept
            -> arith_tuple&;

        [[nodiscard]] explicit constexpr operator scaler_type() const
            noexcept(false);

    private:
        std::tuple<T...> m_data{};
    };

} // namespace posu::vmath

#include "posu/ipp/vmath.ipp"

#endif // #ifndef POSU_VMATH_HPP
