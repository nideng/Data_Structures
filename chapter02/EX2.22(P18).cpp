#include"LinkList.h"
#include<iostream>
using std::cout; using std::endl;

template<typename T>
void inversion(LinkList<T>& l)
{
	auto preit = l.zeroth();
	auto it = l.first();
	preit.getNextNode() = nullptr;
	auto afterit = it;
	afterit.advance();
	auto temp = afterit;
	temp.advance();
	while (!afterit.isPastEnd())
	{
		afterit.getNextNode() = it.getNode();
		it.getNextNode() = preit.getNextNode();
		preit.getNextNode() = it.getNode();
		it = afterit;
		afterit = temp;
		temp.advance();
	}
	preit.getNextNode() = it.getNode();
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
	inversion(l1);
	auto it1 = l1.first();
	while (!it1.isPastEnd())
	{
		cout << it1.retrieve() << endl;
		it1.advance();
	}
}