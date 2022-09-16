#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct String {
    char data[100];
    struct String *next;
};

void str_push(struct String** head, char *s) {
	struct String* new = (struct String*) malloc(sizeof(struct String));

	strcpy(new->data, s);
	new->next = (*head);
	(*head) = new;
}

void str_append(struct String** head, char *s) {
    struct String* new = (struct String *) malloc(sizeof(struct String));
    struct String* last = *head;

    strcpy(new->data, s);
    new->next = NULL;

    if(*head == NULL) {
        *head = new;
        return;
    }

    while(last->next != NULL) {
        last = last->next;
    }

    last->next = new;
    return;
}

void printElement(struct String** str) {
    printf("%s\n", (*str)->data);
    return;
}

void forEachElement(struct String **str, void (*func)(struct String **)) {
    struct String *tmp = NULL;

    while(*str != NULL) {
        (*func)( (str) );
        str_append(&tmp, (*str)->data);
        *str = (*str)->next;
    }

    *str = tmp;
    return;
}

int main() {
    struct String* str = NULL;
    
    str_append(&str, "Apple");
    str_append(&str, "Orange");
    str_push(&str, "Watermelon");


    forEachElement(&str, printElement);

    return 0;
}