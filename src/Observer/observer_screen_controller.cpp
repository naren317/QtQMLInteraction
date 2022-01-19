#include "observer_screen_controller.hpp"
#include <QQmlContext>

FirstObserver::FirstObserver(QQmlApplicationEngine* engine, ObjectNotifier* object): AbstractModelObserver(nullptr, object)
{
    engine->rootContext()->setContextProperty("first_observer", this);
}
void FirstObserver::updateLabel()
{
    setLabelName("This");
}


SecondObserver::SecondObserver(QQmlApplicationEngine* engine, ObjectNotifier* object): AbstractModelObserver(nullptr, object)
{
    engine->rootContext()->setContextProperty("second_observer", this);
}
void SecondObserver::updateLabel()
{
    setLabelName("Uses");
}


ThirdObserver::ThirdObserver(QQmlApplicationEngine* engine, ObjectNotifier* object): AbstractModelObserver(nullptr, object)
{
    engine->rootContext()->setContextProperty("third_observer", this);
}
void ThirdObserver::updateLabel()
{
    setLabelName("Observer");
}


FourthObserver::FourthObserver(QQmlApplicationEngine* engine, ObjectNotifier* object): AbstractModelObserver(nullptr, object)
{
    engine->rootContext()->setContextProperty("fourth_observer", this);
}
void FourthObserver::updateLabel()
{
    setLabelName("Pattern");
}

ObserverScreenController::ObserverScreenController(QQmlApplicationEngine* engine, QObject *parent) noexcept
    : QObject(parent)
    , m_notifier(engine)
{
    engine->rootContext()->setContextProperty("observer_screen_controller", this);
    setModel(m_model << new FirstObserver(engine, &m_notifier)
            << new SecondObserver(engine, &m_notifier)
            << new ThirdObserver(engine, &m_notifier)
            << new FourthObserver(engine, &m_notifier));
}

const QList<QObject*>& ObserverScreenController::getModel() const
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
