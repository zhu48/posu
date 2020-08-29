#include "posu/vmath.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE("construction invariants", "[construct]")
{
    using type_0      = std::uint16_t;
    using type_1      = std::int32_t;
    using type_2      = float;
    using common_type = std::common_type_t<type_0, type_1, type_2>;

    SECTION("construction from scaler")
    {
        constexpr auto constant_value = common_type{22};

        const auto test_value =
            posu::vmath::arith_tuple<type_0, type_1, type_2>{constant_value};

        CHECK(std::get<0>(test_value) == constant_value);
        CHECK(std::get<1>(test_value) == constant_value);
        CHECK(std::get<2>(test_value) == constant_value);
    }

    SECTION("construction from argument list")
    {
        constexpr auto constant_0 = type_0{2};
        constexpr auto constant_1 = type_1{557};
        constexpr auto constant_2 = type_2{-2.44};

        const auto test_value =
            posu::vmath::arith_tuple<type_0, type_1, type_2>{
                constant_0, constant_1, constant_2};

        CHECK(std::get<0>(test_value) == constant_0);
        CHECK(std::get<1>(test_value) == constant_1);
        CHECK(std::get<2>(test_value) == constant_2);
    }

    SECTION("CTAD construction from argument list")
    {
        constexpr auto constant_0 = type_0{2};
        constexpr auto constant_1 = type_1{557};
        constexpr auto constant_2 = type_2{-2.44};

        const auto test_value =
            posu::vmath::arith_tuple{constant_0, constant_1, constant_2};

        CHECK(std::get<0>(test_value) == constant_0);
        CHECK(std::get<1>(test_value) == constant_1);
        CHECK(std::get<2>(test_value) == constant_2);
    }

    SECTION("construction from size-value factory")
    {
        constexpr auto size           = std::size_t{3};
        constexpr auto constant_value = common_type{22};

        const auto test_value =
            posu::vmath::make_arith_tuple<size>(constant_value);

        CHECK(std::get<0>(test_value) == constant_value);
        CHECK(std::get<1>(test_value) == constant_value);
        CHECK(std::get<2>(test_value) == constant_value);
    }

    SECTION("construction from multi-argument factory")
    {
        constexpr auto constant_0 = type_0{2};
        constexpr auto constant_1 = type_1{557};
        constexpr auto constant_2 = type_2{-2.44};

        const auto test_value =
            posu::vmath::make_arith_tuple(constant_0, constant_1, constant_2);

        CHECK(std::get<0>(test_value) == constant_0);
        CHECK(std::get<1>(test_value) == constant_1);
        CHECK(std::get<2>(test_value) == constant_2);
    }
}
