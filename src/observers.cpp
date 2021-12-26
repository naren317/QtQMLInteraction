#include "observers.hpp"


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
