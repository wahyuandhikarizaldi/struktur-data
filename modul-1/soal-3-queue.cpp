#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
};

struct Queue {
    Node* _front, *_rear;
    unsigned _size;
};

void init(Queue* queue) {
    queue->_front = NULL;
    queue->_rear = NULL;
    queue->_size = 0;
}

bool isEmpty(Queue *queue) {
  return (queue->_front == NULL && queue->_rear == NULL);
}

void push(Queue *queue, string value) {
  Node* newNode = new Node;
  if (newNode) {
    queue->_size++;
    newNode->data = value;
    newNode->next = NULL;
    
    if (isEmpty(queue))                 
      queue->_front = queue->_rear = newNode;
    else {
      queue->_rear->next = newNode;
      queue->_rear = newNode;
    }
  }
}

void pop(Queue *queue) {
    if(!isEmpty(queue)) {
        Node *temp = queue->_front;
        queue->_front = queue->_front->next;
        free(temp);

        if(queue->_front == NULL) {
            queue->_rear = NULL;
        }
        queue->_size--;
    }
}

string top(Queue *queue) {
    if(!isEmpty(queue)) {
        return queue->_front->data;
    }
    return 0;
}

void printQueue(Queue *queue) {
    Node* current = queue->_front;

    while(current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
}

int main()
{
    Queue queue;
    init(&queue);

    push(&queue, "string1");
    push(&queue, "string2");
    push(&queue, "string3");
    push(&queue, "string4");
    pop(&queue);
    cout << top(&queue) << endl;

    printQueue(&queue);

    return 0;
}