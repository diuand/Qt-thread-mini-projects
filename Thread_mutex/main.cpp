#include <QCoreApplication>
#include "worker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMutex mutex;
    int count{0};

    for(int i=0;i<1;i++){
        Worker *worker = new Worker();
        worker->setMutex(&mutex);
        worker->setCount(&count);
        worker->setAutoDelete(true);


        QThreadPool::globalInstance()->start(worker);




    }
    QThreadPool::globalInstance()->waitForDone(); // remove all threads from thread pool
    qInfo()<<"counter done:" <<count;





    return a.exec();
}
