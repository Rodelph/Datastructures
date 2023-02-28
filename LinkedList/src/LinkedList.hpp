#ifndef __LINKED_LIST_HPP__
#define __LINKED_LIST_HPP__

#include <iostream>

template <typename T>
class LinkedList
{
    private:
        struct Node
        {
            T data;
            Node *next;
        };

        Node *head, *tail;
        uint16_t count;

    public:
        LinkedList();
        ~LinkedList();

        void addFirst(T value);
        void addLast(T value);
        void addAt(uint16_t index, T value);

        void removeFirst();
        void removeLast();
        void removeElement(T element);
        void removeElementAt(uint16_t index);

        void showAll();

        T at(uint16_t index);

        uint16_t size();

        bool isEmpty();
};

template<typename T>
LinkedList<T>::LinkedList()
{
    this->head  = nullptr;
    this->tail  = nullptr;
    this->count = 0;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    this->head = nullptr;
    this->count = 0;
}

template<typename T>
void LinkedList<T>::addFirst(T value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if(this->head == nullptr)
    {
        this->head = newNode;
        newNode->next = this->tail;
        this->count++;
    }
    else
    {
        newNode->next = this->head;
        this->head = newNode;
        this->count++;
    }   
}

template<typename T>
uint16_t LinkedList<T>::size()
{
    return this->count;
}

template<typename T>
void LinkedList<T>::addLast(T value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (this->head == nullptr)
    {
        this->head = newNode;
        newNode->next = this->tail;
        this->count++;
    }
    else
    {
        Node* cache = this->head;
        while (cache != nullptr)
        {
            if (cache->next == nullptr)
            {
                newNode->next = this->tail;
                cache->next = newNode;
                this->count++;
                break;
            }
            else
                cache = cache->next;
        }
    }
}

template<typename T>
void LinkedList<T>::addAt(uint16_t index, T value)
{
    if (!this->isEmpty() && index < this->size())
    {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        uint16_t n = 0;

        Node* cache = this->head;

        while(n < this->size())
        {
            if (n == (index - 1))
            {
                newNode->next = cache->next;
                cache->next = newNode;
                this->count++;
                break;
            }
            else
            {
                n++;
                cache = cache->next;
            }
        }

        cache = nullptr;
        delete cache;
    }
    else
    {
        std::cerr << "The linkedlist is empty or the index is bigger than the size !" << std::endl;
    }
}

template<typename T>
void LinkedList<T>::removeFirst()
{
    Node* cache = head;
    head = cache->next;
    cache->next = nullptr;
    this->count--;
    delete cache;
}

template<typename T>
void LinkedList<T>::removeLast()
{
    Node* cache = head;
    while (cache != nullptr)
    {
        if (((Node*)cache->next)->next == nullptr)
        {
            cache->next = nullptr;
            this->count--;
            break;
        }
        else
            cache = cache->next;
    }

    cache = nullptr;
    delete cache;
}

template<typename T>
void LinkedList<T>::removeElementAt(uint16_t index)
{
    if (!this->isEmpty() && (index < this->size() && index > 0))
    {
        uint16_t n = 0;

        Node* cache = this->head;

        while (n < this->size())
        {
            if (n == (index - 1))
            {
                cache->next = ((Node*)(cache->next))->next;
                this->count--;
                break;
            }
            else
            {
                n++;
                cache = cache->next;
            }
        }

        cache = nullptr;
        delete cache;
    }
    else
    {
        std::cerr << "The linkedlist is empty or the index is bigger than the size !" << std::endl;
    }
}

template<typename T>
void LinkedList<T>::removeElement(T element)
{
    Node* cache = head;
    int n = 0;
    while (cache != nullptr)
    {
        if (((Node*)cache->next)->data == element)
        {
            if (n == 0)
            {
                this->head = this->head->next;
                this->count--;
                break;
            }
            else
            {
                cache->next = ((Node*)(cache->next))->next;
                this->count--;
                break;
            }
        }
        else
        {
            cache = cache->next;
            n++;
        }
    }
}

template<typename T>
T LinkedList<T>::at(uint16_t index)
{
    if (!this->isEmpty() && index < this->size())
    {
        uint16_t n = 0;

        Node* cache = this->head;

        while (n < this->size())
        {
            if (n == index)
                return cache->data;
            else
            {
                n++;
                cache = cache->next;
            }
        }

        cache = nullptr;
        delete cache;
    }
}

template<typename T>
void LinkedList<T>::showAll()
{
    Node *printer = this->head;
    while(printer != nullptr)
    {
        std::cout << printer->data << std::endl;
        printer = printer->next;
    }
    printer = nullptr;
    delete printer;
}

template<typename T>
bool LinkedList<T>::isEmpty()
{
    return this->count == 0;
}

#endif //!__LINKED_LIST_HPP__