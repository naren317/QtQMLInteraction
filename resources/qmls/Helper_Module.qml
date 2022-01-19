pragma Singleton
import "."
import QtQuick 2.12
import QtQml 2.12
import ViewControllerHelper 1.0

QtObject {

    property var property_map : {

         0: {
            "color" : {
                "background"          :   launch_screen_bg,
                "launch_screen_cell_color"  :   launch_screen_cell_color,
                "launch_screen_bottom_bar"  :   launch_screen_bottom_bar,
                "bottom_bar"                : "transparent"
            },
            "font_size" : 10},

        2 : {
            "color" : {
                "background"       :    observer_pattern_bg,
                "bottom_bar"       :    observer_pattern_bottom_bar
            },
            "font_size" : 20
        },

        3 : {
            "color" : {
                "background"       :    visitor_pattern_button_bg,
                "bottom_bar"       :    visitor_pattern_bottom_bar
            },
            "font_size" : 20
        },

        4 : {
            "color" : {
                "background"       :    adapter_pattern_button_bg,
                "bottom_bar"       :    adapter_pattern_bottom_bar
            },
            "font_size" : 20
        }
    }

    property var launch_screen_bg: Gradient {
        GradientStop{position: 0.0; color: "#FCFAD3"}
        GradientStop{position: 0.3; color: "#F8F296"}
        GradientStop{position: 0.6; color: "#F5EF76"}
        GradientStop{position: 0.8; color: "#FEB4AD"}
        GradientStop{position: 1.0; color: "#FC6F63"}
    }
    property var launch_screen_bottom_bar: Gradient {
        GradientStop {position: 0.0; color: "#BBE3E1"}
        GradientStop {position: 0.5; color: "#9AD6D2"}
        GradientStop {position: 1.0; color: "#E3F4F3"}
    }
    property var launch_screen_cell_color : Gradient {
        GradientStop {position: 0.0; color: "#FF0000"}
        GradientStop {position: 0.5; color: "#00FF00"}
        GradientStop {position: 1.0; color: "#0000FF"}
    }

    property var observer_pattern_bg : Gradient {
        GradientStop {position: 0.0; color: "#FFDFD0"}
        GradientStop {position: 0.3; color: "#FFC6AA"}
        GradientStop {position: 0.5; color: "#FFA67B"}
        GradientStop {position: 0.8; color: "#FF7B3C"}
        GradientStop {position: 1.0; color: "#F24F00"}
    }
    property var observer_pattern_bottom_bar: "#F24F00"

    property var visitor_pattern_button_bg : Gradient {
        GradientStop {position: 0.0; color: "#FBFADF"}
        GradientStop {position: 0.3; color: "#F4F1B7"}
        GradientStop {position: 0.5; color: "#F0EC95"}
        GradientStop {position: 0.8; color: "#EAE36F"}
        GradientStop {position: 1.0; color: "#E4DD49"}
    }
    property var visitor_pattern_bottom_bar: "#E4DD49"

    property var adapter_pattern_button_bg : Gradient {
        GradientStop {position: 0.0; color: "#FBFADF"}
        GradientStop {position: 0.3; color: "#F4F1B7"}
        GradientStop {position: 0.5; color: "#F0EC95"}
        GradientStop {position: 0.8; color: "#EAE36F"}
        GradientStop {position: 1.0; color: "#E4DD49"}
    }
    property var adapter_pattern_bottom_bar: "#E4DD49"
}
