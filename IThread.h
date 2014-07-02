
#ifndef ITHREAD_HEADER
#define ITHREAD_HEADER

#include "stdafx.h"
#include "IWork.h"
#include "SmartPointer.h"
#include <iostream>
#include <Windows.h>
#include <memory>
using namespace std;

class IThread
{
public: IThread() { }
		virtual ~IThread() {  }
		virtual bool run() = 0;
		virtual string getTname() = 0;
		virtual void setWork(IWorkPtr work) = 0;
		virtual HANDLE getHandle() = 0;
		
		static unsigned int _stdcall run_final(void *work) {
			//IWorkPtr workk_static = reinterpret_cast<IWorkPtr>(work);
			IWorkPtr workk_static = *(reinterpret_cast<IWorkPtr*>(work));
			workk_static->do_work();

			Sleep(15000);
			return 0;
		}		
};

typedef shared_ptr<IThread> IThreadPtr;

class Type1Thread : public IThread
{
public:
	Type1Thread();
	virtual ~Type1Thread()
	{
		CloseHandle(thd);
	}
	virtual void setWork(IWorkPtr p);
	
	
	virtual bool run();
	
	virtual string getTname();

	virtual HANDLE getHandle() { return thd; }
private:
	string tname;
	IWorkPtr work;
	HANDLE thd;
};

typedef  SP<Type1Thread> Type1ThreadPtr;
#endif
