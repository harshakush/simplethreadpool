#ifndef T1THREAD_HEADER
#define T1THREAD_HEADER

#include "AThread.h"
#include <Windows.h>
#include <process.h> 
#include "IQueue.h"


class Type1Thread : public AThread
{
public:
	Type1Thread(IQueuePtr &queue_par);

	virtual ~Type1Thread();
	virtual void setWork(IWorkPtr p);


	virtual bool run();

	virtual string getTname();

	virtual HANDLE getHandle() { return thd; }
private:
	string tname;
	IWorkPtr work;
	HANDLE thd;
};

typedef  shared_ptr<Type1Thread> Type1ThreadPtr;

#endif