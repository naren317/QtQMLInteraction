import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12
import "."

Item {

    Rectangle {
        anchors.fill: parent
        gradient: Helper_Module.property_map["launch_screen"]["color"]["launch_screen_bg"]

        GridView {
            anchors.fill: parent
            id: view
            model: launch_screen_controller.launch_screen_model
            cellWidth: view.width / view.count
            cellHeight: cellWidth * 0.5

            delegate: Rectangle {
                id: view_element
                gradient: Helper_Module.property_map["launch_screen"]["color"]["launch_screen_cell_color"]
                radius: height * 0.2
                border.color: "red"
                border.width: width  * 0.02

                Text {
                    id: model_text
                    anchors.centerIn: parent
                    text: modelData.design_name
                    font.pointSize: Helper_Module.property_map["launch_screen"]["font_size"]
                    width: implicitWidth
                    height: implicitHeight
                    font.bold: true
                }
                height: view.cellHeight
                width: view.cellWidth

                MouseArea {
                    anchors.fill: parent
                    onClicked: modelData.loadPattern()
                }
            }
        }
    }
}
