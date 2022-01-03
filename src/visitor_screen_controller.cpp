#include "visitor_screen_controller.hpp"
#include <QQmlContext>

AlgorithmFirst::AlgorithmFirst(const QString& text): AbstractModelVisitor(text)
{}
void AlgorithmFirst::accept(AbstractVisitor* visitor)
{
    visitor->visit(this);
}
void AlgorithmFirst::update()
{
    setLabelName(tr("Visiting Algorithm 1"));
}


AlgorithmSecond::AlgorithmSecond(const QString& text) : AbstractModelVisitor(text)
{}
void AlgorithmSecond::accept(AbstractVisitor* visitor)
{
    visitor->visit(this);
}
void AlgorithmSecond::update()
{
    setLabelName(tr("Visiting Algorithm 2"));
}


AlgorithmThird::AlgorithmThird(const QString& text) : AbstractModelVisitor(text)
{}
void AlgorithmThird::accept(AbstractVisitor* visitor)
{
    visitor->visit(this);
}
void AlgorithmThird::update()
{
    setLabelName(tr("Visiting Algorithm 3"));
}

void Visitor::visit(AlgorithmFirst* one)
{
    one->update();
}
void Visitor::visit(AlgorithmSecond* second)
{
    second->update();
}
void Visitor::visit(AlgorithmThird* third)
{
    third->update();
}

VisitorScreenController::VisitorScreenController(QQmlApplicationEngine* engine, QObject* parent)
    : QObject(parent)
    , m_timeout_interval(1000)
{
    engine->rootContext()->setContextProperty("visitor_screen_controller", this);

    setModel(m_model << new AlgorithmFirst("")
                     << new AlgorithmSecond("")
                     << new AlgorithmThird(""));

    connect(&m_timer, &QTimer::timeout, this, &VisitorScreenController::onTimeOut);
    m_timer.setInterval(m_timeout_interval);
}

VisitorScreenController::~VisitorScreenController()
{
    m_timer.stop();
    qDeleteAll(m_model);
}

void VisitorScreenController::onTimeOut()
{
    static int index = 0;
    if(index == m_model.size())
        index = 0;
    dynamic_cast<AbstractModelVisitor*>(m_model.at(index))->accept(&m_visitor);
    ++index;
}

const QList<QObject*>& VisitorScreenController::getModel() const
{
    return m_model;
}

void VisitorScreenController::setModel(const QList<QObject*>& model)
{
    m_model = model;
    modelChanged();
}

void VisitorScreenController::updateModel()
{
    if(!m_timer.isActive())
        m_timer.start();
}
