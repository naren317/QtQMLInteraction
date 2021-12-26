#include "abstract_model_observer.hpp"
#include "object_notifier.hpp"
#include <QQmlApplicationEngine>
#include <QQmlContext>

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
