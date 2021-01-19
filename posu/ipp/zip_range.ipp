
namespace posu {

    namespace ranges {

        template<typename... Views>
            requires(std::ranges::view<Views>&&...)
        [[nodiscard]] auto zip_view<Views...>::begin() -> iterator {}

        template<typename... Views>
            requires(std::ranges::view<Views>&&...)
        [[nodiscard]] auto zip_view<Views...>::end() -> iterator
            requires(std::ranges::common_range<Views>&&...)
        {
        }

        template<typename... Views>
            requires(std::ranges::view<Views>&&...)
        [[nodiscard]] auto zip_view<Views...>::end() -> sentinel {}

    } // namespace ranges

} // namespace posu
