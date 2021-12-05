#include "../std_lib_facilities.h"
#include "vector"

void print_vector(ostream& os, vector<int>& v)
{
	for(int i=0; i<v.size(); i++)
	{
		os << v[i] << endl;
	}
	return;
}

void print_array(ostream& os, int* a, int n)
{
	for(int i = 0; i<n; i++)
        {
                os << a[i] << endl;
        }

        return;
}

void print_array10(ostream& os, int* a)
{
	for(int i = 0; i<10; i++)
        {
                os << a[i] << endl;
        }
	return;
}

int main()
{
	int* free1 = new int[10];
	for(int i = 0; i<10; i++)
        {
                cout << free1[i] << endl;
        }
	delete[] free1;

	int* free2 = new int[10] {100,101,102,103,104,105,106,107,108,109};
	print_array10(cout, free2);
	delete[] free2;

	int* free3 = new int[11] {100,101,102,103,104,105,106,107,108,109,110};
	print_array(cout, free3, 11);
	delete[] free3;

	int* free4 = new int[20] {100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119};
	print_array(cout, free4, 20);
	delete[] free4;

	cout << "\n";

	vector<int> vector1 = {100,101,102,103,104,105,106,107,108,109};
        print_vector(cout, vector1);

	vector<int> vector2 = {100,101,102,103,104,105,106,107,108,109,110};
	print_vector(cout, vector2);

        vector<int> vector3 =  {100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119};
        print_vector(cout, vector3);

	//2. rész

	int x = 7;
	int* p1 = &x;

	cout << "\n\nValue of p1:\t" << p1 << "\nValue of *p1:\t" << *p1 << endl;

	int* p2 = new int[7] {1,2,4,8,16,32,64};

	cout << "Value of p2: \t" << p2 << "\nValue of *p2:\t";
	for(int i = 0; i < 7; i++)
	{
		cout << p2[i] << " ";
	}
	cout << endl;

	int* p3 = p2;
	p2 = p1;
	p2 = p3;

	cout << "\nValue of p1:\t" << p1 << "\nValue of *p1:\t" << *p1 << endl;
	cout << "Value of p2: \t" << p2 << "\nValue of *p2:\t" << *p2 << endl;

	delete[] p2;

	p1 = new int[10]{1,2,4,8,16,32,64,128,256,512};
	p2 = new int[10];

	for (int i = 0; i<10; i++) p2[i] = p1[i];

	cout << "Copying pointer array\n";
	for (int i=0; i<10; i++) cout << p1[i] << ", " << p2[i] << endl;

	vector<int> v1 = {1,2,4,8,16,32,64,128,256,512};
	vector<int> v2;

	for (int i=0; i<v1.size(); i++) v2.push_back(v1[i]);

	cout << "Copying vector array\n";
	for (int i=0; i<v1.size(); i++) cout << v1[i] << ", " << v2[i] << endl;

	return 0;
}
