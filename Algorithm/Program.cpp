#include <iostream>

using namespace std;
#define SIZE 5

int main()
{
#pragma region 선택 정렬
	// 주어진 리스트 중에 최소값을 찾아서 맨 앞에 위치한
	// 결과를 교체하는 방식으로 정렬하는 알고리즘

	int selection[SIZE] = { 13, 5, 2, 1, 9 };
	for (int i = 0; i < SIZE-1; i++)
	{
		int min = selection[i];
		int minIdx = i;
		for (int j = i+1; j < SIZE; j++)
		{
			if (min > selection[j])
			{
				min = selection[j];
				minIdx = j;
			}
		}
		std::swap(selection[i], selection[minIdx]);
	}

	for (const int& num : selection)
	{
		cout << num << " ";
	}
#pragma endregion


	return 0;
}