#include "mathOperations.h"

using namespace std;

int main() {
    SetOperation operation;
    SetOperands operands;
    ExecuteOperations execute;

    operands.setOperands();
    operation.setOperation();
    execute.performOperations(operands, operation);
    return 0;
}
