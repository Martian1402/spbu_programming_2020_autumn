#include "ArrayList.h"
#include<ctime>

ArrayList::ArrayList(const ArrayList& list)
{
	count = list.count;
	capacity = list.count;
	data = new int[count];
	for (int i = 0; i < count; data[i] = list.data[i], ++i);
	str = nullptr;
}

ArrayList::~ArrayList()
{
	if (data != nullptr)
	{
		delete[] data;
	}
	if (str != nullptr)
	{
		delete[] str;
	}
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
	for (int i = count + 1; i < list.count + 1; ++i)
	{
		add(list.get(i));
	}
	return true;
}

bool ArrayList::addAll(int index, ArrayList& list)
{
	for (int i = count - 1; i >= 0; --i)
	{
		if (!add(index, list.get(i)))
		{
			return false;
		}
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

char* ArrayList::toString()
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

void ArrayList::operator+= (int item)
{
	add(item);
}

void ArrayList::operator-= (int item)
{
	if (contains(item))
	{
		remove(indexOf(item));
	}
}

ArrayList& ArrayList::operator= (const ArrayList& list)
{
	if (&list != this)
	{
		if (data != nullptr)
		{
			delete[] data;
		}
		if (str != nullptr)
		{
			delete[] data;
			str = nullptr;
		}
		count = list.count;
		capacity = list.count;
		data = new int[count];
		for (int i = 0; i < count; data[i] = list.data[i], ++i);
	}
	return *this;
}

int& ArrayList::operator[](int index)
{
	if (index < 0)
	{
		index = 0;
	}
	if (index > count)
	{
		index = count;
	}
	if (count == index)
	{
		count++;
		return data[index];
	}
	return data[index];

}

ArrayList operator+(const ArrayList& list, int item)
{
	ArrayList result(list);
	result.add(item);
	return result;
}

ArrayList operator+(int item, const ArrayList& list)
{
	ArrayList result(list);
	result.add(0, item);
	return result;
}

ArrayList operator+(const ArrayList& list1, const ArrayList& list2)
{
	ArrayList result(list1);
	for (int i = 0; i < list2.count; ++i)
	{
		result.add(list2.data[i]);
	}
	return result;
}

ArrayList operator-(const ArrayList& list, int item)
{
	int index = -1;
	for (int i = list.count - 1; i > 0; --i)
	{
		if (list.data[i] == item)
		{
			index = i;
			break;
		}
	}
	ArrayList result(list);
	result.remove(index);
	return result;
}

ArrayList operator-(int item, const ArrayList& list)
{
	int index = -1;
	for (int i = 0; i < list.count; ++i)
	{
		if (list.data[i] == item)
		{
			index = i;
			break;
		}
	}
	ArrayList result(list);
	result.remove(index);
	return result;
}

std::ostream& operator<<(std::ostream& stream, const ArrayList& list)
{
	stream << "[" << list.count << "/" << list.capacity << "] {";
	if (list.count == 0)
	{
		stream << " EMPTY ";
	}
	for (int i = 0; i < list.count; ++i)
	{
		stream << list.data[i];
		if (i != list.count - 1)
		{
			stream << ", ";
		}
	}
	stream << "}";
	return stream;
}