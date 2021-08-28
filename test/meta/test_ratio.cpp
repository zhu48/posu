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
    using lhs     = std::tuple_element_t<0, TestType>;
    using rhs     = std::tuple_element_t<1, TestType>;
    using product = std::tuple_element_t<2, TestType>;

    static_assert(std::same_as<product, meta::ratio_multiply<lhs, rhs>>);
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
    using dividend = std::tuple_element_t<0, TestType>;
    using divisor  = std::tuple_element_t<1, TestType>;
    using quotient = std::tuple_element_t<2, TestType>;

    static_assert(std::same_as<quotient, meta::ratio_divide<dividend, divisor>>);
}
