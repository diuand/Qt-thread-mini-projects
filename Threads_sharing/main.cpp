#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <QtConcurrent>
#include <QRandomGenerator>
#include <QFuture>

void test(){
    qInfo()<<"testing"<<QThread::currentThread();
}

int test_random(int max){
    qInfo()<<"get random"<<QThread::currentThread();
    QThread::currentThread()->msleep(5000);
    return QRandomGenerator::global()->bounded(max);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QThread::currentThread()->setObjectName("Main thread");

    qInfo()<<"starting"<<QThread::currentThread();

    //QtConcurrent::run(test); (asa nu asteapta pana se termina functia test)
    //asteapta ca functia test sa fie terminata
    QFuture<void> f = QtConcurrent::run(test);
    f.waitForFinished();

    // wait for test funtion to finish and get the return from it
    QFuture<int> f_r = QtConcurrent::run(test_random,10);
    qInfo()<<"random number:"<<f_r.result();

    qInfo()<<"finishing"<<QThread::currentThread();

    return a.exec();
}
