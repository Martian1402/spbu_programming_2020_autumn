#include <iostream>

using namespace std;


int main(int argt, char* argv[])
{
	int x, f = 1;
	cin >> x;
	for (int i = 1; i <= x; i++)
	{
		f = f * i;
	}
	cout << f;
	return EXIT_SUCCESS;
}