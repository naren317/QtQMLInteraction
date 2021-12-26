TEMPLATE = app
TARGET = QtQMLInteraction
QT += quick
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


HEADERS += \
    includes/abstract_model_design_patterns.hpp \
    includes/abstract_model_observer.hpp \
    includes/adapter_design_pattern.hpp \
    includes/launch_screen_controller.hpp \
    includes/object_notifier.hpp \
    includes/observer_design_pattern.hpp \
    includes/observer_model_class.hpp \
    includes/observers.hpp \
    includes/platform_header.hpp \
    includes/view_controller.hpp \
    includes/visitor_design_pattern.hpp

INCLUDEPATH += includes \

SOURCES += \
    src/abstract_model_design_patterns.cpp \
    src/abstract_model_observer.cpp \
    src/adapter_design_pattern.cpp \
    src/launch_screen_controller.cpp \
    src/main.cpp \
    src/object_notifier.cpp \
    src/observer_design_pattern.cpp \
    src/observer_model_class.cpp \
    src/observers.cpp \
    src/view_controller.cpp \
    src/visitor_design_pattern.cpp

RESOURCES += \
    resources/qml.qrc

TRANSLATIONS += \
    helper_files/TravelExpensesMobile_en_IN.ts

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
