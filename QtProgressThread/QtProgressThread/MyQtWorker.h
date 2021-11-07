#pragma once
#include <qobject.h>
#include <QThread>
class MyQtWorker :
    public QObject
{
Q_OBJECT

public:
    MyQtWorker();
    ~MyQtWorker();

    static void progressCallback(int p, const char* msg);

    void start();


private:
    static MyQtWorker* this_worker;
    QThread m_thread;

signals:
    void progress(int p, const char* msg);
    void done();

public slots:
    void doMyJob();
};

