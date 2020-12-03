#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;


int fact(int i)      
{                           
	if (i == 0 || i == 1)
	{
		return 1;
	}
	else
	{
		return i * fact(i - 1);
	}
}

double nextMem(double x, int i)
{
	double member = 0;
	member = (pow(x, 2 * i + 1)) / (fact(2 * i + 1));
	return member;
}

double MyFunction(double x, int n)
{
	double E = 1 / pow(10, n);
	double result = x;
	for (int i = 1; i < (n - 1) / 2 + 1; ++i)
	{
		result = result + nextMem(x, i);
	}
	//while (result > (floor(E * result)) / pow(10, n))
	//{
	//	result = result + nextMem(x, i);
	//	++i;
	//}
	return result;  //(floor(E * result)) / pow(10, n);
}



int main()
{
	double x = 0;
	int n = 0;
	cin >> x >> n;
	
	cout << sinh(x) << endl;
	cout << MyFunction(x, n) << endl;
	return EXIT_SUCCESS;
}

