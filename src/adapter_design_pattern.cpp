#include "adapter_design_pattern.hpp"
#include "view_controller.hpp"

AdapterDesignPattern::AdapterDesignPattern(const QString& name) : AbstractModelDesignPatterns(name)
{}


void AdapterDesignPattern::loadPattern()
{
    ViewController::getViewController()->pushViewScreen(ViewControllerHelper::Adapter_Pattern);
}
