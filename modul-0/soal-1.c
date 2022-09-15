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

void printElement(struct List** node) {
    printf("%d\n", (*node)->data);
    return;
}

void multiply2(struct List** node) {
    (*node)->data *= 2;
    return;
}

void reverseEach(struct List** node)
{
    int remainder, reverse = 0;

    while ((*node)->data != 0) {
        remainder = (*node)->data % 10;
        reverse = reverse * 10 + remainder;
        (*node)->data /= 10;
    }

    (*node)->data = reverse;
}

void sumDigit(struct List** node) {

}

/** Yang penting work ygy **/
void forEachElement(struct List **list, void (*func)(struct List **)) {
    struct List *tmp = NULL;

    while(*list != NULL) {
        (*func)( (list) );
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

    // forEachElement(&myList, multiply2);
    forEachElement(&myList, reverseEach);
    forEachElement(&myList, printElement);

    free(myList);
    return 0;
}