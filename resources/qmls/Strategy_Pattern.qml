import QtQuick 2.0
import QtQuick.Controls 2.12

Item {
    Rectangle {
        anchors.fill: parent
        color: "transparent"
        Rectangle {
            id: button_rect
            width: parent.width/2
            height: parent.height
            gradient: Helper_Module.property_map["visitor_pattern"]["color"]["visitor_pattern_button_bg"]
            Button {
                id: update_button
                text: qsTr("Click to Visit")
                font.pointSize: Helper_Module.property_map["visitor_pattern"]["font_size"]
                height: view.height/5
                width: implicitWidth
                anchors.centerIn: parent
                onClicked: visitor_screen_controller.updateModel()
                background: Rectangle {
                    height: view.height/5
                    width: update_button.width
                    color: "#FF8000"
                    radius: height * 0.2
                }
            }
        }
        Rectangle {
            width: button_rect.width
            height: parent.height
            anchors.right: parent.right
            color: "#AC00AC"
            ListView {
                anchors.fill: parent
                id: view
                model: visitor_screen_controller.visitor_model
                delegate: Rectangle {
                    id: view_element
                    height: view.height/ view.count
                    width: view.width
                    color: "#14CCF3"
                    border.color: "#00FF40"
                    border.width: parent.width * 0.01
                    radius: height * 0.2

                    Text {
                        anchors.centerIn: parent
                        id: element_text
                        text: modelData.label_name
                        font.pointSize: Helper_Module.property_map["visitor_pattern"]["font_size"]
                    }
                }
            }
        }
    }
}
