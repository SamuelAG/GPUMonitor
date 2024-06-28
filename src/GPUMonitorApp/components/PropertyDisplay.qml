import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    property color textColor
    property string labelValue
    property string value

    Label {
        id: label
        font.pixelSize: 22
        text: labelValue
        color: textColor
    }

    Label {
        anchors.left: label.right
        anchors.top: parent.top
        font.pixelSize: 22
        text: value
        color: textColor
    }
}
