
#include "ThreadManager.h"

ThreadManager::ThreadManager()
{
}

ThreadManager::~ThreadManager()
{
}
void ThreadManager::startThread() {
	for (int i = 0; i < TNUM; i++) {
		thread_group_[i].start();
	}
}
void ThreadManager::endThread() {
	for (int i = 0; i < TNUM; i++) {
		thread_group_[i].endThread();
	}
}
void ThreadManager::pushtask(Runnable *ptask)
{
	CThread *p_thread = NULL;

	int task_num = thread_group_[0].getTaskNum();
	int input_thread_num=0;
	for (int i = 0; i < TNUM; i++)
	{
		if (task_num >thread_group_[i].getTaskNum()) {
			task_num = thread_group_[i].getTaskNum();
			input_thread_num = i;// 选择任务数最低
		}
	}
	thread_group_[input_thread_num].pushTask(ptask);
}