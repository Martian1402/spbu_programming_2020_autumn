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
	cout << "1 - Добавить в список 10 случайных положительных двузначных чисел и вывести список" << endl;
	cout << "2 - Добавить в список 10 случайных отрицательных двузначных чисел и вывести список" << endl;
	cout << "3 - Поменять местами первый минимальный и последний максимальный элемент и вывести список" << endl;
	cout << "4 - Перемешать все элементы массива и вывести массив." << endl;
	cout << "5 - Заменить каждый отрицательный элемент массива на 0" << endl;
}

void processChoice(ArrayList& a, int choice)
{
	switch (choice)
	{
	case 1:
		for (int i = 0; i < 10; ++i)
		{
			a.add1;
		}
		a.toString;
		break;
	case 2:
		for (int i = 0; i < 10; ++i)
		{
			a.add2;
		}
		a.toString;
		break;
	case 3:

		break;
	case 4:

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