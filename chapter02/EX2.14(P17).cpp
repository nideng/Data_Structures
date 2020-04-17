#include"LinkList.h"
#include<iostream>
using std::endl;
using std::cout;
template<typename T>
unsigned LENGTH(const LinkList<T>& li)
{
	unsigned i = 0;
	auto itr = li.zeroth();
	for (itr.advance(); !itr.isPastEnd(); itr.advance())
		i += 1;
	return i;
}
int main()
{
	LinkList<int>li;
	cout << LENGTH(li) << endl;
	auto itr = li.zeroth();
	for (int i = 0; i < 10; i++)
		li.insert(i,itr);
	cout << LENGTH(li) << endl;
	return 0;
}
