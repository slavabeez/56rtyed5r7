#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include "H:\Бердюгин Вячеслав\практика\работа 7\ConsoleApplication1\ConsoleApplication1\ConsoleApplication1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GeometryTests
{
    TEST_CLASS(GeometryTests)
    {
    public:

        TEST_METHOD(TestTriangleArea_ValidInput_ReturnsCorrectArea)
        {
            // Arrange
            working calculator;
            double a = 10.0;
            double h = 5.0;

            // Act
            double result = calculator.triangleArea(a, h);

            // Assert - ВАША формула: 2/(a*h) = 2/(10*5) = 2/50 = 0.04
            Assert::AreEqual(0.04, result, 0.001);
        }

        TEST_METHOD(TestRectangleArea_ValidInput_ReturnsCorrectArea)
        {
            // Arrange
            working calculator;
            double length = 4.0;
            double width = 5.0;

            // Act
            double result = calculator.rectangleArea(length, width);

            // Assert
            Assert::AreEqual(20.0, result, 0.001);
        }

        TEST_METHOD(TestCircleArea_ValidRadius_ReturnsCorrectArea)
        {
            // Arrange
            working calculator;
            double radius = 3.0;

            // Act
            double result = calculator.circleArea(radius);

            // Assert - π * 3² = 3.14159265 * 9 = 28.274333
            Assert::AreEqual(28.274333, result, 0.001);
        }

        TEST_METHOD(TestTriangleArea_NegativeBase_ThrowsException)
        {
            // Arrange
            working calculator;
            double negativeBase = -5.0;
            double height = 4.0;

            auto func = [&calculator, &negativeBase, &height]() {
                calculator.triangleArea(negativeBase, height);
                };

            // Act & Assert
            Assert::ExpectException<std::invalid_argument>(func);
        }

        TEST_METHOD(TestRectangleArea_ZeroWidth_ThrowsException)
        {
            // Arrange
            working calculator;
            double length = 5.0;
            double zeroWidth = 0.0;

            auto func = [&calculator, &length, &zeroWidth]() {
                calculator.rectangleArea(length, zeroWidth);
                };

            // Act & Assert
            Assert::ExpectException<std::invalid_argument>(func);
        }

        // Дополнительные тесты для покрытия всех методов

        TEST_METHOD(TestTrapezoidArea_ValidInput_ReturnsCorrectArea)
        {
            // Arrange
            working calculator;
            double a = 3.0;
            double b = 5.0;
            double h = 4.0;

            // Act
            double result = calculator.trapezoidArea(a, b, h);

            // Assert - ((3+5)*4)/2 = (8*4)/2 = 32/2 = 16
            Assert::AreEqual(16.0, result, 0.001);
        }

        TEST_METHOD(TestTrapezoidArea_NegativeHeight_ThrowsException)
        {
            // Arrange
            working calculator;
            double base1 = 3.0;
            double base2 = 5.0;
            double negativeHeight = -4.0;

            auto func = [&calculator, &base1, &base2, &negativeHeight]() {
                calculator.trapezoidArea(base1, base2, negativeHeight);
                };

            // Act & Assert
            Assert::ExpectException<std::invalid_argument>(func);
        }
    };
}