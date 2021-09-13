#pragma once
#include "core_units.h"

class CsharpClassUnit : public ClassUnit
{
public:
    using ClassUnit::ClassUnit;

    void add(const std::shared_ptr<Unit>& unit, Flags flags) override;

    std::string compile(unsigned int level = 0) const override;
};

/*!
 * \brief The CsharpMethodUnit class это класс для генерации методов.
 */
class CsharpMethodUnit : public MethodUnit
{
public:
    using MethodUnit::MethodUnit;
    std::string compile(unsigned int level = 0) const override;
};

class CsharpPrintOperatorUnit : public PrintOperatorUnit
{
public:
    using PrintOperatorUnit::PrintOperatorUnit;
    std::string compile(unsigned int level = 0) const override;
};

class CsharpUnitFactory : public UnitFactory
{
public:
    std::shared_ptr<ClassUnit> createClassUnit(const std::string& name, Unit::Flags flags) const override;

    std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) const override;

    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) const override;
};
