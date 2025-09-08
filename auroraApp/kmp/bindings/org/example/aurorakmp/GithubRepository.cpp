// Generated code, DO NOT EDIT IT MANUALLY!

#include "CoroutineOperation.hpp"
#include "GithubRepository.hpp"

namespace org {
namespace example {
namespace aurorakmp {

GithubRepository::GithubRepository()
{
    auto s = libshared_symbols();
    auto ns = s->kotlin.root.org.example.aurorakmp.GithubRepository;
    d_ptr = ns.GithubRepository();
}

GithubRepository::GithubRepository(GithubRepository &&other)
{
    d_ptr.pinned = other.d_ptr.pinned;
    other.d_ptr.pinned = nullptr;
}

GithubRepository::GithubRepository(libshared_kref_org_example_aurorakmp_GithubRepository ptr)
    : d_ptr(ptr)
{}

GithubRepository::~GithubRepository()
{
    auto s = libshared_symbols();
    s->DisposeStablePointer(d_ptr.pinned);
}

GithubRepository &GithubRepository::operator=(GithubRepository &&other)
{
    if (this != &other) {
        this->d_ptr = other.d_ptr;
        other.d_ptr.pinned = nullptr;
        return *this;
    }
    return *this;
}

QFuture<QString> GithubRepository::revision() const
{
    auto s = libshared_symbols();
    auto ns = s->kotlin.root.org.example.aurorakmp;
    auto coroutineLauncher = ns.revisionAsync(d_ptr);
    auto qtFutureResult = Aurora::Kmp::QtBindings::coroutine<QString>((KotlinCoroutineLauncher *) coroutineLauncher, [=](void *coroutineResult) {
        return coroutineResult != nullptr ? QString::fromUtf8((char *) coroutineResult) : QString();
    });
    return qtFutureResult;
}

libshared_kref_org_example_aurorakmp_GithubRepository GithubRepository::unsafeKotlinPointer() const
{
    return d_ptr;
}

} /* namespace aurorakmp */
} /* namespace example */
} /* namespace org */
