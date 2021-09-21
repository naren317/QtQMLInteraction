TEMPLATE = app
TARGET = QtQMLInteraction
QT += quick
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


HEADERS += \
    includes/platform_header.hpp \
    includes/view_controller.hpp

INCLUDEPATH += includes \

SOURCES += \
    src/main.cpp \
    src/view_controller.cpp

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
