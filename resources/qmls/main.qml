import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import ViewController 1.0

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Travel Expenses App")
    Loader
    {
        anchors.fill: parent
        source: view_controller.qmlname
    }
    onClosing:
    {
        if(view_controller.popViewScreen() === ViewController.Launch_Screen)
            close.accepted = true
        else
            close.accepted = false
    }
}
