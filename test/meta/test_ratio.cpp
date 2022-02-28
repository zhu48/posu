#include "posu/meta/ratio.hpp"

#include <catch2/catch.hpp>

namespace {

    namespace meta = posu::meta;

}

TEMPLATE_TEST_CASE(
    "automatic reduction",
    "[ratio][reduce]",
    (std::tuple<meta::ratio<meta::list<int>, meta::list<int>>, meta::ratio<>>),
    (std::tuple<
        meta::ratio<meta::list<int, double>, meta::list<int>>,
        meta::ratio<meta::list<double>>>),
    (std::tuple<
        meta::ratio<meta::list<double, int>, meta::list<int>>,
        meta::ratio<meta::list<double>>>),
    (std::tuple<
        meta::ratio<meta::list<int>, meta::list<int, double>>,
        meta::ratio<meta::list<>, meta::list<double>>>),
    (std::tuple<
        meta::ratio<meta::list<int>, meta::list<double, int>>,
        meta::ratio<meta::list<>, meta::list<double>>>))
{
    using original_t = std::tuple_element_t<0, TestType>;
    using reduced_t  = std::tuple_element_t<1, TestType>;

    STATIC_REQUIRE(!std::same_as<original_t, reduced_t>);
    STATIC_REQUIRE(std::same_as<typename original_t::type, reduced_t>);
    STATIC_REQUIRE(std::same_as<decltype(original_t::num), decltype(reduced_t::num)>);
    STATIC_REQUIRE(std::same_as<decltype(original_t::den), decltype(reduced_t::den)>);

    constexpr auto original = original_t{};
    constexpr auto reduced  = reduced_t{};

    STATIC_REQUIRE(original == reduced);
    STATIC_REQUIRE(original.num == reduced.num);
    STATIC_REQUIRE(original.den == reduced.den);
}

TEMPLATE_TEST_CASE(
    "multiplication",
    "[ratio][multiply]",
    (std::tuple<meta::ratio<>, meta::ratio<>, meta::ratio<>>),
    (std::tuple<meta::ratio<meta::list<int>>, meta::ratio<>, meta::ratio<meta::list<int>>>),
    (std::tuple<meta::ratio<>, meta::ratio<meta::list<int>>, meta::ratio<meta::list<int>>>),
    (std::tuple<
        meta::ratio<meta::list<>, meta::list<int>>,
        meta::ratio<>,
        meta::ratio<meta::list<>, meta::list<int>>>),
    (std::tuple<
        meta::ratio<>,
        meta::ratio<meta::list<>, meta::list<int>>,
        meta::ratio<meta::list<>, meta::list<int>>>),
    (std::tuple<
        meta::ratio<meta::list<int>, meta::list<double>>,
        meta::ratio<meta::list<int>, meta::list<double>>,
        meta::ratio<meta::list<int, int>, meta::list<double, double>>>),
    (std::tuple<
        meta::ratio<meta::list<int>, meta::list<double>>,
        meta::ratio<meta::list<double>, meta::list<int>>,
        meta::ratio<>>))
{
    constexpr auto lhs     = std::tuple_element_t<0, TestType>{};
    constexpr auto rhs     = std::tuple_element_t<1, TestType>{};
    constexpr auto product = std::tuple_element_t<2, TestType>{};

    static_assert(product == lhs * rhs);
}

TEMPLATE_TEST_CASE(
    "division",
    "[ratio][divide]",
    (std::tuple<meta::ratio<>, meta::ratio<>, meta::ratio<>>),
    (std::tuple<meta::ratio<meta::list<int>>, meta::ratio<>, meta::ratio<meta::list<int>>>),
    (std::tuple<
        meta::ratio<>,
        meta::ratio<meta::list<int>>,
        meta::ratio<meta::list<>, meta::list<int>>>),
    (std::tuple<
        meta::ratio<meta::list<>, meta::list<int>>,
        meta::ratio<>,
        meta::ratio<meta::list<>, meta::list<int>>>),
    (std::tuple<
        meta::ratio<>,
        meta::ratio<meta::list<>, meta::list<int>>,
        meta::ratio<meta::list<int>, meta::list<>>>),
    (std::tuple<
        meta::ratio<meta::list<int>, meta::list<double>>,
        meta::ratio<meta::list<int>, meta::list<double>>,
        meta::ratio<>>),
    (std::tuple<
        meta::ratio<meta::list<int>, meta::list<double>>,
        meta::ratio<meta::list<double>, meta::list<int>>,
        meta::ratio<meta::list<int, int>, meta::list<double, double>>>))
{
    constexpr auto dividend = std::tuple_element_t<0, TestType>{};
    constexpr auto divisor  = std::tuple_element_t<1, TestType>{};
    constexpr auto quotient = std::tuple_element_t<2, TestType>{};

    static_assert(quotient == dividend / divisor);
}
