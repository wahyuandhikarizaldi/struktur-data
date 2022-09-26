#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* _top;
    unsigned _size;
};

void init(Stack* stack) {
    stack->_top = NULL;
    stack->_size = 0;
}

bool isEmpty(Stack* stack) {
    return (stack->_top == NULL);
}

void push(Stack* stack, int value) {
    Node* newNode = new Node;
    if(newNode) {
        newNode->data = value;

        if(isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
        stack->_size++;
    }
}

void pop(Stack *stack) {
    if(!isEmpty(stack)) {
        Node *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

int top(Stack *stack) {
    if(!isEmpty(stack)) {
        return stack->_top->data;
    }
    return 0;
}

void printStack(Stack *stack) {
    Node* current = stack->_top;

    while(current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
}

Node* findSmallestNode(Stack* stack) {
    Node* current = stack->_top;
    Node* smallest = current;
    
    while(current != NULL) {
        if(current->data < smallest->data) {
            smallest = current;
        }
        current = current->next;
    }

    return smallest;
}

int main()
{
    Stack stack;
    init(&stack);

    push(&stack, 3);
    push(&stack, 2);
    push(&stack, 8);
    push(&stack, -5);
    push(&stack, 4);
    push(&stack, 2);
    push(&stack, 1);
    pop(&stack);
    Node* smallest = findSmallestNode(&stack);
    cout << smallest->data << endl;
    
    cout << top(&stack) << endl;

    printStack(&stack);

    return 0;
}