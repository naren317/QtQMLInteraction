#ifndef OBJECTNOTIFIER_HPP
#define OBJECTNOTIFIER_HPP

#include <QObject>
#include <QVector>
#include <QQmlApplicationEngine>

class AbstractModelObserver;
class ObjectNotifier : public QObject
{
    Q_OBJECT
public:
    explicit ObjectNotifier(QQmlApplicationEngine* engine = nullptr, QObject *parent = nullptr);
    void add_observer(AbstractModelObserver* object);

    Q_INVOKABLE void update();

private:
    QVector<AbstractModelObserver*> observer_list;

};

#endif // OBJECTNOTIFIER_HPP
