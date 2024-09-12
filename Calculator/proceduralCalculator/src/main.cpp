#include <iostream>
#include "math_operations.h" 
using namespace std;

int main() {
    int a,b;
    std::string operation;
    
    InputFunc::enterOperands(a, b);
    operation = InputFunc::enterOperation();

        MathOperations::performOperation(a, b, operation);
    return 0;
}
