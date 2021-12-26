#include "abstract_model_design_patterns.hpp"

AbstractModelDesignPatterns::AbstractModelDesignPatterns(QObject* parent) : QObject(parent)
{
}

QString AbstractModelDesignPatterns::getDesignName() const
{
    return design_name;
}

void AbstractModelDesignPatterns::setDesignName(const QString& name)
{
    design_name = name;
    designNameChanged();
}
