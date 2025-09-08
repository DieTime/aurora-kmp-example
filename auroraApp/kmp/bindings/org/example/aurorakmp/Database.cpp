// Generated code, DO NOT EDIT IT MANUALLY!

#include "CoroutineOperation.hpp"
#include "Database.hpp"

namespace {

QList<QString> toQListQString(libshared_kref_kotlin_collections_List kotlinList)
{
    QList<QString> qtResult;
    auto s = libshared_symbols();
    auto ns = s->kotlin.root.ru.auroraos.kmp.qtbindings.generated;
    for (int i = 0; i < ns.listGetSize(kotlinList.pinned); i++) {
        auto ptr = ns.listGetElementByIndex(kotlinList.pinned, i);
        qtResult.append(ptr != nullptr ? QString::fromUtf8((char *) ptr) : QString());
        if (ptr != nullptr) {
            s->DisposeString((char *) ptr);
        }
    }
    return qtResult;
}

} /* anonymous */

namespace org {
namespace example {
namespace aurorakmp {

Database::Database(const DatabaseDriverFactory &driverFactory)
{
    auto s = libshared_symbols();
    auto ns = s->kotlin.root.org.example.aurorakmp.Database;
    auto kotlinDriverFactory = driverFactory.unsafeKotlinPointer();
    d_ptr = ns.Database(kotlinDriverFactory);
}

Database::Database(Database &&other)
{
    d_ptr.pinned = other.d_ptr.pinned;
    other.d_ptr.pinned = nullptr;
}

Database::Database(libshared_kref_org_example_aurorakmp_Database ptr)
    : d_ptr(ptr)
{}

Database::~Database()
{
    auto s = libshared_symbols();
    s->DisposeStablePointer(d_ptr.pinned);
}

Database &Database::operator=(Database &&other)
{
    if (this != &other) {
        this->d_ptr = other.d_ptr;
        other.d_ptr.pinned = nullptr;
        return *this;
    }
    return *this;
}

QFuture<void> Database::recordCurrentVisit() const
{
    auto s = libshared_symbols();
    auto ns = s->kotlin.root.org.example.aurorakmp;
    auto coroutineLauncher = ns.recordCurrentVisitAsync(d_ptr);
    auto qtFutureResult = Aurora::Kmp::QtBindings::coroutine<void>((KotlinCoroutineLauncher *) coroutineLauncher);
    return qtFutureResult;
}

QFuture<QList<QString>> Database::getLastVisits() const
{
    auto s = libshared_symbols();
    auto ns = s->kotlin.root.org.example.aurorakmp;
    auto coroutineLauncher = ns.getLastVisitsAsync(d_ptr);
    auto qtFutureResult = Aurora::Kmp::QtBindings::coroutine<QList<QString>>((KotlinCoroutineLauncher *) coroutineLauncher, [=](void *coroutineResult) {
        return toQListQString(libshared_kref_kotlin_collections_List{ coroutineResult });
    });
    return qtFutureResult;
}

libshared_kref_org_example_aurorakmp_Database Database::unsafeKotlinPointer() const
{
    return d_ptr;
}

} /* namespace aurorakmp */
} /* namespace example */
} /* namespace org */
