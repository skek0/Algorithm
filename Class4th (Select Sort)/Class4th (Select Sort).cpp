#include <iostream>

using namespace std;
#define SIZE 5

int main()
{
	int list[SIZE] = { 6,2,8,1,0 };

	for (int i = 0; i < SIZE; i++)
	{
		int min = list[i];
		int select = i;

		for (int j = i + 1; j < SIZE; j++)
		{
			if (min > list[j])
			{
				min = list[j];
				select = j;
			}
		}

		std::swap(list[i], list[select]);
	}
	for (const int& element : list)
	{
		cout << element << " ";
	}
}