#include "observer_model_class.hpp"
#include "observers.hpp"
#include <QQmlContext>

ObserverModelClass::ObserverModelClass(QQmlApplicationEngine* engine, QObject *parent) noexcept
    : QObject(parent)
    , m_notifier(engine)
{
    engine->rootContext()->setContextProperty("observerModelInstance", this);
    m_model << new FirstObserver(engine, &m_notifier)
            << new SecondObserver(engine, &m_notifier)
            << new ThirdObserver(engine, &m_notifier)
            << new FourthObserver(engine, &m_notifier);
    modelChanged();
}

QList<QObject*> ObserverModelClass::getModel() const
{
    return m_model;
}

void ObserverModelClass::setModel(const QList<QObject*>& model)
{
    this->m_model = model;
    modelChanged();
}

void ObserverModelClass::updateModel()
{
    m_notifier.update();
}

ObserverModelClass::~ObserverModelClass()
{
    qDeleteAll(m_model);
}
