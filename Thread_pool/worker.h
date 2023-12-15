#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QThreadPool>
#include <QDebug>
#include <QRunnable>

class Worker : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);
    ~Worker();

signals:
    void started();
    void finished();


    // QRunnable interface
public:
    void run();
};

#endif // WORKER_H
