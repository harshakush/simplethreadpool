
#ifndef AThread_HEADER
#define AThread_HEADER

#include "stdafx.h"
#include "SmartPointer.h"
#include <iostream>
#include <memory>
#include <Windows.h>
#include "IWork.h"
using namespace std;

class AThread
{
public: AThread() { }
		virtual ~AThread() {  }
			virtual bool run() = 0;
			virtual string getTname() = 0;
			virtual void setWork(IWorkPtr work) = 0;
			virtual HANDLE getHandle() = 0;

			static unsigned int _stdcall run_final(void *work);
};

typedef shared_ptr<AThread> AThreadPtr;
#endif
