import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15
import QtQuick.Controls.Basic

import SetOperation 1.0

Item {
  width: parent.width
  height: parent.height

  GridLayout {
    id: gridButtons

    columns: 4
    rows: 5

    columnSpacing: 12
    rowSpacing: 14

    StyledButton {
      id: buttonAC
      buttonText: "AC"

      Layout.preferredWidth: 142

      Layout.row: 0
      Layout.column: 0
      Layout.columnSpan: 2

      onClicked: {
        setOperands.onClearOperands()
        resultOfOperations.onClearResult()
        displayManager.onClearDisplay()
      }
    }

    StyledButton {
      id: buttonDelete
      buttonText: "DEL"

      Layout.row: 0
      Layout.column: 2

      onClicked: {
        setOperands.onDeleteLastOperand()
      }
    }

    StyledButton {
      id: buttonDivision
      buttonText: "/"

      Layout.row: 0
      Layout.column: 3

      onClicked: {
        setOperation.onSaveOperator(OperationType.Division)
      }
    }

    StyledButton {
      id: button1
      buttonText: "1"

      Layout.row: 1
      Layout.column: 0

      onClicked: setOperands.onSaveOperands("1")
    }

    StyledButton {
      id: button2
      buttonText: "2"

      Layout.row: 1
      Layout.column: 1

      onClicked: setOperands.onSaveOperands("2")
    }

    StyledButton {
      id: button3
      buttonText: "3"

      Layout.row: 1
      Layout.column: 2

      onClicked: setOperands.onSaveOperands("3")
    }

    StyledButton {
      id: buttonPlus
      buttonText: "+"

      Layout.row: 1
      Layout.column: 3

      onClicked: {
        setOperation.onSaveOperator(OperationType.Addition)
      }
    }

    StyledButton {
      id: button4
      buttonText: "4"

      Layout.row: 2
      Layout.column: 0

      onClicked: setOperands.onSaveOperands("4")
    }

    StyledButton {
      id: button5
      buttonText: "5"

      Layout.row: 2
      Layout.column: 1

      onClicked: setOperands.onSaveOperands("5")
    }

    StyledButton {
      id: button6
      buttonText: "6"

      Layout.row: 2
      Layout.column: 2

      onClicked: setOperands.onSaveOperands("6")
    }

    StyledButton {
      id: buttonSubtraction
      buttonText: "-"

      Layout.row: 2
      Layout.column: 3

      onClicked: {
        setOperation.onSaveOperator(OperationType.Subtraction)
      }
    }

    StyledButton {
      id: button7
      buttonText: "7"

      Layout.row: 3
      Layout.column: 0

      onClicked: setOperands.onSaveOperands("7")
    }

    StyledButton {
      id: button8
      buttonText: "8"

      Layout.row: 3
      Layout.column: 1

      onClicked: setOperands.onSaveOperands("8")
    }

    StyledButton {
      id: button9
      buttonText: "9"

      Layout.row: 3
      Layout.column: 2

      onClicked: setOperands.onSaveOperands("9")
    }

    StyledButton {
      id: buttonMultiplication
      buttonText: "*"

      Layout.row: 3
      Layout.column: 3

      onClicked: {

        setOperation.onSaveOperator(OperationType.Multiplication)
      }
    }

    StyledButton {
      id: buttonDot
      buttonText: "."

      Layout.row: 4
      Layout.column: 0

      onClicked: setOperands.onSaveOperands(".")
    }

    StyledButton {
      id: button0
      buttonText: "0"

      Layout.row: 4
      Layout.column: 1

      onClicked: setOperands.onSaveOperands("0")
    }

    StyledButton {
      id: buttonEqual
      buttonText: "="

      Layout.preferredWidth: 142

      Layout.row: 4
      Layout.column: 2

      Layout.columnSpan: 2

      onClicked: {

        resultOfOperations.onExecuteResult()
        setOperands.onSetresultAsNum1()
      }
    }
  }
}
