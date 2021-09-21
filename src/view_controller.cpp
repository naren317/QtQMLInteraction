#include "view_controller.hpp"
#include <QDebug>
#include <QQmlEngine>
#include <QJSEngine>
#include <QStack>
#include <QMap>
#include <functional>

struct ViewController::impl {

    QString qml_name;
    QStack<ViewController::ViewIndex> screen_stack;
};

ViewController::ViewController() noexcept : pImpl(std::make_shared<impl>())
{
    qmlRegisterType<ViewController>("ViewController",1,0,"ViewController");
    pushViewScreen(ViewIndex::Launch_Screen);
}

QString ViewController::getQMLname() const
{
    return pImpl->qml_name;
}

void ViewController::setQMLname(const QString& qml)
{
    pImpl->qml_name = qml;
    emit qmlnameChanged();
}

void ViewController::pushViewScreen(ViewIndex screen_index)
{
    pImpl->screen_stack.push(screen_index);
    setQMLname(getIndexToScreen(pImpl->screen_stack.top()));
}

ViewController::ViewIndex ViewController::popViewScreen()
{
    if(pImpl->screen_stack.size() > 1)
    {
        pImpl->screen_stack.pop();
        setQMLname(getIndexToScreen(pImpl->screen_stack.top()));
    }
    return pImpl->screen_stack.top();
}

QString ViewController::getIndexToScreen(ViewIndex screen_index)
{
    return QVariant::fromValue(screen_index).toString().append(".qml");
}
