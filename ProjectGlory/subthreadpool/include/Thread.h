#ifndef __THREAD_H__  
#define __THREAD_H__  

//#include <QString>
#include <vector>
#include <iostream>
using namespace std;
class Runnable
{
public:
	virtual ~Runnable() {};
	virtual void Run() = 0;
};

class CThread : public Runnable
{

	public:
		CThread();
		CThread(Runnable * pRunnable);

	private:
		explicit CThread(const CThread & rhs);
		vector<Runnable*> m_taskvec;  

};

#endif  