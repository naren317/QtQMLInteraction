import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: mainWindow
    width: 640
    height: 480
    visible: true
    title: class_module_instance.hello_world//qsTr("Hello World")
    property bool mouse_click: true

    Rectangle
    {
        id: outer_filler
        anchors.fill: parent
        color: "orange"
    }

    Rectangle
    {
        height: parent.height * 0.4
        width: parent.width * 0.6
        anchors.centerIn: parent
        color: outer_filler.color
        Text
        {
            id: helloworld
            color: (mouse_click) ? "red" : "#00FF00"
            font.pointSize: mainWindow.height / 24
            text: class_module_instance.hello_world//qsTr("text")
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            MouseArea
            {
                anchors.fill: parent
                onClicked:
                {
                    console.log(" Mouse is clicked ... \n")
                    mouse_click = !mouse_click;
                }
            }
        }
    }
}
