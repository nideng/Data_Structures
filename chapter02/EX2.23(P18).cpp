#include"LinkList.h"
#include<iostream>
using std::cout; using std::endl;

template<typename T>
void uni(LinkList<T>& A, LinkList<T>& B,LinkList<T>&C)
{
	auto C_preit = C.zeroth();
	auto A_preit = A.first();
	C_preit.getNextNode() = A_preit.getNode();
	auto B_preit = B.first();
	A.zeroth().getNextNode()= nullptr;
	B.zeroth().getNextNode() = nullptr;
	auto A_it = A_preit;
	A_it.advance();
	auto B_it = B_preit;
	B_it.advance();
	while (!A_it.isPastEnd() && !B_it.isPastEnd())
	{
		A_preit.getNextNode() = B_preit.getNode();
		B_preit.getNextNode() = A_it.getNode();
		A_preit = A_it;
		A_it.advance();
		B_preit = B_it;
		B_it.advance();
	}
	if (A_it.isPastEnd())
	{
		A_preit.getNextNode() = B_preit.getNode();
		B_preit.getNextNode() = B_it.getNode();
	}

}
int main()
{
	LinkList<int>A;
	auto it = A.zeroth();
	for (int i = 0; i < 20; i++)
	{
		A.insert(i, it);
		it.advance();
	}
	LinkList<int>B;
	auto it1 = B.zeroth();
	for (int i = 20; i < 30; i++)
	{
		B.insert(i, it1);
		it1.advance();
	}
	LinkList<int>C;
	uni(A, B,C);
	auto it2 = C.first();
	while (!it2.isPastEnd())
	{
		cout << it2.retrieve() << endl;
		it2.advance();
	}
}