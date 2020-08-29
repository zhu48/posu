
namespace posu::vmath {

    namespace detail {

        template<typename Arg>
        decltype(auto)
        expand_forward_helper(Arg&& arg, std::size_t /*unused*/) noexcept {
            return std::forward<Arg>(arg);
        }

        template<typename Tuple, typename Arg, std::size_t... I>
        auto expand_as_tuple_impl(
            Arg&& arg, std::index_sequence<I...> /*unused*/) noexcept -> Tuple {
            return {expand_forward_helper<Arg>(arg, I)...};
        }

        template<typename Tuple, typename Arg>
        auto expand_as_tuple(Arg&& arg) -> Tuple {
            return expand_as_tuple_impl<Tuple>(
                std::forward<Arg>(arg),
                std::make_index_sequence<std::tuple_size_v<Tuple>>{});
        }

        template<typename... T, typename Arg, std::size_t I = 0>
        void assign_all(std::tuple<T...>& tuple, Arg arg) noexcept {
            if constexpr(I < sizeof...(T)) {
                std::get<I>(tuple) = std::forward<Arg>(arg);
                assign_all<T..., Arg, I + 1>(tuple, arg);
            }
        }

        template<typename... T, std::size_t... I>
        [[nodiscard]] auto add_all(
            const std::tuple<T...>& lhs,
            const std::tuple<T...>& rhs,
            std::index_sequence<I...> /*unused*/) noexcept
            -> arith_tuple<T...> {
            return {(std::get<I>(lhs) + std::get<I>(rhs))...};
        }

        template<typename... T, std::size_t... I>
        [[nodiscard]] auto add_all(
            const std::tuple<T...>&         lhs,
            const std::common_type_t<T...>& rhs,
            std::index_sequence<I...> /*unused*/) noexcept
            -> arith_tuple<T...> {
            return {(std::get<I>(lhs) + rhs)...};
        }

        template<typename... T, std::size_t I = 0>
        void
        add_all(std::tuple<T...>& lhs, const std::tuple<T...>& rhs) noexcept {
            if constexpr(I < sizeof...(T)) {
                add_all<T..., I + 1>(lhs, rhs);
                std::get<I>(lhs) += std::get<I>(rhs);
            }
        }

        template<typename... T, std::size_t I = 0>
        void add_all(
            std::tuple<T...>&               lhs,
            const std::common_type_t<T...>& rhs) noexcept {
            if constexpr(I < sizeof...(T)) {
                add_all<T..., I + 1>(lhs, rhs);
                std::get<I>(lhs) += rhs;
            }
        }

        template<typename... T, std::size_t... I>
        [[nodiscard]] auto sub_all(
            const std::tuple<T...>& lhs,
            const std::tuple<T...>& rhs,
            std::index_sequence<I...> /*unused*/) noexcept
            -> arith_tuple<T...> {
            return {(std::get<I>(lhs) - std::get<I>(rhs))...};
        }

        template<typename... T, std::size_t... I>
        [[nodiscard]] auto sub_all(
            const std::tuple<T...>&         lhs,
            const std::common_type_t<T...>& rhs,
            std::index_sequence<I...> /*unused*/) noexcept
            -> arith_tuple<T...> {
            return {(std::get<I>(lhs) - rhs)...};
        }

        template<typename... T, std::size_t I = 0>
        void
        sub_all(std::tuple<T...>& lhs, const std::tuple<T...>& rhs) noexcept {
            if constexpr(I < sizeof...(T)) {
                sub_all<T..., I + 1>(lhs, rhs);
                std::get<I>(lhs) -= std::get<I>(rhs);
            }
        }

        template<typename... T, std::size_t I = 0>
        void sub_all(
            std::tuple<T...>&               lhs,
            const std::common_type_t<T...>& rhs) noexcept {
            if constexpr(I < sizeof...(T)) {
                sub_all<T..., I + 1>(lhs, rhs);
                std::get<I>(lhs) -= rhs;
            }
        }

        template<typename... T, std::size_t... I>
        [[nodiscard]] auto mul_all(
            const std::tuple<T...>&         lhs,
            const std::common_type_t<T...>& rhs,
            std::index_sequence<I...> /*unused*/) noexcept
            -> arith_tuple<T...> {
            return {(std::get<I>(lhs) * rhs)...};
        }

        template<typename... T, std::size_t I = 0>
        void mul_all(
            std::tuple<T...>&               lhs,
            const std::common_type_t<T...>& rhs) noexcept {
            if constexpr(I < sizeof...(T)) {
                mul_all<T..., I + 1>(lhs, rhs);
                std::get<I>(lhs) *= rhs;
            }
        }

        template<typename... T, std::size_t... I>
        [[nodiscard]] auto div_all(
            const std::tuple<T...>&         lhs,
            const std::common_type_t<T...>& rhs,
            std::index_sequence<I...> /*unused*/) noexcept
            -> arith_tuple<T...> {
            return {(std::get<I>(lhs) / rhs)...};
        }

        template<typename... T, std::size_t I = 0>
        void div_all(
            std::tuple<T...>&               lhs,
            const std::common_type_t<T...>& rhs) noexcept {
            if constexpr(I < sizeof...(T)) {
                div_all<T..., I + 1>(lhs, rhs);
                std::get<I>(lhs) /= rhs;
            }
        }

        template<typename... T, std::size_t I = 0>
        auto obtain_value(const std::tuple<T...>& value) noexcept(false)
            -> std::common_type_t<T...> {
            if constexpr(I < sizeof...(T) && I + 1 < sizeof...(T)) {
                if(std::get<I>(value) != std::get<I + 1>(value)) {
                    throw not_pure_diagonal(
                        "scaler conversion requires all elements to be equal");
                }
            } else {
                return std::get<0>(value);
            }
        }

    } // namespace detail

    template<typename... T> // clang-format off
        requires((std::integral<T> || std::floating_point<T>) && ...)
    constexpr arith_tuple<T...>:: // clang-format on
        arith_tuple(scaler_type n) noexcept
        : m_data{detail::expand_as_tuple<std::tuple<T...>>(n)} {}

    template<typename... T> // clang-format off
        requires((std::integral<T> || std::floating_point<T>) && ...)
    constexpr arith_tuple<T...>:: // clang-format on
        arith_tuple(T... n) noexcept requires(sizeof...(T) != 1)
        : m_data{n...} {}

    template<typename... T> // clang-format off
        requires((std::integral<T> || std::floating_point<T>) && ...)
    constexpr auto arith_tuple<T...>:: // clang-format on
    operator=(scaler_type n) noexcept -> arith_tuple& {
        detail::assign_all(m_data, n, std::make_index_sequence<sizeof...(T)>{});
        return *this;
    }

    template<typename... T> // clang-format off
        requires((std::integral<T> || std::floating_point<T>) && ...)
    [[nodiscard]] constexpr auto arith_tuple<T...>:: // clang-format on
        operator+(arith_tuple rhs) const noexcept -> arith_tuple {
        return detail::add_all(
            m_data, rhs.m_data, std::make_index_sequence<sizeof...(T)>{});
    }

    template<typename... T> // clang-format off
        requires((std::integral<T> || std::floating_point<T>) && ...)
    [[nodiscard]] constexpr auto arith_tuple<T...>:: // clang-format on
        operator+(scaler_type rhs) const noexcept -> arith_tuple {
        return detail::add_all(
            m_data, rhs, std::make_index_sequence<sizeof...(T)>{});
    }

    template<typename... T> // clang-format off
        requires((std::integral<T> || std::floating_point<T>) && ...)
    [[nodiscard]] constexpr auto arith_tuple<T...>:: // clang-format on
        operator-(arith_tuple rhs) const noexcept -> arith_tuple {
        return detail::sub_all(
            m_data, rhs.m_data, std::make_index_sequence<sizeof...(T)>{});
    }

    template<typename... T> // clang-format off
        requires((std::integral<T> || std::floating_point<T>) && ...)
    [[nodiscard]] constexpr auto arith_tuple<T...>:: // clang-format on
        operator-(scaler_type rhs) const noexcept -> arith_tuple {
        return detail::sub_all(
            m_data, rhs, std::make_index_sequence<sizeof...(T)>{});
    }

    template<typename... T> // clang-format off
        requires((std::integral<T> || std::floating_point<T>) && ...)
    [[nodiscard]] constexpr auto arith_tuple<T...>:: // clang-format on
        operator*(scaler_type rhs) const noexcept -> arith_tuple {
        return detail::mul_all(
            m_data, rhs, std::make_index_sequence<sizeof...(T)>{});
    }

    template<typename... T> // clang-format off
        requires((std::integral<T> || std::floating_point<T>) && ...)
    [[nodiscard]] constexpr auto arith_tuple<T...>:: // clang-format on
        operator/(scaler_type rhs) const noexcept -> arith_tuple {
        return detail::div_all(
            m_data, rhs, std::make_index_sequence<sizeof...(T)>{});
    }

    template<typename... T> // clang-format off
        requires((std::integral<T> || std::floating_point<T>) && ...)
    constexpr auto arith_tuple<T...>:: // clang-format on
    operator+=(arith_tuple rhs) noexcept -> arith_tuple& {
        detail::add_all(m_data, rhs.m_data);
        return *this;
    }

    template<typename... T> // clang-format off
        requires((std::integral<T> || std::floating_point<T>) && ...)
    constexpr auto arith_tuple<T...>:: // clang-format on
    operator+=(scaler_type rhs) noexcept -> arith_tuple& {
        detail::add_all(m_data, rhs);
        return *this;
    }

    template<typename... T> // clang-format off
        requires((std::integral<T> || std::floating_point<T>) && ...)
    constexpr auto arith_tuple<T...>:: // clang-format on
    operator-=(arith_tuple rhs) noexcept -> arith_tuple& {
        detail::sub_all(m_data, rhs.m_data);
        return *this;
    }

    template<typename... T> // clang-format off
        requires((std::integral<T> || std::floating_point<T>) && ...)
    constexpr auto arith_tuple<T...>:: // clang-format on
    operator-=(scaler_type rhs) noexcept -> arith_tuple& {
        detail::sub_all(m_data, rhs);
        return *this;
    }

    template<typename... T> // clang-format off
        requires((std::integral<T> || std::floating_point<T>) && ...)
    constexpr auto arith_tuple<T...>:: // clang-format on
    operator*=(scaler_type rhs) noexcept -> arith_tuple& {
        detail::mul_all(m_data, rhs);
        return *this;
    }

    template<typename... T> // clang-format off
        requires((std::integral<T> || std::floating_point<T>) && ...)
    constexpr auto arith_tuple<T...>:: // clang-format on
    operator/=(scaler_type rhs) noexcept -> arith_tuple& {
        detail::div_all(m_data, rhs);
        return *this;
    }

    template<typename... T> // clang-format off
        requires((std::integral<T> || std::floating_point<T>) && ...)
    [[nodiscard]] constexpr arith_tuple<T...>:: // clang-format on
        operator scaler_type() const noexcept(false) {
        return detail::obtain_value(m_data);
    }

    template<typename... T> // clang-format off
        requires((std::integral<T> || std::floating_point<T>) && ...)
    [[nodiscard]] constexpr arith_tuple<T...>:: // clang-format on
        operator std::tuple<T...> &() & noexcept {
        return m_data;
    }

    template<typename... T> // clang-format off
        requires((std::integral<T> || std::floating_point<T>) && ...)
    [[nodiscard]] constexpr arith_tuple<T...>:: // clang-format on
        operator std::tuple<T...> &&() && noexcept {
        return std::move(m_data);
    }

    template<typename... T> // clang-format off
        requires((std::integral<T> || std::floating_point<T>) && ...)
    [[nodiscard]] constexpr arith_tuple<T...>:: // clang-format on
        operator const std::tuple<T...> &() const& noexcept {
        return m_data;
    }

    template<typename... T> // clang-format off
        requires((std::integral<T> || std::floating_point<T>) && ...)
    [[nodiscard]] constexpr arith_tuple<T...>:: // clang-format on
        operator const std::tuple<T...> &&() const&& noexcept {
        return std::move(m_data);
    }

} // namespace posu::vmath

namespace std {

    template<size_t I, typename... Types>
    [[nodiscard]] constexpr auto
    get(posu::vmath::arith_tuple<Types...>& value) noexcept
        -> tuple_element_t<I, tuple<Types...>>& {
        return get<I>((std::tuple<Types...>&)(value));
    }

    template<size_t I, typename... Types>
    [[nodiscard]] constexpr auto
    get(posu::vmath::arith_tuple<Types...>&& value) noexcept
        -> tuple_element_t<I, tuple<Types...>>&& {
        return get<I>((std::tuple<Types...> &&)(value));
    }

    template<size_t I, typename... Types>
    [[nodiscard]] constexpr auto
    get(const posu::vmath::arith_tuple<Types...>& value) noexcept
        -> const tuple_element_t<I, tuple<Types...>>& {
        return get<I>((const std::tuple<Types...>&)(value));
    }

    template<size_t I, typename... Types>
    [[nodiscard]] constexpr auto
    get(const posu::vmath::arith_tuple<Types...>&& value) noexcept
        -> const tuple_element_t<I, tuple<Types...>>&& {
        return get<I>((const std::tuple<Types...>&&)(value));
    }

    template<typename T, typename... Types>
    [[nodiscard]] constexpr auto
    get(posu::vmath::arith_tuple<Types...>& value) noexcept -> T& {
        return get<T>((std::tuple<Types...>&)(value));
    }

    template<typename T, typename... Types>
    [[nodiscard]] constexpr auto
    get(posu::vmath::arith_tuple<Types...>&& value) noexcept -> T&& {
        return get<T>((std::tuple<Types...> &&)(value));
    }

    template<typename T, typename... Types>
    [[nodiscard]] constexpr auto
    get(const posu::vmath::arith_tuple<Types...>& value) noexcept -> const T& {
        return get<T>((const std::tuple<Types...>&)(value));
    }

    template<typename T, typename... Types>
    [[nodiscard]] constexpr auto
    get(const posu::vmath::arith_tuple<Types...>&& value) noexcept
        -> const T&& {
        return get<T>((const std::tuple<Types...>&&)(value));
    }

} // namespace std
