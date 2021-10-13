//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "P2.h"
#include <deque>
using namespace std;

static void test_1() {
    std::list<int> lst1 = {3, 3, -3, 5, 4, -4, 0, -4, -4, -5};
    std::deque f1 = get_maximum_product_range<std::deque>(lst1);
    for (const auto& value: f1)
        std::cout << value << " ";
    std::cout << std::endl;
}

static void test_2() {
    forward_list<int> fl {istream_iterator<int>(cin), istream_iterator<int>()};
    std::vector result = get_maximum_product_range(fl);
    for (const auto& value: result)
        std::cout << value << " ";
    std::cout << std::endl;
}

TEST_CASE("Question #2_1") {
    execute_test("test_2_1.in", test_1);
}

TEST_CASE("Question #2_2") {
    execute_test("test_2_2.in", test_2);
}