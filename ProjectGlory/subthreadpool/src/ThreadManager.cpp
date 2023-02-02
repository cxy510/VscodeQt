
#include "ThreadManager.h"

ThreadManager::ThreadManager()
{
}

ThreadManager::~ThreadManager()
{
}
void ThreadManager::startThread() {
	for (int i = 0; i < TNUM; i++) {
		//thread[i].Start();
	}
}
void ThreadManager::endThread() {
	for (int i = 0; i < TNUM; i++) {
		//thread[i].Terminate(0);
	}
}
void ThreadManager::Pushtask(Runnable *ptask)
{
	// CThread *pThread = NULL;
	// int num = 10000;
	// int tasknum = 0;
	// int geti = 0;
	// tasknum = thread[0].GetTasknum();
	// for (int i = 0; i < TNUM; i++)
	// {
	// 	if (tasknum >thread[i].GetTasknum()) {
	// 		tasknum = thread[i].GetTasknum();
	// 		geti = i;
	// 	}
	// }
	// thread[geti].pushTask(ptask);
}