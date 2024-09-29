#include <iostream>
#include <vector>

class ListContainer {
private:
    struct Node {
        int value;
        Node* prev;
        Node* next;
        Node(int val) : value(val), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int list_size;

public:
    ListContainer() : head(nullptr), tail(nullptr), list_size(0) {}

    ~ListContainer() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_back(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        ++list_size;
    }

    void insert(int index, int value) {
        if (index < 0 || index > list_size) return;

        Node* newNode = new Node(value);

        if (index == 0) {
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
            if (!tail) tail = head;
        } else if (index == list_size) {
            push_back(value);
            return;
        } else {
            Node* current = head;
            for (int i = 0; i < index; ++i) {
                current = current->next;
            }
            newNode->next = current;
            newNode->prev = current->prev;
            if (current->prev) current->prev->next = newNode;
            current->prev = newNode;
        }
        ++list_size;
    }

    void erase(int index) {
        if (index < 0 || index >= list_size) return;

        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        if (current->prev) current->prev->next = current->next;
        if (current->next) current->next->prev = current->prev;
        if (current == head) head = current->next;
        if (current == tail) tail = current->prev;

        delete current;
        --list_size;
    }

    int size() const {
        return list_size;
    }

    int& operator[](int index) {
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->value;
    }

    void print() const {
        Node* current = head;
        while (current) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};