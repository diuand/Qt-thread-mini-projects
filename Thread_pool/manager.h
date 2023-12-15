#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include "worker.h"


class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = nullptr);
    ~Manager();
signals:
    //void work(); it cant be sended signals to a specific worker in a thread pool


public slots:
    void started();
    void finished();
    void start();

};

#endif // MANAGER_H
