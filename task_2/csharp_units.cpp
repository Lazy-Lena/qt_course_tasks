#include "csharp_units.h"
#include <sstream>

void CsharpClassUnit::add(const std::shared_ptr<Unit> &unit, Unit::Flags flags)
{
    auto accessModifier = PRIVATE;
    if (flags <= PRIVATE_PROTECTED) { // потому что дальше java-спецификаторы
        accessModifier = static_cast<AccessModifier>(flags);
    }
    m_fields[accessModifier].push_back(unit);
}

std::string CsharpClassUnit::compile(unsigned int level) const
{
    std::stringstream result;
    result << generateShift(level) << ACCESS_MODIFIERS[m_flag]
              << " class " << m_name << " {\n";

    for (size_t i = 0; i < m_fields.size(); ++i)
    {
        // Как С++
        if (m_fields[i].empty()) {
            continue;
        }

        for (const auto& field : m_fields[i]) {
            result << generateShift(level + 1)
                   << ACCESS_MODIFIERS[i] << ' ' + field->compile(level + 1);
        }
        result << '\n';
    }

    result << generateShift(level) << "};\n";
    return result.str();
}

std::string CsharpMethodUnit::compile(unsigned int level) const
{
    std::stringstream result;

    if (m_flags & Modifier::ABSTRACT
            && !(m_flags & Modifier::VIRTUAL) && !(m_flags & Modifier::STATIC)) {
        result << "abstract ";
    }

    // у методов он тоже что-то делает
    if (m_flags & Modifier::SEALED) {
        result << "sealed ";
    }

    // я хз, что это
    if (m_flags & Modifier::UNSAFE) {
        result << "unsafe ";
    }

    // Статичный ли метод
    if (m_flags & Modifier::STATIC) {
        result << "static ";
    } else if (m_flags & Modifier::VIRTUAL) {
        result << "virtual ";
    }

    result << m_returnType << ' ' + m_name << "()" << " {\n";
    for (const auto& it : m_body) {
        result << it->compile(level + 1);
    }
    result << generateShift(level) << "}\n";

    return result.str();
}

std::string CsharpPrintOperatorUnit::compile(unsigned int level) const
{
    std::stringstream ss;
    ss << generateShift(level) << "Console.WriteLine( \"" << m_text + "\" );\n";
    return ss.str();
}

std::shared_ptr<ClassUnit> CsharpUnitFactory::createClassUnit(const std::string &name, Unit::Flags flags) const
{
    return std::make_shared<CsharpClassUnit>(name, flags);
}

std::shared_ptr<MethodUnit> CsharpUnitFactory::createMethodUnit(const std::string &name, const std::string &returnType, Unit::Flags flags) const
{
    return std::make_shared<CsharpMethodUnit>(name, returnType, flags);
}

std::shared_ptr<PrintOperatorUnit> CsharpUnitFactory::createPrintOperatorUnit(const std::string &text) const
{
    return std::make_shared<CsharpPrintOperatorUnit>(text);
}
