#pragma once

#include <QSharedPointer>
#include "abstractcompany.h"

/*!
 * \brief The CompanyRegistry class это реестр компаний, **синглтон**
 */
class CompanyRegistry
{
    CompanyRegistry() {}
    ~CompanyRegistry() {}

public:
    CompanyRegistry(const CompanyRegistry&)= delete;
    CompanyRegistry& operator=(const CompanyRegistry&) = delete;
    CompanyRegistry(CompanyRegistry&&) = delete;
    CompanyRegistry& operator=(CompanyRegistry&&) = delete;

    static CompanyRegistry& Instance()
    {
        static CompanyRegistry instance;
        return instance;
    }

    void addCompany(const QSharedPointer<AbstractCompany>& company);

    /*!
     * \brief getCompanyByIndex -- получить компанию по индексу
     * \param index             -- индекс
     * \return                  -- компания, если есть, иначе nullptr
     */
    QSharedPointer<AbstractCompany> getCompanyByIndex(int index) const;

    /*!
     * \brief replaceCompanyByIndex -- изменяет компанию по индексу. Прочие изменяторы не имеют смысла из-за умного указателя
     * \param index                 -- индекс
     * \param newCompany            -- чем заменить
     * \return                      -- если индекс корректен, то true, иначе false
     */
    bool replaceCompanyByIndex(int index, const QSharedPointer<AbstractCompany> newCompany);

    int getCompaniesCount() const;

private:
    QList<QSharedPointer<AbstractCompany>> companies_;
};
