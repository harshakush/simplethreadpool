#include "Pool.h"
#include "IThread.h"
#include <Windows.h>

IPool::IPool()
{

}
void IPool::init(const int limi)
{
	int lim = work_queue.size();
	for (int i = 0; i < lim; i++)
	{
		IThreadPtr thd(new Type1Thread());
		thd->setWork(work_queue.at(i));
		thrd_queue.push_back(thd);
	}

}

void IPool::add_work(IWorkPtr item)
{
	work_queue.push_back(item);
}

void IPool::run_all()
{
	for each (IThreadPtr tr in thrd_queue)
	{
		tr->run();
	}
}

void IPool::wait_all()
{
	HANDLE *array = new HANDLE[thrd_queue.size()];
	int i = 0;
	for each (IThreadPtr tr in thrd_queue)
	{
		array[i++] = tr->getHandle();
	}
	WaitForMultipleObjectsEx(thrd_queue.size(),array, true, INFINITE, true);
}