#include "LinkedList.h"

LinkedList::LinkedList(const LinkedList& list)
{
	tail = head = nullptr;
	count = 0;

	Node* temp = list.head;
	while (temp != nullptr)
	{
		addToTail(temp->data);
		temp = temp->next;
	}
}

LinkedList::~LinkedList()
{
	Node* temp = head;
	while (temp != nullptr)
	{
		Node* node = temp;
		temp = temp->next;
		delete node;
	}
}

bool LinkedList::indexValid(int index)
{

	return (index >= 0 && index < count);
}

int LinkedList::lenght()
{
	return count;
}

bool LinkedList::addToHead(int element)
{
	if (head == nullptr)
	{
		head = tail = new Node(element);
	}
	else
	{
		head = new Node(element, head);
	}
	++count;
	return true;
	
}

bool LinkedList::addToTail(int element)
{
	if (tail == nullptr) 
	{
		head = tail = new Node(element);
	}
	else 
	{
		tail->next = new Node(element);
		tail = tail->next;
	}
	++count;
	return true;
}

bool LinkedList::add(int index, int element)
{
	if (index == 0)
	{
		return addToHead(element);
	}
	if (index == count)
	{
		return addToTail(element);
	}
	if (!indexValid(index))
	{
		return false;
	}

	Node* temp = head;
	for (int i = 0; i < index - 1; ++i)
	{
		temp = temp->next;
	}
	temp->next = new Node(element, temp->next);
	++count;

	return true;
}

int LinkedList::get(int index)
{
	if (!indexValid(index))
	{
		return -1;
	}
	if (index == 0)
	{
		return head->data;
	}
	if (index == count - 1)
	{
		return tail->data;
	}

	Node* temp = head;
	for (int i = 0; i < index; ++i)
	{
		temp = temp->next;
	}
	return temp->data;

}

bool LinkedList::set(int index, int element)
{
	if (!indexValid(index))
	{
		return false;
	}
	if (index == 0)
	{
		head->data = element;
	}
	else if (index == count - 1)
	{
		tail->data = element;
	}
	else
	{
		Node* temp = head;
		for (int i = 0; i < index; ++i)
		{
			temp = temp->next;
		}
		temp->data = element;
	}
	return true;
}

int& LinkedList::operator[](int index)
{
	if (head == nullptr)
	{
		addToHead(0);
		return head->data;
	}
	if (index <= 0)
	{
		return head->data;
	}
	if (index >= count)
	{
		addToTail(0);
		return tail->data;
	}
	if (index == count - 1)
	{
		return tail->data;
	}
	Node* temp = head;
	for (int i = 0; i < index; ++i)
	{
		temp = temp->next;
	}
	return temp->data;
}

int LinkedList::extractHead()
{
	if (head == nullptr)
	{
		return -1;
	}
	else if (count == 1)
	{
		int result = head->data;
		delete head;
		head = tail = nullptr;
		--count;
		return result;
	}
	else if (count > 1)
	{
		int result = head->data;
		Node* temp = head;
		head = head->next;
		--count;
		delete temp;
		return result;
	}
}

int LinkedList::extractTail()
{
	if (tail == nullptr) 
	{
		return -1; 
	}
	else if (count == 1) //если там есть один элемент, нужно удалить его и обнулить ссылки head и tail. Сравнение делается через ==
	{
		int result = tail->data;
		delete tail;
		head = tail = nullptr;
		return result;
	}
	if (count > 1) 
	{
		int result = tail->data; //запоминаем лежащий в хвосте элемент
		Node* temp = head;
		while (temp->next != tail) //ищем элемент, стоящий ПЕРЕД tail
		{
			temp = temp->next;
		}
		temp->next = nullptr; //говорим, что теперь после найденого элемента ничего нет (теперь он является последним
		delete tail; 
		--count;
		tail = temp; //присваиваем новое значение ссылке на хвост
		return result;
	}
}

int LinkedList::extract(int index)
{
	if (!indexValid(index))
	{
		return -1;
	}
	if (index == 0)
	{
		extractHead();
	} 
	else if (index == count - 1)
	{
		return extractTail();
	}
		Node* temp = head;
		for (int i = 0; i < index - 1; ++i, temp = temp->next);
		Node* deleted = temp->next;
		int result = deleted->data;
		temp->next = temp->next->next;
		delete deleted;
		--count;
		return result;
	
}

void LinkedList::operator-=(int index)
{
	if (indexValid(index))
	{
		extract(index);
	}
	
}

LinkedList& LinkedList::operator=(const LinkedList& list)
{
	if (this != &list)
	{
		while (count > 0)
		{
			extractHead();
		}
		for (Node* temp = list.head; temp != nullptr; temp = temp->next)
		{
			addToTail(temp->data);
		}

	}
	return *this;
}

int LinkedList::indexOf(int element)
{
	int result = 0;
	Node* temp = head;
	while (temp != nullptr)
	{
		++result;
		if (temp->data == element)
		{
			return result;
		}
		temp = temp->next;
	}
	return -1;
}

bool LinkedList::contains(int element)
{
	return (indexOf(element) != -1 ? true : false);
}

Node* LinkedList::extractHeadNode()
	{
		Node* node = head;
		head = head->next;
		--count;
		node->next = nullptr;
		return node;
	}

Node* LinkedList::extractTailNode()
{
	if (head->next == nullptr)
	{
		return extractHeadNode();
	}
	Node* node = head;
	while (node->next->next != nullptr)
	{
		node = node->next;
	}
	tail = node;
	node = node->next;
	tail->next = nullptr;
	--count;
	node->next = nullptr;
	return node;
}

Node * LinkedList::extractNode(int index)
{
	if (index == 0)
	{
		return extractHeadNode();
	}
	if (index == count - 1)
	{
		return extractTailNode();
	}
	Node* node = head;
	for (int i = 0; i < index - 1; ++i, node = node->next);
	Node* temp = node;
	node = node->next;
	temp->next = temp->next->next;
	node->next = nullptr;
	--count;
	return node;
}

void LinkedList::inserttHeadNode(Node* &node)
{
	node->next = head;
	head = node;
	++count;
}

void LinkedList::insertTailNode(Node* &node)
{
	tail->next = node;
	tail = tail->next;
	tail->next = nullptr;
	++count;
}

void LinkedList::insertNode(int index, Node* &node)
{
	if (index == 0)
	{
		return inserttHeadNode(node);
	}
	if (index == count)
	{
		return insertTailNode(node);
	}
	Node*temp = head;
	for (int i = 0; i < index - 1; ++i, temp = temp->next);
	node->next = temp->next;
	temp->next = node;
	++count;
}

bool LinkedList::swap(int index1, int index2)
{
	if ((!indexValid(index1)) && (!indexValid(index2)))
	{
		return false;
	}
	else if (index1 == index2)
	{
		return true;
	}
	else if (index1 > index2)
	{
		return swap(index2, index1);
	}
	Node* node2 = extractNode(index2);
	Node* node1 = extractNode(index1);
	insertNode(index1, node2);
	insertNode(index2, node1);
	return true;
}

std::ostream & operator<<(std::ostream & stream, const LinkedList list)
{
	stream << "[" << list.count << "]{";
	if (list.head == nullptr)
	{
		stream << "EMPTY";
	}
	else
	{
		Node* temp = list.head;
		while (temp != nullptr)
		{
			stream << temp->data;
			if (temp->next != nullptr)
			{
				stream << ", ";
			}
			temp = temp->next;
		}
	}
	stream << "}";

	return stream;
}
