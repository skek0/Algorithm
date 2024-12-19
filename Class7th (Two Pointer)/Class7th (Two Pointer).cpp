#include <iostream>
#define SIZE 5
using namespace std;

int main()
{
#pragma region 투 포인터
	// 두개의 포인터를 활용해서 배열의 요소를 효과적으로
	// 탐색하는 알고리즘

	// 1. 시작점과 끝나는 지점이 첫번쨰 원소를 가리키도록 한다.
	// 2. 현재 부분합이 m과 같다면 count를 증가시킨다.
	// 3. 현재 부분합이 m보다 작다면 end를 1 증가시킨다.
	// 4. 현재 부분합이 m보다 크거나 같다면 start를 1 증가시킨다.

	int list[SIZE] = { 1,2,3,2,5 };

	int start = 0, end = 0;

	int sum = list[0];
	int count = 0;

	int m = 5;

	while (start <= end /*end < SIZE*/)
	{
		if (sum == m)
		{
			count++;
		}

		if (sum < m)
		{
			end++;
			if (end >= SIZE) break;
			sum += list[end];
		}
		else //sum >= m
		{
			sum -= list[start++];
		}
	}
	cout << count;
#pragma endregion


	return 0;
}