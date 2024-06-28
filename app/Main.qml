import QtQuick
import Qt.labs.qmlmodels
import GPUMonitorLib 1.0
import QtQuick.Controls 2.15
import "components"

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("GPUMonitor")

    Rectangle {

        anchors.centerIn: parent
        width: 640
        height: 480

        GPUMonitorLib {
            id: gpu
        }

        PropertyDisplay {
            id: temperatureDisplay
            anchors.top: parent.top
            anchors.left: parent.left
            labelValue: "Temperature: "
            value: gpu.temperature
            textColor: "black"
        }

        PropertyDisplay {
            anchors.topMargin: 30
            anchors.top: temperatureDisplay.bottom
            anchors.left: parent.left
            labelValue: "Gpu Clock: "
            value: gpu.gpuClock
            textColor: "black"
        }


    }


}
