#include "launch_screen_controller.hpp"
#include "observer_design_pattern.hpp"
#include "visitor_design_pattern.hpp"
#include "strategy_design_pattern.hpp"
#include "abstract_factory_design_pattern.hpp"
#include "adapter_design_pattern.hpp"
#include <QQmlContext>

LaunchScreenController::LaunchScreenController(QQmlApplicationEngine* engine, QObject* parent): QObject(parent)
{
    engine->rootContext()->setContextProperty("launch_screen_controller", this);
    m_model << new ObserverDesignPattern(tr("Observer Pattern"));
    m_model << new VisitorDesignPattern(tr("Visitor Pattern"));
    m_model << new AdapterDesignPattern(tr("Adapter Pattern"));
    m_model << new StrategyDesignPattern(tr("Strategy Pattern"));
    m_model << new AbstractFactoryDesignPattern(tr("Abstract Factory Pattern"));
    modelChanged();
}

const QList<QObject*>& LaunchScreenController::getLaunchScreenModel() const
{
    return m_model;
}

void LaunchScreenController::setLaunchScreenModel(const QList<QObject*> model)
{
    m_model = model;
    modelChanged();
}
