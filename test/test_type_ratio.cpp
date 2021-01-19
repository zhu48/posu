#include "posu/type_ratio.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEMPLATE_TEST_CASE(
    "multiplication",
    "[ratio][multiply]",
    (std::tuple<posu::type_ratio<>, posu::type_ratio<>, posu::type_ratio<>>))
{
    using lhs     = std::tuple_element_t<0, TestType>;
    using rhs     = std::tuple_element_t<1, TestType>;
    using product = std::tuple_element_t<2, TestType>;

    static_assert(std::same_as<product, posu::ratio_multiply<lhs, rhs>>);
}
