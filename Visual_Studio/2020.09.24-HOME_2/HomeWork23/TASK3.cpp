#include <iostream>
#include<clocale>

using namespace std;


int factorial(int x)
{
	int sum = 1;
	for (int i = 1; i < x + 1; ++i)
	{
		sum *= i;
	}
	return sum;
}



int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int x = -1;
	int count = 0;
	int sum = 0;
	cout << "¬водите числа (пока не введЄте 0): " << endl;
	while (true)
	{
		if (x == 0)
		{
			break;
		}
		else
		{
			cin >> x;
			++count;
			sum += factorial(x);
		}
	}
	cout << "—реднее арифметическое факториалов последовательности чисел = " << sum / (count - 1) << endl;
	return EXIT_SUCCESS;
}
