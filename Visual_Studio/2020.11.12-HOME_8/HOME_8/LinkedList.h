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


	
	/// ������� ������ ������
	/// <returns>�������� ��������, ��������� � ������</returns>
	int extractHead();

	
	/// ������� ����� ������
	/// <returns>�������� ��������, ��������� � �����</returns>
	int extractTail();

	
	/// ������� �������, ������� �� ����� index
	/// <returns>�������� ��������, ��������� �� ����� index</returns>
	int extract(int index);

	
	/// ������� �������
	/// <param name="">������ ���������� ��������</param>
	void operator-=(int index);

	LinkedList& operator=(const LinkedList& list);

	
	/// ����� ��������
	/// <param name="">�������� ��������</param>
	/// <returns>-1, ���� �������� � ������ ���</returns>
	int indexOf(int element);

	/// ���������� �� ������� � ������. � ������� ����� �������� ����� �������
	/// <param name="">�������� ��������</param>
	bool contains(int element);

	/// �������� ��� �������� �������.
	/// ������������ �������� ��������� ������.
	/// ����� ������ ������ �������� ����� next.
	/// <param name="">������ ������� ��������</param>
	/// <param name="">������ ������� ��������</param>
	/// <returns>false - ���� ������� ���� �����������</returns>
	bool swap(int index1, int index2);

};