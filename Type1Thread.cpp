#include <Windows.h>
#include <process.h> 
#include "Type1Thread.h"
#include "AThread.h"

class IQueue;

Type1Thread::Type1Thread(IQueuePtr& contained) : tname("typ1") {
	thd = (HANDLE)_beginthreadex(NULL, NULL, AThread::run_final, &contained, CREATE_SUSPENDED, 0);
}

Type1Thread::~Type1Thread()
{
	CloseHandle(thd);
}

void Type1Thread::setWork(IWorkPtr p) {
	work = p;
}

bool Type1Thread::run() {
	ResumeThread(thd);
	return true;
}

string Type1Thread::getTname() { 
	return tname; 
}