#pragma once
#include "core_units.h"

class JavaClassUnit : public ClassUnit
{
public:
    using ClassUnit::ClassUnit;

    void add(const std::shared_ptr<Unit>& unit, Flags flags) override;

    // тут копипаста из C#
    std::string compile(unsigned int level = 0) const override;
};

/*!
 * \brief The JavaMethodUnit class это про методы в Java,
 *  тут я тоже не уверена, что обработала все сочетания правильно, пыталась немного
 */
class JavaMethodUnit : public MethodUnit
{
public:
    using MethodUnit::MethodUnit;
    std::string compile(unsigned int level = 0) const override;
};

class JavaPrintOperatorUnit : public PrintOperatorUnit
{
public:
    using PrintOperatorUnit::PrintOperatorUnit;
    std::string compile(unsigned int level = 0) const override;
};

class JavaUnitFactory : public UnitFactory
{
public:
    std::shared_ptr<ClassUnit> createClassUnit(const std::string& name, Unit::Flags flags) const override;

    std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) const override;

    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) const override;
};
