/* 
    We all know about static arrays, lets make these Arrays Dynamic(shrink and grow)
    This file contains an implementation of Integer Only Dynamic Array
*/

//header files
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Associating properties of dynamic array into one datatype
struct DynamicArray 
{
    int size; //actual size of the array
    int length; //no. of elements in the array
    int* arr; //array itself
};

typedef struct DynamicArray darray;

//Function protoypes
darray* createArray(int size);
void add(darray* arr, int element);
void display(darray* darr);

int main (void) 
{
    darray* arr = createArray(5);
    for(int i = 0 ; i < 10; i++) {
        add(arr, i);
    }

    display(arr);
    return 0;
}

/*
    This function allocates memory for new array,
    and initializes the basic properties of array
*/
darray* createArray(int size) 
{
    darray* newArray = (darray*) malloc(sizeof(darray)); //allocated memory for DynamicArray structure
    newArray->arr = (int*) calloc(size, sizeof(int)); //allocating memory of size(size) for actual array which is inside the dynamic array structure
    printf("\ncreated array at : %p\n", newArray->arr);
    newArray->length = 0; //initally length will be 0
    newArray->size = size; //initial size
    printf("\ncreated array size and length : %d, %d\n", newArray->size, newArray->length);

    return newArray;
}

/*
    This function adds the element to the end of the array,
    and if there is no space in the array it reallocates it
*/
void add(darray* darr, int element) 
{
    darr->length++; //incrementing the length
    if (darr->length <= darr->size) 
    {
        //inserting the element inside the array
        int* arr = darr->arr;
        arr = arr + ((darr->length) - 1);
        *arr = element;
        printf("\n%d, inserted at location %p\n", element, arr);
    } 
    else 
    {
        printf("\narray is full, reallocating for space\n");
        //reallocating the array
        darr->size = (int) (darr->size + (darr->size) * 0.5);
        darr->arr = (int*) realloc(darr->arr, (darr->size) * sizeof(int));
        printf("\nreallocated array size : %d\n", darr->size);
        printf("\nreallocated array address : %p\n", darr->arr);
        //inserting the element
        int* arr = darr->arr;
        arr = arr + ((darr->length) - 1);
        *arr = element;
        printf("\n%d, inserted at location %p\n", element, arr);
    }    
}

void display(darray* darr)
{
    int* arr = darr->arr;
    for(int i = 0; i < darr->length; i++) 
    {
        int n = *(arr + i);
        printf("Element %d, at address %p : %d\n", i,(arr + i), n);
    }
}