#include "object_notifier.hpp"
#include "abstract_model_observer.hpp"
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
