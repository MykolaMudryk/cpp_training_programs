import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15
import QtQuick.Controls.Basic

ApplicationWindow {
  id: rootBlueWindow
  visible: true
  width: 650
  height: 797

  color: "#a0d7fe"

  title: "Calculator"

  Rectangle {
    id: mainGrayWindow

    width: 350
    height: 540

    color: "#18191b"

    radius: 15
    anchors.centerIn: parent

    Rectangle {
      id: textContainer

      color: parent.color

      width: parent.width
      height: 110

      anchors {
        top: parent.top

        left: parent.left
        leftMargin: 27

        right: parent.right
        rightMargin: 27
      }

      Text {
        id: extraOutput

        width: textContainer.width
        height: 40

        horizontalAlignment: Text.AlignRight

        anchors {
          top: textContainer.top
          topMargin: 35
        }

        font {
          family: "Arial"
          pointSize: 17
          bold: true
        }

        color: "#808080"
        text: displayManager.extraOutput
      }

      Text {
        id: mainOutput

        width: parent.width
        height: 40

        horizontalAlignment: Text.AlignRight

        anchors {
          top: extraOutput.bottom
          bottomMargin: 10
        }

        font {
          family: "Arial"
          pointSize: 24
          bold: true
        }

        color: "white"
        text: displayManager.mainOutput
      }
    }

    Rectangle {
      id: gridContainer
      color: parent.color

      anchors {
        top: textContainer.bottom
        topMargin: 25

        left: parent.left
        leftMargin: 27

        right: parent.right
        rightMargin: 27

        bottom: parent.bottom
        bottomMargin: 20
      }

      Buttons {
        anchors.fill: parent
      }
    }
  }
}
