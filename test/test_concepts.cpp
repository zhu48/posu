#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "posu/concepts.hpp"

TEST_CASE("Standard integral constant values", "[integra_constant]")
{
    static_assert(posu::integral_constant<std::true_type>);
}
