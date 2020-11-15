# include <iostream>

using namespace std;

int main(int argt, char* argv[])
{
	int a, b, z = 0, t = 1;
	cin >> a >> b;
	if (b == 0)
	{
		cout << "Tak ne rabotaet";
		return EXIT_SUCCESS;
	}
	if (a < 0)
	{
		t *= -1;
		a -= 2 * a;
	}
	if (b < 0)
	{
		t *= -1;
		b -= 2 * b;
	}
	while (b * z <= a)
	{
		z++;
	}
	cout << --z * t;
	return EXIT_SUCCESS;
}