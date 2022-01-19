#include "abstract_model_observer.hpp"
#include <QQmlApplicationEngine>
#include <QQmlContext>

ObjectNotifier::ObjectNotifier(QQmlApplicationEngine* engine, QObject *parent) : QObject(parent)
{
   engine->rootContext()->setContextProperty("object_notifier", this);
}

void ObjectNotifier::add_observer(AbstractModelObserver* object)
{
   observer_list.append(object);
}

void ObjectNotifier::update()
{
    for(auto& it: observer_list)
    {
        it->updateLabel();
    }
}

ObjectNotifier::~ObjectNotifier()
{
    qDeleteAll(observer_list);
}

AbstractModelObserver::AbstractModelObserver(QObject *parent, ObjectNotifier* notifier) : QObject(parent)
{
    notifier->add_observer(this);
    setLabelName("default");
}

const QString& AbstractModelObserver::getLabelName() const
{
    return label_name;
}

void AbstractModelObserver::setLabelName(const QString& label_name)
{
    this->label_name = label_name;
    emit labelNameChanged();
}
