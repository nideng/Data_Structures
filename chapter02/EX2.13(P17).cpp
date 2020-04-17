#include"LinkList.h"
#include<iostream>
using std::cout;
using std::endl;

template<typename T>
bool compares(const T& lhs, const T& rhs)
{
	return (lhs < rhs) ? true : false;
}

template<typename T>
LinkListItr<T> LOCATE(const LinkList<T>& l, const T& x, function<bool(const T&, const T&)>f)
{
	auto preitr = l.zeroth();
	auto itr = l.first();
	while (itr.retrieve() != x && f(itr.retrieve(), x))
	{
		itr.advance();
		preitr.advance();
	}
	return preitr;
}
int main()
{
	LinkList<int> li;
	auto Itr = li.zeroth();
	for (int i = 0; i < 10; i++)
	{
		li.insert(i, Itr);
		Itr.advance();
	}
	li.remove(5);
	auto it = LOCATE<int>(li, 5, compares<int>);
	cout << it.retrieve() << endl;
}