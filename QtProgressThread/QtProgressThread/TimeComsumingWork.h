#pragma once
#include <cstdint>

typedef void(* CallbackFun)(int, const char*);

class TimeComsumingWork
{
public:
	void startWork(CallbackFun callback=nullptr);
};

