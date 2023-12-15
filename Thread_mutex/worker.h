#ifndef WORKER_H
#define WORKER_H

#include <QCoreApplication>
#include <QMutex>
#include <QMutexLocker>
#include <QDebug>
#include <QRunnable>
#include <QThreadPool>

class Worker : public QRunnable
{
public:
    Worker();



    // QRunnable interface
public:
    void run();

    void setMutex(QMutex *newMutex);

    void setCount(int *newCount);

private:
    QMutex *mutex;
    int *count;
};

#endif // WORKER_H
