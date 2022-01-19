#ifndef ABSTRACTFACTORYPATTERN_HPP
#define ABSTRACTFACTORYPATTERN_HPP

#include "abstract_model_design_patterns.hpp"

class AbstractFactoryDesignPattern : public AbstractModelDesignPatterns
{
public:
    AbstractFactoryDesignPattern(const QString& name = "default");
    Q_INVOKABLE void loadPattern() override;
};

#endif // ABSTRACTFACTORYPATTERN_HPP
