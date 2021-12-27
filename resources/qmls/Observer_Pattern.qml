import QtQuick 2.0
import QtQuick.Controls 2.5
import "."

Item {
    Rectangle {
        anchors.fill: parent
        gradient: Helper_Module.property_map["observer_pattern"]["color"]["observer_pattern_bg"]

        ListView {
            anchors.fill: parent
            orientation: ListView.Horizontal
            id: view
            model: observer_model_instance.model

            delegate: Rectangle {
                id: view_element
                height: view.height/5
                width: view.width / view.count
                color: "blue"
                border.color: "#00FF40"
                border.width: parent.width * 0.01
                radius: height * 0.2

                Text {
                    anchors.centerIn: parent
                    id: element_text
                    text: modelData.label_name
                    font.pointSize: Helper_Module.property_map["observer_pattern"]["font_size"]
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
            id: update_button
            text: qsTr("Click to update")
            font.pointSize: Helper_Module.property_map["observer_pattern"]["font_size"]
            height: view.height/5
            width: view.width * 0.5
            anchors.centerIn: parent
            onClicked: observer_model_instance.updateModel()
            background: Rectangle {
                height: view.height/5
                width: update_button.width
                color: "yellow"
                radius: height * 0.2
            }
        }
    }
}
