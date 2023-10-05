#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "LogEntry.h"

class DoublyLinkedList {
public:
    DoublyLinkedList();

    void insert(const LogEntry& entry);
    void sort();
    void sortByIP();
    void searchByIPRange(const std::string& startIP, const std::string& endIP);
    void sumByYearAndMonth() const;

private:
    struct Node {
        LogEntry data;
        Node* next;
        Node* prev;
        Node(const LogEntry& entry) : data(entry), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;
};

#endif // DOUBLYLINKEDLIST_H
