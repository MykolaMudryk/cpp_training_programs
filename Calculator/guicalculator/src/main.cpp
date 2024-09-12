#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "mathOperations.h"

using namespace std;

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);
  QQmlApplicationEngine engine;

  SetOperands *operands = new SetOperands(&app);
  SetOperation *operation = new SetOperation(&app);
  ExecuteOperations *execute = new ExecuteOperations(&app, operands, operation);
  DisplayManager *displayManager = new DisplayManager(&app);

  QObject::connect(operation, &SetOperation::operatorUpdated, operands,
                   &SetOperands::onOperatorPressed);
  // Operation class inform numbers class in order to correctly set num1/num2

  QObject::connect(operands, &SetOperands::operandsUpdated, displayManager,
                   &DisplayManager::onDisplayOperands);
  // Numbers class inform display class about numbers to display

  QObject::connect(operands, &SetOperands::executeCurrentOperation, execute,
                   &ExecuteOperations::onExecuteResult);

  QObject::connect(operands, &SetOperands::num2EmptyChanged, operation,
                   &SetOperation::updateNum2Empty);
  // Inform SetOperation class about num2 empty so that operation can be
  // overwritten

  QObject::connect(operands, &SetOperands::updateNum1Op, displayManager,
                   &DisplayManager::onDisplayFirstOp);
  // Operands class inform display class about num1 and operations string

  QObject::connect(operands, &SetOperands::updateFirstOp, operation,
                   &SetOperation::updatedFirstOpToSecond);
  // This will update the first operator to the second operator when the signal
  // is emitted.

  QObject::connect(execute, &ExecuteOperations::resultReady, operands,
                   &SetOperands::getResult);

  QObject::connect(execute, &ExecuteOperations::resultReady, displayManager,
                   &DisplayManager::onEqualPressed);
  // Execute class inform display class about result of calculation

  QObject::connect(operands, &SetOperands::UpdateHandleDelete, displayManager,
                   &DisplayManager::onDeleteLastChar);
  // Signal UpdateHandleDelete is being emitted to avoid unnecessary clearing of
  // mainOutput when num2.isEmpty()

  engine.rootContext()->setContextProperty("setOperands", operands);
  engine.rootContext()->setContextProperty("setOperation", operation);
  engine.rootContext()->setContextProperty("displayManager", displayManager);
  engine.rootContext()->setContextProperty("resultOfOperations", execute);

  qmlRegisterType<SetOperation>("SetOperation", 1, 0, "OperationType");

  const QUrl url(QStringLiteral("qrc:/qml/Main.qml"));
  engine.load(url);

  return app.exec();
}
