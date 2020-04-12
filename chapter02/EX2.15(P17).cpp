
#include"LinkList.h"
#include<iostream>
using std::cout; using std::endl;

template<typename T>
LinkListItr<T> connect(LinkListItr<T>& ha, unsigned m, LinkListItr<T>& hb, unsigned n)
{
	LinkListItr<T>temp;
	auto it1 = ha;
	auto it2 = hb;
	if (m <= n)
	{
		it1.advance(m);
		it1.getNextNode() = it2.getNextNode();

		hb.getNextNode()=nullptr;

		return ha;
	}
	else
	{
		it2.advance(n);
		it2.getNextNode() = it1.getNextNode();

		ha.getNextNode() = nullptr;

		return hb;
	}

}
int main()
{
	LinkList<int>l1;
	auto it = l1.zeroth();
	for (int i = 0; i < 5; i++)
	{
		l1.insert(i, it);
		it.advance();
	}
	LinkList<int>l2;
	auto it2 = l2.zeroth();
	for (int i = 5; i < 15; i++)
	{
		l2.insert(i, it2);
		it2.advance();
	}
	auto ha = l1.zeroth();
	auto hb = l2.zeroth();
	auto li = connect(ha, 5, hb, 10);
	li.advance();
	while (!li.isPastEnd())
	{
		cout << li.retrieve() << endl;
		li.advance();
	}
	return 0;
}