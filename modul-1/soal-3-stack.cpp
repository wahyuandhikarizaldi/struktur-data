#include <iostream>
using namespace std;

struct Node {
    string data;
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

void push(Stack* stack, string value) {
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

string top(Stack *stack) {
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

int main()
{
    Stack stack;
    init(&stack);

    push(&stack, "string1");
    push(&stack, "string2");
    push(&stack, "string3");
    push(&stack, "string4");
    pop(&stack);
    cout << top(&stack) << endl;

    printStack(&stack);

    return 0;
}