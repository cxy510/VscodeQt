#pragma once
#include "Thread.h"
#define TNUM 1

class ThreadManager
{

public:
	ThreadManager();
	~ThreadManager();
	void startThread();
	void endThread();
	void pushtask(Runnable *ptask);
private:
	CThread thread_group_[TNUM];
};

