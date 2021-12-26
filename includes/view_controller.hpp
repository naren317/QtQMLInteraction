#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSharedPointer>

class ViewControllerHelper : public QObject
{
    Q_OBJECT
public:
    enum ViewIndex: unsigned int{
        Launch_Screen,
        Home_Screen,
        Observer_Pattern,
        Visitor_Pattern,
        Adapter_Pattern
    };
    Q_ENUM(ViewIndex)
};

class ViewController: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString qmlname READ getQMLname WRITE setQMLname NOTIFY qmlnameChanged)

public:
    static QSharedPointer<ViewController> getViewController();
    ~ViewController() = default;

public slots:
    const QString& getQMLname() const;
    void setQMLname(const QString& qml);
    void pushViewScreen(ViewControllerHelper::ViewIndex screen_index);
    ViewControllerHelper::ViewIndex popViewScreen();

private:
    QString getIndexToScreen(ViewControllerHelper::ViewIndex screen_index) const;
    explicit ViewController() noexcept;

signals:
    void qmlnameChanged();

private:
    struct impl;
    QSharedPointer<impl> pImpl;
    static QSharedPointer<ViewController> m_view_controller;
};

#endif // VIEWCONTROLLER_H
