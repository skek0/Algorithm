#include <iostream>
#define SIZE 6
#define TARGET 23

using namespace std;

int main()
{
#pragma region 이진 탐색
	// 탐색 범위를 반으로 나누어 찾는 값의 범위를
	// 좁혀나가는 알고리즘

	int dataes[SIZE] = { 1,6,15,22,26,30 };
	// BinarySearch(int list[], int key)로 함수로 만들어도 됨
	int left = 0;
	int right = SIZE - 1;
	int pivot;
	while (left <= right)
	{
		pivot = (left + right) / 2;
		if (dataes[pivot] == TARGET)
		{
			cout << "Found " << TARGET << endl;
			break;
		}
		else if (dataes[pivot] < TARGET)
		{
			left = pivot + 1;
		}
		else // dataes[pivot] > TARGET
		{
			right = pivot - 1;
		}
	}
	if (left > right) cout << TARGET << " is missing" << endl;
#pragma endregion


	return 0;
}