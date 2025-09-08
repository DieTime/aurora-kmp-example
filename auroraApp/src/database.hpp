#ifndef COM_EXAMPLE_AURORAKMP_DATABASE_HPP
#define COM_EXAMPLE_AURORAKMP_DATABASE_HPP

#include "org/example/aurorakmp/Database.hpp"
#include "ru/auroraos/kmp/qtbindings/CoroutineException.hpp"

#include <QObject>
#include <QStringList>
#include <QFutureWatcher>

class Database : public QObject {
    Q_OBJECT
    Q_PROPERTY(QStringList lastVisits READ getLastVisits NOTIFY lastVisitsChanged)

public:
    Database(QObject *parent = nullptr)
        : QObject(parent)
        , database_binding_(org::example::aurorakmp::DatabaseDriverFactory())
    {}

public slots:
    void recordCurrentVisit() {
        QFutureWatcher<void> *watcher = new QFutureWatcher<void>();
        connect(watcher, &QFutureWatcher<QString>::finished, this, [this, watcher] {
            emit recordCurrentVisitCompleted();
            watcher->deleteLater();
        });
        watcher->setFuture(database_binding_.recordCurrentVisit());
    }

    void updateLastVisits() {
        QFutureWatcher<QList<QString>> *watcher = new QFutureWatcher<QList<QString>>();
        connect(watcher, &QFutureWatcher<QString>::finished, this, [this, watcher] {
            QList<QString> visits;

            try {
                visits = watcher->result();
            } catch (Aurora::Kmp::QtBindings::CoroutineException& ex) {
                qDebug() << ex.message();
                return;
            }

            last_visits_ = visits;
            emit lastVisitsChanged();
            watcher->deleteLater();
        });

        watcher->setFuture(database_binding_.getLastVisits());
    }

    QStringList getLastVisits() {
        return last_visits_;
    }

signals:
    void recordCurrentVisitCompleted();
    void lastVisitsChanged();

private:
    org::example::aurorakmp::Database database_binding_;
    QStringList last_visits_;
};

#endif /* COM_EXAMPLE_AURORAKMP_DATABASE_HPP */