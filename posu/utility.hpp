#ifndef POSU_UTILITY_HPP
#define POSU_UTILITY_HPP

namespace posu {

    template<typename F, typename... Tuple>
    constexpr void for_each(F&& f, Tuple&&... tuple);

} // namespace posu

#include "posu/ipp/utility.ipp"

#endif // #ifndef POSU_UTILITY_HPP
