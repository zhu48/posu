#include <functional>
#include <tuple>

namespace posu {

    namespace detail {

        template<std::size_t I, typename Tuple, typename = void>
        struct tuple_index_valid : std::false_type {
        };

        template<std::size_t I, typename Tuple>
        struct tuple_index_valid<
            I,
            Tuple,
            std::enable_if_t<std::less{}(I, std::tuple_size_v<std::remove_cvref_t<Tuple>>)>>
            : std::true_type {
        };

        template<std::size_t I = 0, typename F, typename... Tuple>
        constexpr void for_each_impl(F&& f, Tuple&&... tuple)
        {
            if constexpr(std::conjunction_v<tuple_index_valid<I, Tuple>...>) {
                f(std::get<I>(std::forward<Tuple>(tuple))...);
                for_each_impl<I + 1>(std::forward<F>(f), std::forward<Tuple>(tuple)...);
            }
        }

        template<std::size_t I, typename F, typename... Tuple>
        constexpr decltype(auto) make_indexed_element(F& f, Tuple&&... tuple)
        {
            return f(std::get<I>(std::forward<Tuple>(tuple))...);
        }

        template<typename T, typename F, std::size_t... I, typename... Tuple>
        constexpr decltype(auto)
        make_from_for_each_impl(F&& f, std::index_sequence<I...> /*unused*/, Tuple&&... tuple)
        {
            return T(make_indexed_element<I>(f, std::forward<Tuple>(tuple)...)...);
        }

    } // namespace detail

    template<typename F, typename... Tuple>
    constexpr void for_each(F&& f, Tuple&&... tuple)
    {
        detail::for_each_impl(std::forward<F>(f), std::forward<Tuple>(tuple)...);
    }

    template<typename T, typename F, typename... Tuple>
        requires(std::less_equal{}(
            std::tuple_size_v<T>,
            std::tuple_size_v<std::remove_cvref_t<Tuple>>)&&...)
    [[nodiscard]] constexpr auto make_from_for_each(F&& f, Tuple&&... tuple) -> T
    {
        return detail::make_from_for_each_impl<T>(
            std::forward<F>(f),
            std::make_index_sequence<std::tuple_size_v<T>>{},
            std::forward<Tuple>(tuple)...);
    }

    template<typename T, typename U>
        requires(
            !std::is_const_v<U&&> && !std::is_volatile_v<U&&> && std::is_lvalue_reference_v<U&&>)
    [[nodiscard]] constexpr auto forward_as(U&& u) noexcept -> T&
    {
        return static_cast<T&>(std::forward<U>(u));
    }

    template<typename T, typename U>
        requires(
            std::is_const_v<U&&> && !std::is_volatile_v<U&&> && std::is_lvalue_reference_v<U&&>)
    [[nodiscard]] constexpr auto forward_as(U&& u) noexcept -> const T&
    {
        return static_cast<const T&>(std::forward<U>(u));
    }

    template<typename T, typename U>
        requires(
            !std::is_const_v<U&&> && std::is_volatile_v<U&&> && std::is_lvalue_reference_v<U&&>)
    [[nodiscard]] constexpr auto forward_as(U&& u) noexcept -> volatile T&
    {
        return static_cast<volatile T&>(std::forward<U>(u));
    }

    template<typename T, typename U>
        requires(std::is_const_v<U&&>&& std::is_volatile_v<U&&>&& std::is_lvalue_reference_v<U&&>)
    [[nodiscard]] constexpr auto forward_as(U&& u) noexcept -> const volatile T&
    {
        return static_cast<const volatile T&>(std::forward<U>(u));
    }

    template<typename T, typename U>
        requires(
            !std::is_const_v<U&&> && !std::is_volatile_v<U&&> && std::is_rvalue_reference_v<U&&>)
    [[nodiscard]] constexpr auto forward_as(U&& u) noexcept -> T&&
    {
        return static_cast<T&&>(std::forward<U>(u));
    }

    template<typename T, typename U>
        requires(
            std::is_const_v<U&&> && !std::is_volatile_v<U&&> && std::is_rvalue_reference_v<U&&>)
    [[nodiscard]] constexpr auto forward_as(U&& u) noexcept -> const T&&
    {
        return static_cast<const T&&>(std::forward<U>(u));
    }

    template<typename T, typename U>
        requires(
            !std::is_const_v<U&&> && std::is_volatile_v<U&&> && std::is_rvalue_reference_v<U&&>)
    [[nodiscard]] constexpr auto forward_as(U&& u) noexcept -> volatile T&&
    {
        return static_cast<volatile T&&>(std::forward<U>(u));
    }

    template<typename T, typename U>
        requires(std::is_const_v<U&&>&& std::is_volatile_v<U&&>&& std::is_rvalue_reference_v<U&&>)
    [[nodiscard]] constexpr auto forward_as(U&& u) noexcept -> const volatile T&&
    {
        return static_cast<const volatile T&&>(std::forward<U>(u));
    }

} // namespace posu
