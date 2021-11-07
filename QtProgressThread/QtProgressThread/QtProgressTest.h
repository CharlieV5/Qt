#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include "MyThread.h"
#include "MyQtWorker.h"

#include "ui_QtProgressTest.h"


class QtProgressTest : public QMainWindow
{
    Q_OBJECT

public:
    QtProgressTest(QWidget *parent = Q_NULLPTR);
    ~QtProgressTest();
public slots:
    void doSomething();
    void updateProgress(int p, const char* msg);


private:
    Ui::QtProgressTestClass ui;
    MyThread* my_thread;
    QThread* workerThread;
    MyQtWorker* worker;

};
