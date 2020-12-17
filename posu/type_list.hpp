#ifndef POSU_TYPE_LIST_HPP
#define POSU_TYPE_LIST_HPP

#include <tuple>

namespace posu {

    template<typename... Types>
    struct type_list {
    public:
        template<std::size_t I>
        using at = std::tuple_element_t<I, std::tuple<Types...>>;

        using size  = std::integral_constant<std::size_t, sizeof...(Types)>;
        using empty = std::bool_constant<size::value == 0>;

        using front = at<0>;
        using back  = at<size::value - 1>;
    };

} // namespace posu

#endif // #ifndef POSU_TYPE_LIST_HPP
