#include <iostream>
#define SIZE 5

using namespace std;

int main()
{
#pragma region 삽입 정렬
	// 데이터를 하나씩 확인하면서 이미 정렬된 부분과 비교하여
	// 자신의 위치를 찾아 삽입하는 방식으로 정렬하는 알고리즘

	int insert[SIZE] = { 8,5,6,2,4 };

	for (int i = 1; i < SIZE; i++)
	{
		int n = i;
		int key = insert[i];
		while (n > 0 && key < insert[n - 1])
		{
			insert[n] = insert[n - 1];
			n--;
		}
		insert[n] = key;
	}

	for (const int& element : insert)
	{
		cout << element << " ";
	}
#pragma endregion

	return 0;
}