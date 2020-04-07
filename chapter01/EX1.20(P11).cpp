#include<iostream>
int polynomial(int a[], int x, int n)//a[n+1]
{
	int temp=0;
	for (int i = n; i >= 0; i--)
		temp = temp * x + a[i];
	return temp;
}
int main()
{
	int a[6] = { 1,2,3,4,5,6 };
	int x = 2;
	int n = 5;
	std::cout << polynomial(a, x, n);
	return 0;
}