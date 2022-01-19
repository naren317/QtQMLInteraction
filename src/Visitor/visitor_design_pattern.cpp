#include "visitor_design_pattern.hpp"
#include "view_controller.hpp"

VisitorDesignPattern::VisitorDesignPattern(const QString& name) : AbstractModelDesignPatterns(name)
{}

void VisitorDesignPattern::loadPattern()
{
    ViewController::getViewController()->pushViewScreen(ViewControllerHelper::Visitor_Pattern);
}
