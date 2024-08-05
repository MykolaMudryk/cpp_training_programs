#ifndef MATH_OPERATIONS_H
#define MATH_OPERATIONS_H

#include <iostream>
#include <string>

namespace MathOperations {
void addition(int a, int b);
void subtraction(int a, int b);
void multiplication(int a, int b);
void division(int a, int b);
void performOperation(int a, int b, const std::string& operation);
}
namespace InputFunc {
void enterOperands(int &a, int &b);
std::string enterOperation();
}

struct ArithmeticOperations {
    std::string addition = "+";
    std::string subtraction = "-";
    std::string multiplication = "*";
    std::string division = "/";
    std::string operation;
};

#endif
