//1. try this

void suspicious(vector<int>& v, int s)
{
	try
	{
		int* p = new int[s];
		vector<int>v1;
		// . . .
		int* q = new int[s];
		vector<double> v2;
		// . . .
		delete[] p;
		delete[] q;
	}
	catch (...)
	{
		delete[] p;
		delete[] q;
		throw;
	}
}

//2. try this

template<typename T, typename A>
void vector<T,A>::reserve(int newalloc)
{
	if (newalloc<=space) return; // never decrease allocation
	try
	{
		unique_ptr<T> p = alloc.allocate(newalloc); // allocate new space
		for (int i=0; i<sz; ++i) alloc.construct(&p[i],elem[i]); // copy
		for (int i=0; i<sz; ++i) alloc.destroy(&elem[i]); // destroy
		alloc.deallocate(elem,space); // deallocate old space
		elem = p;
		space = newalloc;
		delete[] p;
		return;
	}
	catch (...)
	{
		delete[] p;
		return;
	}
}
