#pragma once
#include "Thread.h"
#define TNUM 3

class ThreadManager
{

public:
	ThreadManager();
	~ThreadManager();
	void startThread();
	void endThread();
	void Pushtask(Runnable *ptask);
private:
	//CThread thread[TNUM];
};

