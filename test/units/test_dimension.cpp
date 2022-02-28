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

    CATCH_SECTION("dimensional analysis")
    {
        CATCH_SECTION("multiplication")
        {
            CATCH_SECTION("multiplication between base dimensions") {}

            CATCH_SECTION("multiplication between derived dimensions") {}

            CATCH_SECTION("multiplication between base and derived dimensions") {}
        }

        CATCH_SECTION("division")
        {
            CATCH_SECTION("division between base dimensions") {}

            CATCH_SECTION("division between derived dimensions") {}

            CATCH_SECTION("division between base and derived dimensions") {}
        }
    }
}
