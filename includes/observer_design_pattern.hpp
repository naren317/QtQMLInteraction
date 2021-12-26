#ifndef OBSERVERDESIGNPATTERN_HPP
#define OBSERVERDESIGNPATTERN_HPP

#include "abstract_model_design_patterns.hpp"

class ObserverDesignPattern : public AbstractModelDesignPatterns
{

public:
    ObserverDesignPattern(const QString& name = "default");
    Q_INVOKABLE void loadPattern() override;
};

#endif // OBSERVERDESIGNPATTERN_HPP
