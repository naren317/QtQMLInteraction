#ifndef LAUNCHSCREENCONTROLLER_HPP
#define LAUNCHSCREENCONTROLLER_HPP

#include <QQmlApplicationEngine>
#include <QObject>

class ViewController;
class LaunchScreenController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> launch_screen_model READ getLaunchScreenModel WRITE setLaunchScreenModel NOTIFY modelChanged)

public:
    LaunchScreenController(QQmlApplicationEngine* engine, QObject* parent = nullptr);

public slots:
    QList<QObject*> getLaunchScreenModel() const;
    void setLaunchScreenModel(const QList<QObject*> model);

signals:
    void modelChanged();

private:
    QList<QObject*> m_model;
};

#endif // LAUNCHSCREENCONTROLLER_HPP
