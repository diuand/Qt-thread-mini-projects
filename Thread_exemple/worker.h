#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QTimer>
#include <QThread>
#include <QDebug>
#include <QRandomGenerator>

class worker : public QObject
{
    Q_OBJECT
public:
    explicit worker(QObject *parent = nullptr);

    bool getIs_producer() const;
    void setIs_producer(bool newIs_producer);
    ~worker();

signals:
    void finished();
    void produced(int value);

public slots:
    void start();
    void consume(int value);
    void quit();

private:
    QTimer *timer;
    bool is_producer=false;
    int count;
    void timeout();
};

#endif // WORKER_H
