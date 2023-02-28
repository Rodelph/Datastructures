#include "./src/vector.hpp"

int main()
{
    vector<int> vec;
    vec.addLast(20);
    vec.addLast(10);
    vec.showAll();
    vec.removeFirst();
    //std::cout << "------------------" << std::endl;
    vec.showAll();
    vec.addFirst(30);
    //std::cout << "The value : " << vec.at(1)  << std::endl;
    //vec.~vector();
    vec.addLast(30);
    vec.addLast(30);
    vec.showAll();
}