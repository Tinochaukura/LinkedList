
#include "DoublyLinkedList.h"

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

template <typename T>
void DoublyLinkedList<T>::insertAtFront(T value) {
    Node<T>* newNode = new Node<T>(value);
    newNode->next = head;

    if (head != nullptr) {
        head->prev = newNode;
    }
    else {
        tail = newNode;
    }

    head = newNode;
}

template <typename T>
void DoublyLinkedList<T>::insertAtEnd(T value) {
    Node<T>* newNode = new Node<T>(value);

    if (tail != nullptr) {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    else {
        head = tail = newNode;
    }
}

template <typename T>
void DoublyLinkedList<T>::deleteFirst() {
    if (head == nullptr) {
        std::cout << "List is empty, nothing to delete\n";
        return;
    }

    Node<T>* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    }
    else {
        tail = nullptr;
    }

    delete temp;
}

template <typename T>
void DoublyLinkedList<T>::deleteLast() {
    if (tail == nullptr) {
        std::cout << "List is empty, nothing to delete\n";
        return;
    }

    Node<T>* temp = tail;
    tail = tail->prev;

    if (tail != nullptr) {
        tail->next = nullptr;
    }
    else {
        head = nullptr;
    }

    delete temp;
}

template <typename T>
int DoublyLinkedList<T>::size() {
    int count = 0;
    Node<T>* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

template <typename T>
void DoublyLinkedList<T>::display() {
    Node<T>* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
