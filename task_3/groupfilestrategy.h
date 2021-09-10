#pragma once

#include "abstractdirectorystrategy.h"

class GroupFileStrategy : public AbstractDirectoryStrategy
{
public:
    static const QString DIR_MIME;
    QHash<QString, double> getDirectoryInfo(const QString &path) override;
};
