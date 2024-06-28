import QtQuick
import Qt.labs.qmlmodels
import GPUMonitorLib 1.0
import AmdGPULib 1.0
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

        AmdGPULib {
            id: gpu
        }


        PropertyDisplay {
            id: usageDisplay
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.topMargin: 30

            labelValue: "Usage: "
            value: gpu.GPUUsage
            textColor: "black"
        }

        PropertyDisplay {
            id: temperatureDisplay
            anchors.top: usageDisplay.bottom
            anchors.left: parent.left
            anchors.topMargin: 30
            labelValue: "Temperature: "
            value: gpu.GPUTemperature
            textColor: "black"
        }

        PropertyDisplay {
            anchors.topMargin: 30
            anchors.top: temperatureDisplay.bottom
            anchors.left: parent.left
            labelValue: "Gpu Clock: "
            value: gpu.GPUClockSpeed
            textColor: "black"
        }


    }


}
