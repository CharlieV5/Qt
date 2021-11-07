#include "QtProgressTest.h"

QtProgressTest::QtProgressTest(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);    
    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(doSomething()));

    my_thread = new MyThread(this);
    workerThread = new QThread(this);
    worker = new MyQtWorker;
    //worker->moveToThread(workerThread);

    //connect(workerThread, &QThread::started, worker, &MyQtWorker::doMyJob);
    //connect(worker, &MyQtWorker::done, workerThread, &QThread::quit);
    //connect(workerThread, &QThread::finished, workerThread, &QThread::deleteLater);
    connect(worker, &MyQtWorker::progress, this, &QtProgressTest::updateProgress);

    connect(my_thread, &MyThread::progress, this, &QtProgressTest::updateProgress);

}

QtProgressTest::~QtProgressTest()
{
    delete my_thread;
    delete worker;
    delete workerThread;
}

void QtProgressTest::updateProgress(int p, const char* msg)
{
    ui.progressBar->setValue(p);
    ui.label->setText(msg);
}

void QtProgressTest::doSomething()
{
    //my_thread->start();

    //workerThread->start();

    worker->start();
}