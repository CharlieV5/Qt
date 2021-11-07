#include "TimeComsumingWork.h"
#include "stdlib.h"
void TimeComsumingWork::startWork(CallbackFun callback)
{
	for (size_t i = 0; i < 100; i++)
	{
		_sleep(10);
		if (callback != nullptr)
			callback(i, "Working...");
	}

	if (callback != nullptr)
		callback(100, "Done!");
}
