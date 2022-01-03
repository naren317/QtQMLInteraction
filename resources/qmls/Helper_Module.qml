pragma Singleton
import QtQuick 2.12

QtObject {


    property var property_map : {

        "launch_screen" : {
            "color" : {
                "launch_screen_bg"          :   launch_screen_bg,
                "launch_screen_cell_color"  :   launch_screen_cell_color,
            },
            "font_size" : 10},

        "observer_pattern" : {
            "color" : {
                "observer_pattern_bg"       :    observer_pattern_bg
            },
            "font_size" : 20
        },

        "visitor_pattern" : {
            "color" : {
                "visitor_pattern_button_bg" :    visitor_pattern_button_bg
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

    property var visitor_pattern_button_bg : Gradient {
        GradientStop {position: 0.0; color: "#FBFADF"}
        GradientStop {position: 0.3; color: "#F4F1B7"}
        GradientStop {position: 0.5; color: "#F0EC95"}
        GradientStop {position: 0.8; color: "#EAE36F"}
        GradientStop {position: 1.0; color: "#E4DD49"}
    }
}
