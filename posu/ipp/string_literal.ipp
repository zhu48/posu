
template<typename CharT, std::size_t N>
constexpr posu::basic_string_literal<CharT, N>::basic_string_literal(const CharT (&arr)[N]) noexcept
    : basic_string_literal{arr, std::make_index_sequence<N>{}}
{
}

template<typename CharT, std::size_t N>
template<std::size_t... I>
constexpr posu::basic_string_literal<CharT, N>::basic_string_literal(
    const CharT (&arr)[N],
    std::index_sequence<I...> /*unused*/) noexcept
    : basic_string_literal{arr[I]...}
{
}

template<typename CharT, std::size_t N>
template<typename... C>
constexpr posu::basic_string_literal<CharT, N>::basic_string_literal(C... c) noexcept : value{c...}
{
}
