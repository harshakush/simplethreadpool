#include "IThread.h"
#include <Windows.h>
#include <process.h> 
Type1Thread::Type1Thread() : tname("typ1")
{

}


void Type1Thread::setWork(IWorkPtr p)
{
	work = p;
}

bool Type1Thread::run()
{
	thd = (HANDLE)_beginthreadex(NULL, NULL, IThread::run_final, &work, 0, 0);
	return true;
}

string Type1Thread::getTname() 
{ 
	return tname; 
}