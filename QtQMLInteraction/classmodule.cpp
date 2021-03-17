#include "classmodule.h"
#include <QQmlContext>
#include <QDebug>


/* The underlying motivation of this project is to demonstrate how to pass data and create logic from cpp,
 * QML should only be used for displaying those data passed from the cpp world to QML world
*/

struct ClassModule::impl
{
    QString hello_world_impl;
};

ClassModule::ClassModule(QQmlApplicationEngine *engine, const QUrl* const url, QObject *parent): pImpl{std::make_shared<impl>()}
{
    engine->rootContext()->setContextProperty("class_module_instance", this); // this is how you pass the class instance from Qt to QML

    // ******** there's an alternative way, kindly read about qmlRegisterType and qRegisterMetaType.
    // Also read about connecting signal and slot in Qt.

    engine->load(*url);

    setString("~HELLO WORLD~"); // this will call the method and set the hello_world string Q_PROPERTY

}

QString ClassModule::getString() const
{
    qDebug() << " Getter is invoked " ;
    return pImpl->hello_world_impl;
}

void ClassModule::setString(const QString& hello_string)
{
    pImpl->hello_world_impl = hello_string;
    emit string_changed(); // this will now call the getString method which will set the hello_world Q_PROPERTY and that gets reflected
    // in the QML
    return;
}
