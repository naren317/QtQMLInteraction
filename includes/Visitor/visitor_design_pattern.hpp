#ifndef VISITORDESIGNPATTERN_HPP
#define VISITORDESIGNPATTERN_HPP

#include "abstract_model_design_patterns.hpp"

class VisitorDesignPattern : public AbstractModelDesignPatterns
{
public:
    VisitorDesignPattern(const QString& name = "default");
    Q_INVOKABLE void loadPattern() override;
};

#endif // VISITORDESIGNPATTERN_HPP
