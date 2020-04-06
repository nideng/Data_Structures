#include<iostream>
auto sorts(int (&arr)[3])->int (&)[3]
{
	for (int i = 1; i < 3; i++)
	{
		for (int j = 0; j < 3-i; j++)
		{
			if (arr[j + 1] > arr[j])
				std::swap(arr[j + 1], arr[j]);
		}
	}
return arr;
}
int main()
{
	int arr[3] = { 1,3,2 };

	for (auto e : sorts(arr))
		std::cout << e << std::endl;
}