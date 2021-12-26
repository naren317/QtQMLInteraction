#ifndef OBSERVERS_HPP
#define OBSERVERS_HPP

#include "abstract_model_observer.hpp"
#include <QQmlApplicationEngine>
#include <QQmlContext>

class FirstObserver: public AbstractModelObserver
{
public:
    FirstObserver(QQmlApplicationEngine* engine = nullptr, ObjectNotifier* object = nullptr);
    void updateLabel() override;
};

class SecondObserver: public AbstractModelObserver
{
public:
    SecondObserver(QQmlApplicationEngine* engine = nullptr, ObjectNotifier* object = nullptr);
    void updateLabel() override;
};

class ThirdObserver: public AbstractModelObserver
{
public:
    ThirdObserver(QQmlApplicationEngine* engine = nullptr, ObjectNotifier* object = nullptr);
    void updateLabel() override;
};

class FourthObserver: public AbstractModelObserver
{
public:
    FourthObserver(QQmlApplicationEngine* engine = nullptr, ObjectNotifier* object = nullptr);
    void updateLabel() override;
};
#endif // OBSERVERS_HPP
