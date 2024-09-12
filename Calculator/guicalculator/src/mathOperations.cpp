#include "mathOperations.h"

SetOperation::SetOperation(QObject *parent)
    : QObject(parent),
      firstOperation(OperationType::None),
      secondOperation(OperationType::None),
      isNum2EmptyFlag(true) {}

void SetOperation::onSaveOperator(const SetOperation::OperationType op) {
  if (isNum2EmptyFlag) {
    firstOperation = op;

  } else {
    secondOperation = op;
  }
  emit operatorUpdated(firstOperation, secondOperation);
}

SetOperation::OperationType SetOperation::getOperation() const {
  return firstOperation;
}

void SetOperation::updateNum2Empty(bool isNum2Empty) {
  isNum2EmptyFlag = isNum2Empty;
}

void SetOperation::updatedFirstOpToSecond() {
  firstOperation = secondOperation;
}

SetOperands::SetOperands(QObject *parent)
    : QObject(parent),
      num1(""),
      num2(""),
      operatorPressed(false),
      isNum2Empty(true),
      handleDelete(true) {}

void SetOperands::onSaveOperands(const QString &digit) {
  if (digit == ".") {
    if (!num1.contains(".") && !operatorPressed) {
      num1 += ".";
    } else if (!num2.contains(".") && operatorPressed) {
      num2 += ".";
    }
  } else {
    if (operatorPressed) {
      num2 += digit;  // add number to num2 after choosing operator

    } else {
      num1 += digit;  // add number to num1 before choosing operator
    }
  }
  emit num2EmptyChanged(num2.isEmpty());
  // Signalize onOperatorClicked slot in order to change operator only if num2
  // empty
  emit operandsUpdated(num1, num2, operatorPressed);
  // DisplayManager class with method onNumberClicked display numbers
}

void SetOperands::onOperatorPressed(
    const SetOperation::OperationType &firstOperation,
    const SetOperation::OperationType &secondOperation) {
  if (num2.isEmpty()) {
    firstOp = firstOperation;
    operatorPressed = true;
  } else {
    emit executeCurrentOperation();
    num1 = result;

    operatorPressed = true;

    num2.clear();
    emit updateFirstOp();  // signal for changing operator to second clicked op
    firstOp = secondOperation;
  }
  emit updateNum1Op(num1, firstOp);
  emit num2EmptyChanged(num2.isEmpty());
  emit operandsUpdated(num1, num2, operatorPressed);
}

void SetOperands::getResult(const QString &resultStr) { result = resultStr; }

void SetOperands::onClearOperands() {
  num1.clear();
  num2.clear();
  operatorPressed = false;
}

void SetOperands::onDeleteLastOperand() {
  if (!operatorPressed && !num1.isEmpty()) {
    num1.chop(1);
    handleDelete = true;
  }

  if (operatorPressed && !num2.isEmpty()) {
    num2.chop(1);
    handleDelete = true;
  } else if (operatorPressed && num2.isEmpty()) {
    operatorPressed = false;
    handleDelete = false;

    emit num2EmptyChanged(num2.isEmpty());
    emit operandsUpdated(num1, num2, operatorPressed);
    emit UpdateHandleDelete(handleDelete);
  }

  emit UpdateHandleDelete(handleDelete);
}

void SetOperands::onSetresultAsNum1() {
  if (!num1.isEmpty() && !num2.isEmpty() && operatorPressed) {
    num1.clear();
    num1 = result;
    num2.clear();
    operatorPressed = false;
  }
  emit num2EmptyChanged(num2.isEmpty());
}

QString SetOperands::getNum1() const { return num1; }

QString SetOperands::getNum2() const { return num2; }

ExecuteOperations::ExecuteOperations(QObject *parent, SetOperands *operands,
                                     SetOperation *operation)
    : QObject(parent), operands(operands), operation(operation), result(0) {}

void ExecuteOperations::onClearResult() {
  result = 0;
  emit resultReady(QString::number(result));
}

void ExecuteOperations::onExecuteResult() {
  QString num1Str = operands->getNum1();
  SetOperation::OperationType op = operation->getOperation();
  QString num2Str = operands->getNum2();

  if (num1Str.contains(".") || num2Str.contains(".")) {
    num1 = num1Str.toDouble();
    num2 = num2Str.toDouble();
  } else {
    num1 = num1Str.toInt();
    num2 = num2Str.toInt();
  }

  switch (op) {
    case SetOperation::OperationType::Addition:
      result = num1 + num2;
      break;
    case SetOperation::OperationType::Subtraction:
      result = num1 - num2;
      break;
    case SetOperation::OperationType::Multiplication:
      result = num1 * num2;
      break;
    case SetOperation::OperationType::Division:
      if (num2 == 0) {
        emit resultReady("Error: Division by zero");
        return;
      } else {
        result = num1 / num2;
      }
      break;
    default:
      emit resultReady("Unknown error");
      return;
  }

  if (result == static_cast<int>(result)) {
    resultStr = QString::number(static_cast<int>(result));
  } else {
    resultStr = QString::number(result, 'f', 2);
  }

  if (result != static_cast<int>(result) && resultStr.endsWith("0")) {
    resultStr.chop(1);
  }

  emit resultReady(resultStr);
}

DisplayManager::DisplayManager(QObject *parent)
    : QObject(parent), mainOutput(""), extraOutput("") {}

QString DisplayManager::getMainOutput() const { return mainOutput; }
QString DisplayManager::getExtraOutput() const { return extraOutput; }

void DisplayManager::onDisplayOperands(const QString &num1, const QString &num2,
                                       bool operatorPressed) {

  if (operatorPressed) {
    mainOutput = num2;
  } else if (num2.isEmpty()) {
    extraOutput.clear();
    mainOutput = num1;
  } else {
    mainOutput = num1;
  }

  emit extraOutputChanged(extraOutput);
  emit mainOutputChanged(mainOutput);
}

void DisplayManager::onDisplayFirstOp(const QString &num1,
                                      const SetOperation::OperationType &op) {
  switch (op) {
    case SetOperation::OperationType::Addition:
      operation = "+";
      break;
    case SetOperation::OperationType::Subtraction:
      operation = "-";
      break;
    case SetOperation::OperationType::Multiplication:
      operation = "*";
      break;
    case SetOperation::OperationType::Division:
      operation = "/";
      break;
    case SetOperation::OperationType::None:
      break;
  }

  if (extraOutput.isEmpty() && !num1.isEmpty()) {
    extraOutput = num1 + operation;
    mainOutput.clear();
  }

  emit extraOutputChanged(extraOutput);
  emit mainOutputChanged(mainOutput);
}

void DisplayManager::onEqualPressed(const QString &result) {
  if (!mainOutput.isEmpty()) {
    mainOutput = result;
    extraOutput.clear();
    emit mainOutputChanged(mainOutput);
    emit extraOutputChanged(extraOutput);
  }
}

void DisplayManager::onClearDisplay() {
  mainOutput.clear();
  extraOutput.clear();

  emit mainOutputChanged(mainOutput);
  emit extraOutputChanged(extraOutput);
}

void DisplayManager::onDeleteLastChar(const bool &UpdateHandleDelete) {
  if (UpdateHandleDelete && !mainOutput.isEmpty()) {
    mainOutput.chop(1);
    emit mainOutputChanged(mainOutput);
  }
}
