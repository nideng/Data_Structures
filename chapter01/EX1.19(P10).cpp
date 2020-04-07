#include<iostream>
#include<limits>
#include<stdexcept>
#define arrsize 20
#define maxint INT_MAX
void func(unsigned i,unsigned (a)[])
{
	if (i+1 > arrsize)
		throw std::out_of_range("out of range");
	a[0] = 1;
	for (int j = 1; j <= i; j++)
	{
		if (a[j - 1] > (maxint / 2 / j))
			throw std::overflow_error("overflow");
		a[j] = a[j - 1] * j * 2;
	}
}
int main()
{
	unsigned arr[20];
	func(18, arr);
	for (auto e : arr)
		std::cout << e << std::endl;
}