#include "manager.h"

Manager::Manager(QObject *parent)
    : QObject{parent}
{
    qInfo()<<this<<"Created"<<QThread::currentThread();
}

Manager::~Manager()
{
    qInfo()<<this<<"Destoryed"<<QThread::currentThread();
}

void Manager::started()
{
    // get the worker who send the signal
    Worker* worker = qobject_cast<Worker*>(sender());
    if(!worker) return;
    qInfo()<<worker<<"Started"<<QThread::currentThread();
}

void Manager::finished()
{
    // get the worker who send the signal
    Worker* worker = qobject_cast<Worker*>(sender());
    if(!worker) return;
    qInfo()<<worker<<"Finished"<<QThread::currentThread();
}

void Manager::start()
{
//    create some workers and connect them to the manager slots (in my actual pc is working 8 simultaneous)
    for(int i =0;i<8;i++){

        Worker *worker = new Worker();
        worker->setAutoDelete(true); // automatical cleaning

//        manager slots connection
        connect(worker,&Worker::started,this,&Manager::started,Qt::QueuedConnection);
        connect(worker,&Worker::finished,this,&Manager::finished,Qt::QueuedConnection);

        QThreadPool::globalInstance()->start(worker); // put the worker in thread pull and call the run in the worker

    }
}
