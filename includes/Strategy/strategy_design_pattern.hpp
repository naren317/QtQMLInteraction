#ifndef STRATEGYDESIGNPATTERN_HPP
#define STRATEGYDESIGNPATTERN_HPP

#include "abstract_model_design_patterns.hpp"
#include <QObject>

class StrategyDesignPattern : public AbstractModelDesignPatterns
{
public:
    StrategyDesignPattern(const QString& name = "default");
    Q_INVOKABLE void loadPattern() override;
};

#endif // STRATEGYDESIGNPATTERN_HPP
