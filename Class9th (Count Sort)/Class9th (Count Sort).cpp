#include <iostream>
#define SIZE 7

using namespace std;

void CountSort(int list[])
{
	int result[5] = { 0, };

	for (int i = 0; i < SIZE; i++)
	{
		result[list[i] - 1]++;
	}

	for (int num : result)
	{
		cout << num << " ";
	}
}

int main()
{
#pragma region 계수 정렬
	// 데이터의 값을 비교하지 않고 각 원소에 데이터가 몇 개 있는지
	// 갯수를 세어 저장한 후 정렬하는 알고리즘

	int dataes[SIZE] = { 1,1,2,2,3,4,5 };

	CountSort(dataes);
#pragma endregion

	return 0;
}