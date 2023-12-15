#include "worker.h"

Worker::Worker()
{

}

void Worker::run()
{
    qInfo()<<"Running";
    for(int i=0;i<10;i++){
        QMutexLocker locker(mutex);
        (*count)++;
        qInfo()<<"counter:"<<*count;
    }
    qInfo()<<"done";
}

void Worker::setMutex(QMutex *newMutex)
{
    mutex = newMutex;
}

void Worker::setCount(int *newCount)
{
    count = newCount;
}
