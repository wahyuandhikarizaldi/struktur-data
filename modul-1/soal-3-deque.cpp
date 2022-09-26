#include <iostream>
using namespace std;

struct Node {
    string data;
    struct Node *next, *prev;
};

struct Deque {
    Node *_head, *_tail;
    unsigned _size;
};

void init(Deque* deque) {
    deque->_head = NULL;
    deque->_tail = NULL;
    deque->_size = 0;
}

bool isEmpty(Deque *deque) {
    return (deque->_head == NULL && deque->_tail == NULL);
}

void pushFront(Deque *deque, string value) {
    Node *newNode = new Node;
    if(newNode) {
        deque->_size++;

        newNode->data = value;
        
        if(isEmpty(deque)) {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }

        newNode->next = deque->_head;
        deque->_head->prev = newNode;
        deque->_head = newNode;
    }
}

void pushBack(Deque* deque, string value) {
    Node* newNode = new Node;
    if(newNode) {
        deque->_size++;

        newNode->data = value;

        if(isEmpty(deque)) {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }

        deque->_tail->next = newNode;
        newNode->prev = deque->_tail;
        deque->_tail = newNode;
    }
}

string front(Deque* deque) {
    if(isEmpty(deque)) {
        return deque->_head->data;
    }
    return 0;
}

string back(Deque* deque) {
    if(isEmpty(deque)) {
        return deque->_tail->data;
    }
    return 0;
}

void popFront(Deque *deque)
{
    if (!isEmpty(deque)) {
        Node *temp = deque->_head;
        if (deque->_head == deque->_tail) {
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else {
            deque->_head = deque->_head->next;
            deque->_head->prev = NULL;
            free(temp);
        }
        deque->_size--;
    }
}

void popBack(Deque *deque)
{
    if (!isEmpty(deque)) {
        Node *temp;
        if (deque->_head == deque->_tail) {
            temp = deque->_head;
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else {
            temp = deque->_tail;
            deque->_tail = deque->_tail->prev;
            deque->_tail->next = NULL;
            free(temp);
        }
        deque->_size--;
    }
}

void printDeque(Deque *deque) {
    Node* current = deque->_head;

    while(current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
}

int main()
{
    Deque deque;
    init(&deque);

    pushFront(&deque, "string1");
    pushFront(&deque, "string2");
    pushBack(&deque, "string3");
    pushBack(&deque, "string4");
    popFront(&deque);
    popBack(&deque);
    printDeque(&deque);

    return 0;
}