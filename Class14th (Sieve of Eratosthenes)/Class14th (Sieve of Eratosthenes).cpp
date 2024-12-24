#include <iostream>

using namespace std;

void Sieve(int n)
{
	int* container = new int[n + 1];
	for (int i = 0; i <= n; i++)
	{
		container[i] = i;
	}

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (container[i] == 0)
		{
			continue;
		}
		for (int j = i * 2; j <= n; j += i)
		{
			container[j] = 0;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (container[i] != 0) cout << container[i] << " ";
	}

	delete[] container;
}

bool IsPrime(int n)
{
	if (n <= 1) return false;

	for (int i = 2; i <= n / 2; i++)
	{
		if (n % i == 0) { return false; }
	}
	return true;
}

int main()
{
	cout << IsPrime(7) << endl;
	Sieve(29);

	return 0;
}