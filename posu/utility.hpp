#ifndef POSU_UTILITY_HPP
#define POSU_UTILITY_HPP

namespace posu {

    template<typename F, typename... Tuple>
    constexpr void for_each(F&& f, Tuple&&... tuple);

    template<typename T, typename F, typename... Tuple> // clang-format off
        requires(
            std::less_equal{}(
                std::tuple_size_v<T>,
                std::tuple_size_v<std::remove_cvref_t<Tuple>>
            ) && ...
        )
    [[nodiscard]] constexpr auto make_from_for_each( // clang-format on
            F&& f,
            Tuple&&... tuple) -> T;

} // namespace posu

#include "posu/ipp/utility.ipp"

#endif // #ifndef POSU_UTILITY_HPP
