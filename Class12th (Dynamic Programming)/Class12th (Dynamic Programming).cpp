#include <iostream>

using namespace std;

int list[100] = { 0, };
int Fibonacci(int n)
{
	if (n <= 1)
	{
		list[n] = n;
		return n;
	}
	else if (list[n] != 0)
	{
		return list[n];
	}

	return list[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main()
{
#pragma region 동적 계획법
	// 특정 범위까지의 값을 구하기 위해서 그것과
	// 다른 범위까지의 값을 이용하여 효율적으로
	// 값을 구하는 알고리즘

	// 메모리제이션 (Memorization)
	// 프로그램이 동일한 계산을 반복해야 할 떄, 
	// 이전에 계산한 값을 메모리에 저장함으로써
	// 동일한 계산을 반복 수행하는 작업을 제거하여
	// 프로그램의 실행 속도를 향상시키는 기법

	int lsit[100] = { 0, };

	cout << Fibonacci(40) << endl;
#pragma endregion


	return 0;
}