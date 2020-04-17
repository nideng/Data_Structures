#include"LinkList.h"
#include<iostream>
using std::cout; using std::endl;

template<typename T>
void duplicate_removal(LinkList<T>& li)
{
	auto preitr = li.zeroth();
	auto itr = li.first();
	preitr.advance();
	itr.advance();
	for(;!itr.isPastEnd();itr.advance())
	{
		if (preitr.retrieve() == itr.retrieve())
		{
			li.remove(preitr);
			itr = preitr;
		}
		else
			preitr.advance();
	}
}
int main()
{
	LinkList<int>l1;
	auto it = l1.zeroth();
	for (int i = 0; i < 10; i++)
	{
		l1.insert(i, it);
		it.advance();
	}
	l1.insert(9, it);
	it.advance();
	l1.insert(9, it);
	it.advance();
	l1.insert(9, it);
	it.advance();
	l1.insert(10, it);
	it.advance();
	l1.insert(10, it);
	duplicate_removal(l1);
	auto it1 = l1.first();
	while (!it1.isPastEnd())
	{
		cout << it1.retrieve() << endl;
		it1.advance();
	}
}