# include <iostream>

using namespace std;

int main(int argt, char* argv[])
{
	int x;
	cin >> x;
	int y = x * x;
	int s = (y + x) * y + y + x + 1;
	cout << s;
	return EXIT_SUCCESS;
}