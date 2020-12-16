#ifndef POSU_TYPE_LIST_HPP
#define POSU_TYPE_LIST_HPP

#include <tuple>

namespace posu {

    template<typename... Types>
    struct type_list {
    public:
        template<std::size_t I>
        using at = std::tuple_element_t<I, std::tuple<Types...>>;
    };

} // namespace posu

#endif // #ifndef POSU_TYPE_LIST_HPP
