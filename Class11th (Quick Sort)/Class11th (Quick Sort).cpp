#include <iostream>
#define SIZE 6

using namespace std;
void Print(int list[])
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << list[i] << " ";
	}cout << endl;

}
void QuickSort(int list[], int start, int end)
{
	if (start >= end) return;

	int pivot = start;
	int left = start + 1;
	int right = end;
	while (left < right)
	{
		while (left <= end && list[pivot] >= list[left])left++;
		while (right > start && list[pivot] <= list[right]) right--;

		if (left > right)
		{
			swap(list[pivot], list[right]);
		}
		else
		{
			swap(list[left], list[right]);
		}
	}

	swap(list[right], list[0]);

	//pivot을 기준으로 나누어진 두 배열에 대해 재귀적으로 퀵 정렬
	QuickSort(list, start, right - 1);
	QuickSort(list, right + 1, end);

}

int main()
{
#pragma region 퀵 정렬
	// 기준점을 획득한 다음 기준점을 기준으로 배열을 나누고
	// 한쪽에는 기준점보다 작은 값들이, 다른쪽에는 기준점보다 큰 값들이 
	// 위치하도록 정렬하는 알고리즘

	// 나누어진 하위 배열에 대해 재귀적으로 퀵 정렬을 호출하여
	// 모든 배열이 기본 배열이 될 때까지 반복하면서 정렬
	int arr[SIZE] = { 5,4,6,2,1,3 };

	QuickSort(arr, 0, SIZE - 1);

	for (const int& num : arr)
	{
		cout << num << " ";
	}
#pragma endregion


	return 0;
}