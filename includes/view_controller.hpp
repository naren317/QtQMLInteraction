#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <memory>

class ViewController: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString qmlname READ getQMLname WRITE setQMLname NOTIFY qmlnameChanged)


public:
    explicit ViewController() noexcept;
    ~ViewController() = default;

    enum class ViewIndex: unsigned int{
        Launch_Screen,
        Home_Screen
    };
    Q_ENUM(ViewIndex)

public slots:
    QString getQMLname() const;
    void setQMLname(const QString& qml);
    void pushViewScreen(ViewIndex screen_index);
    ViewIndex popViewScreen();
    QString getIndexToScreen(ViewIndex screen_index);

signals:
    void qmlnameChanged();

private:
    struct impl;
    std::shared_ptr<impl> pImpl;
};

#endif // VIEWCONTROLLER_H
