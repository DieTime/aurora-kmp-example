// Generated code, DO NOT EDIT IT MANUALLY!

#ifndef ORG_EXAMPLE_AURORAKMP_GITHUBREPOSITORY_HPP
#define ORG_EXAMPLE_AURORAKMP_GITHUBREPOSITORY_HPP

#include <QFuture>
#include <QString>

#include "libshared_api.h"

namespace org {
namespace example {
namespace aurorakmp {

class GithubRepository;

class GithubRepository
{
public:
    GithubRepository();
    GithubRepository(GithubRepository &&other);
    GithubRepository(libshared_kref_org_example_aurorakmp_GithubRepository ptr);
    ~GithubRepository();

    GithubRepository &operator=(GithubRepository &&other);

    QFuture<QString> revision() const;

    libshared_kref_org_example_aurorakmp_GithubRepository unsafeKotlinPointer() const;
private:
    libshared_kref_org_example_aurorakmp_GithubRepository d_ptr;
};

} /* namespace aurorakmp */
} /* namespace example */
} /* namespace org */

#endif /* ORG_EXAMPLE_AURORAKMP_GITHUBREPOSITORY_HPP */
