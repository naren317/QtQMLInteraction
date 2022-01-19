#ifndef MODELCLASS_HPP
#define MODELCLASS_HPP

#include "abstract_model_observer.hpp"
#include <QObject>
#include <QQmlApplicationEngine>
#include <QVector>

class FirstObserver: public AbstractModelObserver
{
public:
    FirstObserver(QQmlApplicationEngine* engine = nullptr, ObjectNotifier* object = nullptr);
    void updateLabel() override;
};

class SecondObserver: public AbstractModelObserver
{
public:
    SecondObserver(QQmlApplicationEngine* engine = nullptr, ObjectNotifier* object = nullptr);
    void updateLabel() override;
};

class ThirdObserver: public AbstractModelObserver
{
public:
    ThirdObserver(QQmlApplicationEngine* engine = nullptr, ObjectNotifier* object = nullptr);
    void updateLabel() override;
};

class FourthObserver: public AbstractModelObserver
{
public:
    FourthObserver(QQmlApplicationEngine* engine = nullptr, ObjectNotifier* object = nullptr);
    void updateLabel() override;
};

class ObserverScreenController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> observer_model READ getModel WRITE setModel NOTIFY modelChanged)

public:
    explicit ObserverScreenController(QQmlApplicationEngine* engine = nullptr, QObject *parent = nullptr) noexcept;

public slots:
    const QList<QObject*>& getModel() const;
    void setModel(const QList<QObject*>& model);
    void updateModel();

signals:
    void modelChanged();

private:
    QList<QObject*> m_model;
    ObjectNotifier m_notifier;
};

#endif // MODELCLASS_HPP
