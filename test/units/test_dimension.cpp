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
        struct num0 : public units::make_dimension<num0, "num0"> {
        };
        struct num1 : public units::make_dimension<num1, "num1"> {
        };
        struct den0 : public units::make_dimension<den0, "den0"> {
        };
        struct den1 : public units::make_dimension<den1, "den1"> {
        };

        CATCH_SECTION("multiplication")
        {
            CATCH_SECTION("multiplication between base dimensions")
            {
                using prod_t        = units::dimension_multiply<num0, num1>;
                constexpr auto prod = prod_t{};

                CATCH_STATIC_REQUIRE(prod == meta::ratio<meta::list<num0, num1>>{});
                CATCH_STATIC_REQUIRE(prod == meta::ratio<meta::list<num1, num0>>{});
                CATCH_STATIC_REQUIRE(
                    units::dimension_multiply<prod_t, num1>{} ==
                    meta::ratio<meta::list<num0, num1, num1>>{});
            }

            CATCH_SECTION("multiplication between derived dimensions")
            {
                CATCH_SECTION("dimensionless result")
                {
                    CATCH_STATIC_REQUIRE(std::same_as<
                                         units::dimension_multiply<
                                             meta::ratio<meta::list<num0>>,
                                             meta::ratio<meta::list<>, meta::list<num0>>>,
                                         units::dimensionless>);
                    CATCH_STATIC_REQUIRE(std::same_as<
                                         units::dimension_multiply<
                                             meta::ratio<meta::list<num1, num0>>,
                                             meta::ratio<meta::list<>, meta::list<num0, num1>>>,
                                         units::dimensionless>);
                    CATCH_STATIC_REQUIRE(std::same_as<
                                         units::dimension_multiply<
                                             meta::ratio<meta::list<>, meta::list<num0, num1>>,
                                             meta::ratio<meta::list<num1, num0>>>,
                                         units::dimensionless>);
                    CATCH_STATIC_REQUIRE(std::same_as<
                                         units::dimension_multiply<
                                             meta::ratio<meta::list<num0>, meta::list<num1>>,
                                             meta::ratio<meta::list<num1>, meta::list<num0>>>,
                                         units::dimensionless>);
                }

                CATCH_SECTION("base dimension result")
                {
                    CATCH_STATIC_REQUIRE(std::same_as<
                                         units::dimension_multiply<
                                             meta::ratio<meta::list<num0>>,
                                             meta::ratio<meta::list<num1>, meta::list<num0>>>,
                                         num1>);
                    CATCH_STATIC_REQUIRE(std::same_as<
                                         units::dimension_multiply<
                                             meta::ratio<meta::list<num1, num0>>,
                                             meta::ratio<meta::list<>, meta::list<num1>>>,
                                         num0>);
                    CATCH_STATIC_REQUIRE(std::same_as<
                                         units::dimension_multiply<
                                             meta::ratio<meta::list<>, meta::list<num0>>,
                                             meta::ratio<meta::list<num1, num0>>>,
                                         num1>);
                    CATCH_STATIC_REQUIRE(std::same_as<
                                         units::dimension_multiply<
                                             meta::ratio<meta::list<num0>, meta::list<num1>>,
                                             meta::ratio<meta::list<num1>>>,
                                         num0>);
                }

                CATCH_SECTION("derived dimension result")
                {
                    CATCH_STATIC_REQUIRE(
                        units::dimension_multiply<
                            meta::ratio<meta::list<num0>, meta::list<den1>>,
                            meta::ratio<meta::list<den1>, meta::list<den0>>>{} ==
                        meta::ratio<meta::list<num0>, meta::list<den0>>{});
                    CATCH_STATIC_REQUIRE(
                        units::dimension_multiply<
                            meta::ratio<meta::list<num0>, meta::list<den0, den1>>,
                            meta::ratio<meta::list<den1>, meta::list<num0>>>{} ==
                        meta::ratio<meta::list<>, meta::list<den0>>{});
                    CATCH_STATIC_REQUIRE(
                        units::dimension_multiply<
                            meta::ratio<meta::list<den0>, meta::list<den1>>,
                            meta::ratio<meta::list<num1, num0>, meta::list<den0>>>{} ==
                        meta::ratio<meta::list<num0, num1>, meta::list<den1>>{});
                    CATCH_STATIC_REQUIRE(
                        units::dimension_multiply<
                            meta::ratio<meta::list<num1, num0, den1>, meta::list<den1, den0>>,
                            meta::ratio<meta::list<num0>, meta::list<num0, num1, den1>>>{} ==
                        meta::ratio<meta::list<num0>, meta::list<den0, den1>>{});
                }
            }

            CATCH_SECTION("multiplication between base and derived dimensions")
            {
                CATCH_SECTION("dimensionless result")
                {
                    CATCH_STATIC_REQUIRE(std::same_as<
                                         units::dimension_multiply<
                                             num0,
                                             meta::ratio<meta::list<>, meta::list<num0>>>,
                                         units::dimensionless>);
                    CATCH_STATIC_REQUIRE(std::same_as<
                                         units::dimension_multiply<
                                             meta::ratio<meta::list<>, meta::list<num0>>,
                                             num0>,
                                         units::dimensionless>);
                }

                CATCH_SECTION("base dimension result")
                {
                    CATCH_STATIC_REQUIRE(std::same_as<
                                         units::dimension_multiply<
                                             num1,
                                             meta::ratio<meta::list<num0>, meta::list<num1>>>,
                                         num0>);
                    CATCH_STATIC_REQUIRE(std::same_as<
                                         units::dimension_multiply<
                                             meta::ratio<meta::list<num0>, meta::list<num1>>,
                                             num1>,
                                         num0>);
                }

                CATCH_SECTION("derived dimension result")
                {
                    CATCH_STATIC_REQUIRE(
                        units::dimension_multiply<
                            num0,
                            meta::ratio<meta::list<>, meta::list<num0, den0>>>{} ==
                        meta::ratio<meta::list<>, meta::list<den0>>{});
                    CATCH_STATIC_REQUIRE(
                        units::dimension_multiply<
                            meta::ratio<meta::list<>, meta::list<num0, den0>>,
                            num0>{} == meta::ratio<meta::list<>, meta::list<den0>>{});
                    CATCH_STATIC_REQUIRE(
                        units::dimension_multiply<
                            num1,
                            meta::ratio<meta::list<>, meta::list<den0, num1, den1>>>{} ==
                        meta::ratio<meta::list<>, meta::list<den1, den0>>{});
                    CATCH_STATIC_REQUIRE(
                        units::dimension_multiply<
                            meta::ratio<meta::list<>, meta::list<den0, num1, den1>>,
                            num1>{} == meta::ratio<meta::list<>, meta::list<den1, den0>>{});
                    CATCH_STATIC_REQUIRE(
                        units::dimension_multiply<
                            num0,
                            meta::ratio<meta::list<>, meta::list<den1>>>{} ==
                        meta::ratio<meta::list<num0>, meta::list<den1>>{});
                    CATCH_STATIC_REQUIRE(
                        units::dimension_multiply<
                            meta::ratio<meta::list<>, meta::list<den1>>,
                            num0>{} == meta::ratio<meta::list<num0>, meta::list<den1>>{});
                    CATCH_STATIC_REQUIRE(
                        units::dimension_multiply<
                            num1,
                            meta::ratio<meta::list<num0>, meta::list<den1, den0, num1>>>{} ==
                        meta::ratio<meta::list<num0>, meta::list<den0, den1>>{});
                    CATCH_STATIC_REQUIRE(
                        units::dimension_multiply<
                            meta::ratio<meta::list<num0>, meta::list<den1, den0, num1>>,
                            num1>{} == meta::ratio<meta::list<num0>, meta::list<den0, den1>>{});
                    CATCH_STATIC_REQUIRE(
                        units::dimension_multiply<
                            num0,
                            meta::ratio<meta::list<num1, num0>, meta::list<num0>>>{} ==
                        meta::ratio<meta::list<num1, num0>>{});
                    CATCH_STATIC_REQUIRE(
                        units::dimension_multiply<
                            meta::ratio<meta::list<num1, num0>, meta::list<num0>>,
                            num0>{} == meta::ratio<meta::list<num1, num0>>{});
                    CATCH_STATIC_REQUIRE(
                        units::dimension_multiply<
                            num1,
                            meta::ratio<meta::list<num0>, meta::list<den0>>>{} ==
                        meta::ratio<meta::list<num0, num1>, meta::list<den0>>{});
                    CATCH_STATIC_REQUIRE(
                        units::dimension_multiply<
                            meta::ratio<meta::list<num0>, meta::list<den0>>,
                            num1>{} == meta::ratio<meta::list<num0, num1>, meta::list<den0>>{});
                    CATCH_STATIC_REQUIRE(
                        units::dimension_multiply<
                            num0,
                            meta::ratio<meta::list<num1>, meta::list<den1, den0>>>{} ==
                        meta::ratio<meta::list<num0, num1>, meta::list<den0, den1>>{});
                    CATCH_STATIC_REQUIRE(
                        units::dimension_multiply<
                            meta::ratio<meta::list<num1>, meta::list<den1, den0>>,
                            num0>{} ==
                        meta::ratio<meta::list<num0, num1>, meta::list<den0, den1>>{});
                }
            }
        }

        CATCH_SECTION("division")
        {
            CATCH_SECTION("division between base dimensions")
            {
                CATCH_SECTION("dimensionless result")
                {
                    CATCH_STATIC_REQUIRE(
                        std::same_as<units::dimension_divide<num0, num0>, units::dimensionless>);
                }

                CATCH_SECTION("derived dimension result")
                {
                    CATCH_STATIC_REQUIRE(std::same_as<
                                         units::dimension_divide<num0, den0>,
                                         meta::ratio<meta::list<num0>, meta::list<den0>>>);
                }
            }

            CATCH_SECTION("division between derived dimensions")
            {
                CATCH_SECTION("dimensionless result")
                {
                    CATCH_STATIC_REQUIRE(std::same_as<
                                         units::dimension_divide<
                                             meta::ratio<meta::list<num0, num1>, meta::list<>>,
                                             meta::ratio<meta::list<num1, num0>, meta::list<>>>,
                                         units::dimensionless>);
                    CATCH_STATIC_REQUIRE(std::same_as<
                                         units::dimension_divide<
                                             meta::ratio<meta::list<>, meta::list<den0>>,
                                             meta::ratio<meta::list<>, meta::list<den0>>>,
                                         units::dimensionless>);
                    CATCH_STATIC_REQUIRE(std::same_as<
                                         units::dimension_divide<
                                             meta::ratio<meta::list<num0>, meta::list<den0>>,
                                             meta::ratio<meta::list<num0>, meta::list<den0>>>,
                                         units::dimensionless>);
                    CATCH_STATIC_REQUIRE(std::same_as<
                                         units::dimension_divide<
                                             meta::ratio<meta::list<num1, num0>, meta::list<den0>>,
                                             meta::ratio<meta::list<num0, num1>, meta::list<den0>>>,
                                         units::dimensionless>);
                    CATCH_STATIC_REQUIRE(
                        std::same_as<
                            units::dimension_divide<
                                meta::ratio<meta::list<num1, num0>, meta::list<den0, den1>>,
                                meta::ratio<meta::list<num0, num1>, meta::list<den0, den1>>>,
                            units::dimensionless>);
                }

                CATCH_SECTION("base dimension result")
                {
                    CATCH_STATIC_REQUIRE(
                        std::same_as<
                            units::dimension_divide<
                                meta::ratio<meta::list<num0, num0, num1>, meta::list<>>,
                                meta::ratio<meta::list<num1, num0>, meta::list<>>>,
                            num0>);
                    CATCH_STATIC_REQUIRE(std::same_as<
                                         units::dimension_divide<
                                             meta::ratio<meta::list<num1>, meta::list<den0>>,
                                             meta::ratio<meta::list<>, meta::list<den0>>>,
                                         num1>);
                    CATCH_STATIC_REQUIRE(std::same_as<
                                         units::dimension_divide<
                                             meta::ratio<meta::list<den0, num0>, meta::list<den0>>,
                                             meta::ratio<meta::list<num0>, meta::list<den0>>>,
                                         den0>);
                    CATCH_STATIC_REQUIRE(
                        std::same_as<
                            units::dimension_divide<
                                meta::ratio<meta::list<den1, num1, num0>, meta::list<den0>>,
                                meta::ratio<meta::list<num0, num1>, meta::list<den0>>>,
                            den1>);
                    CATCH_STATIC_REQUIRE(
                        std::same_as<
                            units::dimension_divide<
                                meta::ratio<meta::list<num0, num1, num0>, meta::list<den0, den1>>,
                                meta::ratio<meta::list<num0, num1>, meta::list<den0, den1>>>,
                            num0>);
                }

                CATCH_SECTION("derived dimension result")
                {
                    CATCH_STATIC_REQUIRE(
                        units::dimension_divide<
                            meta::ratio<meta::list<num1>, meta::list<den0>>,
                            meta::ratio<meta::list<>, meta::list<num0, den0>>>{} ==
                        meta::ratio<meta::list<num0, num1>, meta::list<>>{});
                    CATCH_STATIC_REQUIRE(
                        units::dimension_divide<
                            meta::ratio<meta::list<>, meta::list<den1>>,
                            meta::ratio<meta::list<den0>, meta::list<den1>>>{} ==
                        meta::ratio<meta::list<>, meta::list<den0>>{});
                    CATCH_STATIC_REQUIRE(
                        units::dimension_divide<
                            meta::ratio<meta::list<>, meta::list<den0>>,
                            meta::ratio<meta::list<>, meta::list<num0>>>{} ==
                        meta::ratio<meta::list<num0>, meta::list<den0>>{});
                    CATCH_STATIC_REQUIRE(
                        units::dimension_divide<
                            meta::ratio<meta::list<num1>, meta::list<den0>>,
                            meta::ratio<meta::list<>, meta::list<num0>>>{} ==
                        meta::ratio<meta::list<num0, num1>, meta::list<den0>>{});
                    CATCH_STATIC_REQUIRE(
                        units::dimension_divide<
                            meta::ratio<meta::list<num0, num1>, meta::list<den0, den1>>,
                            meta::ratio<meta::list<num1, num0>, meta::list<>>>{} ==
                        meta::ratio<meta::list<>, meta::list<den0, den1>>{});
                    CATCH_STATIC_REQUIRE(
                        units::dimension_divide<
                            meta::ratio<meta::list<>, meta::list<den1>>,
                            meta::ratio<meta::list<den0>, meta::list<num0>>>{} ==
                        meta::ratio<meta::list<num0>, meta::list<den0, den1>>{});
                    CATCH_STATIC_REQUIRE(
                        units::dimension_divide<
                            meta::ratio<meta::list<>, meta::list<den1, den0>>,
                            meta::ratio<meta::list<>, meta::list<num0, num1>>>{} ==
                        meta::ratio<meta::list<num0, num1>, meta::list<den0, den1>>{});
                }
            }

            CATCH_SECTION("division between base and derived dimensions")
            {
                CATCH_SECTION("base dimension result")
                {
                    CATCH_STATIC_REQUIRE(std::same_as<
                                         units::dimension_divide<
                                             num0,
                                             meta::ratio<meta::list<num0>, meta::list<num1>>>,
                                         num1>);
                    CATCH_STATIC_REQUIRE(
                        std::same_as<
                            units::dimension_divide<meta::ratio<meta::list<num1, num1>>, num1>,
                            num1>);
                }

                CATCH_SECTION("derived dimension result")
                {
                    CATCH_STATIC_REQUIRE(
                        units::
                            dimension_divide<num1, meta::ratio<meta::list<>, meta::list<num0>>>{} ==
                        meta::ratio<meta::list<num0, num1>, meta::list<>>{});
                    CATCH_STATIC_REQUIRE(
                        units::
                            dimension_divide<meta::ratio<meta::list<num1, den0, num0>>, den0>{} ==
                        meta::ratio<meta::list<num0, num1>, meta::list<>>{});
                    CATCH_STATIC_REQUIRE(
                        units::dimension_divide<
                            num1,
                            meta::ratio<meta::list<den0>, meta::list<num0>>>{} ==
                        meta::ratio<meta::list<num0, num1>, meta::list<den0>>{});
                    CATCH_STATIC_REQUIRE(
                        units::dimension_divide<
                            meta::ratio<meta::list<num0, num1, num1>, meta::list<den0>>,
                            num1>{} == meta::ratio<meta::list<num0, num1>, meta::list<den0>>{});
                    CATCH_STATIC_REQUIRE(
                        units::dimension_divide<
                            num1,
                            meta::ratio<meta::list<num1, den1, den0>, meta::list<>>>{} ==
                        meta::ratio<meta::list<>, meta::list<den0, den1>>{});
                    CATCH_STATIC_REQUIRE(
                        units::dimension_divide<
                            meta::ratio<meta::list<num1>, meta::list<den0, den1>>,
                            num1>{} == meta::ratio<meta::list<>, meta::list<den0, den1>>{});
                    CATCH_STATIC_REQUIRE(
                        units::dimension_divide<num0, meta::ratio<meta::list<den0, den1>>>{} ==
                        meta::ratio<meta::list<num0>, meta::list<den0, den1>>{});
                    CATCH_STATIC_REQUIRE(
                        units::dimension_divide<
                            meta::ratio<meta::list<num0>, meta::list<den1>>,
                            den0>{} == meta::ratio<meta::list<num0>, meta::list<den0, den1>>{});
                    CATCH_STATIC_REQUIRE(
                        units::dimension_divide<
                            num0,
                            meta::ratio<meta::list<den0, den1>, meta::list<num1>>>{} ==
                        meta::ratio<meta::list<num0, num1>, meta::list<den0, den1>>{});
                    CATCH_STATIC_REQUIRE(
                        units::dimension_divide<
                            meta::ratio<meta::list<num0, num1>, meta::list<den1>>,
                            den0>{} ==
                        meta::ratio<meta::list<num0, num1>, meta::list<den0, den1>>{});
                }
            }
        }
    }
}
