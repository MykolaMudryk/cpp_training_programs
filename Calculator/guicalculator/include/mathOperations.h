#ifndef GUICALCULATOR_INCLUDE_MATH_OPERATIONS_H_
#define GUICALCULATOR_INCLUDE_MATH_OPERATIONS_H_

#include <QObject>
#include <QString>

class SetOperation : public QObject {
  Q_OBJECT

 private:
  bool isNum2EmptyFlag;

 public:
  explicit SetOperation(QObject *parent = nullptr);

  enum class OperationType {
    Addition,
    Subtraction,
    Multiplication,
    Division,
    None
  };
  Q_ENUM(OperationType)

  Q_INVOKABLE void onSaveOperator(const SetOperation::OperationType op);

  OperationType firstOperation;
  OperationType secondOperation;

  OperationType getOperation() const;
  void updatedFirstOpToSecond();

 public slots:
  void updateNum2Empty(bool isNum2Empty);

 signals:
  void operatorUpdated(const OperationType &firstOperation,
                       const OperationType &secondOperation);
};

class SetOperands : public QObject {
  Q_OBJECT

 private:
  QString num1;
  QString num2;
  QString result;

  SetOperation::OperationType firstOp;

  bool operatorPressed;
  bool isNum2Empty;
  bool handleDelete;

 public:
  explicit SetOperands(QObject *parent = nullptr);

  Q_INVOKABLE void onSaveOperands(const QString &digit);
  Q_INVOKABLE void onClearOperands();
  Q_INVOKABLE void onDeleteLastOperand();
  Q_INVOKABLE void onSetresultAsNum1();

  QString getNum1() const;
  QString getNum2() const;

 public slots:
  void onOperatorPressed(const SetOperation::OperationType &firstOperation,
                         const SetOperation::OperationType &secondOperation);
  void getResult(const QString &result);

 signals:
  void operandsUpdated(const QString &num1, const QString &num2,
                       bool operatorPressed);
  void numbersCleared(const QString &num1, const QString &num2,
                      bool operatorPressed);
  void deletedLastChar(const QString &num1, const QString &num2);
  void updateNum1Op(const QString &num1,
                    const SetOperation::OperationType &firstOp);
  void executeCurrentOperation();
  void num2EmptyChanged(bool isNum2Empty);
  void updateFirstOp();
  void UpdateHandleDelete(const bool &handleDelete);
};

class ExecuteOperations : public QObject {
  Q_OBJECT

 private:
  double result;
  double num1, num2;

  SetOperands *operands;
  SetOperation *operation;

  QString num1Str, num2Str;
  QString resultStr;

 public:
  explicit ExecuteOperations(QObject *parent = nullptr,
                             SetOperands *operands = nullptr,
                             SetOperation *operation = nullptr);
  Q_INVOKABLE void onClearResult();

  Q_INVOKABLE void onExecuteResult();

 signals:
  void resultReady(const QString &result);
};

class DisplayManager : public QObject {
  Q_OBJECT

  Q_PROPERTY(
      QString mainOutput READ getMainOutput NOTIFY mainOutputChanged FINAL)
  Q_PROPERTY(
      QString extraOutput READ getExtraOutput NOTIFY extraOutputChanged FINAL)
 private:
  QString updatedNum1;
  QString mainOutput;
  QString extraOutput;
  QString operation;

 public:
  explicit DisplayManager(QObject *parent = nullptr);

  Q_INVOKABLE void onClearDisplay();

  QString getMainOutput() const;
  QString getExtraOutput() const;

 public slots:
  void onDisplayOperands(const QString &num1, const QString &num2,
                         bool operatorPressed);
  void onDisplayFirstOp(const QString &num1,
                        const SetOperation::OperationType &op);
  void onEqualPressed(const QString &resultStr);
  void onDeleteLastChar(const bool &UpdateHandleDelete);
 signals:
  void mainOutputChanged(const QString &mainOutput);
  void extraOutputChanged(const QString &extraOutput);
  void num2Cleared(const QString &updatedNum1, const QString &num2);
  void displayNum1();
};

#endif  // GUICALCULATOR_INCLUDE_MATH_OPERATIONS_H_
