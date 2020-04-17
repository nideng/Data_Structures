#include"SeqList.h"
#include<iostream>
template<typename T>
bool compares(T x1, T x2)
{
	return x1 > x2 ? true : false;
}

template<typename T>
void insertX(SeqList<T>& seq, T x)
{
	auto i = LocateElem<T>(seq, x, compares<T>);
	seq.ListInsert(i+1, x);
}
int main()
{
	SeqList<int>seq{ 1,2,4 };
	insertX(seq, 3);
	for (int i = 0; i != seq.ListLength(); i++)
		std::cout << seq[i] <<std:: endl;
	return 0;
}