#include <stdio.h>
#include <stdlib.h>

struct List {
    int data;
    struct List *next;
};

void slist_push(struct List** head, int new_data) {
	struct List* new_node = (struct List*) malloc(sizeof(struct List));

	new_node->data = new_data;
	new_node->next = (*head);
	(*head) = new_node;
}

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
    for(int i = 2550 ; i <= 2555; i++) {
        slist_append(head, i);
    }
}

void printElement(int *elem) {
    printf("%d\n", *elem);
    return;
}

void multiply2(int *elem) {
    *elem *= 2;
    return;
}

void reverseEach(int *elem) {
    int remainder, reverse = 0;

    while (*elem != 0) {
        remainder = *elem % 10;
        reverse = reverse * 10 + remainder;
        *elem /= 10;
    }

    *elem = reverse;
}

void sumDigit(int *elem) {
    int remainder, reverse = 0;

    while (*elem != 0) {
        remainder = *elem % 10;
        reverse += remainder;
        *elem /= 10;
    }

    *elem = reverse;
}

/** Yang penting work ygy **/
void forEachElement(struct List **list, void (*func)(int *elem)) {
    struct List *tmp = NULL;

    while(*list != NULL) {
        (*func)( &(*list)->data);
        slist_append(&tmp, (*list)->data);
        *list = (*list)->next;
    }

    *list = tmp;
    return;
}

int main()
{
    struct List *myList = NULL;

    slist_init(&myList);

    printf("==== [initialize] ====\n");
    forEachElement(&myList, printElement);
    printf("\n");

    printf("==== [multiply2] ====\n");
    forEachElement(&myList, multiply2);
    forEachElement(&myList, printElement);
    printf("\n");

    printf("==== [reverseEach] ====\n");
    forEachElement(&myList, reverseEach);
    forEachElement(&myList, printElement);
    printf("\n");

    printf("==== [sumDigit] ====\n");
    forEachElement(&myList, sumDigit);
    forEachElement(&myList, printElement);
    printf("\n");

    free(myList);
    return 0;
}