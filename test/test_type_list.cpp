#include "posu/type_list.hpp"

#include <concepts>

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE("initialization", "[construct]")
{
    using list = posu::type_list<int, float, double>;

    static_assert(std::same_as<list::at<0>, int>, "the first element must be int");
    static_assert(std::same_as<list::at<1>, float>, "the second element must be float");
    static_assert(std::same_as<list::at<2>, double>, "the third element must be double");
}
