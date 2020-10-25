#include <iostream>

using namespace std;


int main(int argt, char* argv[])
{
	int x, y, s = 1;
	cin >> x >> y;
	for (int i = 1; i <= y; i++)
	{
		s = s * x;
	}
	cout << s;
	return EXIT_SUCCESS;
}