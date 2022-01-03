#include "view_controller.hpp"
#include <QQmlEngine>
#include <QStack>

QSharedPointer<ViewController> ViewController::m_view_controller = nullptr;

struct ViewController::impl {
    QString qml_name;
    QStack<ViewControllerHelper::ViewIndex> screen_stack;
};

ViewController::ViewController() noexcept : pImpl(new impl())
{
    qmlRegisterType<ViewControllerHelper>("ViewControllerHelper", 1, 0, "ViewControllerHelper");
    pushViewScreen(ViewControllerHelper::Launch_Screen);
}

QSharedPointer<ViewController> ViewController::getViewController()
{
    if ( !m_view_controller.get() )
        m_view_controller.reset(new ViewController);

    return m_view_controller;
}

const QString& ViewController::getQMLname() const
{
    return pImpl->qml_name;
}

void ViewController::setQMLname(const QString& qml)
{
    pImpl->qml_name = qml;
    emit qmlnameChanged();
}

void ViewController::pushViewScreen(ViewControllerHelper::ViewIndex screen_index)
{
    pImpl->screen_stack.push(screen_index);
    setQMLname(getIndexToScreen(pImpl->screen_stack.top()));
}

ViewControllerHelper::ViewIndex ViewController::popViewScreen()
{
    if(pImpl->screen_stack.size() > 1)
    {
        pImpl->screen_stack.pop();
        setQMLname(getIndexToScreen(pImpl->screen_stack.top()));
    }
    return pImpl->screen_stack.top();
}

QString ViewController::getIndexToScreen(ViewControllerHelper::ViewIndex screen_index) const
{
    return QVariant::fromValue(screen_index).toString().append(".qml");
}


ViewControllerHelper::ViewIndex ViewController::getCurrentViewIndex() const
{
    return pImpl->screen_stack.top();
}
