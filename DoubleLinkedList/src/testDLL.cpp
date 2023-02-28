#include "DoubleLinkedList.hpp"

int main()
{
	DoubleLinkedList<int> dll;
	dll.addFirst(10);
	dll.addFirst(11);
	dll.addLast(20);
	dll.addLast(22);
	dll.addAt(2, 15);
	dll.removeElement(10);
	dll.showAllLastToFirst();
}