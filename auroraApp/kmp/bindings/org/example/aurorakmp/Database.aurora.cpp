// Generated code, DO NOT EDIT IT MANUALLY!

#include "Database.aurora.hpp"

namespace org {
namespace example {
namespace aurorakmp {

DatabaseDriverFactory::DatabaseDriverFactory()
{
    auto s = libshared_symbols();
    auto ns = s->kotlin.root.org.example.aurorakmp.DatabaseDriverFactory;
    d_ptr = ns.DatabaseDriverFactory();
}

DatabaseDriverFactory::DatabaseDriverFactory(DatabaseDriverFactory &&other)
{
    d_ptr.pinned = other.d_ptr.pinned;
    other.d_ptr.pinned = nullptr;
}

DatabaseDriverFactory::DatabaseDriverFactory(libshared_kref_org_example_aurorakmp_DatabaseDriverFactory ptr)
    : d_ptr(ptr)
{}

DatabaseDriverFactory::~DatabaseDriverFactory()
{
    auto s = libshared_symbols();
    s->DisposeStablePointer(d_ptr.pinned);
}

DatabaseDriverFactory &DatabaseDriverFactory::operator=(DatabaseDriverFactory &&other)
{
    if (this != &other) {
        this->d_ptr = other.d_ptr;
        other.d_ptr.pinned = nullptr;
        return *this;
    }
    return *this;
}

libshared_kref_org_example_aurorakmp_DatabaseDriverFactory DatabaseDriverFactory::unsafeKotlinPointer() const
{
    return d_ptr;
}

} /* namespace aurorakmp */
} /* namespace example */
} /* namespace org */
