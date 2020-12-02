#include<iostream>
#include<string>
#include<ctime>

using namespace std;

void resolveError(int errorCode)
{
	const int error = 2;
	string Code1[error] = {"Встретился неопознаный символ, повторите попытку", "Странный символ, ожидалось число (например: 56780 или 54387.098)"};
	string Code2[error] = { "Число не соответсвует требованиям программы", "Число не входит в дозволенный диапозон(от −9.223.372.036.854.775.808 до +9.223.372.036.854.775.807)" };
	if (errorCode == 1)
	{
		cout << Code1[rand() % 2 + 1] << endl;
	}
	else if (errorCode == 2)
	{
		cout << Code2[rand() % 2 + 1] << endl;
	}
}

void trim(string& str)
{
	int startIndex = 0;
	while (str[startIndex] == ' ')
	{
		startIndex++;
	}
	str = str.substr(startIndex);
}

bool isDigit(char symbol)
{
	if (symbol >= '0' && symbol <= '9' && symbol == '-')
	{
		return true;
	}
	return false;
}

int stringToInt(string& str)
{
	int result = 0;
	for (int i = 0; str[i] != '\0' && isDigit(str[i]); ++i)
	{
		result = 10 * result + str[i] - '0';
	}
	return result;
}

int readInt(long long& number)
{
	int max[19] = { 9, 2, 2, 3, 3, 7, 2, 0, 3, 6, 8, 5, 4, 7, 7, 5, 8, 0, 7};
	string str;
	getline(cin, str);
	trim(str);

	if (str.size() > 21)
	{
		number = 0;
		return 2;
	}
	if (str.size() == 19)
	{
		for (int i = 0; i < 20; i++)
		{
			if ((isDigit(str[i]) == true) & (str[i] - '0' > max[i]))
			{
				number = 0;
				return 2;
			}
			else if ((isDigit(str[i]) == true) & (str[i] - '0' <= max[i]))
			{
				break;
			}
			else
			{
				number = 0;
				return 1;
			}
		}
	}

	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (isDigit(str[i]) == false)
		{
			number = 0;
			return 1;
		}
	}
	number = stringToInt(str);
	return number;
}

double readDouble(double& number)
{
	double result = 0;
	string str;
	getline(cin, str);
	trim(str);

	if (str.size() > 21)
	{
		number = 0;
		return 2;
	}	
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (isdigit(str[i]) == false && str[i] != '.')
		{
			number = 0;
			return 1;  
		}
	}
	
	int index = 0;
	for (int i = 0; str[i] != '.'; ++i)
	{
		index = i + 1;
	}
	for (int i = 0; i < index; ++i)
	{
		result = stringToInt(str);
	}
	for (int i = index + 1; i < 4; ++i)
	{
		result = result + (double)(str[i] - '0') / pow(10, i - index);
	}
	number = result;
	return number;
}

main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	long long n1;
	double n2;
	int er1 = 0;
	int er2 = 0;

	do
	{
		er1 = readInt(n1);
		er2 = readDouble(n2);
		if (er1 != 0 || er2 != 0)
		{
			resolveError(er1);
			resolveError(er2);
		}
		else
		{
			break;
		}
	} while (true);
	
	cout << readInt(n1) + readDouble(n2);

	return EXIT_SUCCESS;
}