// Generated code, DO NOT EDIT IT MANUALLY!

#ifndef ORG_EXAMPLE_AURORAKMP_DATABASE_AURORA_HPP
#define ORG_EXAMPLE_AURORAKMP_DATABASE_AURORA_HPP

#include "libshared_api.h"

namespace org {
namespace example {
namespace aurorakmp {

class DatabaseDriverFactory;

class DatabaseDriverFactory
{
public:
    DatabaseDriverFactory();
    DatabaseDriverFactory(DatabaseDriverFactory &&other);
    DatabaseDriverFactory(libshared_kref_org_example_aurorakmp_DatabaseDriverFactory ptr);
    ~DatabaseDriverFactory();

    DatabaseDriverFactory &operator=(DatabaseDriverFactory &&other);

    libshared_kref_org_example_aurorakmp_DatabaseDriverFactory unsafeKotlinPointer() const;
private:
    libshared_kref_org_example_aurorakmp_DatabaseDriverFactory d_ptr;
};

} /* namespace aurorakmp */
} /* namespace example */
} /* namespace org */

#endif /* ORG_EXAMPLE_AURORAKMP_DATABASE_AURORA_HPP */
