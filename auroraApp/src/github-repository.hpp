#ifndef COM_EXAMPLE_AURORAKMP_GITHUB_REPOSITORY_HPP
#define COM_EXAMPLE_AURORAKMP_GITHUB_REPOSITORY_HPP

#include "org/example/aurorakmp/GithubRepository.hpp"
#include "ru/auroraos/kmp/qtbindings/CoroutineException.hpp"

#include <QObject>
#include <QFutureWatcher>

class GithubRepository : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString revision READ revision NOTIFY revisionChanged)

public:
    GithubRepository(QObject *parent = nullptr)
        : QObject(parent)
    {}

public slots:
    QString revision() {
        if (revision_.isEmpty()) {
            QFutureWatcher<QString> *watcher = new QFutureWatcher<QString>();
            connect(watcher, &QFutureWatcher<QString>::finished, this, [this, watcher] {
                QString revision = "unknown";

                try {
                    revision = watcher->result();
                } catch (Aurora::Kmp::QtBindings::CoroutineException& ex) {
                    qDebug() << ex.message();
                }

                revision_ = revision;
                emit revisionChanged();
                watcher->deleteLater();
            });

            watcher->setFuture(github_repository_binding_.revision());
            return "...";
        }

        return revision_;
    }

signals:
    void revisionChanged();

private:
    org::example::aurorakmp::GithubRepository github_repository_binding_;
    QString revision_;
};

#endif /* COM_EXAMPLE_AURORAKMP_GITHUB_REPOSITORY_HPP */