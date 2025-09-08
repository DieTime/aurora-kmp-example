#include "greeting.hpp"
#include "github-repository.hpp"
#include "database.hpp"

#include <auroraapp.h>
#include <QGuiApplication>
#include <QQuickView>

int main(int argc, char* argv[]) {
    qmlRegisterType<Greeting>("Shared", 1, 0, "Greeting");
    qmlRegisterType<GithubRepository>("Shared", 1, 0, "GithubRepository");
    qmlRegisterType<Database>("Shared", 1, 0, "Database");

    QScopedPointer<QGuiApplication> app(Aurora::Application::application(argc, argv));
    app->setOrganizationName("com.example");
    app->setApplicationName("aurorakmp");

    QScopedPointer<QQuickView> view(Aurora::Application::createView());
    view->setSource(Aurora::Application::pathTo("qml/com.example.aurorakmp.qml"));
    view->show();

    return app->exec();
}
