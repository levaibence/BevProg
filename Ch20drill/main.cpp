#include "std_lib_facilities.h"

template<typename Iter1, typename Iter2>
// requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 copy2(Iter1 f1, Iter1 e1, Iter2 f2)
{
	for (Iter1 i = f1; i != e1; i++) *f2++ = *i;
	return f2;
}

int main()
{
	array<int, 10> array = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> lst = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; //1., 2., 3.

	int array2[10]; //array másolása 4.
	for (int i = 0; i<10; i++) array[i] = array2[i];

	vector<int> vec2 = vec;

	for (int i = 0; i<vec2.size(); i++) cout << vec2[i] << " ";
	cout << endl;

	list<int> lst2 = lst;

	for (auto p = lst2.begin(); p != lst2.end() ; p++) cout << *p << " ";
        cout << endl;

        for (int i = 0; i<10; i++) array[i] += 2; //5.
	for (auto p = vec.begin(); p != vec.end(); p++) {*p+=3;}
	for (auto p = lst.begin(); p != lst.end(); p++) {*p+=5;}

        copy2(array.begin(), array.end(), vec.begin()); //???????????????????????????????????????????????????????
        copy2(lst.begin(), lst.end(), array.begin());

	for(int i = 0; i < vec.size(); i++) cout << vec[i] << " ";

	vector<int>::iterator veci = find(vec.begin(), vec.end(), 3);
	if ( veci != vec.end() ) cout << distance(vec.begin(), veci) << endl;
	else cout << "nincs eredmeny." << endl;

	for(auto lstj = lst.begin(); lstj != lst.end(); lstj++) cout << *lstj << " ";

	list<int>::iterator lsti = find(lst.begin(), lst.end(), 27);
        if ( lsti != lst.end() ) cout << distance(lst.begin(), lsti) << endl;
        else cout << "nincs eredmeny." << endl;

	return 0;
}
