#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct dArrayOfString {
    unsigned _size, _capacity;
    char **_array;
} DArrayOfString;

void dArrayOfString_init(DArrayOfString *darray) {
    darray->_size = 0u;
    darray->_capacity = 2u;
    darray->_array = malloc(darray->_capacity * sizeof(*darray->_array));
}

bool dArrayOfString_isEmpty(DArrayOfString *darray) {
    return (darray->_size == 0);
}

void dArrayOfstring_autoExpand(DArrayOfString *darray) {
    darray->_capacity *= 2;
    char **newArray = (char **)malloc(darray->_capacity * sizeof(*darray->_array));

    unsigned it;
    for (it = 0; it < darray->_size; it++) {
        newArray[it] = darray->_array[it];
    }

    char **oldArray = darray->_array;
    darray->_array = newArray;
    free(oldArray);
}

void dArrayOfString_push(DArrayOfString *darray, char *string) {
    if (darray->_size + 1 >= darray->_capacity) {
        dArrayOfstring_autoExpand(darray);
    }

    darray->_array[darray->_size++] = string;
}

void dArrayOfString_insertAt(DArrayOfString *darray, unsigned int index, char *string) {
    if (index > darray->_size) {
        printf("Gagal insert \"%s\" di index ke-%d\n", string, index);
        return;
    }

    if (darray->_size + 1 >= darray->_capacity) {
        dArrayOfstring_autoExpand(darray);
    }

    if (darray->_array[index] != NULL) {
        memmove(&darray->_array[index+1], &darray->_array[index], (&darray->_array[darray->_size] - &darray->_array[index]) * sizeof(*darray));
        darray->_array[index] = string;
        darray->_size++;
    } else {
        darray->_array[index] = string;
        darray->_size++;
    }
}

void dArrayOfString_removeAt(DArrayOfString *darray, unsigned index) {
    if(index > darray->_size) {
        printf("Gagal remove data di index ke-%d\n", index);
        return;
    }

    memmove(&darray->_array[index], &darray->_array[index+1], (&darray->_array[darray->_size] - &darray->_array[index]) * sizeof(*darray));
    darray->_array[darray->_size] = "";
    darray->_size--;
}

void dArrayOfString_printAll(DArrayOfString *darray) {
    for(unsigned i = 0; i < darray->_size; i++) {
        printf(" [%d] %s\n", i, darray->_array[i]);
    }
}
int main() {
    DArrayOfString darray;

    dArrayOfString_init(&darray);
    dArrayOfString_push(&darray, "Apple");
    dArrayOfString_push(&darray, "Orange");
    dArrayOfString_push(&darray, "Melon");
    dArrayOfString_insertAt(&darray, 0, "Kacang");
    dArrayOfString_insertAt(&darray, 1, "Kacang");
    dArrayOfString_removeAt(&darray, 0);
    dArrayOfString_insertAt(&darray, 5, "Permen");

    printf("Array Information :\n");
    printf("  Capacity : %d\n", darray._capacity);
    printf("  Size : %d\n", darray._size);
    printf("\nArray Contents :\n");
    dArrayOfString_printAll(&darray);

    
    return 0;
}