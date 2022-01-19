#include "abstract_model_design_patterns.hpp"

AbstractModelDesignPatterns::AbstractModelDesignPatterns(const QString& name, QObject* parent) : QObject(parent)
{
    setDesignName(name);
}

const QString& AbstractModelDesignPatterns::getDesignName() const
{
    return design_name;
}

void AbstractModelDesignPatterns::setDesignName(const QString& name)
{
    design_name = name;
    designNameChanged();
}
