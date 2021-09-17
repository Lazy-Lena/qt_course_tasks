#pragma once

#include <QSharedPointer>
#include <QMap>
class AbstractDirectoryStrategy;

class AbstractStatHolder
{
public:
    virtual ~AbstractStatHolder() {}

    void setStatsGrouped(bool grouped);

    void updateStatistics(const QMap<QString, double> &stats);

protected:
    virtual void updateStatisticsImpl(const QMap<QString, double> &stats) = 0;

protected:
    bool m_statIsGrouped = false;
    QMap<QString, double> m_stats;
};
