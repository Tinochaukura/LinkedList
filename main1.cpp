#include "DoublyLinkedList.h"

int main() {
    DoublyLinkedList<int> list;

    list.insertAtFront(10);
    list.insertAtFront(20);
    list.insertAtEnd(30);
    list.display();  

    list.deleteFirst();
    list.display();  

    list.deleteLast();
    list.display();  

    std::cout << "List size: " << list.size() << std::endl; 

    return 0;
}