
namespace posu {

    namespace ranges {

        template<typename... Views> // clang-format off
            requires(std::ranges::view<Views>&&...)
        [[nodiscard]] auto zip_view<Views...>::begin() -> iterator // clang-format on
        {
        }

        template<typename... Views> // clang-format off
            requires(std::ranges::view<Views>&&...)
        [[nodiscard]] auto zip_view<Views...>::end() -> iterator
            requires(std::ranges::common_range<Views>&&...) // clang-format on
        {
        }

        template<typename... Views> // clang-format off
            requires(std::ranges::view<Views>&&...)
        [[nodiscard]] auto zip_view<Views...>::end() -> sentinel // clang-format on
        {
        }

    } // namespace ranges

} // namespace posu
