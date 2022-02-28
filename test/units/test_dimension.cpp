#include "posu/units/dimension.hpp"

#define CATCH_CONFIG_PREFIX_ALL

#include <catch2/catch.hpp>

namespace {

    namespace units = posu::units;
    namespace meta  = posu::meta;

} // namespace

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
            struct num0 : public units::make_dimension<num0, "num0"> {
            };
            struct num1 : public units::make_dimension<num1, "num1"> {
            };

            CATCH_SECTION("multiplication between base dimensions")
            {
                using prod_t        = units::dimension_multiply<num0, num1>;
                constexpr auto prod = prod_t{};

                CATCH_STATIC_REQUIRE(prod == meta::ratio<meta::list<num0, num1>>{});
                CATCH_STATIC_REQUIRE(
                    units::dimension_multiply<prod_t, num1>{} ==
                    meta::ratio<meta::list<num0, num1, num1>>{});
            }

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
