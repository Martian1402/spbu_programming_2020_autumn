#include <iostream>

using namespace std;

bool isPrime(int n)
{
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
		return true;
}

int main(int argt, char* argv[])
{
	int x;
	cin >> x;
	for (int i = 2; i <= x; i++)
	{
		if (isPrime(i)) 
		{
			cout << i << " ";
		}
	}
	
	return EXIT_SUCCESS;
}