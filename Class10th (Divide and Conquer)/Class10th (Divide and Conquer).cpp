#include <iostream>
#define SIZE 4

using namespace std;
int Find(int list[], int left, int right)
{
	if (left < right)
	{
		int n1 = Find(list, left, (left + right) / 2);
		int n2 = Find(list, (left + right) / 2 + 1, right);
		return n1 > n2 ? n1 : n2;
	}
	else return list[left];
}

int main()
{
#pragma region 분할 정복
	// 주어진 문제를 2개 이상의 부분으로 나눈 뒤 
	// 각 부분 문제에 대한 답을 재귀 호출을 이용해서 계산한 다음,
	// 그 답으로부터 전체 문제의 답을 계산해내는 알고리즘

	// 분할(Divide)	: 주어진 문제를 두 개 혹은 그 이상의 형식으로 나눈다.
	// 정복(Conquer)	: 나누어진 문제를 재귀적으로 해결해서 나누어진 문제를
	//				  더 이상 나눌 필요가 없을 떄까지 계속 분할
	// 통합(Combine)	: 나누어서 해결한 문제들을 통합해서 원래의 문제를 해결

	int list[SIZE] = { 5,99,2,1 };
	cout << Find(list, 0, SIZE - 1) << endl;

#pragma endregion


	return 0;
}