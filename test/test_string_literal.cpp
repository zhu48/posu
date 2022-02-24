#include "posu/string_literal.hpp"

#define CATCH_CONFIG_PREFIX_ALL

#include <catch2/catch.hpp>

namespace {

    template<posu::basic_string_literal String>
    struct test_type {
    };

} // namespace

CATCH_TEST_CASE("use `string_literal` as NTTP")
{
    CATCH_CHECK(std::same_as<test_type<"this">, test_type<"this">>);
    CATCH_CHECK(!std::same_as<test_type<"this">, test_type<"that">>);
}
