#include <QCoreApplication>
#include <QCommandLineParser>
#include <QDebug>
#include <stdexcept>

#include "abstractcompany.h"
#include "companyregistry.h"
#include "gamingcompany.h"
#include "russianbankcompany.h"
#include "cannabisgrowingcompany.h"

namespace {

void GenerateCompanyData()
{
    srand(static_cast<unsigned>(time(nullptr)));
    QList<QSharedPointer<AbstractCompany>> data;

    QVector<QString> owners {"Sechin", "Miller", "Tsukerberg", "Durov", "Elon Musk", "Abramovich", "Pupkin", "Vasechkin", "Sidorov"};

    QSharedPointer<AbstractCompany> lol = QSharedPointer<RussianBankCompany>::create("SberBank");
    lol->setOwners(QList<QString>() << "Sechin" << "Pupkin");
    lol->setCompanyArea(200000.44);
    lol->setCompanyIncome(10000000.2);
    lol->setEmployeeNumber(30000);
    data.append(lol);

    QVector<QString> bank_names = {"PochtaBank", "AlfaBank", "Moscow Credit Bank"};
    QVector<QString> planting_names = {"Wear & Rops Co.", "Oil & Food Inc", "Somename Inc.", "Funny Things Everywhere Ltd."};
    QVector<QString> gaming_names = {"Wargaming", "Gaijin Entertainment", "Bethesda", "Ubisoft", "Sperasoft"};

    for (int i = 0 ; i < 3 + rand() % 10; ++i) {
        QString companyName = bank_names[rand() % bank_names.size()] + QString::number(rand() % 101);
        QSharedPointer<AbstractCompany> firm = QSharedPointer<RussianBankCompany>::create(companyName);
        firm->setOwners(QList<QString>() << owners[rand() % owners.size()] << owners[rand() % owners.size()]);
        firm->setCompanyArea(1000 + rand() / 10000.);
        firm->setCompanyIncome((10000 + rand() / 1000) * 100.);
        firm->setEmployeeNumber(5 + rand() / 300);
        data.append(firm);
    }

    for (int i = 0 ; i < 3 + rand() % 10; ++i) {
        QString companyName = bank_names[rand() % bank_names.size()] + QString::number(rand() % 101);
        QSharedPointer<AbstractCompany> firm = QSharedPointer<CannabisGrowingCompany>::create(companyName);
        firm->setOwners(QList<QString>() << owners[rand() % owners.size()] << owners[rand() % owners.size()]);
        firm->setCompanyArea(10000 + rand() / 10000.);
        firm->setCompanyIncome((100 + rand() / 1000) * 100.);
        firm->setEmployeeNumber(5 + rand() / 300);
        data.append(firm);
    }

    for (int i = 0 ; i < 3 + rand() % 10; ++i) {
        QString companyName = bank_names[rand() % bank_names.size()] + QString::number(rand() % 101);
        QSharedPointer<AbstractCompany> firm = QSharedPointer<GamingCompany>::create(companyName);
        firm->setOwners(QList<QString>() << owners[rand() % owners.size()] << owners[rand() % owners.size()]);
        firm->setCompanyArea(10 + rand() / 10000.);
        firm->setCompanyIncome((1000 + rand() / 1000) * 100.);
        firm->setEmployeeNumber(5 + rand() / 300);
        data.append(firm);
    }

    for (const auto& c : data) {
        CompanyRegistry::Instance().addCompany(c);
    }
}

void GetCompanyGroupStats(const QString &label, const QList<QSharedPointer<AbstractCompany>> &group)
{
    double income = 0.;
    double taxes = 0.;
    double employeeCount = 0.;
    double area = 0;

    for(const auto &cc : group) {
        income += cc->getCompanyIncome();
        taxes += cc->getMonthlyTaxes();
        employeeCount += cc->getEmployeeNumber();
        area += cc->getCompanyArea();
    }

    income /= group.size();
    taxes /= group.size();
    employeeCount /= group.size();
    area /= group.size();

    qInfo().noquote() << QString("Stats for company type %1:").arg(label) << "\n"
            << QString("Income = %1, Taxes= %2, Avg. Empl. = %3, Area = %4")
               .arg(income)
               .arg(taxes)
               .arg(employeeCount)
               .arg(area);
}


void ListCompaniesByType(AbstractCompany::CompanyType type)
{
    QList<QSharedPointer<AbstractCompany>> typeGroup;
    for(int i = 0; i < CompanyRegistry::Instance().getCompaniesCount(); ++i) {
        auto firm = CompanyRegistry::Instance().getCompanyByIndex(i);
        if (firm->getCompanyType() == type) {
            typeGroup.append(firm);
        }
    }

    GetCompanyGroupStats(AbstractCompany::CompanyTypeNames[type - 1], typeGroup);
}

void ListCompaniesByOwner(const QString& owner)
{
    qInfo().noquote() << "Belongs to " << owner << ":";
    for(int i = 0; i < CompanyRegistry::Instance().getCompaniesCount(); ++i) {
        auto firm = CompanyRegistry::Instance().getCompanyByIndex(i);
        if (firm->getOwners().contains(owner)){
            qInfo().noquote() << firm->getCompanyName();
        }
    }
}

void ListStatsForCompanies()
{
    auto cnt = CompanyRegistry::Instance().getCompaniesCount();
    qInfo() << "Company count = " << cnt;

    QHash<AbstractCompany::CompanyType, QList<QSharedPointer<AbstractCompany>>> allCompanies;

    for(int i = 0; i < cnt; ++i) {
        auto firm = CompanyRegistry::Instance().getCompanyByIndex(i);
        allCompanies[firm->getCompanyType()].append(firm);
    }

    for (auto type: allCompanies.keys()) {
        GetCompanyGroupStats(AbstractCompany::CompanyTypeNames[type - 1], allCompanies[type]);
    }
}

} // так ворнинги пропали

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int type = 4; // 1 - 7
    QString owner = "Sidorov";

    GenerateCompanyData();

    if (type > 0 && type < AbstractCompany::COMPANY_TYPE_COUNT) {
        ListCompaniesByType(static_cast<AbstractCompany::CompanyType>(type));
    }
    qInfo() << "\n";

    if (!owner.isEmpty()) {
        ListCompaniesByOwner(owner);
    }
    qInfo() << "\n";

    ListStatsForCompanies();

    return a.exec();
}
