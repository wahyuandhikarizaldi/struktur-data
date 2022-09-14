#include <stdio.h>
#include <stdlib.h>

struct List {
    int data;
    struct List *next;
};

void slist_append(struct List** head, int data) {
    struct List* new_node = (struct List*) malloc(sizeof(struct List));
    struct List* last = *head;

    new_node->data = data;
    new_node->next = NULL;

    if(*head == NULL) {
        *head = new_node;
        return;
    }

    while(last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    return;
}

void slist_init(struct List** head) {
    for(int i = 1 ; i <= 5; i++) {
        slist_append(head, i);
    }
}

void printElement(int *elem) {
    printf("%d ", *elem);
    return;
}

void multiply2(int *elem) {
    *elem *= 2;
    return;
}

/** Yang penting work ygy **/
void forEachElement(struct List **list, void (*func)(int *)) {
    struct List *tmp = NULL;

    while(*list != NULL) {
        (*func)( &((*list)->data) );
        slist_append(&tmp, ((*list)->data));
        *list = (*list)->next;
    }

    *list = tmp;
    return;
}

int main()
{
    struct List *myList = NULL;

    slist_init(&myList);

    forEachElement(&myList, multiply2);
    
    forEachElement(&myList, printElement);

    free(myList);
    return 0;
}