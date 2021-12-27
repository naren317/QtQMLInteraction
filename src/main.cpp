#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QFileSelector>
#include <QQmlFileSelector>
#include <memory>
#include "platform_header.hpp"
#include "view_controller.hpp"
#include "object_notifier.hpp"
#include "observers.hpp"
#include "observer_screen_controller.hpp"
#include "launch_screen_controller.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    QQmlFileSelector qml_files(&engine);
    QFileSelector file_selector;
    file_selector.setExtraSelectors(QStringList(platform));
    qml_files.setSelector(&file_selector);

    ObserverScreenController model(&engine);
    LaunchScreenController launch_screen(&engine);

    engine.rootContext()->setContextProperty("view_controller", ViewController::getViewController().get());

    const QUrl url(QStringLiteral("qrc:/qmls/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
