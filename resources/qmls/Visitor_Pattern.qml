import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQml 2.12
import QtQuick.Layouts 1.12

Item {
    property int visitor_pattern: view_controller.getCurrentViewIndex()
    Rectangle {
        anchors.fill: parent
        color: "transparent"
        Rectangle {
            id: button_rect
            width: parent.width/2
            height: parent.height
            gradient: Helper_Module.property_map[visitor_pattern]["color"]["background"]
            Button {
                id: update_button
                text: qsTr("Click to Visit")
                font.pointSize: Helper_Module.property_map[visitor_pattern]["font_size"]
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
            gradient: Helper_Module.property_map[visitor_pattern]["color"]["background"]
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
                    visible: false
                    Text {
                        anchors.centerIn: parent
                        id: element_text
                        text: modelData.label_name
                        font.pointSize: Helper_Module.property_map[visitor_pattern]["font_size"]
                    }

                    PropertyAnimation{
                        running: true
                        id: model_animation
                        target: view_element
                        property: "visible"
                        to: true
                        duration: 2000
                        easing.type: Easing.InQuad
                    }
                    Connections {
                        target: visitor_screen_controller
                        onModelChanged: {
                            model_animation.start()
                        }
                    }
                }
            }
        }
    }
}
