#include <iostream>

using namespace std;

struct Node {
    string data;
    Node* next;
};

struct PriorityQueue {
    Node* _top;
    unsigned _size;
};

void init(PriorityQueue* pqueue) {
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool isEmpty(PriorityQueue *pqueue) {
    return (pqueue->_top == NULL);
}

void push(PriorityQueue *pqueue, string value) {
    Node *temp = pqueue->_top;
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }

    if (value.compare(pqueue->_top->data) < 0) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    } else {
        while ( temp->next != NULL && (temp->next->data).compare(value) < 0) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void pop(PriorityQueue *pqueue)
{
    if (!isEmpty(pqueue)) {
        Node *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}

string top(PriorityQueue *pqueue) {
    if (!isEmpty(pqueue))
        return pqueue->_top->data;
    else return 0;
}

void printPriorityQueue(PriorityQueue *pqueue) {
    Node* current = pqueue->_top;

    while(current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
}

int main()
{
    PriorityQueue pqueue;
    init(&pqueue);

    push(&pqueue, "A");
    printPriorityQueue(&pqueue);
    cout << endl;
    
    push(&pqueue, "C");
    printPriorityQueue(&pqueue);
    cout << endl;

    push(&pqueue, "B");
    printPriorityQueue(&pqueue);
    cout << endl;

    push(&pqueue, "Z");
    printPriorityQueue(&pqueue);
    cout << endl;

    push(&pqueue, "B");
    printPriorityQueue(&pqueue);
    cout << endl;

    push(&pqueue, "D");
    printPriorityQueue(&pqueue);
    cout << endl;

    push(&pqueue, "F");
    printPriorityQueue(&pqueue);

    // string z = "Z";
    // string b = "B";
    // cout << endl;
    // cout << z.compare(b) << endl;
    return 0;
}