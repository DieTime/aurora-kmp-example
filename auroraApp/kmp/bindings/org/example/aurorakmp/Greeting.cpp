// Generated code, DO NOT EDIT IT MANUALLY!

#include "Greeting.hpp"

namespace org {
namespace example {
namespace aurorakmp {

Greeting::Greeting()
{
    auto s = libshared_symbols();
    auto ns = s->kotlin.root.org.example.aurorakmp.Greeting;
    d_ptr = ns.Greeting();
}

Greeting::Greeting(Greeting &&other)
{
    d_ptr.pinned = other.d_ptr.pinned;
    other.d_ptr.pinned = nullptr;
}

Greeting::Greeting(libshared_kref_org_example_aurorakmp_Greeting ptr)
    : d_ptr(ptr)
{}

Greeting::~Greeting()
{
    auto s = libshared_symbols();
    s->DisposeStablePointer(d_ptr.pinned);
}

Greeting &Greeting::operator=(Greeting &&other)
{
    if (this != &other) {
        this->d_ptr = other.d_ptr;
        other.d_ptr.pinned = nullptr;
        return *this;
    }
    return *this;
}

QString Greeting::greet() const
{
    auto s = libshared_symbols();
    auto ns = s->kotlin.root.org.example.aurorakmp.Greeting;
    auto kotlinResult = ns.greet(d_ptr);
    auto qtResult = kotlinResult != nullptr ? QString::fromUtf8((char *) kotlinResult) : QString();
    if (kotlinResult != nullptr) {
        s->DisposeString(kotlinResult);
    }
    return qtResult;
}

libshared_kref_org_example_aurorakmp_Greeting Greeting::unsafeKotlinPointer() const
{
    return d_ptr;
}

} /* namespace aurorakmp */
} /* namespace example */
} /* namespace org */
