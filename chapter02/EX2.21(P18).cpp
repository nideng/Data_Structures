#include"SeqList.h"
#include<iostream>
using std::cout; using std::endl;

template<typename T>
void inversion(SeqList<T>&l1)
{
	int i = 0;
	int j = l1.ListLength() - 1;
	while(i != j&&i<j)
	{
		auto temp = l1[i];
		l1[i] = l1[j];
		l1[j] = temp;
		i++, j--;
	}
}
int main()
{
	SeqList<int>seq{ 1,2,3,4,5 };
	inversion(seq);
	for (int i = 0; i < seq.ListLength(); i++)
		cout << seq[i] << endl;
	return 0;
}
