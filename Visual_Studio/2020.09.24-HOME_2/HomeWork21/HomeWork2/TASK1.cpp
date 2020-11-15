#include <iostream>
#include<clocale>

using namespace std;


void printMenu()
{
	cout << "Меню: " << endl;
	cout << "0 - Выход из программы" << endl;
	cout << "1 - Добавить число в массив" << endl;
	cout << "2 - Вывести массив на экран" << endl;
	cout << "3 - Найти номер максимального элемента массива" << endl;
	cout << "4 - Найти минимальный элемент массива" << endl;
	cout << "5 - Посчитать сумму элементов массива" << endl;
	cout << "6 - Вывести массив в обратном порядке" << endl;
	cout << "Чего желаете?" << endl;
}

void expandArray(int* &arr, int &capacity)
{
	int newCapacity = capacity * 2;
	int* temp = new int[newCapacity];
	for (int j = 0; j < capacity; ++j)
	{
		temp[j] = arr[j];
	}
	delete[] arr;
	arr = temp;
	capacity = newCapacity;
}

void addArray(int* &arr, int &count, int &cap, int x)
{
	if (count == cap)
	{
		expandArray(arr, cap);
	}
	arr[count] = x;
	count++;
}

void printArray(int count, int* arr)
{
	cout << "{";
	for (int i = 0; i < count; ++i)
	{
		cout << arr[i] << (i != count - 1 ? ", " : "");
	}
	cout << "}" << endl;
}

int sumArray(int* arr, int count)
{
	int sum = 0;
	for (int i = 0; i < count; ++i)
	{
		sum += arr[i];
	}
	return sum;
}

void changeArray(int* arr, int count)
{
	cout << "{";
	for (int i = count - 1; i > -1; --i)
	{
		cout << arr[i] << (i != 0 ? ", " : "");
	}
	cout << "}" << endl;
}

int maxnumArray(int* arr, int count)
{
	int max = 0;
	for (int i = 1; i < count; i++)
	{
		if (arr[i] > arr[max])
		{
			max = i;
		}
	}
	return max;
}

int minArray(int* arr, int count)
{
	int min = arr[0];
	for (int i = 1; i < count; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}

void Switch(int choice, int* &arr, int &cap, int &count)
{
	int x = 0;
	switch (choice)
	{
	case 1:
		cin >> x;
		addArray(arr, count, cap, x);
		break;
	case 2:
		printArray(count, arr);
		system("pause");
		break;
	case 3:
		cout << maxnumArray(arr, count) << endl;
		system("pause");
		break;
	case 4:
		cout << minArray(arr, count) << endl;
		system("pause");
		break;
	case 5:
		cout << sumArray(arr, count) << endl;
		system("pause");
		break;
	case 6:
		changeArray(arr, count);
		system("pause");
		break;
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int cap = 10;
	int* arr = new int[cap] {0};
	int choice = -1;
	int count = 0;
	while (choice != 0)
	{
		system("cls");
		printMenu();
		cin >> choice;
		Switch(choice, arr, cap, count);
	}
	return EXIT_SUCCESS;
}
