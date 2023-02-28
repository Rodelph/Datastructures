#ifndef __DOUBLE_LINKED_LIST_HPP__
#define __DOUBLE_LINKED_LIST_HPP__

#include <iostream>

template<typename T>
class DoubleLinkedList
{
	private :
		struct Node
		{
			Node *next, *previous;
			T data;
		};

		Node *head, *tail;
		uint16_t count;

	public :
		DoubleLinkedList();
		~DoubleLinkedList();

		void addFirst(T value);
		void addLast(T value);
		void addAt(uint16_t index, T value);

		void removeFirst();
		void removeLast();
		void removeElement(T element);
		void removeElementAt(uint16_t index);

		void showAllLastToFirst();
		void showAllFirstToLast();

		T at(uint16_t index);

		uint16_t size();
		bool isEmpty();
};

// Not working properly

template<typename T>
void DoubleLinkedList<T>::removeElement(T element)
{
	Node* tracer = this->head;
	while (tracer != nullptr)
	{
		if (((Node*)tracer->next)->data == element)
		{
			tracer->next = ((Node*)tracer->next)->next;
			((Node*)(tracer->next))->previous = nullptr;
			this->count--;
			break;
		}
		else
			tracer = tracer->next;
	}
}

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
	this->head  = nullptr;
	this->tail  = nullptr;
	this->count = 0;
}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	this->head = nullptr;
	this->tail = nullptr;
	this->count = 0;
}

template<typename T>
void DoubleLinkedList<T>::addAt(uint16_t index, T value)
{
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;
	newNode->previous = nullptr;

	uint16_t n = 0;
	Node* parser = this->head;

	while (n < this->size() && parser != nullptr)
	{
		if (n == (index - 1))
		{
			newNode->next = parser->next;
			newNode->previous = parser;
			parser->next = newNode;
			this->count++;
			break;
		}
		else
		{
			n++;
			parser = parser->next;
		}
	}
}

template<typename T>
void DoubleLinkedList<T>::addFirst(T value)
{
	Node *newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;
	newNode->previous = nullptr;

	if (this->head == nullptr)
	{
		this->head = newNode;
		newNode->next = this->tail;
		this->count++;
	}
	else
	{
		newNode->next = this->head;
		((Node*)this->head)->previous = newNode;
		this->head = newNode;
		this->count++;
	}
}

template<typename T>
void DoubleLinkedList<T>::addLast(T value)
{
	Node* newNode = new Node;
	newNode->previous = nullptr;
	newNode->next = this->tail;
	newNode->data = value;

	Node* parser = this->head;
	while (parser != nullptr)
	{
		if (parser->next == nullptr)
		{
			parser->next = newNode;
			newNode->previous = parser;
			this->count++;
			break;
		}

		parser = parser->next;
	}
}

template<typename T>
uint16_t DoubleLinkedList<T>::size()
{
	return this->count;
}

template<typename T>
bool DoubleLinkedList<T>::isEmpty()
{
	return this->count == 0;
}

template<typename T>
void DoubleLinkedList<T>::showAllFirstToLast()
{
	Node* parser = this->head;
	while (parser != nullptr)
	{
		std::cout << parser->data << " ";
		parser = parser->next;
	}
}

template<typename T>
void DoubleLinkedList<T>::showAllLastToFirst()
{
	Node* parser = this->head;

	while (parser->next != nullptr)
	{
		parser = parser->next;
	}

	while (parser != this->head)
	{
		std::cout << parser->data << " ";
		parser = parser->previous;
	}

	std::cout << parser->data << " ";
}

#endif // !__DOUBLE_LINKED_LIST_HPP__