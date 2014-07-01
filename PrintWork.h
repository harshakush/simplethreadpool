#ifndef PWORK_HEADER
#define PWORK_HEADER

#include<iostream>
#include "IWork.h"
using namespace std;

class PrintWork : public IWork
{
		public: 
		PrintWork()	{ 
			p = new char[5];
			p = "Harsha";
		}

		~PrintWork() {
			cout << "Print work destructor called";
		}

		virtual bool do_work() {
			cout << "Work Completed";
			return true;
		}
private :
	char *p;
};

typedef  shared_ptr<PrintWork> PrintWorkPtr;

#endif