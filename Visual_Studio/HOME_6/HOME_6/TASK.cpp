#pragma once
#include<iostream>
#include<clocale>
#include<ctime>
#include"ArrayList.h"

using namespace std;

void printMenu()
{
	cout << "МЕНЮ" << endl;
	cout << "0 - Выход из программы" << endl;
	cout << "1 - Добавить элемент, введенный с клавиатуры" << endl;
	cout << "2 - Вывести массив" << endl;
	cout << "3 - Проверить, является ли массив симметричным" << endl;
	cout << "4 - Циклический сдвинуть массив на n элементов.n > 0 - сдвиг вправо, n < 0 - сдвиг влево" << endl;
	cout << "5 - Проверить, может ли массив стать симметричным, если из него удалить один элемент" << endl;
}


void processChoice(ArrayList& a, int choice)
{
	switch (choice)
	{
	case 1:
		int element;
		cin >> element;
		cout << endl;
		a.add(a.length, element);
		break;
	case 2:
		cout << a.toString << endl;
		break;
	case 3:
	
		int t = 0;
	for (int i = 0; i < a.length / 2; ++i)
	{
		if (a.get(i) == a.get(a.length - 1 - i))
		{
			++t;
		}
	}
	if (t == a.length / 2)
	{
		cout << a.toString << endl;
	}
	else
	{
		cout << 'no' << endl;
	
	}
		break;
	case 4:
		int n = 0;
		cin >> n;
		cout << endl;
		if (n > 0)
		{
			for (int j = 0; j < n; ++j)
			{
				for (int i = a.length - n - 1 + j; i > -1 + j; --i)
				{
					a.swap(a.get(i), a.get(i + 1));
				}
			}
		}
		else
		{
			for (int j = 0; j < n; ++j)
			{
				for (int i = n - j; i < a.length - j; ++i)
				{
					a.swap(a.get(i), a.get(i - 1));
				}
			}
		}
		break;
	case 5:

		break;
	}
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	ArrayList a;

	int choice = 0;
	do
	{
		system("cls");
		printMenu();
		cin >> choice;
		processChoice(a, choice);
		system("pause");
	} while (choice != 0);

	return EXIT_SUCCESS;
}