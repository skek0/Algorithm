#include <iostream>
#define SIZE 8

using namespace std;

void Merge(int list[], int start, int middle, int end)
{
	if (start >= end) return;

	int* temp = new int[end - start + 1];
	int left = start;
	int right = middle + 1;
	for (int count = 0; count <= end - start; count++)
	{
		if (left <= middle && right <= end)
		{
			if (list[left] < list[right])
			{
				temp[count] = list[left++];
			}
			else// list[left] > list[right]
			{
				temp[count] = list[right++];
			}
		}
		else
		{
			if (left > middle)
			{
				temp[count] = list[right++];
			}
			else // right > end
			{
				temp[count] = list[left++];
			}
		}
	}

	int n = 0;
	for (int i = start; i <= end; i++)
	{
		list[i] = temp[n++];
	}

	delete[] temp;
}

void MergeSort(int list[], int start, int end)
{
	if (start < end)
	{
		int middle = (start + end) / 2;
		MergeSort(list, start, middle);
		MergeSort(list, middle + 1, end);
		Merge(list, start, middle, end);
	}
}

int main()
{
#pragma region 병합 정렬
	// 하나의 리스트를 두개의 균등한 크기로 분할하고
	// 분할된 부분 리스트를 정렬한 다음, 두개의 정렬된 부분 리스트를
	// 합하여 전체가 정렬된 리스트가 되게 하는 방법

	// 1. 리스트의 길이가 0 또는 1이면 이미 정렬된 것으로 간주함
	// 2. 그렇지 않을 경우 
	// 2-1. 정렬되지 않은 리스트를 절반으로 잘라 비슷한 크기의
	//		두 부분 리스트로 나눔
	// 2-2. 각 부분 리스트를 재귀적으로 병합 정렬을 이용하여 정렬
	// 2-3. 두 부분 리스트를 다시 하나의 정렬된 리스트로 병합

	int arr[SIZE] = { 3,5,2,7,4,1,8,6 };
	MergeSort(arr, 0, SIZE - 1);

	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}
#pragma endregion


	return 0;
}