#include "observer_screen_controller.hpp"
#include "observers.hpp"
#include <QQmlContext>

ObserverScreenController::ObserverScreenController(QQmlApplicationEngine* engine, QObject *parent) noexcept
    : QObject(parent)
    , m_notifier(engine)
{
    engine->rootContext()->setContextProperty("observer_model_instance", this);
    m_model << new FirstObserver(engine, &m_notifier)
            << new SecondObserver(engine, &m_notifier)
            << new ThirdObserver(engine, &m_notifier)
            << new FourthObserver(engine, &m_notifier);
    modelChanged();
}

QList<QObject*> ObserverScreenController::getModel() const
{
    return m_model;
}

void ObserverScreenController::setModel(const QList<QObject*>& model)
{
    this->m_model = model;
    modelChanged();
}

void ObserverScreenController::updateModel()
{
    m_notifier.update();
}
