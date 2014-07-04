
#ifndef IPOOL_HEADER
#define IPOOL_HEADER

#include<iostream>
#include<list>
#include<vector>
#include <Windows.h>
#include <memory>
//#include "IQueue.h"

//user defined
#include "AThread.h"

using namespace std;

class IQueue;

class IPool
{
public: IPool();
		
		~IPool();
		
		virtual void init();
		

		virtual void add_work(IWorkPtr item);
		
		//virtual IWorkPtr getNextWorkItem();
		

		virtual void run_all();

		virtual void wait_all();

				
private: int limit;
		 std::vector<IWorkPtr> work_queue;
		 std::vector<AThreadPtr> thrd_queue;
		 CRITICAL_SECTION crt_sct_obj;
		 shared_ptr<IQueue>  queue_pvt;
		
};
typedef  shared_ptr<IPool> IPoolPtr;
#endif