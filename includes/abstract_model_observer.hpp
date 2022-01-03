#ifndef ABSTRACT_MODEL_OBSERVER_HPP
#define ABSTRACT_MODEL_OBSERVER_HPP

#include <QObject>
#include <QQmlApplicationEngine>
#include <QVector>

class AbstractModelObserver;
class ObjectNotifier : public QObject
{
    Q_OBJECT
public:
    explicit ObjectNotifier(QQmlApplicationEngine* engine = nullptr, QObject *parent = nullptr);
    void add_observer(AbstractModelObserver* object);

    Q_INVOKABLE void update();
    ~ObjectNotifier();

private:
    QVector<AbstractModelObserver*> observer_list;

};

class AbstractModelObserver : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString label_name READ getLabelName WRITE setLabelName NOTIFY labelNameChanged)

public:
    explicit AbstractModelObserver(QObject *parent = nullptr, ObjectNotifier* notifier = nullptr);
    virtual void updateLabel() = 0;

public slots:
    const QString& getLabelName() const;
    void setLabelName(const QString& label_name);

signals:
    void labelNameChanged();

private:
    QString label_name;
};

#endif // ABSTRACT_MODEL_OBSERVER_HPP
