#pragma once

#include <QFileInfo>

/*!
 * \brief The AbstractDirectoryStrategy будет использоваться в модельке, где папка существует.
 */
class AbstractDirectoryStrategy
{
public:
    virtual ~AbstractDirectoryStrategy() {}

    virtual QHash<QString, double> getDirectoryInfo(const QString &path) = 0;

protected:
    qint64 getTotalSize(const QString &path);

protected:
    QHash<QString, qint64> m_dirSizeCache; // optimization
};
