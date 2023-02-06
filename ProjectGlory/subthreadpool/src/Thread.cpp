#include "Thread.h"  

CThread::CThread(void) 
{
}


void CThread::run(){
    while(1){
		if (getTaskNum())
		{			
			auto itr = vec_task_.begin();
			while (itr != vec_task_.end())
			{
				(*itr)->run_task(); // 操作
				++itr;
			}
		}
	}
}



void CThread::pushTask(Runnable *ptask){
    vec_task_.push_back(ptask);
}