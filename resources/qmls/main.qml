import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import ViewControllerHelper 1.0

ApplicationWindow {
    property bool navigator_visible: false
    width: 640
    height: 480
    visible: true
    title: qsTr("Qt-QML with Design patterns")
    Loader
    {
        id: loader
        width: parent.width
        height: (navigator_visible)?  parent.height * 0.75 : parent.height
        source: view_controller.qmlname
        onSourceChanged: {
            if(view_controller.getCurrentViewIndex() === ViewControllerHelper.Launch_Screen)
                navigator_visible = false
            else
                navigator_visible = true
        }
    }

    Rectangle {
        id: image_rect
        visible: navigator_visible
        enabled: visible
        width: parent.width
        height: parent.height - loader.height
        anchors.bottom: parent.bottom
        gradient: Gradient {
            GradientStop {position: 0.0; color: "#BBE3E1"}
            GradientStop {position: 0.5; color: "#9AD6D2"}
            GradientStop {position: 1.0; color: "#E3F4F3"}
        }
        Image {
            id: left_arrow
            source: "qrc:/images/left-arrow.png" // Courtesy https://www.freeiconspng.com/downloadimg/31756
            anchors.left: parent.left
            width: parent.width * 0.2
            height: parent.height
            MouseArea {
                anchors.fill: parent
                onClicked: view_controller.popViewScreen()
            }
        }
        Image {
            id: right_arrow
            source: "qrc:/images/right-arrow.png" // Courtesy https://imgbin.com/png/RvuC9XQy/wood-arrow-computer-icons-png
            anchors.right: parent.right
            width: parent.width * 0.2
            height: parent.height
            MouseArea {
                anchors.fill: parent
                onClicked: view_controller.popViewScreen()
            }
        }
    }

    onClosing:
    {
        if(view_controller.popViewScreen() === ViewControllerHelper.Launch_Screen)
            close.accepted = true
        else
            close.accepted = false
    }
}
