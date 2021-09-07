#pragma once

#include "abstractcompany.h"

class GamingCompany: public AbstractCompany
{
public:
    using AbstractCompany::AbstractCompany;

    CompanyType getCompanyType() const;

    double getMonthlyTaxes() const;
};
