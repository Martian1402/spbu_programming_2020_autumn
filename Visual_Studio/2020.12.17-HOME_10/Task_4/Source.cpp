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

	
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{  
			if (i == j)
			{
				data[i][j] = m;
				++m;
			}		
			if (j > i)
			{
				data[i][j] = i + 1;
			}
			else
			{
				data[i][j] = j + 1;
			}
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