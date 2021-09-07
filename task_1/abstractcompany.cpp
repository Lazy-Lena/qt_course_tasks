#include "abstractcompany.h"
#include <stdexcept>

QList<QString> AbstractCompany::CompanyTypeNames = {"Inductry", "Plants", "Fuel", "Gaming", "Government", "Banks"};

AbstractCompany::AbstractCompany(const QString &name)
    : m_companyName(name)
    , m_companyIncome(0.)
    , m_companyArea(0.)
    , m_employeeNumber(0)
{ }

QString AbstractCompany::getCompanyName() const
{
    return m_companyName;
}

void AbstractCompany::setCompanyName(const QString &value)
{
    m_companyName = value;
}

QList<QString> AbstractCompany::getOwners() const
{
    return m_owners;
}

void AbstractCompany::setOwners(const QList<QString> &value)
{
    if (value.isEmpty())
        throw std::runtime_error("Company should have at least one owner");
    m_owners = value;
}

double AbstractCompany::getCompanyIncome() const
{
    return m_companyIncome;
}

void AbstractCompany::setCompanyIncome(double value)
{
    m_companyIncome = value;
}

double AbstractCompany::getCompanyArea() const
{
    return m_companyArea;
}

void AbstractCompany::setCompanyArea(double value)
{
    if (value <= 0)
        throw std::runtime_error("Company area must be > 0");
    m_companyArea = value;
}

int AbstractCompany::getEmployeeNumber() const
{
    return m_employeeNumber;
}

void AbstractCompany::setEmployeeNumber(int value)
{
    if (value <= 0)
        throw std::runtime_error("Employee number must be > 0");
    m_employeeNumber = value;
}
