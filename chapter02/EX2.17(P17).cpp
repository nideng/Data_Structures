/*
见头文件中insert
*/
#include"LinkList.h"
#include<iostream>
using std::cout;
using std::endl;
int main()
{
	LinkList<int>l1;
	auto it = l1.zeroth();
	for (int i = 0; i < 10; i++)
	{
		l1.insert(i, it);
		it.advance();
	}
	l1.insert(5, 5);
	auto it1 = l1.first();
	while (!it1.isPastEnd())
	{
		cout << it1.retrieve() << endl;
		it1.advance();
	}
}