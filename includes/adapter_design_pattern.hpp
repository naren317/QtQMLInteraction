#ifndef ADAPTERDESIGNPATTERN_HPP
#define ADAPTERDESIGNPATTERN_HPP

#include "abstract_model_design_patterns.hpp"

class AdapterDesignPattern : public AbstractModelDesignPatterns
{
public:
    AdapterDesignPattern(const QString& name = "default");
    Q_INVOKABLE void loadPattern() override;
};

#endif // ADAPTERDESIGNPATTERN_HPP
