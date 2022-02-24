#ifndef POSU_STRING_LITERAL_HPP
#define POSU_STRING_LITERAL_HPP

#include <type_traits>

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

        static constexpr auto npos = static_cast<size_type>(-1);

        constexpr basic_string_literal() noexcept requires(N == 0) = default;

        [[nodiscard]] constexpr operator const storage_type&() const noexcept { return value; }

        [[nodiscard]] constexpr auto data() const noexcept -> const_pointer { return value; }
        [[nodiscard]] constexpr auto c_str() const noexcept -> const_pointer { return value; }

        [[nodiscard]] constexpr auto size() const noexcept -> size_type { return N; }

        [[nodiscard]] constexpr auto begin() const noexcept -> const_iterator { return data(); }
        [[nodiscard]] constexpr auto cbegin() const noexcept -> const_iterator { return data(); }
        [[nodiscard]] constexpr auto end() const noexcept -> const_iterator { return data() + N; }
        [[nodiscard]] constexpr auto cend() const noexcept -> const_iterator { return data() + N; }

        const storage_type value;
    };

    template<typename CharT, std::size_t N>
    basic_string_literal(const CharT (&)[N]) -> basic_string_literal<std::remove_cv_t<CharT>, N>;

} // namespace posu

#endif // #ifndef POSU_STRING_LITERAL_HPP
