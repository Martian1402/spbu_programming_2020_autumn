#pragma once
#include<iostream>

using namespace std;

struct ArrayList
{
private:
	int count;
	int capacity;
	int* data;
	char* str;
public:
	ArrayList(int capacity = 10) : count(0), capacity(capacity), data(new int[capacity]), str(nullptr) {}
	ArrayList(const ArrayList& list);
	~ArrayList();

private:
	void expandArray(int* &arr, int &capacity);
	int numLength(int number);
	void addSymbolToStr(int& index, char symbol);
	void addNumberToStr(int& index, int number);

public:

	bool add(int element);

	bool add(int index, int element);

	bool addAll(ArrayList& list);

	bool addAll(int index, ArrayList& list);

	void clear();

	bool contains(int element);

	int get(int index);

	bool set(int index, int element);

	int indexOf(int element);

	bool isEmpty();

	char* toString();

	bool remove(int index);

	bool swap(int index1, int index2);

	int length();

	
	void operator+= (int item);
	   	 	
	void operator-= (int item);

	ArrayList& operator= (const ArrayList& list);

	friend ArrayList operator+ (const ArrayList& list, int item);

	friend ArrayList operator+ (int item, const ArrayList& list);

	friend ArrayList operator+ (const ArrayList& list1, const ArrayList& list2);

	friend ArrayList operator- (const ArrayList& list, int item);

	friend ArrayList operator- (int item, const ArrayList& list);

	friend std::ostream& operator<<(std::ostream& stream, const ArrayList& list);

	int& operator[](int index);
};

