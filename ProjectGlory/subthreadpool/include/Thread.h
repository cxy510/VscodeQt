#ifndef __THREAD_H__  
#define __THREAD_H__  

//#include <QString>
#include <vector>
#include <iostream>
#include <QtCore/QThread>
#include <QtDebug>
using namespace std;
class Runnable
{
public:
	virtual ~Runnable() {};
	virtual void run_task() = 0;
};

class CThread:public QThread
{

	public:
		CThread();
		int getTaskNum(){
			return vec_task_.size();
		}
		void pushTask(Runnable *ptask);
		void endThread();

	protected:
		virtual void run(); 

	private:
		explicit CThread(const CThread & rhs);
		vector<Runnable*> vec_task_;  
};

#endif  