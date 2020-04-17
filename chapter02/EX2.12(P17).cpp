#include"SeqList.h"
#include<iostream>
using std::cout;
using std::endl;

template<typename T>
int compares(const SeqList<T>& a, const SeqList<T>& b)
{
	int i = 0;
	for (; (i != a.ListLength()) && (i != b.ListLength()); i++)
	{
		if (a[i] < b[i])
			return 1;
		else if (b[i] < a[i])
			return -1;
	}
	if (i < a.ListLength())
		return -1;
	else if (i < b.ListLength())
		return 1;
	else
		return 0;
}
int main()
{
	SeqList<int>A = { 1,2,3,4,5 };
	SeqList<int>B = { 1,2,3 ,5};
	cout << compares(A, B) << endl;
}