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
	ArrayList(int capacity = 10) :count(0), capacity(capacity), data(new int[capacity]), str(nullptr) {}
	~ArrayList();

private:
	void expandArray(int* &arr, int &capacity);
	int numLength(int number);
	void addSymbolToStr(int& index, char symbol);
	void addNumberToStr(int& index, int number);

public:

	bool add1();

	bool add2();

	bool add(int index, int element);

	bool addAll(ArrayList& list);

	bool addAll(int index, ArrayList& list);

	void clear();

	bool contains(int element);

	int get(int index);

	bool set(int index, int element);

	int indexOf(int element);

	bool isEmpty();

	char* toString(int& count, int& capacity, int*& data);

	bool remove(int index);

	bool swap(int index1, int index2);

	int length();

};