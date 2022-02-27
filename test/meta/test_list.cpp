#include <concepts>

#include "posu//meta/list.hpp"

#include <catch2/catch.hpp>

namespace {

    namespace meta = posu::meta;

}

TEST_CASE("initialization", "[construct]")
{
    using list = meta::list<int, float, double, int&, float&&, const double&>;

    static_assert(std::same_as<list::at<0>, int>, "the first element must be int");
    static_assert(std::same_as<list::at<1>, float>, "the second element must be float");
    static_assert(std::same_as<list::at<2>, double>, "the third element must be double");
    static_assert(std::same_as<list::at<3>, int&>, "the fourth element must be int&");
    static_assert(std::same_as<list::at<4>, float&&>, "the fifth element must be float&&");
    static_assert(
        std::same_as<list::at<5>, const double&>,
        "the sixth element must be const double&");

    REQUIRE(list::size() == 6);
    REQUIRE(!list::empty());

    static_assert(std::same_as<meta::front<list>, int>, "the first element must be an int");
    static_assert(
        std::same_as<meta::back<list>, const double&>,
        "the last element must be const double&");
}

TEST_CASE("range operations", "[algorithms]")
{
    SECTION("concatenation")
    {
        constexpr auto lhs = meta::list<int, float, double>{};
        constexpr auto rhs = meta::list<unsigned int, unsigned char>{};

        constexpr auto result = meta::concatenate(lhs, rhs);

        static_assert(result == meta::list<int, float, double, unsigned int, unsigned char>{});
        static_assert(meta::concatenate(lhs, rhs, lhs, rhs) == meta::concatenate(result, lhs, rhs));
    }

    SECTION("pushing types")
    {
        constexpr auto original = meta::list<>{};

        constexpr auto add_one   = meta::push_back<int>(original);
        constexpr auto add_two   = meta::push_back<double>(add_one);
        constexpr auto add_three = meta::push_front<long double>(add_two);

        static_assert(add_one == meta::list<int>{});
        static_assert(add_two == meta::list<int, double>{});
        static_assert(add_three == meta::list<long double, int, double>{});
    }

    SECTION("popping types")
    {
        constexpr auto list = meta::list<char, int, long, float, double>{};

        constexpr auto pop_one = meta::pop_front(list);
        constexpr auto pop_two = meta::pop_back(pop_one);

        static_assert(pop_one == meta::list<int, long, float, double>{});
        static_assert(pop_two == meta::list<int, long, float>{});
    }

    SECTION("finding types")
    {
        using list = meta::list<char, int, int, long, float, double>;

        REQUIRE(meta::find<list, char>() == 0);
        REQUIRE(meta::find<list, int>() == 1);
        REQUIRE(meta::find<list, long>() == 3);
        REQUIRE(meta::find<list, float>() == 4);
        REQUIRE(meta::find<list, double>() == 5);
    }

    SECTION("sub-lists")
    {
        SECTION("first N elements")
        {
            constexpr auto list = meta::list<char, int, long, float, double>{};

            static_assert(meta::first<0>(list) == meta::list<>{});
            static_assert(meta::first<1>(list) == meta::list<char>{});
            static_assert(meta::first<2>(list) == meta::list<char, int>{});
            static_assert(meta::first<3>(list) == meta::list<char, int, long>{});
            static_assert(meta::first<4>(list) == meta::list<char, int, long, float>{});
            static_assert(meta::first<5>(list) == meta::list<char, int, long, float, double>{});
        }

        SECTION("last N elements")
        {
            constexpr auto list = meta::list<char, int, long, float, double>{};

            static_assert(meta::last<0>(list) == meta::list<>{});
            static_assert(meta::last<1>(list) == meta::list<double>{});
            static_assert(meta::last<2>(list) == meta::list<float, double>{});
            static_assert(meta::last<3>(list) == meta::list<long, float, double>{});
            static_assert(meta::last<4>(list) == meta::list<int, long, float, double>{});
            static_assert(meta::last<5>(list) == meta::list<char, int, long, float, double>{});
        }
    }

    SECTION("inserting types")
    {
        using list = meta::list<char, int, long, float, double>;

        static_assert(std::same_as<
                      meta::insert<list, 0, int>,
                      meta::list<int, char, int, long, float, double>>);
        static_assert(std::same_as<
                      meta::insert<list, 1, int>,
                      meta::list<char, int, int, long, float, double>>);
        static_assert(std::same_as<
                      meta::insert<list, 2, int>,
                      meta::list<char, int, int, long, float, double>>);
        static_assert(std::same_as<
                      meta::insert<list, 3, int>,
                      meta::list<char, int, long, int, float, double>>);
        static_assert(std::same_as<
                      meta::insert<list, 4, int>,
                      meta::list<char, int, long, float, int, double>>);
        static_assert(std::same_as<
                      meta::insert<list, 5, int>,
                      meta::list<char, int, long, float, double, int>>);
    }

    SECTION("removing types")
    {
        using list = meta::list<char, int, long, float, double>;

        static_assert(std::same_as<meta::remove<list, 0>, meta::list<int, long, float, double>>);
        static_assert(std::same_as<meta::remove<list, 1>, meta::list<char, long, float, double>>);
        static_assert(std::same_as<meta::remove<list, 2>, meta::list<char, int, float, double>>);
        static_assert(std::same_as<meta::remove<list, 3>, meta::list<char, int, long, double>>);
        static_assert(std::same_as<meta::remove<list, 4>, meta::list<char, int, long, float>>);
    }
}

TEST_CASE("algebraic types", "[algebraic][tuple][variant]")
{
    using list = meta::list<unsigned int, double>;

    REQUIRE(list::make_tuple(11, 5.5) == std::make_tuple(11, 5.5));
    REQUIRE(meta::make_tuple_from(list{}, 11, 5.5) == std::make_tuple(11, 5.5));
    REQUIRE(std::get<double>(list::make_variant(11.8)) == 11.8);
    REQUIRE(std::get<double>(meta::make_variant_from(list{}, 11.8)) == 11.8);
}
