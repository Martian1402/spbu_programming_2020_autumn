#include "ArrayList.h"
#include<ctime>

ArrayList::ArrayList(int cap)
{
	count = 0;
	capacity = cap;
	data = new int [capacity] {0};
	str = nullptr;
}

ArrayList::~ArrayList()
{
	if (str != nullptr)
	{
		delete[] str;
	}
	delete[] data;
}

void ArrayList::expandArray(int* &arr, int &capacity)
{
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
}

bool indexIncorrect(int index, int count)
{
	return ((index < 0) || (index >= count));
}

bool ArrayList::add(int element)
{
	{
		if (count == capacity)
		{
			expandArray(data, capacity);
		}
		data[count] = element;
		count++;
		return true;
	}
}

bool ArrayList::add(int index, int element)
{
	if (indexIncorrect(index, count))
	{
		return false;
	}
	if (count + 1 == capacity)
	{
		expandArray(data, capacity);
	}
	for (int i = index + 1; i < count + 1; ++i)
	{
		data[i + 1] = data[i];
	}
	data[index] = element;
	return true;
}

bool ArrayList::addAll(ArrayList& list)
{
	if (count <= list.capacity)
	{
		expandArray(data, capacity);
	}
	int h = 0;
	for (int i = count + 1; i < list.count + 1; ++i)
	{
		data[i] = list.data[h];
		++h;
	}
	return true;
}

bool ArrayList::addAll(int index, ArrayList& list)
{
	if (indexIncorrect(index, count))
	{
		return false;
	}
	if (count <= list.capacity)
	{
		expandArray(data, capacity);
	}
	for (int i = count - 1; i < index + 1; --i)
	{
		data[i + list.count] = data[i];
	}
	int g = 0;
	for (int i = index; i < index + list.count + 1; ++i)
	{
		data[i] = list.data[g];
		++g;
	}
	return true;
}

void ArrayList::clear()
{
	count = 0;
}

bool ArrayList::contains(int element)
{
	for (int i = 0; i < count; ++i)
	{
		if (data[i] == element)
		{
			return true;
		}
	}
	return false;
}

int ArrayList::get(int index)
{
	if (indexIncorrect(index, count))
	{
		return -1;
	}
	return data[index];
}

bool ArrayList::set(int index, int element)
{
	if (indexIncorrect(index, count))
	{
		return false;
	}
	data[index] = element;
	return true;
}

int ArrayList::indexOf(int element)
{

	for (int i = 0; i < count; ++i)
	{
		if (data[i] == element)
		{
			return i;
		}
	}
	return -1;
}

bool ArrayList::isEmpty()
{
	return (count > 0);
}

int ArrayList::numLength(int number)
{
	int result = 1;
	if (number < 0)
	{
		while (number < -1)
		{
			number /= 10;
			result++;
		}
	}

	else
	{
		while (number > 9)
		{
			number /= 10;
			result++;
		}
	}
	return result;
}

void ArrayList::addSymbolToStr(int& index, char symbol)
{
	str[index] = symbol;
	++index;
}

void ArrayList::addNumberToStr(int& index, int number)
{
	int length = numLength(number);
	for (int i = 0; i < length; ++i)
	{
		int digit = number % 10;
		str[index + length - 1 - i] = '0' + digit;
		number /= 10;
	}
	index += length;
}

char* ArrayList::toString(int& count, int& capacity, int*& data)
{
	int length = 10 + numLength(count) + numLength(capacity);
	if (str != nullptr)
	{
		delete[] str;
		str = nullptr;
	}
	str = new char[length];
	int index = 0;
	addSymbolToStr(index, '[');
	addNumberToStr(index, count);
	addSymbolToStr(index, '/');
	addNumberToStr(index, capacity);
	addSymbolToStr(index, ']');
	addSymbolToStr(index, ' ');
	addSymbolToStr(index, '{');

	for (int i = 0; i < count; i++)
	{
		if (data[i] < 0)
		{
			addSymbolToStr(index, '-');
		}
		addNumberToStr(index, data[i]);
		length += numLength(data[i]);
	}
	addSymbolToStr(index, '}');
	addSymbolToStr(index, '\0');
	return str;
}

bool ArrayList::remove(int index)
{
	if (indexIncorrect(index, count))
	{
		return false;
	}
	for (int i = index; i < count - 1; ++i)
	{
		data[i] = data[i + 1];
	}
	return true;
}

bool ArrayList::swap(int index1, int index2)
{
	if ((indexIncorrect(index1, count)) || (indexIncorrect(index2, count)))
	{
		return false;
	}
	int c = data[index1];
	data[index1] = data[index2];
	data[index2] = c;
	return true;
}

int ArrayList::length()
{
	return count;
}