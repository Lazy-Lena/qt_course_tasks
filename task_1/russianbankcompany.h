#pragma once

#include "abstractcompany.h"

class RussianBankCompany: public AbstractCompany
{
public:
    using AbstractCompany::AbstractCompany;

    CompanyType getCompanyType() const;

    double getMonthlyTaxes() const;
};
