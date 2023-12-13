#include "worker.h"

worker::worker(QObject *parent)
    : QObject{parent}
{
    qInfo()<<this<<"Created"<<QThread::currentThread();
}

bool worker::getIs_producer() const
{
    return is_producer;
}

void worker::setIs_producer(bool newIs_producer)
{
    is_producer = newIs_producer;
}

worker::~worker()
{
    qInfo()<<this<<"Destroyed"<<QThread::currentThread();
}

void worker::start()
{
    qInfo()<<this<<"Starting"<<QThread::currentThread();
    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&worker::timeout);
    if(is_producer){
        qInfo()<<this<<"Starting timer"<<QThread::currentThread();
        timer->setInterval(1000);
        timer->start();
    }
}

void worker::consume(int value)
{
    qInfo()<<this<<"consumed"<<value<<QThread::currentThread();
}

void worker::quit()
{
    qInfo()<<this<<"Quitting"<<QThread::currentThread();
    timer->stop();
    emit finished();

}

void worker::timeout()
{

    int value = QRandomGenerator::global()->bounded(100);
    count++;
    emit produced(value);
    qInfo()<<this<<"Producing"<<value<<QThread::currentThread();
    if(count > 5){
        quit();
    }

}
