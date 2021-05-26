#include "posu/utility.hpp"

namespace posu::vmath {

    namespace detail {

        template<typename T, typename...>
        struct first_type {
            using type = T;
        };

        template<typename T, typename... Rest>
        using first_type_t = typename first_type<T, Rest...>::type;

        template<typename Arg>
        constexpr decltype(auto) expand_forward_helper(Arg&& arg, std::size_t /*unused*/) noexcept
        {
            return std::forward<Arg>(arg);
        }

        template<typename Tuple, typename Arg, std::size_t... I>
        constexpr auto
        expand_as_tuple_impl(Arg&& arg, std::index_sequence<I...> /*unused*/) noexcept -> Tuple
        {
            return {expand_forward_helper<Arg>(arg, I)...};
        }

        template<typename Tuple, typename Arg>
        constexpr auto expand_as_tuple(Arg&& arg) -> Tuple
        {
            return expand_as_tuple_impl<Tuple>(
                std::forward<Arg>(arg),
                std::make_index_sequence<std::tuple_size_v<Tuple>>{});
        }

        template<std::size_t I = 0, typename... T>
        constexpr auto obtain_value(const std::tuple<T...>& value) noexcept(false)
            -> std::common_type_t<T...>
        {
            if constexpr(I < sizeof...(T) && I + 1 < sizeof...(T)) {
                if(std::get<I>(value) != std::get<I + 1>(value)) {
                    throw not_pure_diagonal("scaler conversion requires all elements to be equal");
                }
                return obtain_value<I + 1>(value);
            }
            else {
                return std::get<0>(value);
            }
        }

        template<typename T, std::size_t... I>
        [[nodiscard]] constexpr decltype(auto)
        make_arith_tuple_from_size(T&& t, std::index_sequence<I...> /*unused*/) noexcept
        {
            return arith_tuple<
                std::remove_cvref_t<first_type_t<T, std::integral_constant<std::size_t, I>>>...>{
                std::forward<T>(t)};
        }

    } // namespace detail

    template<typename... T>
        requires((std::integral<T> || std::floating_point<T>)&&...)
    constexpr arith_tuple<T...>::arith_tuple(scaler_type n) noexcept
        : m_data{detail::expand_as_tuple<std::tuple<T...>>(n)}
    {
    }

    template<typename... T>
        requires((std::integral<T> || std::floating_point<T>)&&...)
    constexpr arith_tuple<T...>::arith_tuple(T... n) noexcept requires(sizeof...(T) != 1)
        : m_data{n...}
    {
    }

    template<typename... T>
        requires((std::integral<T> || std::floating_point<T>)&&...)
    constexpr auto arith_tuple<T...>::operator=(scaler_type n) noexcept -> arith_tuple&
    {
        posu::for_each([&](auto& elem) { elem = n; }, m_data);
        return *this;
    }

    template<typename... T>
        requires((std::integral<T> || std::floating_point<T>)&&...)
    [[nodiscard]] constexpr auto arith_tuple<T...>::operator+(scaler_type rhs) const noexcept
        -> arith_tuple
    {
        return posu::make_from_for_each<arith_tuple<T...>>(
            [&](const auto& l) { return l + rhs; },
            m_data);
    }

    template<typename... T>
        requires((std::integral<T> || std::floating_point<T>)&&...)
    [[nodiscard]] constexpr auto arith_tuple<T...>::operator+(const arith_tuple& rhs) const noexcept
        -> arith_tuple
    {
        return posu::make_from_for_each<arith_tuple<T...>>(
            [](const auto& l, const auto& r) { return l + r; },
            m_data,
            rhs.m_data);
    }

    template<typename... T>
        requires((std::integral<T> || std::floating_point<T>)&&...)
    [[nodiscard]] constexpr auto arith_tuple<T...>::operator-(scaler_type rhs) const noexcept
        -> arith_tuple
    {
        return posu::make_from_for_each<arith_tuple<T...>>(
            [&](const auto& l) { return l - rhs; },
            m_data);
    }

    template<typename... T>
        requires((std::integral<T> || std::floating_point<T>)&&...)
    [[nodiscard]] constexpr auto arith_tuple<T...>::operator-(const arith_tuple& rhs) const noexcept
        -> arith_tuple
    {
        return posu::make_from_for_each<arith_tuple<T...>>(
            [](const auto& l, const auto& r) { return l - r; },
            m_data,
            rhs.m_data);
    }

    template<typename... T>
        requires((std::integral<T> || std::floating_point<T>)&&...)
    [[nodiscard]] constexpr auto arith_tuple<T...>::operator*(scaler_type rhs) const noexcept
        -> arith_tuple
    {
        return posu::make_from_for_each<arith_tuple<T...>>(
            [&](const auto& l) { return l * rhs; },
            m_data);
    }

    template<typename... T>
        requires((std::integral<T> || std::floating_point<T>)&&...)
    [[nodiscard]] constexpr auto arith_tuple<T...>::operator/(scaler_type rhs) const noexcept
        -> arith_tuple
    {
        return posu::make_from_for_each<arith_tuple<T...>>(
            [&](const auto& l) { return l / rhs; },
            m_data);
    }

    template<typename... T>
        requires((std::integral<T> || std::floating_point<T>)&&...)
    constexpr auto arith_tuple<T...>::operator+=(scaler_type rhs) noexcept -> arith_tuple&
    {
        posu::for_each([&](auto& l) { l += rhs; }, m_data);
        return *this;
    }

    template<typename... T>
        requires((std::integral<T> || std::floating_point<T>)&&...)
    constexpr auto arith_tuple<T...>::operator+=(const arith_tuple& rhs) noexcept -> arith_tuple&
    {
        posu::for_each([](auto& l, const auto& r) { l += r; }, m_data, rhs.m_data);
        return *this;
    }

    template<typename... T>
        requires((std::integral<T> || std::floating_point<T>)&&...)
    constexpr auto arith_tuple<T...>::operator-=(scaler_type rhs) noexcept -> arith_tuple&
    {
        posu::for_each([&](auto& l) { l -= rhs; }, m_data);
        return *this;
    }

    template<typename... T>
        requires((std::integral<T> || std::floating_point<T>)&&...)
    constexpr auto arith_tuple<T...>::operator-=(const arith_tuple& rhs) noexcept -> arith_tuple&
    {
        posu::for_each([](auto& l, const auto& r) { l -= r; }, m_data, rhs.m_data);
        return *this;
    }

    template<typename... T>
        requires((std::integral<T> || std::floating_point<T>)&&...)
    constexpr auto arith_tuple<T...>::operator*=(scaler_type rhs) noexcept -> arith_tuple&
    {
        posu::for_each([&](auto& l) { l *= rhs; }, m_data);
        return *this;
    }

    template<typename... T>
        requires((std::integral<T> || std::floating_point<T>)&&...)
    constexpr auto arith_tuple<T...>::operator/=(scaler_type rhs) noexcept -> arith_tuple&
    {
        posu::for_each([&](auto& l) { l /= rhs; }, m_data);
        return *this;
    }

    template<typename... T>
        requires((std::integral<T> || std::floating_point<T>)&&...)
    [[nodiscard]] constexpr arith_tuple<T...>::operator scaler_type() const noexcept(false)
    {
        return detail::obtain_value(m_data);
    }

    template<typename... T>
        requires((std::integral<T> || std::floating_point<T>)&&...)
    [[nodiscard]] constexpr arith_tuple<T...>::operator std::tuple<T...>&() & noexcept
    {
        return m_data;
    }

    template<typename... T>
        requires((std::integral<T> || std::floating_point<T>)&&...)
    [[nodiscard]] constexpr arith_tuple<T...>::operator std::tuple<T...>&&() && noexcept
    {
        return std::move(m_data);
    }

    template<typename... T>
        requires((std::integral<T> || std::floating_point<T>)&&...)
    [[nodiscard]] constexpr arith_tuple<T...>::operator const std::tuple<T...>&() const& noexcept
    {
        return m_data;
    }

    template<typename... T>
        requires((std::integral<T> || std::floating_point<T>)&&...)
    [[nodiscard]] constexpr arith_tuple<T...>::operator const std::tuple<T...>&&() const&& noexcept
    {
        return std::move(m_data);
    }

    template<std::size_t I, typename T>
    [[nodiscard]] constexpr decltype(auto) make_arith_tuple(T&& t) noexcept
    {
        return detail::make_arith_tuple_from_size(
            std::forward<T>(t),
            std::make_index_sequence<I>{});
    }

    template<typename... T>
    [[nodiscard]] constexpr auto make_arith_tuple(T&&... t) noexcept
        -> arith_tuple<std::remove_cvref_t<T>...>
    {
        return {std::forward<T>(t)...};
    }

} // namespace posu::vmath

namespace std {
    template<size_t I, typename... Types>
    [[nodiscard]] constexpr auto get(posu::vmath::arith_tuple<Types...>& value) noexcept
        -> tuple_element_t<I, tuple<Types...>>&
    {
        return get<I>((std::tuple<Types...>&)(value));
    }

    template<size_t I, typename... Types>
    [[nodiscard]] constexpr auto get(posu::vmath::arith_tuple<Types...>&& value) noexcept
        -> tuple_element_t<I, tuple<Types...>>&&
    {
        return get<I>((std::tuple<Types...> &&)(value));
    }

    template<size_t I, typename... Types>
    [[nodiscard]] constexpr auto get(const posu::vmath::arith_tuple<Types...>& value) noexcept
        -> const tuple_element_t<I, tuple<Types...>>&
    {
        return get<I>((const std::tuple<Types...>&)(value));
    }

    template<size_t I, typename... Types>
    [[nodiscard]] constexpr auto get(const posu::vmath::arith_tuple<Types...>&& value) noexcept
        -> const tuple_element_t<I, tuple<Types...>>&&
    {
        return get<I>((const std::tuple<Types...>&&)(value));
    }

    template<typename T, typename... Types>
    [[nodiscard]] constexpr auto get(posu::vmath::arith_tuple<Types...>& value) noexcept -> T&
    {
        return get<T>((std::tuple<Types...>&)(value));
    }

    template<typename T, typename... Types>
    [[nodiscard]] constexpr auto get(posu::vmath::arith_tuple<Types...>&& value) noexcept -> T&&
    {
        return get<T>((std::tuple<Types...> &&)(value));
    }

    template<typename T, typename... Types>
    [[nodiscard]] constexpr auto get(const posu::vmath::arith_tuple<Types...>& value) noexcept
        -> const T&
    {
        return get<T>((const std::tuple<Types...>&)(value));
    }

    template<typename T, typename... Types>
    [[nodiscard]] constexpr auto get(const posu::vmath::arith_tuple<Types...>&& value) noexcept
        -> const T&&
    {
        return get<T>((const std::tuple<Types...>&&)(value));
    }

} // namespace std
