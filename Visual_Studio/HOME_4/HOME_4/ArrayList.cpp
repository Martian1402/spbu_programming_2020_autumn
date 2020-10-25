#include "ArrayList.h"

ArrayList::ArrayList()
{
	count = 0;
	capacity = 10;
	data = new int [capacity] {0};
}

ArrayList::ArrayList(int cap)
{
	count = 0;
	capacity = cap;
	data = new int [capacity] {0};
}

ArrayList::~ArrayList()
{
	delete[] data;
}

void expandArray(int* &arr, int &capacity)
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
}

int ArrayList::get(int index)
{
	if (indexIncorrect(index, count))
	{
		return -1;
	}
	return data[index];
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

void ArrayList::print()
{
	cout << "[ " << count << " / " << capacity << " ]{ ";
	for (int i = 0; i < count; ++i)
	{
		cout << data[i] << (i != count - 1 ? ", " : "");
	}
	cout << "}" << endl;
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
	{
			int c = data[index1];
		data[index1] = data[index2];
		data[index2] = c;
		return true;
	}

}