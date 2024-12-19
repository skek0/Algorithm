#include <iostream>

using namespace std;

int main()
{
#pragma region 브루트 포스
	// 가능한 모든 경우의 수를 탐색하면서
	// 결과를 도출하는 알고리즘

	int pw[3] = { 4,5,6 };
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				if (pw[0] == i && pw[1] == j && pw[2] == k)
				{
					cout << "password is " << pw[0] << pw[1] << pw[2] << endl;
					cout << "tried " << count << " times" << endl;
				}
				count++;
			}
		}
	}
#pragma endregion


	return 0;
}