import QtQuick 2.0
import QtQuick.Controls 2.5

Item {
    Rectangle {
        anchors.fill: parent
        color: "transparent"
        ListView {
            anchors.fill: parent
            orientation: ListView.Horizontal
            id: view
            model: observerModelInstance.model
            delegate: Rectangle {
                id: view_element
                height: view.height/5
                width: view.width
                color: "blue"
                radius: height * 0.2
                Text {
                    anchors.centerIn: parent
                    id: element_text
                    text: modelData.label_name
                    font.pointSize: 20
                }
                Rectangle {
                    width: view.width
                    height: view_element/2
                    color: "red"
                    anchors.verticalCenter: parent.verticalCenter
                }
            }
        }
        Button {
            text: qsTr("Click to update")
            height: view.height/5
            width: view.width
            anchors.bottom: parent.bottom
            onClicked: observerModelInstance.updateModel()
            background: Rectangle {
                height: view.height/5
                width: view.width
                color: "yellow"
                radius: height * 0.2
            }
        }
    }
}
