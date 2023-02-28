#ifndef __VECTOR__
#define __VECTOR__

#include <iostream>

#define INITIAL_SIZE 5

template<typename T>
class vector
{
    private :
        T *data;
        uint16_t count;

    public :
        vector();
        ~vector();

        void addFirst(T value);
        void addLast(T value);

        void removeFirst();
        void removeLast();
        
        bool isEmpty();
        void replace(T value, uint16_t index);
        void showAll();

        uint16_t size();

        T at(uint16_t index);
};

template<typename T>
uint16_t vector<T>::size()
{
    return this->count;
}

template<typename T>
vector<T>::vector()
{
    this->data = new T[INITIAL_SIZE];
    this->count = 0;
}

template<typename T>
vector<T>::~vector()
{
    delete[] this->data;
    this->count = 0;
}

template<typename T>
void vector<T>::showAll()
{
    for(int i = 0; i < this->count; i++)
        std::cout << this->data[i] << std::endl;
}

template<typename T>
void vector<T>::addLast(T value)
{
    uint16_t size = sizeof(*this->data)/sizeof(this->data[0]);
    if(this->count == size)
    {
        T* cache = new T[size * 2];

        for(int i = 0; i < this->count; i++)
            cache[i] = this->data[i];

        this->data = cache;
        delete[] cache;
        this->data[this->count] = value;
        this->count++;
    }
    else 
    {
        this->data[this->count] = value;
        this->count++;
    }
}

template<typename T>
void vector<T>::addFirst(T value)
{
    for(int i = this->count; i > 0; i--)
        this->data[i] = this->data[i - 1];

    this->data[0] = value;
    this->count++;
}

template<typename T>
void vector<T>::removeFirst()
{
    for(int i = 0; i < this->count; i++)
        this->data[i] = this->data[i + 1];

    this->count--;
}

template<typename T>
void vector<T>::removeLast()
{
    this->count--;
}

template<typename T>
T vector<T>::at(uint16_t index)
{
    return this->data[index];
}

template<typename T>
bool vector<T>::isEmpty()
{
    if(this->count == 0)
        return true;
    
    return false;
}

template<typename T>
void vector<T>::replace(T value, uint16_t index)
{
    this->data[index] = value;
}

#endif