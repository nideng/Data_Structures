#include<iostream>
#include<stdexcept>
using std::invalid_argument;
int func(int k,int m)
{
	int fm = 0;
	if (k < 2 || m < 0)//±ðÍüÁË´ËÅÐ¶Ï
		throw invalid_argument("invalid arguments");
	if (m < k - 1)
		return 0;
	else if (m == k - 1)
		return 1;
	else
	{
		for (int i = 1; i <= k; ++i)
			fm += func(k, m - i);
		return fm;
	}
}
int main()
{
	std::cout << func(2, 10);
}