

#include "Pool.h"
#include "IWork.h"
#include "AThread.h"
#include "Type1Thread.h"
#include <Windows.h>
#include "IQueue.h"
IPool::IPool()
{
	init();
}

IPool::~IPool()
{
	DeleteCriticalSection(&crt_sct_obj);
	cout << "Ipool destructor called";
}


void IPool::init()
{

	queue_pvt = IQueuePtr(new IQueue());
	if (!InitializeCriticalSectionAndSpinCount(&crt_sct_obj,
		0x00000400))
	{
		cout << "Failed to initialize the critical section";
	}
	
	int lim = 5; // queue_pvt.work_queue.size();
	for (int i = 0; i < lim; i++)
	{
		AThreadPtr thd(new Type1Thread(queue_pvt));
		queue_pvt->push_back_t(thd);
	}

}


/*
IWorkPtr IPool::getNextWorkItem()
{
	EnterCriticalSection(&crt_sct_obj);
	// Access the shared resource.

	//IWorkPtr returnable =queue_pvt->getWorkQueue().back();

	// Release ownership of the critical section.
	LeaveCriticalSection(&crt_sct_obj);

	return returnable;
}
*/

void IPool::add_work(IWorkPtr item)
{
	EnterCriticalSection(&crt_sct_obj);
	// Access the shared resource.

	queue_pvt->push_back_w(item);

	// Release ownership of the critical section.
	LeaveCriticalSection(&crt_sct_obj);	
}

void IPool::run_all()
{
	for each (AThreadPtr tr in queue_pvt->getThreadQueue())
	{
		tr->run();
	}
}

void IPool::wait_all()
{
	HANDLE *array = new HANDLE[queue_pvt->getThreadQueue().size()];
	int i = 0;

	for each (AThreadPtr tr in queue_pvt->getThreadQueue()) {
		array[i++] = tr->getHandle();
	}

	WaitForMultipleObjectsEx(queue_pvt->getThreadQueue().size(), array, true, INFINITE, true);
	delete [] array;
}