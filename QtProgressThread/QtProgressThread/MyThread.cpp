#include "MyThread.h"
#include "TimeComsumingWork.h"
#include "MyQtWorker.h"
#include "QtProgressTest.h"

MyThread::MyThread(QtProgressTest* creator, QObject* parent) : QThread(parent)
{
	m_thread_creator = creator;
}

void MyThread::run()
{
	//startWork();
	startMyWork();
}

void MyThread::startWork()
{
	for (size_t i = 1; i <= 100; i++)
	{
		msleep(10);
		emit progress(i, "Working...");
	}
	
	emit progress(100, "Done!");
}

void MyThread::startMyWork()
{
	MyQtWorker w;

	// connect the slot and signal from different thread
	connect(&w, &MyQtWorker::progress, m_thread_creator, &QtProgressTest::updateProgress);

	w.doMyJob();
}