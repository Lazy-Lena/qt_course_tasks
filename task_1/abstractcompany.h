#pragma once

#include <QObject>
#include <QString>
#include <QList>

/*!
 * \brief The AbstractCompany class это абстрактный базовый класс
 */
class AbstractCompany
{
public:
    // Какие-то типы компаний
    enum CompanyType
    {
        INDUSTRY_COMPANY_TYPE,
        PLANTS_COMPANY_TYPE,
        PETROLEUM_COMPANY_TYPE,
        GAMBLING_COMPANY_TYPE,
        IT_COMPANY_TYPE,
        GOVERNMENT_COMPANY_TYPE,
        BANK_COMPANY_TYPE,
        COMPANY_TYPE_COUNT
    };

    static QList<QString> CompanyTypeNames;

    explicit AbstractCompany(const QString& name);
    virtual ~AbstractCompany() {}

    virtual CompanyType getCompanyType() const = 0;

    virtual double getMonthlyTaxes() const = 0;

    QString getCompanyName() const;
    void setCompanyName(const QString &value);

    QList<QString> getOwners() const;
    void setOwners(const QList<QString> &value);

    double getCompanyIncome() const;
    void setCompanyIncome(double value);

    double getCompanyArea() const;
    void setCompanyArea(double value);

    int getEmployeeNumber() const;
    void setEmployeeNumber(int value);

protected:
    QString m_companyName;
    QList<QString> m_owners;
    double m_companyIncome;
    double m_companyArea;
    int m_employeeNumber;
};
