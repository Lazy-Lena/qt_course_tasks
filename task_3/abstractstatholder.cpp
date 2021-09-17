#include "abstractstatholder.h"

void AbstractStatHolder::setStatsGrouped(bool grouped)
{
    m_statIsGrouped = grouped;
}

void AbstractStatHolder::updateStatistics(const QMap<QString, double> &stats)
{
    m_stats = stats;
    updateStatisticsImpl(stats);
}
