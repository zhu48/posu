#include "posu/vmath.hpp"

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

        constexpr auto test_value =
            posu::vmath::arith_tuple<type_0, type_1, type_2>{constant_value};

        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<0>(test_value) == constant_value);
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<1>(test_value) == constant_value);
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<2>(test_value) == constant_value);
    }

    SECTION("construction from argument list")
    {
        constexpr auto constant_0 = type_0{2};
        constexpr auto constant_1 = type_1{557};
        constexpr auto constant_2 = type_2{-2.44};

        constexpr auto test_value =
            posu::vmath::arith_tuple<type_0, type_1, type_2>{constant_0, constant_1, constant_2};

        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<0>(test_value) == constant_0);
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<1>(test_value) == constant_1);
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<2>(test_value) == constant_2);
    }

    SECTION("CTAD construction from argument list")
    {
        constexpr auto constant_0 = type_0{2};
        constexpr auto constant_1 = type_1{557};
        constexpr auto constant_2 = type_2{-2.44};

        constexpr auto test_value = posu::vmath::arith_tuple{constant_0, constant_1, constant_2};

        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<0>(test_value) == constant_0);
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<1>(test_value) == constant_1);
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<2>(test_value) == constant_2);
    }

    SECTION("construction from size-value factory")
    {
        constexpr auto size           = std::size_t{3};
        constexpr auto constant_value = common_type{22};

        constexpr auto test_value = posu::vmath::make_arith_tuple<size>(constant_value);

        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<0>(test_value) == constant_value);
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<1>(test_value) == constant_value);
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<2>(test_value) == constant_value);
    }

    SECTION("construction from multi-argument factory")
    {
        constexpr auto constant_0 = type_0{2};
        constexpr auto constant_1 = type_1{557};
        constexpr auto constant_2 = type_2{-2.44};

        constexpr auto test_value =
            posu::vmath::make_arith_tuple(constant_0, constant_1, constant_2);

        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<0>(test_value) == constant_0);
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<1>(test_value) == constant_1);
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<2>(test_value) == constant_2);
    }
}

TEST_CASE("arithmetic operations", "[arithmetic]")
{
    using type_0      = std::uint16_t;
    using type_1      = std::int32_t;
    using type_2      = float;
    using common_type = std::common_type_t<type_0, type_1, type_2>;

    SECTION("scaler addition")
    {
        constexpr auto value_0 = type_0{98};
        constexpr auto value_1 = type_1{5002};
        constexpr auto value_3 = type_2{1};

        constexpr auto add_value = common_type{1};

        constexpr auto initial = posu::vmath::arith_tuple{value_0, value_1, value_3};
        constexpr auto result  = initial + add_value;

        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<0>(result) == std::get<0>(initial) + add_value);
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<1>(result) == std::get<1>(initial) + add_value);
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<2>(result) == std::get<2>(initial) + add_value);
    }

    SECTION("scaler subtraction")
    {
        constexpr auto value_0 = type_0{98};
        constexpr auto value_1 = type_1{5002};
        constexpr auto value_3 = type_2{1};

        constexpr auto sub_value = common_type{1};

        constexpr auto initial = posu::vmath::arith_tuple{value_0, value_1, value_3};
        constexpr auto result  = initial - sub_value;

        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<0>(result) == std::get<0>(initial) - sub_value);
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<1>(result) == std::get<1>(initial) - sub_value);
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<2>(result) == std::get<2>(initial) - sub_value);
    }

    SECTION("scaler multiply")
    {
        constexpr auto value_0 = type_0{98};
        constexpr auto value_1 = type_1{5002};
        constexpr auto value_3 = type_2{-0.5};

        constexpr auto mul_value = common_type{2};

        constexpr auto initial = posu::vmath::arith_tuple{value_0, value_1, value_3};
        constexpr auto result  = initial * mul_value;

        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<0>(result) == std::get<0>(initial) * mul_value);
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<1>(result) == std::get<1>(initial) * mul_value);
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<2>(result) == std::get<2>(initial) * mul_value);
    }

    SECTION("scaler divide")
    {
        constexpr auto value_0 = type_0{98};
        constexpr auto value_1 = type_1{5002};
        constexpr auto value_3 = type_2{-1};

        constexpr auto div_value = common_type{2};

        constexpr auto initial = posu::vmath::arith_tuple{value_0, value_1, value_3};
        constexpr auto result  = initial / div_value;

        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<0>(result) == std::get<0>(initial) / div_value);
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<1>(result) == std::get<1>(initial) / div_value);
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<2>(result) == std::get<2>(initial) / div_value);
    }

    SECTION("vector addition")
    {
        constexpr auto value_0_0 = type_0{98};
        constexpr auto value_0_1 = type_0{12};
        constexpr auto value_1_0 = type_1{5002};
        constexpr auto value_1_1 = type_1{33};
        constexpr auto value_2_0 = type_2{1};
        constexpr auto value_2_1 = type_2{7.8};

        constexpr auto initial   = posu::vmath::arith_tuple{value_0_0, value_1_0, value_2_0};
        constexpr auto add_value = posu::vmath::arith_tuple{value_0_1, value_1_1, value_2_1};
        constexpr auto result    = initial + add_value;

        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<0>(result) == std::get<0>(initial) + std::get<0>(add_value));
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<1>(result) == std::get<1>(initial) + std::get<1>(add_value));
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<2>(result) == std::get<2>(initial) + std::get<2>(add_value));
    }

    SECTION("vector subtraction")
    {
        constexpr auto value_0_0 = type_0{98};
        constexpr auto value_0_1 = type_0{12};
        constexpr auto value_1_0 = type_1{5002};
        constexpr auto value_1_1 = type_1{33};
        constexpr auto value_2_0 = type_2{1};
        constexpr auto value_2_1 = type_2{7.8};

        constexpr auto initial   = posu::vmath::arith_tuple{value_0_0, value_1_0, value_2_0};
        constexpr auto sub_value = posu::vmath::arith_tuple{value_0_1, value_1_1, value_2_1};
        constexpr auto result    = initial - sub_value;

        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<0>(result) == std::get<0>(initial) - std::get<0>(sub_value));
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<1>(result) == std::get<1>(initial) - std::get<1>(sub_value));
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<2>(result) == std::get<2>(initial) - std::get<2>(sub_value));
    }
}

TEST_CASE("arithmetic assignment operations", "[arithmetic][assignment]")
{
    using type_0      = std::uint16_t;
    using type_1      = std::int32_t;
    using type_2      = float;
    using common_type = std::common_type_t<type_0, type_1, type_2>;

    SECTION("scaler addition")
    {
        constexpr auto value_0 = type_0{98};
        constexpr auto value_1 = type_1{5002};
        constexpr auto value_3 = type_2{1};

        constexpr auto add_value = common_type{1};

        constexpr auto initial = posu::vmath::arith_tuple{value_0, value_1, value_3};

        auto result = initial;
        result += add_value;

        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<0>(result) == std::get<0>(initial) + add_value);
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<1>(result) == std::get<1>(initial) + add_value);
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<2>(result) == std::get<2>(initial) + add_value);
    }

    SECTION("scaler subtraction")
    {
        constexpr auto value_0 = type_0{98};
        constexpr auto value_1 = type_1{5002};
        constexpr auto value_3 = type_2{1};

        constexpr auto sub_value = common_type{1};

        constexpr auto initial = posu::vmath::arith_tuple{value_0, value_1, value_3};

        auto result = initial;
        result -= sub_value;

        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<0>(result) == std::get<0>(initial) - sub_value);
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<1>(result) == std::get<1>(initial) - sub_value);
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<2>(result) == std::get<2>(initial) - sub_value);
    }

    SECTION("scaler multiply")
    {
        constexpr auto value_0 = type_0{98};
        constexpr auto value_1 = type_1{5002};
        constexpr auto value_3 = type_2{-0.5};

        constexpr auto mul_value = common_type{2};

        constexpr auto initial = posu::vmath::arith_tuple{value_0, value_1, value_3};

        auto result = initial;
        result *= mul_value;

        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<0>(result) == std::get<0>(initial) * mul_value);
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<1>(result) == std::get<1>(initial) * mul_value);
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<2>(result) == std::get<2>(initial) * mul_value);
    }

    SECTION("scaler divide")
    {
        constexpr auto value_0 = type_0{98};
        constexpr auto value_1 = type_1{5002};
        constexpr auto value_3 = type_2{-1};

        constexpr auto div_value = common_type{2};

        constexpr auto initial = posu::vmath::arith_tuple{value_0, value_1, value_3};

        auto result = initial;
        result /= div_value;

        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<0>(result) == std::get<0>(initial) / div_value);
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<1>(result) == std::get<1>(initial) / div_value);
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<2>(result) == std::get<2>(initial) / div_value);
    }

    SECTION("vector addition")
    {
        constexpr auto value_0_0 = type_0{98};
        constexpr auto value_0_1 = type_0{12};
        constexpr auto value_1_0 = type_1{5002};
        constexpr auto value_1_1 = type_1{33};
        constexpr auto value_2_0 = type_2{1};
        constexpr auto value_2_1 = type_2{7.8};

        constexpr auto initial   = posu::vmath::arith_tuple{value_0_0, value_1_0, value_2_0};
        constexpr auto add_value = posu::vmath::arith_tuple{value_0_1, value_1_1, value_2_1};

        auto result = initial;
        result += add_value;

        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<0>(result) == std::get<0>(initial) + std::get<0>(add_value));
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<1>(result) == std::get<1>(initial) + std::get<1>(add_value));
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<2>(result) == std::get<2>(initial) + std::get<2>(add_value));
    }

    SECTION("vector subtraction")
    {
        constexpr auto value_0_0 = type_0{98};
        constexpr auto value_0_1 = type_0{12};
        constexpr auto value_1_0 = type_1{5002};
        constexpr auto value_1_1 = type_1{33};
        constexpr auto value_2_0 = type_2{1};
        constexpr auto value_2_1 = type_2{7.8};

        constexpr auto initial   = posu::vmath::arith_tuple{value_0_0, value_1_0, value_2_0};
        constexpr auto sub_value = posu::vmath::arith_tuple{value_0_1, value_1_1, value_2_1};

        auto result = initial;
        result -= sub_value;

        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<0>(result) == std::get<0>(initial) - std::get<0>(sub_value));
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<1>(result) == std::get<1>(initial) - std::get<1>(sub_value));
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg): CHECK macro
        CHECK(std::get<2>(result) == std::get<2>(initial) - std::get<2>(sub_value));
    }
}
