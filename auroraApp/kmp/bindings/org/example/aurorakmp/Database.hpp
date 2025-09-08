// Generated code, DO NOT EDIT IT MANUALLY!

#ifndef ORG_EXAMPLE_AURORAKMP_DATABASE_HPP
#define ORG_EXAMPLE_AURORAKMP_DATABASE_HPP

#include <QFuture>
#include <QList>
#include <QString>

#include "Database.aurora.hpp"
#include "libshared_api.h"

namespace org {
namespace example {
namespace aurorakmp {

class Database;

class Database
{
public:
    Database(const DatabaseDriverFactory &driverFactory);
    Database(Database &&other);
    Database(libshared_kref_org_example_aurorakmp_Database ptr);
    ~Database();

    Database &operator=(Database &&other);

    QFuture<void> recordCurrentVisit() const;
    QFuture<QList<QString>> getLastVisits() const;

    libshared_kref_org_example_aurorakmp_Database unsafeKotlinPointer() const;
private:
    libshared_kref_org_example_aurorakmp_Database d_ptr;
};

} /* namespace aurorakmp */
} /* namespace example */
} /* namespace org */

#endif /* ORG_EXAMPLE_AURORAKMP_DATABASE_HPP */
