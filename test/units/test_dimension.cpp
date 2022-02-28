#include "posu/units/dimension.hpp"

#define CATCH_CONFIG_PREFIX_ALL

#include <catch2/catch.hpp>

namespace {

    namespace units = posu::units;

}

CATCH_TEST_CASE("dimension definition results in operable tag types", "[units][tag][dimension]")
{
    CATCH_SECTION("make_dimension creates a dimension")
    {
        struct test_dim : public units::make_dimension<test_dim, "test dimension"> {
        };

        CATCH_STATIC_REQUIRE(units::dimension<test_dim>);
    }
}
