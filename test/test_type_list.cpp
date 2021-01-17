#include "posu/type_list.hpp"

#include <concepts>

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE("initialization", "[construct]")
{
    using list = posu::type_list<int, float, double, int&, float&&, const double&>;

    static_assert(std::same_as<list::at<0>, int>, "the first element must be int");
    static_assert(std::same_as<list::at<1>, float>, "the second element must be float");
    static_assert(std::same_as<list::at<2>, double>, "the third element must be double");
    static_assert(std::same_as<list::at<3>, int&>, "the fourth element must be int&");
    static_assert(std::same_as<list::at<4>, float&&>, "the fifth element must be float&&");
    static_assert(
        std::same_as<list::at<5>, const double&>, "the sixth element must be const double&");

    REQUIRE(list::size() == 6);
    REQUIRE(!list::empty());

    static_assert(std::same_as<list::front, int>, "the first element must be an int");
    static_assert(
        std::same_as<list::back, const double&>, "the last element must be const double&");
}

TEST_CASE("range operations", "[algorithms]")
{
    SECTION("concatenation")
    {
        using lhs = posu::type_list<int, float, double>;
        using rhs = posu::type_list<unsigned int, unsigned char>;

        using result = posu::concatenate<lhs, rhs>;

        static_assert(
            std::same_as<result, posu::type_list<int, float, double, unsigned int, unsigned char>>);
        static_assert(std::same_as<
                      posu::concatenate<lhs, rhs, lhs, rhs>,
                      posu::concatenate<result, lhs, rhs>>);
    }

    SECTION("pushing types")
    {
        using original = posu::type_list<>;

        using add_one   = posu::push_back<original, int>;
        using add_two   = posu::push_back<add_one, double>;
        using add_three = posu::push_front<add_two, long double>;

        static_assert(std::same_as<add_one, posu::type_list<int>>);
        static_assert(std::same_as<add_two, posu::type_list<int, double>>);
        static_assert(std::same_as<add_three, posu::type_list<long double, int, double>>);
        static_assert(std::same_as<
                      posu::push_front<add_three, posu::type_list<char>>,
                      posu::push_front<add_three, char>>);
        static_assert(std::same_as<
                      posu::push_back<add_three, posu::type_list<char>>,
                      posu::push_back<add_three, char>>);
    }

    SECTION("popping types")
    {
        using list = posu::type_list<char, int, long, float, double>;

        using pop_one = posu::pop_front<list>;
        using pop_two = posu::pop_back<pop_one>;

        static_assert(std::same_as<pop_one, posu::type_list<int, long, float, double>>);
        static_assert(std::same_as<pop_two, posu::type_list<int, long, float>>);
    }

    SECTION("finding types")
    {
        using list = posu::type_list<char, int, int, long, float, double>;

        REQUIRE(posu::find<list, char>() == 0);
        REQUIRE(posu::find<list, int>() == 1);
        REQUIRE(posu::find<list, long>() == 3);
        REQUIRE(posu::find<list, float>() == 4);
        REQUIRE(posu::find<list, double>() == 5);
    }

    SECTION("sub-lists")
    {
        SECTION("first N elements")
        {
            using list = posu::type_list<char, int, long, float, double>;

            static_assert(std::same_as<posu::first<list, 0>, posu::type_list<>>);
            static_assert(std::same_as<posu::first<list, 1>, posu::type_list<char>>);
            static_assert(std::same_as<posu::first<list, 2>, posu::type_list<char, int>>);
            static_assert(std::same_as<posu::first<list, 3>, posu::type_list<char, int, long>>);
            static_assert(
                std::same_as<posu::first<list, 4>, posu::type_list<char, int, long, float>>);
            static_assert(
                std::
                    same_as<posu::first<list, 5>, posu::type_list<char, int, long, float, double>>);
        }

        SECTION("last N elements")
        {
            using list = posu::type_list<char, int, long, float, double>;

            static_assert(std::same_as<posu::last<list, 0>, posu::type_list<>>);
            static_assert(std::same_as<posu::last<list, 1>, posu::type_list<double>>);
            static_assert(std::same_as<posu::last<list, 2>, posu::type_list<float, double>>);
            static_assert(std::same_as<posu::last<list, 3>, posu::type_list<long, float, double>>);
            static_assert(
                std::same_as<posu::last<list, 4>, posu::type_list<int, long, float, double>>);
            static_assert(
                std::same_as<posu::last<list, 5>, posu::type_list<char, int, long, float, double>>);
        }
    }
}

TEST_CASE("algebraic types", "[algebraic][tuple][variant]")
{
    using list = posu::type_list<unsigned int, double>;

    REQUIRE(list::make_tuple(11, 5.5) == std::make_tuple(11, 5.5));
    REQUIRE(posu::make_tuple_from(list{}, 11, 5.5) == std::make_tuple(11, 5.5));
    REQUIRE(std::get<double>(list::make_variant(11.8)) == 11.8);
    REQUIRE(std::get<double>(posu::make_variant_from(list{}, 11.8)) == 11.8);
}
