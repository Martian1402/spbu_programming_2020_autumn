#pragma once
#include<iostream>

using namespace std;

struct ArrayList
{
	int count;
	int capacity;
	int* data;

	ArrayList();
	ArrayList(int capacity);

	~ArrayList();

	bool add(int element);

	bool add(int index, int element);

	bool addAll(ArrayList& list);

	bool addAll(int index, ArrayList& list);

	void clear();

	bool contains(int element);

	int get(int index);

	int indexOf(int element);

	bool isEmpty();

	void print();

	bool remove(int index);

	bool swap(int index1, int index2);

};

