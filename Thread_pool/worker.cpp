#include "worker.h"

Worker::Worker(QObject *parent)
    : QObject{parent}
{
    qInfo()<<this<<"Created"<<QThread::currentThread();
}

Worker::~Worker()
{
    qInfo()<<this<<"Destroyed"<<QThread::currentThread();
}

void Worker::run()
{
//    emit starting
    qInfo()<<this<<"Starting"<<QThread::currentThread();
    emit started();

    // do something
    for(int i=0;i<5;i++){
        qInfo()<<this<<"running"<<QString::number(i)<<QThread::currentThread();
        QThread::currentThread()->msleep(100);
    }

//    emit finished
    qInfo()<<this<<"Finished"<<QThread::currentThread();
    emit finished();

}
