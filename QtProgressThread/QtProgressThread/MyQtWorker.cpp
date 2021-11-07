#include "MyQtWorker.h"
#include "TimeComsumingWork.h"
MyQtWorker* MyQtWorker::this_worker = NULL;

MyQtWorker::MyQtWorker()
{
	this_worker = this;
	this->moveToThread(&m_thread);
	connect(&m_thread, &QThread::started, this, &MyQtWorker::doMyJob);
	connect(this, &MyQtWorker::done, &m_thread, &QThread::quit);
}

MyQtWorker::~MyQtWorker()
{
	this_worker = NULL;
}

void MyQtWorker::progressCallback(int p, const char* msg)
{
	if(this_worker)
		emit this_worker->progress(p, msg);
}

void MyQtWorker::start()
{
	m_thread.start();
}

void MyQtWorker::doMyJob()
{
	TimeComsumingWork w;
	w.startWork(progressCallback);

	emit done();
}
