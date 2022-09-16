#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct dynamicarr_t
{
    int *_arr;
    unsigned _size, _capacity;
} DynamicArray;

void dArray_init(DynamicArray *darray)
{
    darray->_capacity = 2u;
    darray->_size = 0u;
    darray->_arr = (int*)malloc(sizeof(int) * darray->_capacity);
}

bool dArray_isEmpty(DynamicArray *darray)
{
    return (darray->_size == 0);
}

int dArray_getAt(DynamicArray *darray, unsigned index)
{
  if(!dArray_isEmpty(darray)) {
    if(index >= darray->_size)
        return darray->_arr[darray->_size - 1];
    else
        return darray->_arr[index];
  }
}

void dArray_autoExpand(DynamicArray *darray) {
    darray->_capacity *= 2;
    int *newArray = (int *)malloc(sizeof(int) * darray->_capacity);

    unsigned it;
    for (it = 0; it < darray->_size; it++)
    {
        newArray[it] = darray->_arr[it];
    }

    int *oldArray = darray->_arr;
    darray->_arr = newArray;
    free(oldArray);
}

void dArray_pushBack(DynamicArray *darray, int value)
{
    if (darray->_size + 1 >= darray->_capacity)
    {
        dArray_autoExpand(darray);
    }

    darray->_arr[darray->_size++] = value;
}
void dArray_insertAt(DynamicArray *darray, unsigned index, int value){
    if(index > darray->_size) {
        printf("Gagal insert \"%d\" di index ke-%d\n", value, index);
        return;
    }

    if (darray->_size + 1 >= darray->_capacity){
        dArray_autoExpand(darray);        
    }
    
    memmove(&darray->_arr[index+1], &darray->_arr[index], (&darray->_arr[darray->_size] - &darray->_arr[index]) * sizeof(*darray));
    darray->_arr[index] = value;
    darray->_size++;
}
void dArray_removeAt(DynamicArray *darray, unsigned index) {
    if(index > darray->_size) {
        printf("Gagal remove data di index ke-%d\n", index);
        return;
    }
    
    memmove(&darray->_arr[index], &darray->_arr[index+1], (&darray->_arr[darray->_size] - &darray->_arr[index]) * sizeof(*darray));
    darray->_arr[darray->_size] = 0;
    darray->_size--;
}

void dArray_printAll(DynamicArray *darray) {
    for(unsigned i = 0; i < darray->_size; i++) {
        printf(" [%d] %d\n", i, darray->_arr[i]);
    }
}

int main()
{
    DynamicArray myArray;
    dArray_init(&myArray);
    dArray_pushBack(&myArray, 1);
    dArray_pushBack(&myArray, 2);
    dArray_pushBack(&myArray, 3);
    dArray_pushBack(&myArray, 4);
    dArray_pushBack(&myArray, 5);
    dArray_insertAt(&myArray, 3, 10);
    dArray_removeAt(&myArray, 2);

    printf("Array Information :\n");
    printf(" Capacity : %d\n", myArray._capacity);
    printf(" Size : %d\n", myArray._size);
    printf("\nArray Contents :\n");
    dArray_printAll(&myArray);
}