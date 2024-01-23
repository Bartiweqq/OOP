#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Polynomial.h" // Подключаем заголовочный файл с определением класса Polynomial

TEST_CASE("Polynomial evaluation") {
    vector<double> coeffs1 = { 2, -3, 1 }; // 2x^2 - 3x + 1
    Polynomial poly1(coeffs1);

    SECTION("Evaluation at x = 2") {
        double result = poly1.evaluate(2);
        REQUIRE(result == 3); // Проверяем, что значение многочлена для x = 2 равно 3
    }

    SECTION("Evaluation at x = 0") {
        double result = poly1.evaluate(0);
        REQUIRE(result == 1); // Проверяем, что значение многочлена для x = 0 равно 1
    }
}

TEST_CASE("Polynomial addition") {
    vector<double> coeffs1 = { 2, -3, 1 }; // 2x^2 - 3x + 1
    vector<double> coeffs2 = { 1, 4 };    // x + 4
    Polynomial poly1(coeffs1);
    Polynomial poly2(coeffs2);

    Polynomial result = poly1.add(poly2);

    vector<double> expected_coeffs = { 2, -2, 5 }; // Ожидаемый результат сложения
    REQUIRE(result.getCoefficients() == expected_coeffs); // Проверяем, что сложение прошло верно
}

TEST_CASE("Polynomial subtraction") {
    vector<double> coeffs1 = { 2, -3, 1 }; // 2x^2 - 3x + 1
    vector<double> coeffs2 = { 1, 4 };    // x + 4
    Polynomial poly1(coeffs1);
    Polynomial poly2(coeffs2);

    Polynomial result = poly1.subtract(poly2);

    vector<double> expected_coeffs = { 2, -4, -3 }; // Ожидаемый результат вычитания
    REQUIRE(result.getCoefficients() == expected_coeffs); // Проверяем, что вычитание прошло верно
}

TEST_CASE("Polynomial multiplication") {
    vector<double> coeffs1 = { 2, -3, 1 }; // 2x^2 - 3x + 1
    vector<double> coeffs2 = { 1, 4 };    // x + 4
    Polynomial poly1(coeffs1);
    Polynomial poly2(coeffs2);

    Polynomial result = poly1.multiply(poly2);

    vector<double> expected_coeffs = { 2, 5, -10, 4 }; // Ожидаемый результат умножения
    REQUIRE(result.getCoefficients() == expected_coeffs); // Проверяем, что умножение прошло верно
}
