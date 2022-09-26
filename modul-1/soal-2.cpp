#include <iostream>

using namespace std;

struct Node {
    int id;
    int urgency_level;
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

void push(PriorityQueue *pqueue, int id, int urgency_level) {
    Node *temp = pqueue->_top;
    Node *newNode = new Node;
    pqueue->_size++;
    newNode->id = id;
    newNode->urgency_level = urgency_level;
    newNode->next = NULL;

    if (isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }

    if (urgency_level > pqueue->_top->urgency_level) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    } else {
        while ( temp->next != NULL && temp->next->urgency_level > urgency_level) {
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
        pqueue->_size--;
        free(temp);
    }
}

Node* top(PriorityQueue *pqueue) {
    if (!isEmpty(pqueue))
        return pqueue->_top;
    else return 0;
}

void printPriorityQueue(PriorityQueue *pqueue) {
    Node* current = pqueue->_top;

    while(current != NULL) {
        cout << current->id << " " << current->urgency_level << endl;
        current = current->next;
    }
}

void dumpPriorityQueue(PriorityQueue *pqueue) {
    Node* current = pqueue->_top;
    cout << endl << "Dump Data : " << endl;
    cout << "size : " << pqueue->_size << endl;
    while(current != NULL) {
        cout << current << " " << current->id << " " << current->urgency_level << " " << current->next << endl;
        current = current->next;
    }
}

void controller(string command, PriorityQueue* pqueue) {
    if (command == "MASUK") {
        int id, x;
        cin >> id;
        cin >> x;

        push(pqueue, id, x);
    } else if (command == "LAYANI") {
        if (!isEmpty(pqueue)) {
            cout << pqueue->_top->id << endl;
            pop(pqueue);
        } else {
            cout << "HORE" << endl;
        }
    } else if (command == "DUMP") {
        dumpPriorityQueue(pqueue);
    } else {
        cout << "TOLONG MASUKKAN QUERY YANG VALID!" << endl;
    }
}

int main()
{
    PriorityQueue pqueue;
    init(&pqueue);

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        string command;
        cin >> command;
        controller(command, &pqueue);
    }


    return 0;
}