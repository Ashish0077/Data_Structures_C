/*
    This file contains implementation of Insertion Sort Algorithms
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

void swap(int* a, int* b);
void InsertionSort(int arr[], int size);

//Main function starts here
int main (void) {

    //test Code
    int arr[10];

    // Use current time as seed for random generator
    srand(time(0));

    //initializing the array with random numbers
    for(int i = 0; i < 10; i++) {
        arr[i] = rand();
    }

    InsertionSort(arr, 10);
    printf("Sorted Array :\n");
    for(int i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}

//This function is used to swap two values (pass by reference)
void swap (int* a, int* b)  {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void InsertionSort(int arr[], int size) {

    for (int i = 1; i < size; i++)
        for (int j = i; j > 0 && arr[j] > arr[j - 1]; j--)
            swap(&arr[j - 1], &arr[j]);
}