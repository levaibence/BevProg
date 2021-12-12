#include "../std_lib_facilities.h"

int ga[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(int array[], int size)
{
	int la[10];
	for (int i = 0; i < size; ++i)
	{
		la[i] = array[i];
		cout << la[i] << endl;
	}
	int* p = new int[size];
	for (int i = 0; i < size; ++i)
        {
                p[i] = array[i];
                cout << p[i] << endl;
        }
	delete[] p;
	return;
}

int main()
{
	f(ga, 10);
	int aa[10] = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
	f(aa, 10);
	return 0;
}
