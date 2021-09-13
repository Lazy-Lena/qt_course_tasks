#include "russianbankcompany.h"

AbstractCompany::CompanyType RussianBankCompany::getCompanyType() const
{
    return BANK_COMPANY_TYPE;
}

double RussianBankCompany::getMonthlyTaxes() const
{
    if (m_owners.contains("Miller")) {
        return 0.;
    }

    return m_employeeNumber * 100 + 0.01 * m_companyIncome;
}
