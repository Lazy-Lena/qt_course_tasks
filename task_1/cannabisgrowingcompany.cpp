#include "cannabisgrowingcompany.h"

AbstractCompany::CompanyType CannabisGrowingCompany::getCompanyType() const
{
    return PLANTS_COMPANY_TYPE;
}

double CannabisGrowingCompany::getMonthlyTaxes() const
{
     return 0.2 * m_companyIncome * m_companyArea / 100;
}
