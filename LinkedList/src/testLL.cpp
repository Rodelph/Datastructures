#include "linkedlist.hpp"

int main()
{
    LinkedList<int> ll;
    ll.addFirst(10);
    ll.addFirst(20);
    ll.addFirst(30);
    ll.addLast(40);
    ll.addLast(50);
    ll.addAt(1, 15);
    ll.addAt(3, 26);
    ll.showAll();
    ll.removeFirst();
    std::cout << "------------------" << std::endl;
    ll.showAll();
    ll.removeLast();
    std::cout << "------------------" << std::endl;
    ll.showAll();
    ll.removeElementAt(1);
    std::cout << "------------------" << std::endl;
    ll.showAll();
    ll.removeElement(10);
    std::cout << "------------------" << std::endl;
    ll.showAll();
}