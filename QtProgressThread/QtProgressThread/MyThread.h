#pragma once
#include <QThread>
#include "TimeComsumingWork.h"
class QtProgressTest;
class MyThread : public QThread
{
    Q_OBJECT

public:

    MyThread(QtProgressTest* creator, QObject* parent = NULL);

signals:
    void progress(int p, const char* msg);

protected:

    void run() override;

    void startWork();

    void startMyWork();

    QtProgressTest* m_thread_creator;
};

