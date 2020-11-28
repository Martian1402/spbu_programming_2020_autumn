#pragma once
#include<iostream>

struct Node
{
public:
	int data;
	Node* next;
	Node(int data, Node* next = nullptr) : data(data), next(next) {}
};

class LinkedList
{
private:
	int count;
	Node* head;
	Node* tail;
public:
	LinkedList() : count(0), head(nullptr), tail(nullptr) {}
	LinkedList(const LinkedList& list);
	~LinkedList();
private:
	bool indexValid(int index);
	Node* extractHeadNode();
	Node* extractTailNode();
	Node* extractNode(int index);
	void inserttHeadNode(Node* &node);
	void insertTailNode(Node* &node);
	void insertNode(int index, Node* &node);
public:
	int lenght();

	bool addToHead(int element);

	bool addToTail(int element);

	bool add(int index, int element);

	int get(int index);

	bool set(int index, int element);

	int& operator[](int index);

	friend std::ostream& operator<<(std::ostream& stream, const LinkedList list);


	
	/// удалить начало списка
	/// <returns>значение элемента, стоявшего в начале</returns>
	int extractHead();

	
	/// удалить хвост списка
	/// <returns>значение элемента, стоявшего в конце</returns>
	int extractTail();

	
	/// удалить элемент, стоящий на месте index
	/// <returns>значение элемента, стоявшего на месте index</returns>
	int extract(int index);

	
	/// удалить элемент
	/// <param name="">индекс удаляемого элемента</param>
	void operator-=(int index);

	LinkedList& operator=(const LinkedList& list);

	
	/// поиск элемента
	/// <param name="">значение искомого</param>
	/// <returns>-1, если элемента в списке нет</returns>
	int indexOf(int element);

	/// содержится ли элемент в списке. в функции нужно обойтись одной строкой
	/// <param name="">значение элемента</param>
	bool contains(int element);

	/// поменять два элемента местами.
	/// Переписывать значения элементов нельзя.
	/// Можно только менять значения полей next.
	/// <param name="">индекс первого элемента</param>
	/// <param name="">индекс второго элемента</param>
	/// <returns>false - если индексы были некорректны</returns>
	bool swap(int index1, int index2);

};