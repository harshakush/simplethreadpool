#ifndef IQUEUE_HEADER
#define IQUEUE_HEADER

#include<iostream>
#include<list>
#include<vector>
#include "IQueueException.h"

typedef std::vector<IWorkPtr> WQueue;
typedef std::vector<AThreadPtr> TQueue;

/**
* 
* Thread safe IQueue implementation. See how it works.
*
*
*/
enum POOL_STATE { RUNNING=0, SUSPENDED=1, STOPPED=2};
class IQueue
{
public: 
	IQueue() :  pstate(RUNNING)
	{
		if (!InitializeCriticalSectionAndSpinCount(&crt_sct_obj, 0x00000400))
		{
			cout << "Critical section initialization failed";
		}
	}

	~IQueue() {}

		
	void toRunning()
	{
		pstate = RUNNING;
	}
	
	void toSuspeneded()
	{
		pstate = SUSPENDED;
	}
	void toStopped()
	{
		pstate = STOPPED;
	}

	virtual void push_back_t(AThreadPtr t)
	{
		thrd_queue.push_back(t);
	}

	virtual void push_back_w(IWorkPtr t)
	{
		work_queue.push_back(t);
	}

	virtual AThreadPtr getNextThreadItem()
	{
		return thrd_queue.back();
	}

	virtual IWorkPtr getNextWorkItem()
	{
		EnterCriticalSection(&crt_sct_obj);
		if (!work_queue.empty())
		{
			IWorkPtr work = work_queue.back();
			work_queue.pop_back();
			LeaveCriticalSection(&crt_sct_obj);
			return work;
		}
		LeaveCriticalSection(&crt_sct_obj);
		IQueueEmtyException exp;
		throw exp;
	}
	
	virtual std::vector<AThreadPtr> getThreadQueue()
	{
		return thrd_queue;
	}

	POOL_STATE getState()
	{
		return pstate;
	}

	
private: int limit;
		 std::vector<IWorkPtr> work_queue;
		 std::vector<AThreadPtr> thrd_queue;
		 CRITICAL_SECTION crt_sct_obj;
		 POOL_STATE pstate;
		
};

typedef shared_ptr<IQueue> IQueuePtr;
#endif