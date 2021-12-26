import QtQuick 2.0
import QtQuick.Controls 2.5

Item {
    property int horizontal_cells : 4
    property real cell_width : 0
    property real cell_spacing : 0
    Rectangle {
        anchors.fill: parent
        color: "transparent"
        GridView {
            anchors.fill: parent
            id: view
            model: launch_screen_controller.launch_screen_model
            delegate: Rectangle {
                id: view_element
                gradient: Gradient {
                    GradientStop {position: 0.0; color: "#FF0000"}
                    GradientStop {position: 0.5; color: "#00FF00"}
                    GradientStop {position: 1.0; color: "#0000FF"}
                }

                radius: height * 0.2
                border.color: "red"
                border.width: width  * 0.05
                Text {
                    id: model_text
                    anchors.centerIn: parent
                    text: modelData.design_name
                    font.pointSize: 10
                    width: implicitWidth
                    height: implicitHeight
                    onWidthChanged: cell_width = width
                    font.bold: true
                }
                height: view.cellHeight
                width: view.cellWidth
                MouseArea {
                    anchors.fill: parent
                    onClicked: modelData.loadPattern()
                }
            }
            cellWidth: cell_width * 1.5//parent.width / horizontal_cells
            cellHeight: cellWidth
        }
    }
}
