#include <QCoreApplication>
#include "manager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Manager manager;
    QThread::currentThread()->setObjectName("Manager thread");
    manager.start();


    return a.exec();
}
