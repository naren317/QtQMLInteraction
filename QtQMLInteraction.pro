TEMPLATE = app
TARGET = QtQMLInteraction
QT += quick
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


HEADERS += \
    includes/Abstract_factory/abstract_factory_design_pattern.hpp \
    includes/Observer/abstract_model_observer.hpp \
    includes/Observer/observer_design_pattern.hpp \
    includes/Observer/observer_screen_controller.hpp \
    includes/Strategy/strategy_design_pattern.hpp \
    includes/Visitor/abstract_model_visitor.hpp \
    includes/Visitor/visitor_design_pattern.hpp \
    includes/Visitor/visitor_screen_controller.hpp \
    includes/abstract_model_design_patterns.hpp \
    includes/adapter_design_pattern.hpp \
    includes/launch_screen_controller.hpp \
    includes/platform_header.hpp \
    includes/view_controller.hpp

INCLUDEPATH += includes \
               includes/Abstract_factory \
               includes/Visitor \
               includes/Observer \
               includes/Strategy

SOURCES += \
    src/Abstract_factory/abstract_factory_design_pattern.cpp \
    src/Observer/abstract_model_observer.cpp \
    src/Observer/observer_design_pattern.cpp \
    src/Observer/observer_screen_controller.cpp \
    src/Strategy/strategy_design_pattern.cpp \
    src/Visitor/abstract_model_visitor.cpp \
    src/Visitor/visitor_design_pattern.cpp \
    src/Visitor/visitor_screen_controller.cpp \
    src/abstract_model_design_patterns.cpp \
    src/adapter_design_pattern.cpp \
    src/launch_screen_controller.cpp \
    src/main.cpp \
    src/view_controller.cpp

RESOURCES += \
    resources/qml.qrc

TRANSLATIONS += \
    helper_files/QtQMLInteraction_en_IN.ts

android {

QT += androidextras

}

lupdate_only {

SOURCES += \
resources/qmls/main.qml \
resources/qmls/LaunchScreen.qml \
resources/qmls/+android/LaunchScreen.qml

}

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
