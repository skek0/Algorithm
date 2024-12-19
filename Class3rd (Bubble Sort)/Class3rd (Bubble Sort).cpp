#include <iostream>

using namespace std;
#define SIZE 5

int main()
{
#pragma region 거품 정렬
	// 서로 인접한 두 원소를 비교하여 정렬하는 알고리즘

	int bubble[5] = { 8, 9, 5, 3, 1 };
	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = 0; j < SIZE - i - 1; j++)
		{
			if (bubble[j] > bubble[j + 1])
			{
				std::swap(bubble[j], bubble[j + 1]);
			}
		}
	}
	for (const int& num : bubble)	// const : 읽기 전용 함수에서 데이터가 변이되는것을 방지  // & : 복사 비용이 발생할 필요 없게 함
	{
		cout << num << " ";
	}
#pragma endregion


	return 0;
}