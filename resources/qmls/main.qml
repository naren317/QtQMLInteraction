import QtQuick 2.12
import QtQml 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import ViewControllerHelper 1.0

ApplicationWindow {
    property int bottom_gradient: 0
    property bool navigator_visible: false
    width: Screen.width * 0.6
    height: width
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
        color: Helper_Module.property_map[bottom_gradient]["color"]["bottom_bar"]
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
    Connections {
        target: view_controller
        onQmlnameChanged: {
            bottom_gradient = view_controller.getCurrentViewIndex()
        }
    }
}
