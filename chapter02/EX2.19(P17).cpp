#include"LinkList.h"
#include<iostream>
using std::cout; using std::endl;

template<typename T>
void Delete_Series(LinkList<T>&l1,const T& minK, const T& maxK)
{
	LinkListItr<T>preit = l1.zeroth();
	LinkListItr<T> it = l1.first();
	while (!it.isPastEnd() && it.retrieve() <= minK)
	{
		it.advance();
		preit.advance();
	}
	auto p = preit;//P指向大于minK的第一个元素的直接前驱结点
	auto q = it;
	while (!q.isPastEnd() && q.retrieve() < maxK)
	{
		l1.remove(p);
		q = p;
		q.advance();

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
	Delete_Series(l1, 4, 10);
	auto it1 = l1.first();
	while (!it1.isPastEnd())
	{
		cout << it1.retrieve() << endl;
		it1.advance();
	}
}