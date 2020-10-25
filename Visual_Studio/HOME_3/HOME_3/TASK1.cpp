#include <iostream>
#include<clocale>
#include<ctime>

using namespace std;


void printMenu()
{
	cout << "����:\n";
	cout << "0 - ����� �� ���������\n";
	cout << "1 - ���� ��������� ��������� � ����������\n";
	cout << "2 - ���������� � ������ n ��������� ����� � ���������� �� a �� b\n";
	cout << "3 - ����� ������� �� �����\n";
	cout << "4 - ����� ������� ��������\n";
	cout << "5 - ���������� ������� � �������\n";
	cout << "6 - ����������� ��������\n";
	cout << "7 - ������� �������� � ������\n";
	cout << "8 - �������� ���������� ������ ������ ��������� �������\n";
	cout << "9 - ����� ���������������������\n";
	cout << "���� �������?\n";
}


int* initArray(int capacity = 10)
{
	int result = new int[capacity + 2]{ 0 };
	*(result + 1) = capacity;
	result += 2;
	return result;
	
	//return (new int[capacity + 2]{ 0, capacity }) + 2;
}

void deleteArray(int* arr)
{
	delete[] (arr - 2);
}

void expandArray(int* &arr)
{
	int* temp = initArray[(*(arr - 1)) * 2];
	for (int j = 0; j < *(arr - 1); ++j)
	{
		*(temp + j) = *(arr + j);
	}
	*(temp - 2) = *(arr - 2);
	deleteArray(arr);
	arr = temp;
}

void addElement(int* &arr, int x)
{
	if (*(arr - 2) == *(arr - 1))
	{
		expandArray(arr);
	}
	*(arr + *(arr - 2)) = x;
	++(*(arr - 2));
}



void addRandomElements(int* &arr, int n, int min, int max)
{
	for (int i = 0; i < n; ++i)
	{
		addElement(arr, rand() % (max - min + 1) + min);
	}
}


void printArray(int* arr)
{
	cout << "[" << *(arr - 2) << "/" << *(arr - 1) << "] {";
	for (int i = 0; i < *(arr - 2); ++i)
	{
		cout << *(arr + i) << (i == *(arr - 2) - 1 ? "}\n" : ", ");
	}
}

int search(int* arr, int element, int start = 0)
{
	while (*(arr + start) != element)
	{
		++start;
	}
	return start;
}



void Switch(int* &arr, int* &brr, int choice)
{
	int n = 0;
	int a = 0;
	int b = 0;
	int x = 0;
	switch (choice)
	{
	case 1:
		cin >> x;
		addElement(arr, x);
		system("pause");
		break;
	case 2:
		cout << "������� ���������� �����: ";
		cin >> n;
		cout << endl << "������� ����������:\n" << "�� ";
		cin >> a;
		cout << "�� ";
		cin >> b;
		if (*(arr - 2) == 0)
		{
			*(arr - 2) = n;
		}
		else
		{
			*(arr - 2) += n;
		}
		addRandomElements(arr, n, a, b);
		printArray(arr);
		system("pause");
		break;
	case 3:
		printArray(arr);
		system("pause");
		break;
	case 4:
		
		system("pause");
		break;
	case 5:
		
		system("pause");
		break;
	case 6:

		system("pause");
		break;
	case 7:

		system("pause");
		break;
	case 8:
		"� ������ ��������: "
		"������� ���������: " 
		system("pause");
		break;
	case 9:

		system("pause");
		break;

	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int choice = -1;
	int* a = initArray(10);
	int* b = initArray(10);

	while (choice != 0)
	{
		system("cls");
		printMenu();
		cin >> choice;
		Switch(a, b, choice);
	}
	return EXIT_SUCCESS;
}