// Generated code, DO NOT EDIT IT MANUALLY!

#ifndef ORG_EXAMPLE_AURORAKMP_GREETING_HPP
#define ORG_EXAMPLE_AURORAKMP_GREETING_HPP

#include <QString>

#include "libshared_api.h"

namespace org {
namespace example {
namespace aurorakmp {

class Greeting;

class Greeting
{
public:
    Greeting();
    Greeting(Greeting &&other);
    Greeting(libshared_kref_org_example_aurorakmp_Greeting ptr);
    ~Greeting();

    Greeting &operator=(Greeting &&other);

    QString greet() const;

    libshared_kref_org_example_aurorakmp_Greeting unsafeKotlinPointer() const;
private:
    libshared_kref_org_example_aurorakmp_Greeting d_ptr;
};

} /* namespace aurorakmp */
} /* namespace example */
} /* namespace org */

#endif /* ORG_EXAMPLE_AURORAKMP_GREETING_HPP */
