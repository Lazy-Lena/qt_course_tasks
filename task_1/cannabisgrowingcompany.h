#pragma once

#include "abstractcompany.h"

class CannabisGrowingCompany: public AbstractCompany
{
public:
    using AbstractCompany::AbstractCompany;

    CompanyType getCompanyType() const;

    double getMonthlyTaxes() const;
};
