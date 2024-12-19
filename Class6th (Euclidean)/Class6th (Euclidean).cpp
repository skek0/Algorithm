#include <iostream>

using namespace std;

int Euclid(int x, int y)
{
	//1.두개의 자연수 x와 y가 있다
	//	x와 y로 나눈 나머지를 R이라고 함
	//2.R이 0이라면, x와 y의 최대공약수는 y
	//3.R이 0이 아니라면, x와 y의 최대공약수는 y와 R의 
	//	최대공약수와 같기 떄문에 x에는 y그리고 y에는 R을 대입한 후
	//  1.로 돌아감

	if (x < y)
	{
		swap(x, y);
	}

	int R = x % y;
	if (R == 0) return y;
	while (R != 0)
	{
		x = y;
		y = R;
		R = x % y;
	}
	return y;
}


int main()
{
#pragma region 유클리드 호제법
	// 2개의 자연수 또는 정수의 최대 공약수를 구하는 방식으로
	// 두 수가 서로 상대방 수를 나누어서 원하는 수를 얻어내는 알고리즘입니다.

	cout << "By Euclid : " << Euclid(36, 24) << endl;
#pragma endregion


	return 0;
}