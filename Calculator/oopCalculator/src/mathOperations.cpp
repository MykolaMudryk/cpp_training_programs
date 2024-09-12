#include <iostream>
#include <stdexcept>
#include <utility>
#include "mathOperations.h"

void SetOperands::setOperands() {
    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;
}

std::pair<int, int> SetOperands::getOperands() const{
    return std::make_pair(num1, num2);
}

void SetOperation::setOperation() {
    std::cout << "Enter arithmetic operation (+, -, *, /): ";
    std::cin >> operation;
}

void ExecuteOperations::performOperations(const SetOperands &operands,
                                          const SetOperation &operation) {
  auto [num1, num2] = operands.getOperands();
  std::string op = operation.getOperation();
  if (op == "+") {
    std::cout << "Performing addition..." << std::endl;
    Addition addition;
    result = addition.execute(num1, num2);
  } else if (op == "-") {
    std::cout << "Performing subtraction..." << std::endl;
    Subtraction subtraction;
    result = subtraction.execute(num1, num2);
  } else if (op == "*") {
    std::cout << "Performing multiplication..." << std::endl;
    Multiplication multiplication;
    result = multiplication.execute(num1, num2);
  } else if (op == "/") {
    try {
      std::cout << "Performing division..." << std::endl;
      Division division;
      result = division.execute(num1, num2);
    } catch (const std::runtime_error &zeroDiv) {
      std::cerr << zeroDiv.what() << std::endl;
    }
  } else {
    std::cout << "Invalid operation entered." << std::endl;
  }
}

int Addition::execute(int num1, int num2) {
    int result = num1 + num2;
    std::cout << "Result: " <<result;
    return result;
}

int Subtraction::execute(int num1, int num2) {
    int result = num1 - num2;
    std::cout << "Result: " <<result;
    return result;
}

int Multiplication::execute(int num1, int num2) {
    int result = num1 * num2;
    std::cout << "Result: " <<result;
    return result;
}

int Division::execute (int num1, int num2) {
    if (num2 == 0) {
        throw std::runtime_error("Error: Division by zero.");
    }
    int result = num1 / num2;
    std::cout << "Result: " <<result;
    return result;
}
