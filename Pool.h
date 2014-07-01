#ifndef IPOOL_HEADER
#define IPOOL_HEADER
#include<iostream>
#include<list>
#include<vector>
#include "IWork.h"
#include "IThread.h"
using namespace std;

class IPool
{
public: IPool();
		
		~IPool()
		{
			cout << "Ipool destructor called";
		}
		virtual void init(const int limi);
		

		virtual void add_work(IWorkPtr item);
		

		virtual void run_all();

		virtual void wait_all();

		
private: int limit;
		 std::vector<IWorkPtr> work_queue;
		 std::vector<IThreadPtr> thrd_queue;
};
typedef  SP<IPool> IPoolPtr;
#endif