#include <iostream>
#include<clocale>
#include<ctime>

using namespace std;


void printMenu()
{
	cout << "Меню:\n";
	cout << "0 - Выход из программы\n";
	cout << "1 - Ввод несколько элемнетов с клавиатуры\n";
	cout << "2 - Добавление в массив n случайных чисел в промежутке от a до b\n";
	cout << "3 - Вывод массива на экран\n";
	cout << "4 - Поиск индекса элемента\n";
	cout << "5 - Добавление массива к массиву\n";
	cout << "6 - Объединение массивов\n";
	cout << "7 - Вставка элемента в массив\n";
	cout << "8 - Удаление нескольких подряд идущих элементов массива\n";
	cout << "9 - Поиск подпоследовательности\n";
	cout << "Чего желаете?\n";
}

int* initArray(int capacity = 10)
{
	int* result = new int[capacity + 2]{ 0 };
	*(result + 1) = capacity;
	result += 2;
	return result;
}

void deleteArray(int* arr)
{
	delete[](arr - 2);
}

void expandArray(int* &arr)
{
	int* temp = initArray((*(arr - 1)) * 2);
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

int* BRR(int* brr)
{
	int a = 10;
	int b = 1000;
	for (int i = 0; i < *(brr - 2); ++i)
	{
		*(brr - i) = rand() % (b - a + 1) + a;
	}
	return brr;
}

void add(int*& arr, int* addedArr)
{
	BRR(addedArr);
	if (*(addedArr - 2) >= (*(arr - 1) - (*(arr - 2))))
	{
		expandArray(arr);
	}
	int j = 0;
	for (int i = *(arr - 2); i < *(addedArr - 2); ++i)
	{
		*(arr - i) = *(addedArr - j);
		++j;
	}
	*(arr - 2) = *(arr - 2) + (*(addedArr - 2));
}

int* unify(int* &arr, int* &brr)
{
	int* temp = initArray(*(arr - 2) + (*(brr - 2)));
	BRR(brr);
	if (*(arr - 2) + (*(brr - 2)) >= *(arr - 1))
	{
		expandArray(arr);
	}
	int i = 0;
	int g = 0;
	if (*(arr - 2) > *(brr - 2))
	{
		while ((g + 1) != *(brr - 2))
		{

			*(temp + i) = *(arr + g);
			*(temp + i + 1) = *(brr + g);
			i+=2;
			++g;
		}
		int h = i;
		for (i = g + 1; i < *(arr - 2) + (*(brr - 2)); ++i)
		{
			*(temp + h + 1) = *(arr + i);
			++h;
		}
	}
	else
	{
		while ((g + 1) != *(arr - 2))
		{

			*(temp + i) = *(brr + g);
			*(temp + i + 1) = *(arr + g);
			i += 2;
			++g;
		}
		int h = i;
		for (i = g + 1; i < *(arr - 2) + (*(brr - 2)); ++i)
		{
			*(temp + h + 1) = *(brr + i);
			++h;
		}
	}
	*(temp - 2) = *(arr - 2) + (*(brr - 2));
	deleteArray(arr);
	deleteArray(brr);
	arr = temp;
	return arr;
}

int insert(int*& arr, int index, int element)
{
	if ((*(arr - 2) + 1) >= *(arr - 1))
	{
		expandArray(arr);
	}
	for (int i = index; i < *(arr - 2) + 1; ++i)
	{
		*(arr + i + 1) = *(arr + i);
	}
	*(arr + index) = element;
	return 0;
}

int deleteGroup(int* arr, int startIndex, int count = 1)
{
	for (int i = startIndex; i < *(arr - 2) - (startIndex + count) + 1; ++i)
	{
		*(arr + i) = *(arr + i + count);
	}
	return 0;
}

int subSequence(int* arr, int* brr)
{
	int c = -1;

}

void Switch(int* &arr, int* &brr, int choice)
{
	int n = 0;
	int a = 0;
	int b = 0;
	int x = 0;
	int in = 0;
	int el = 0;
	int count = 0;
	switch (choice)
	{
	case 1:
		cin >> x;
		addElement(arr, x);
		system("pause");
		break;
	case 2:
		cout << "Введите количество чисел: ";
		cin >> n;
		cout << endl << "Введите промежуток:\n" << "от ";
		cin >> a;
		cout << "до ";
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
		add(arr, brr);
		system("pause");
		break;
	case 5:
		add(arr, brr);
		system("pause");
		break;
	case 6:
		unify(arr, brr);
		system("pause");
		break;
	case 7:
		cout << "Индекс элемента: ";
		cin >> in;
		cout << "Значение элемента: ";
		cin >> el;
		insert(arr, in, el);
		system("pause");
		break;
	case 8:
		cout << "С какого элемента: ";
		cin >> in;
		cout << "Сколько элементов: ";
		cin >> count;
		deleteGroup(arr, in, count);
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
	deleteArray(a);
	deleteArray(b);
	return EXIT_SUCCESS;
}