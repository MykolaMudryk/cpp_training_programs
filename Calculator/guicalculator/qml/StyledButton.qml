import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Basic 2.15

Button {
  id: root

  background: Rectangle {
    radius: 10

    implicitWidth: 65
    implicitHeight: 65

    color: buttonMouseArea.containsMouse ? "#a0a0a0" : "#303135"

    opacity: buttonMouseArea.containsMouse ? 0.3 : 1.0

    MouseArea {
      id: buttonMouseArea
      anchors.fill: parent
      hoverEnabled: true

      cursorShape: Qt.PointingHandCursor
    }
  }

  contentItem: Label {
    color: "#609dd2"
    font.pointSize: 20
    font.bold: true
    text: buttonText

    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter
  }

  property string buttonText: "Default"
}
