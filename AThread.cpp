#include "AThread.h"
#include "IQueue.h"
#include <vector>


unsigned int _stdcall AThread::run_final(void *work) 
{
	while (true)
	{
		IQueuePtr contained = *(reinterpret_cast<IQueuePtr*>(work));
		if (contained->getState() == RUNNING)
		{
			try {

				IWorkPtr work_item = contained->getNextWorkItem();
				work_item->do_work();
			}
			catch (IQueueException &ref_excp)
			{
				goto sleep;
			}
		}
		if (contained->getState() == SUSPENDED)
		{
			sleep:	Sleep(15000);
		}

		if (contained->getState() == STOPPED)
			return 0;
	}
	//namesake
	return 0;
}