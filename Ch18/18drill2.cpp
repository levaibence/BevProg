#include "../std_lib_facilities.h"
#include "vector"

vector<int> gv = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(vector<int> v)
{
	vector<int> lv = v;
	for (int i = 0; i < lv.size(); ++i)
	{
		cout << lv[i] << endl;
	}
	vector<int> lv2 = lv;
	for (int i = 0; i < lv2.size(); ++i)
	{
		cout << lv2[i] << endl;
	}
	return;
}

int main()
{
	f(gv);
	vector<int> vv = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
	f(vv);
	return 0;
}
