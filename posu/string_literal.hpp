#ifndef POSU_STRING_LITERAL_HPP
#define POSU_STRING_LITERAL_HPP

#include <type_traits>
#include <utility>

namespace posu {
    template<typename CharT, std::size_t N>
    struct basic_string_literal {
    private:
        using storage_type = CharT[N];

    public:
        using value_type      = CharT;
        using size_type       = std::size_t;
        using const_reference = const value_type&;
        using reference       = const_reference;
        using const_pointer   = const value_type*;
        using pointer         = const_pointer;
        using iterator        = pointer;
        using const_iterator  = const_pointer;

        constexpr basic_string_literal() noexcept requires(N == 0) = default;
        constexpr basic_string_literal(const CharT (&arr)[N]) noexcept;

        [[nodiscard]] constexpr operator const storage_type&() const noexcept { return value; }

        [[nodiscard]] constexpr auto data() const noexcept -> const_pointer { return value; }
        [[nodiscard]] constexpr auto c_str() const noexcept -> const_pointer { return value; }

        [[nodiscard]] constexpr auto size() const noexcept -> size_type { return N; }

        [[nodiscard]] constexpr auto begin() const noexcept -> const_iterator { return data(); }
        [[nodiscard]] constexpr auto cbegin() const noexcept -> const_iterator { return data(); }
        [[nodiscard]] constexpr auto end() const noexcept -> const_iterator { return data() + N; }
        [[nodiscard]] constexpr auto cend() const noexcept -> const_iterator { return data() + N; }

        const storage_type value;

    private:
        template<std::size_t... I>
        constexpr basic_string_literal(
            const CharT (&arr)[N],
            std::index_sequence<I...> /*unused*/) noexcept;
        template<typename... C>
        constexpr basic_string_literal(C... c) noexcept;
    };

    template<typename CharT, std::size_t N>
    basic_string_literal(const CharT (&)[N]) -> basic_string_literal<std::remove_cv_t<CharT>, N>;

    template<std::size_t N>
    using string_literal = basic_string_literal<char, N>;
    template<std::size_t N>
    using wstring_literal = basic_string_literal<wchar_t, N>;
    template<std::size_t N>
    using u8string_literal = basic_string_literal<char8_t, N>;
    template<std::size_t N>
    using u16string_literal = basic_string_literal<char16_t, N>;
    template<std::size_t N>
    using u32string_literal = basic_string_literal<char32_t, N>;

} // namespace posu

#include "posu/ipp/string_literal.ipp"

#endif // #ifndef POSU_STRING_LITERAL_HPP
