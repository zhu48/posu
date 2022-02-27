#include "posu/meta/ratio.hpp"

#include <catch2/catch.hpp>

namespace {

    namespace meta = posu::meta;

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
