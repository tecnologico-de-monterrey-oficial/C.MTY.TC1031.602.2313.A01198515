#include "DoublyLinkedList.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

void DoublyLinkedList::insert(const LogEntry& entry) {
    Node* newNode = new Node(entry);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

void DoublyLinkedList::sort() {
    std::vector<LogEntry> entries;
    Node* current = head;
    while (current) {
        entries.push_back(current->data);
        current = current->next;
    }
    std::sort(entries.begin(), entries.end());
    current = head;
    for (const auto& entry : entries) {
        current->data = entry;
        current = current->next;
    }
}

void DoublyLinkedList::sortByIP() {
    std::vector<LogEntry> entries;
    Node* current = head;
    while (current) {
        entries.push_back(current->data);
        current = current->next;
    }
    std::sort(entries.begin(), entries.end(), [](const LogEntry& lhs, const LogEntry& rhs) {
        return lhs.getIP() < rhs.getIP() || (lhs.getIP() == rhs.getIP() && lhs < rhs);
    });
    current = head;
    for (const auto& entry : entries) {
        current->data = entry;
        current = current->next;
    }
}

void DoublyLinkedList::searchByIPRange(const std::string& startIP, const std::string& endIP) {
    std::ofstream ascFile("iprange602-a.out");
    std::ofstream descFile("iprange602-d.out");
    if (!ascFile.is_open() || !descFile.is_open()) {
        std::cerr << "Error: Unable to open output files for IP range search." << std::endl;
        return;
    }

    Node* current = head;
    while (current) {
        std::string currentIP = current->data.getIP();
        if (currentIP >= startIP && currentIP <= endIP) {
            ascFile << current->data.getDate() << " " << current->data.getTime() << " " << currentIP << " " << current->data.getMessage() << std::endl;
        }
        current = current->next;
    }

    current = tail;
    while (current) {
        std::string currentIP = current->data.getIP();
        if (currentIP >= startIP && currentIP <= endIP) {
            descFile << current->data.getDate() << " " << current->data.getTime() << " " << currentIP << " " << current->data.getMessage() << std::endl;
        }
        current = current->prev;
    }

    ascFile.close();
    descFile.close();
}

void DoublyLinkedList::sumByYearAndMonth() const {
    std::map<std::string, int> countMap;
    Node* current = head;

    while (current) {
        std::string date = current->data.getDate();
        std::string yearMonth = date.substr(7, 7); // Extract "YYYY MM"
        countMap[yearMonth]++;
        current = current->next;
    }

    std::cout << "Sumatoria de datos por año y mes:" << std::endl;
    for (const auto& pair : countMap) {
        std::cout << "Año-Mes: " << pair.first << ", Cantidad: " << pair.second << std::endl;
    }
}
