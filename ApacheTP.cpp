// ApacheTP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "AThread.h"
#include "Pool.h"
#include "PrintWork.h"
#include "SmartPointer.h"

int _tmain(int argc, _TCHAR* argv[])
{
	{
		IPool pool;
		{
			PrintWorkPtr p1(new PrintWork());
			IWorkPtr p2(new PrintWork());
			IWorkPtr p3(new PrintWork());
			IWorkPtr p4(new PrintWork());
						
			pool.add_work(p1);
			pool.add_work(p2);
			pool.add_work(p3);
			pool.add_work(p4);
			
			pool.run_all();
			pool.wait_all();
		}
	}
	return 0;
}
