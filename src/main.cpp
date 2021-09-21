#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QFileSelector>
#include <QQmlFileSelector>
#include <memory>
#include "platform_header.hpp"
#include "view_controller.hpp"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    QQmlFileSelector qml_files(&engine);
    QFileSelector file_selector;
    file_selector.setExtraSelectors(QStringList(platform));
    qml_files.setSelector(&file_selector);

    auto instance = std::make_shared<ViewController>();
    engine.rootContext()->setContextProperty("view_controller", instance.get());

    const QUrl url(QStringLiteral("qrc:/qmls/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
