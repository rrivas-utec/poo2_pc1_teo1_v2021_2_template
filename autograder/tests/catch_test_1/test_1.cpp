//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "P1.h"
using namespace std;

static void test_1() {
    // genera un arreglo dinámico
    symmetric_difference_t sd1 ({1, 5, 3, 8, 2}, {4, 9, 7, 6, 10, 1});

    // imprimiendo los datos
    std::copy(sd1(), sd1() + sd1.size(), std::ostream_iterator<int>(std::cout," "));
    std::cout << std::endl;

    !sd1;
    std::copy(sd1(), sd1()+sd1.size(), std::ostream_iterator<int>(std::cout," "));
    std::cout << std::endl;
}

static void test_2() {
    int n1 = 0, n2 = 0;
    std::cin >> n1;
    std::cin >> n2;
    std::vector<int> v1(n1);
    std::vector<int> v2(n2);
    std::copy_n(std::istream_iterator<int>(cin), n1, begin(v1));
    std::copy_n(std::istream_iterator<int>(cin), n2, begin(v2));
    symmetric_difference_t sd1 (v1, v2);

    // imprimiendo los datos
    std::copy(sd1(), sd1() + sd1.size(), std::ostream_iterator<int>(std::cout," "));
    std::cout << std::endl;

    auto sd2 = sd1;
    !sd2;
    std::copy(sd2(), sd2() + sd2.size(), std::ostream_iterator<int>(std::cout," "));
    std::cout << std::endl;

    std::copy(sd1(), sd1() + sd1.size(), std::ostream_iterator<int>(std::cout," "));
    std::cout << std::endl;
}

TEST_CASE("Question #1_1") {
    execute_test("test_1_1.in", test_1);
}

TEST_CASE("Question #1_2") {
    execute_test("test_1_2.in", test_2);
}