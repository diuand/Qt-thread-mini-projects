#include <QCoreApplication>
#include "worker.h"
#include <qthread.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QThread p_thread;
    QThread c_thread;

    worker consumer;
    worker producer;

    consumer.moveToThread(&c_thread);
    producer.moveToThread(&p_thread);

    producer.setIs_producer(true);

    QObject::connect(&p_thread,&QThread::started,&producer,&worker::start);
    QObject::connect(&producer,&worker::produced,&consumer,&worker::consume);

    QObject::connect(&producer,&worker::finished,&consumer,&worker::quit);

    producer.setObjectName("Producer");
    consumer.setObjectName("Consumer");
    p_thread.setObjectName("p thread");
    c_thread.setObjectName("c thread");

    p_thread.start();
    c_thread.start();

    return a.exec();
}
