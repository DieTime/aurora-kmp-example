#ifndef COM_EXAMPLE_AURORAKMP_GREETING_HPP
#define COM_EXAMPLE_AURORAKMP_GREETING_HPP

#include "org/example/aurorakmp/Greeting.hpp"

#include <QObject>

class Greeting : public QObject {
    Q_OBJECT

public:
    Greeting(QObject *parent = nullptr)
        : QObject(parent)
    {}

public slots:
    QString greet() const {
        return greeting_binding_.greet();
    }

private:
    org::example::aurorakmp::Greeting greeting_binding_;
};

#endif /* COM_EXAMPLE_AURORAKMP_GREETING_HPP */