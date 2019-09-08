/* 
    We all know about static arrays, lets make these Arrays Dynamic(shrink and grow)
    This file contains an implementation of Integer Only Dynamic Array
*/

//header files
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Associating properties of dynamic array into one datatype
struct DynamicArray {
    int size; //actual size of the array
    int length; //no. of elements in the array
    int* arr; //array itself
};

typedef struct DynamicArray darray;

//Function protoypes
darray* createArray(int size);
void add(darray* arr, int element);

int main (void) {

    return 0;
}

/*
    This function allocates memory for new array,
    and initializes the basic properties of array
*/
darray* createArray(int size) {
    darray* newArray = (darray*) malloc(sizeof(darray)); //allocated memory for DynamicArray structure
    newArray->arr = (int*) malloc(size*sizeof(int)); //allocating memory of size(size) for actual array which is inside the dynamic array structure 
    newArray->length = 0; //initally length will be 0
    newArray->size = size; //initial size

    return newArray;
}

void add(darray* arr, int element) {
    if(arr->length < arr->size) {

    }
    
}
