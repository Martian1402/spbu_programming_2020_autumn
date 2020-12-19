#include<iostream>

using namespace std;

int main()
{
	int m = 1;

	int n = 0;
	cin >> n;

	int** data = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		data[i] = new int[n];
	}

	if (n % 2 != 0)
	{
		data[n / 2][n / 2] = n * n;
	}

	for (int i = 0; i < (n / 2); i++)
	{
		for (int j = i; j < (n - i); j++)
		{
			data[i][j] = m;
			m++;
		}
		for (int j = 1; j < (n - i - i); j++)
		{
			data[j + i][(n - i) - 1] = m;
			m++;
		}
		for (int j = (n - 2) - i; j >= i; j--)
		{
			data[(n - i) - 1][(j)] = m;
			m++;
		}
		for (int j = (n - i) - 2; j > i; j--)
		{
			data[j][i] = m;
			m++;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%4d ", data[i][j]);
		}
		cout << endl;
	}

	for (int i = 0; i < n; ++i)
	{
		delete[] data[i];
	}
	delete[] data;

	return EXIT_SUCCESS;
}