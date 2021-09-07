#include "gamingcompany.h"


AbstractCompany::CompanyType GamingCompany::getCompanyType() const
{
    return IT_COMPANY_TYPE;
}

double GamingCompany::getMonthlyTaxes() const
{
    return m_companyIncome * (0.2 + 0.1 * m_employeeNumber);
}
