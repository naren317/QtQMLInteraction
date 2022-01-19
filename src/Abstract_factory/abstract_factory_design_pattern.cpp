#include "abstract_factory_design_pattern.hpp"
#include "view_controller.hpp"

AbstractFactoryDesignPattern::AbstractFactoryDesignPattern(const QString& name) : AbstractModelDesignPatterns(name)
{}

void AbstractFactoryDesignPattern::loadPattern()
{
    ViewController::getViewController()->pushViewScreen(ViewControllerHelper::Abstract_Factory_Pattern);
}
