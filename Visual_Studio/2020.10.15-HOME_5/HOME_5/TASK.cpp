#pragma once
#include<iostream>
#include<clocale>
#include<ctime>
#include"ArrayList.h"

using namespace std;

void printMenu()
{
	cout << "����" << endl;
	cout << "0 - ����� �� ���������" << endl;
	cout << "1 - �������� � ������ 10 ��������� ������������� ���������� ����� � ������� ������" << endl;
	cout << "2 - �������� � ������ 10 ��������� ������������� ���������� ����� � ������� ������" << endl;
	cout << "3 - �������� ������� ������ ����������� � ��������� ������������ ������� � ������� ������" << endl;
	cout << "4 - ���������� ��� �������� ������� � ������� ������." << endl;
	cout << "5 - �������� ������ ������������� ������� ������� �� 0" << endl;
}

void processChoice(ArrayList& a, int choice)
{
	switch (choice)
	{
	case 1:
		for (int i = 0; i < 10; ++i)
		{
			a.add(rand() % 89 + 10);
		}
		cout << a.toString << endl;
		break;
	case 2:
		for (int i = 0; i < 10; ++i)
		{
			a.add(rand() % 98 - 99);
		}
		cout << a.toString << endl;
		break;
	case 3:
		int minindex = 0;
		int maxindex = 0;
		for (int i = 0; i < a.length; ++i)
		{
			if (a.get(i) < a.get(minindex))
			{
				minindex = i;
			}
			if (a.get(i) >= a.get(maxindex))
			{
				maxindex = i;
			}
		}
		a.swap(minindex, maxindex);
		cout << a.toString << endl;
		break;
	case 4:
		for (int i = 0; i < a.length; ++i)
		{
			a.swap(i, rand() % a.length);
		}
		cout << a.toString << endl;
		break;
	case 5:
		for (int i = 0; i < a.length; ++i)
		{
			if (a.get(i) < 0)
			{
				a.set(i, 0);
			}
		}
		cout << a.toString << endl;
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