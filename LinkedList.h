//
// Created by shira on 12/16/19.
//

#ifndef DATA_STRUCTURES_SINGLY_LINKED_LIST_TEMPLATED_SHIRAZALTSMAN_LINKEDLIST_H
#define DATA_STRUCTURES_SINGLY_LINKED_LIST_TEMPLATED_SHIRAZALTSMAN_LINKEDLIST_H

#include <clocale>

template<class T>
class LinkedList {
public:
    LinkedList();

    // operations
    void add(T value);

    bool search(const T &value) const;

    bool isEmpty() const;

    void clear();

    void remove(T key);

protected:
    class Node {
    public:
        Node(T value, Node *next);

    private:
        Node *next;
        T value;
    };

private:
    Node *m_head;
};

template<class T>
LinkedList<T>::LinkedList(): m_head(NULL) {

}

template<class T>
bool LinkedList<T>::isEmpty() const {
    return m_head == NULL;
}

template<class T>
void LinkedList<T>::add(T value) {
    Node *newNode = new Node(value);
    if (m_head == NULL) {
        m_head = newNode;
    } else {
        Node *next = m_head;
        while (next) {
            next = next->next;
        }
        next = newNode;
    }
}

template<class T>
bool LinkedList<T>::search(const T &value) const {
    if (m_head == NULL) {
        return false;
    } else {
        Node *next = m_head;
        while (next) {
            if(next->value == value){
                return true;
            } else {
                next = next->next;
            }
        }
        return false;
    }
}

template<class T>
void LinkedList<T>::clear() {
    Node* current;
    Node* next;
    current = m_head;
    while (current){
        next = current->next;
        delete current;
        current = next;
    }
    m_head = NULL;

}

template<class T>
void LinkedList<T>::remove(T key) {
    if (m_head == NULL) {
        return;
    } else {
        Node *current = m_head;
        Node *next = current->next;
        while (next) {
            if(next->value == key){
                current->next = next -> next;
                delete next;
                return;
            } else {
                current = current->next;
                next = next->next;
            }
        }
    }
}


#endif //DATA_STRUCTURES_SINGLY_LINKED_LIST_TEMPLATED_SHIRAZALTSMAN_LINKEDLIST_H
