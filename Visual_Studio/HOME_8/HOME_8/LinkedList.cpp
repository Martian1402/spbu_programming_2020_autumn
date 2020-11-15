#include "LinkedList.h"

LinkedList::LinkedList(const LinkedList & list)
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
		return result;
	}
	else if (count > 1)
	{
		int result = head->data;
		Node* temp = head;
		head = head->next;
		delete temp;
		return result;
	}
}

int LinkedList::extractTail()
{
	if (tail == nullptr) //если в списке ничего нет
	{
		return -1; //возвращаем -1
	}
	else if (count == 1) //если там есть один элемент, нужно удалить его и обнулить ссылки head и tail. Сравнение делается через ==
	{
		int result = tail->data;
		delete tail;
		head = tail = nullptr;
		return result;
	}
	else if (count > 1) //если элементов больше одного
	{
		int result = tail->data; //запоминаем лежащий в хвосте элемент
		Node* temp = tail;
		while (temp->next != tail) //ищем элемент, стоящий ПЕРЕД tail
		{
			temp = temp->next;
		}
		temp->next = nullptr; //говорим, что теперь после найденого элемента ничего нет (теперь он является последним
		delete tail; //удаляем хвост
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
	if (count == 0)
	{
		return -1;
	} 
	else if (count == 1)
	{
		extractHead;
	}
	else if (count > 1)
	{
		Node* temp = head;
		for (int i = 0; i < index; ++i)
		{
			temp = temp->next;
		}
		int result = temp->data;
		delete temp;
		temp = temp->next;
		return result;
	}
}

void LinkedList::operator-=(int index)
{
	if (indexValid(index))
	{
		extract(index);
	}
	
}

LinkedList & LinkedList::operator=(LinkedList)
{
	// TODO: вставьте здесь оператор return
}

int LinkedList::indexOf(int element)
{
	int result = -1;
	Node* temp = head;
	while (temp->data != element)
	{
		temp = temp->next;
		++result;
	}
	if (result == count)
	{
		return -1;
	}
	else
	{
		return 0;
	}
	
}

bool LinkedList::contains(int)
{
	return false;
}

bool LinkedList::swap(int index1, int index2)
{
	if ((!indexValid(index1)) && (!indexValid(index2)))
	{
		return false;
	}

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
