#include"LinkList.h"
#include<iostream>
using std::cout;
using std::endl;
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

template<typename T>
ListNode<T>*& maxs(LinkListItr<T>& a, LinkListItr<T>& b)
{
	if (a.retrieve() > b.retrieve())
		return a.getNode();
	else
		return b.getNode();
}


template<typename T>
void sorts(LinkList<T>& A, LinkList<T>& B, LinkList<T>& C)
{
	inversion(A);
	inversion(B);
	auto c_it = C.zeroth();
	auto a_preit = A.zeroth();
	auto b_preit = B.zeroth();
	auto a_it = A.first();
	auto b_it = B.first();
	a_preit.getNextNode() = nullptr;
	b_preit.getNextNode() = nullptr;
	while (!a_it.isPastEnd() && !b_it.isPastEnd())
	{
		c_it.getNextNode() = maxs(a_it, b_it);
		if (a_it.getNode() == maxs(a_it, b_it))
			a_it.advance();
		else
			b_it.advance();
		c_it.advance();
	}
	if (!a_it.isPastEnd())
		c_it.getNextNode() = a_it.getNode();
	else
		c_it.getNextNode() = b_it.getNode();
}
int main()
{
	LinkList<int>l1;
	auto it = l1.zeroth();
	for (int i = 0; i < 10; i++)
	{
		l1.insert(2*i-1, it);
		it.advance();
	}
	LinkList<int>l2;
	auto it2 = l2.zeroth();
	for (int i = 0; i < 15; i++)
	{
		l2.insert(i, it2);
		it2.advance();
	}
	LinkList<int>l3;
	sorts(l1, l2, l3);
	auto it3 = l3.first();
	while (!it3.isPastEnd())
	{
		cout << it3.retrieve() << endl;
		it3.advance();
	}
}