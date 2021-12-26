#ifndef MODELCLASS_HPP
#define MODELCLASS_HPP

#include "object_notifier.hpp"
#include "abstract_model_observer.hpp"
#include <QObject>
#include <QQmlApplicationEngine>
#include <QVector>

class ObserverModelClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> model READ getModel WRITE setModel NOTIFY modelChanged)

public:
    explicit ObserverModelClass(QQmlApplicationEngine* engine = nullptr, QObject *parent = nullptr) noexcept;
    ~ObserverModelClass();

public slots:
    QList<QObject*> getModel() const;
    void setModel(const QList<QObject*>& model);
    void updateModel();

signals:
    void modelChanged();

private:
    QList<QObject*> m_model;
    ObjectNotifier m_notifier;
};

#endif // MODELCLASS_HPP
