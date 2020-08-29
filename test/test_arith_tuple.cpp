#include "posu/vmath.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE("construction invariants", "[construct]") {
    SECTION("construction from scaler") {
        using type_0      = std::uint16_t;
        using type_1      = std::int32_t;
        using type_2      = float;
        using common_type = std::common_type_t<type_0, type_1, type_2>;

        constexpr auto constant_value = common_type{22};

        const auto test_value =
            posu::vmath::arith_tuple<type_0, type_1, type_2>{constant_value};

        CHECK(std::get<0>(test_value) == constant_value);
        CHECK(std::get<1>(test_value) == constant_value);
        CHECK(std::get<2>(test_value) == constant_value);
    }
}
