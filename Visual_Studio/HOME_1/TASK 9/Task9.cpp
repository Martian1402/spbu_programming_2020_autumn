#include <iostream>

using namespace std;

int main(int argt, char* argv[])
{
	int n;
	cin >> n;
		n = ~(~(1 << n ) + 1);
	cout << n;
		return EXIT_SUCCESS;
}

