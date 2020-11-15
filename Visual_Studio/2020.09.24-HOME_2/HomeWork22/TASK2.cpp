#include <iostream>
#include<clocale>
#include<ctime>

using namespace std;


void printMenu()
{
	cout << "Меню: " << endl;
	cout << "0 - Выход из программы" << endl;
	cout << "1 - Добавить в массив n случайных чисел в промежутке от a до b" << endl;
	cout << "2 - Развернуть массив" << endl;
	cout << "3 - Поменять элементы массива местами в парах" << endl;
	cout << "4 - Циклический сдвиг вправо на 1" << endl;
	cout << "5 - Развернуть две половинки массива. v - индекс элемента, разделяющего половинки" << endl;
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

void printArray(int count, int* arr)
{
	cout << "{";
	for (int i = 0; i < count; ++i)
	{
		cout << arr[i] << (i != count - 1 ? ", " : "");
	}
	cout << "}" << endl;
}

void addArray(int &count, int* &arr, int &cap, int n, int a, int b)
{
	srand(time(NULL));
	while (count >= cap)
	{
		expandArray(arr, cap);
	}
	for (int i = count - n; i < count + 1; ++i)
	{
		arr[i] = rand() % (b - a + 1) + a;
	} 
}


void changeArray(int* arr, int count)
{
	int c = 0;
	for (int j = 0; j < count / 2; ++j)
	{
		c = arr[j];
		arr[j] = arr[count - j - 1];
		arr[count - j - 1] = c;
		c = 0;
	}
}

void coupleArray(int* arr, int count)
{
	int c = 0;
	for (int i = 0; i < count - 1; i += 2)
	{
		c = arr[i];
		arr[i] = arr[i + 1];
		arr[i + 1] = c;
	}

}

void cycleArray(int* arr, int count)
{
	int c = arr[count - 1];
	for (int i = count - 1; i > 0; --i)
	{
		arr[i] = arr[i - 1];
	}
	arr[0] = c;
}

void reversalArray(int* arr, int count, int v)
{
	int s = 0;
	for (int j = 0; j < v / 2; ++j)
	{
		s = arr[j];
		arr[j] = arr[v - 1 - j];
		arr[v - 1 - j] = s;
	}
	for (int h = v + 1; h < v + (count - v) / 2 + 1; ++h)
	{
		s = arr[h];
		arr[h] = arr[count - h + v];
		arr[count - h + v] = s;
	}
}

void Switch(int* &arr, int choice, int &cap, int &count)
{
	int n = 0;
	int v = 0;
	int a = 0;
	int b = 0;
	switch (choice)
	{
	case 1:
		cout << "Введите количество чисел: ";
		cin >> n;
		cout << endl << "Введите промежуток:" << endl << "от ";
		cin >> a;
		cout << "до ";
		cin >> b;
		if (count == -1)
		{
			count = n;
		}
		else
		{
			count += n;
		}
		addArray(count, arr, cap, n, a, b);
		printArray(count, arr);
		system("pause");
		break;
	case 2:
		changeArray(arr, count);
		printArray(count, arr);
		system("pause");
		break;
	case 3:
		coupleArray(arr, count);
		printArray(count, arr);
		system("pause");
		break;
	case 4:
		cycleArray(arr, count);
		printArray(count, arr);
		system("pause");
		break;
	case 5:
		cout << "Введите индекс: ";
		cin >> v;
		reversalArray(arr, count, v);
		printArray(count, arr);
		system("pause");
		break;
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int choice = -1;
	int cap = 10;
	int count = -1;
	int* arr = new int[cap] {0};
	while (choice != 0)
	{
		system("cls");
		printMenu();
		cin >> choice;
		Switch(arr, choice, cap, count);
	}
	return EXIT_SUCCESS;
}