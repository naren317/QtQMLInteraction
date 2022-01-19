#include "strategy_design_pattern.hpp"
#include "view_controller.hpp"

StrategyDesignPattern::StrategyDesignPattern(const QString& name) : AbstractModelDesignPatterns(name)
{

}

void StrategyDesignPattern::loadPattern()
{
    ViewController::getViewController()->pushViewScreen(ViewControllerHelper::Strategy_Pattern);
}
