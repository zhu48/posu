#ifndef POSU_ZIP_RANGE_HPP
#define POSU_ZIP_RANGE_HPP

#include <ranges>

namespace posu {

    namespace ranges {

        /**
         * A parallel view of multiple ranges.
         */
        template<typename... Views> // clang-format off
            requires ( std::ranges::view<Views> && ... )
        class zip_view // clang-format on
            : public std::ranges::view_interface<zip_view<Views...>> {
        public:
            class iterator;
            class sentinel;

            [[nodiscard]] auto begin() -> iterator;
            [[nodiscard]] auto end() -> iterator
                requires(std::ranges::common_range<Views>&&...);
            [[nodiscard]] auto end() -> sentinel;

        private:
            std::tuple<Views...> m_views;
        };

        namespace views {}

    } // namespace ranges

    namespace views = ranges::views;

} // namespace posu

#include "posu/ipp/zip_range.ipp"

#endif // #ifndef POSU_ZIP_RANGE_HPP
