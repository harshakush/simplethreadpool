#ifndef IWORK_HEADER
#define IWORK_HEADER

#include <iostream>
#include "SmartPointer.h"
#include <memory>
using namespace std;

class IWork
{
	public:
		IWork()
		{

		}
				
		virtual ~IWork() 
		{
			cout << "I work destructor";
		}
		virtual bool do_work() = 0;
};

typedef  shared_ptr <IWork> IWorkPtr;

#endif