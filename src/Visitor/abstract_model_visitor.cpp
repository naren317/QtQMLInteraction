#include "abstract_model_visitor.hpp"

AbstractModelVisitor::AbstractModelVisitor(const QString& text, QObject *parent)
    : QObject(parent)
{
    setLabelName(text);
}

void AbstractModelVisitor::setLabelName(const QString& text)
{
    m_label_name = text;
    labelNameChanged();
}

const QString& AbstractModelVisitor::getLabelName() const
{
    return m_label_name;
}
