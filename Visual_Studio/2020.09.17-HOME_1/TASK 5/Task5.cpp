#include <iostream>

using namespace std;


int main(int argt, char* argv[])
{
	int x, r = 0;
	cin >> x;

	for (int i = 1; i * i <= x; i++)
	{
		if ((x % i == 0) && (x / i == i))
		{
			r += 1;
		}
		if ((x % i == 0) && (x / i != i))
		{
			r += 2;
		}
	}
	
	//for (int i = 1; i <= x; i++)
		//if (x % i == 0)
		//{
		//	r++;
		//}
	cout << r;
	return EXIT_SUCCESS;
}