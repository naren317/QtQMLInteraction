#include "observer_design_pattern.hpp"
#include "view_controller.hpp"

ObserverDesignPattern::ObserverDesignPattern(const QString& name): AbstractModelDesignPatterns(name)
{}

void ObserverDesignPattern::loadPattern()
{
    ViewController::getViewController()->pushViewScreen(ViewControllerHelper::Observer_Pattern);
}
