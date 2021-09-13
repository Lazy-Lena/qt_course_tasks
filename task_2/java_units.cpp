#include "java_units.h"
#include <sstream>

void JavaClassUnit::add(const std::shared_ptr<Unit> &unit, Unit::Flags flags)
{
    auto accessModifier = PRIVATE;
    if (flags <= PRIVATE || flags >= FINAL) { // не шарповые!
        accessModifier = static_cast<AccessModifier>(flags);
    }
    m_fields[accessModifier].push_back(unit);
}

std::string JavaClassUnit::compile(unsigned int level) const
{
    std::stringstream result;

    std::string modifier = "private";
    if (m_flag <= PRIVATE || m_flag >= FINAL) {
        modifier = ACCESS_MODIFIERS[m_flag];
    }
    result << generateShift(level) << modifier << " class " << m_name << " {\n";

    for (size_t i = 0; i < m_fields.size(); ++i)
    {
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

std::string JavaMethodUnit::compile(unsigned int level) const
{
    std::stringstream result;

    // что-то про потоки
    if (m_flags & Modifier::SYNCHRONIZED) {
        result << "synchronized ";
    }

    if (m_flags & Modifier::STATIC) {
        result << "static ";
    } else if (m_flags & Modifier::ABSTRACT) {
        result << "abstract ";
    } else if (m_flags & Modifier::FINAL) {
        result << "final ";
    }

    result << m_returnType << ' ' + m_name << "()" << " {\n";
    for (const auto& it : m_body) {
        result << it->compile(level + 1);
    }
    result << generateShift(level) << "}\n";

    return result.str();
}

std::string JavaPrintOperatorUnit::compile(unsigned int level) const
{
    std::stringstream ss;
    ss << generateShift(level) << "System.out.println( \"" << m_text << "\" );\n";
    return ss.str();
}

std::shared_ptr<ClassUnit> JavaUnitFactory::createClassUnit(const std::string &name, Unit::Flags flags) const
{
    return std::make_shared<JavaClassUnit>(name, flags);
}

std::shared_ptr<MethodUnit> JavaUnitFactory::createMethodUnit(const std::string &name, const std::string &returnType, Unit::Flags flags) const
{
    return std::make_shared<JavaMethodUnit>(name, returnType, flags);
}

std::shared_ptr<PrintOperatorUnit> JavaUnitFactory::createPrintOperatorUnit(const std::string &text) const
{
    return std::make_shared<JavaPrintOperatorUnit>(text);
}
