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

        [[nodiscard]] explicit constexpr
        operator std::tuple<T...> &() & noexcept;
        [[nodiscard]] explicit constexpr
        operator std::tuple<T...> &&() && noexcept;
        [[nodiscard]] explicit constexpr
        operator const std::tuple<T...> &() const& noexcept;
        [[nodiscard]] explicit constexpr
        operator const std::tuple<T...> &&() const&& noexcept;

    private:
        std::tuple<T...> m_data{};
    };

} // namespace posu::vmath

namespace std {

    template<size_t I, typename... Types>
    [[nodiscard]] constexpr auto
    get(posu::vmath::arith_tuple<Types...>& value) noexcept
        -> tuple_element_t<I, tuple<Types...>>&;

    template<size_t I, typename... Types>
    [[nodiscard]] constexpr auto
    get(posu::vmath::arith_tuple<Types...>&& value) noexcept
        -> tuple_element_t<I, tuple<Types...>>&&;

    template<size_t I, typename... Types>
    [[nodiscard]] constexpr auto
    get(const posu::vmath::arith_tuple<Types...>& value) noexcept
        -> const tuple_element_t<I, tuple<Types...>>&;

    template<size_t I, typename... Types>
    [[nodiscard]] constexpr auto
    get(const posu::vmath::arith_tuple<Types...>&& value) noexcept
        -> const tuple_element_t<I, tuple<Types...>>&&;

    template<typename Ty, typename... Types>
    [[nodiscard]] constexpr auto
    get(posu::vmath::arith_tuple<Types...>& value) noexcept -> Ty&;

    template<typename Ty, typename... Types>
    [[nodiscard]] constexpr auto
    get(posu::vmath::arith_tuple<Types...>&& value) noexcept -> Ty&&;

    template<typename Ty, typename... Types>
    [[nodiscard]] constexpr auto
    get(const posu::vmath::arith_tuple<Types...>& value) noexcept -> const Ty&;

    template<typename Ty, typename... Types>
    [[nodiscard]] constexpr auto
    get(const posu::vmath::arith_tuple<Types...>&& value) noexcept
        -> const Ty&&;

} // namespace std

#include "posu/ipp/vmath.ipp"

#endif // #ifndef POSU_VMATH_HPP
