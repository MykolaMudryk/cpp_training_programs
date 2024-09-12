#include <iostream>
#include <stdexcept>
#include "math_operations.h"

namespace MathOperations {
    void addition(int a, int b){
        int result = a + b;
        std::cout << result;
    }

    void subtraction(int a, int b){
        int result = a - b;
        std::cout << result;
    }

    void multiplication(int a, int b){
        int result = a * b;
        std::cout << result;
    }

    void division(int numerator, int denominator) {
        if (denominator == 0) {
            throw std::runtime_error("Error: Division by zero.");
        }
        int result = numerator / denominator;
        std::cout << result;
        }

    void performOperation(int a, int b, const std::string& operation) {
        if (operation == "+") {
            std::cout << "Performing addition..." << std::endl;
            addition(a, b);
        } else if (operation == "-") {
            std::cout << "Performing subtraction..." << std::endl;
            subtraction(a, b);
        } else if (operation == "*") {
            std::cout << "Performing multiplication..." << std::endl;
            multiplication(a, b);
        } else if (operation == "/") {
            std::cout << "Performing division..." << std::endl;
            division(a, b);
        } else {
            std::cout << "Invalid operation entered." << std::endl;
        }
    }
}

namespace InputFunc {
    void enterOperands(int &a, int &b){
        std::cout << "Введіть перше число: ";
        std::cin >> a;
        std::cout << "Введіть друге число: ";
        std::cin >> b;
    }

    std::string enterOperation(){
        ArithmeticOperations arithmeticOperation1;
        std::cout << "Enter arithmetic operation: ";
        std::cin >> arithmeticOperation1.operation;
        return arithmeticOperation1.operation;
    }
}





