#ifndef REFCNT_HEADER
#define REFCNT_HEADER

#include <iostream>

using namespace std;

class RC
{
private:
	int count; // Reference count

public:
	RC(): count(0) {}
	void AddRef()
	{
		// Increment the reference count
		count++;
	}

	int Release()
	{
		// Decrement the reference count and
		// return the reference count.
		return --count;
	}
};

#endif