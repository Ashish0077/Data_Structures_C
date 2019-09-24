/*
    This file contains implementation of Selection Sort Algorithm
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

//function prototypes
void swap(int* a, int* b);
int getMaxIndex(int arr[], int start, int end);
void SelectionSort(int arr[], int size);


//main function starts here
int main (void) {

    //test Code
    int arr[100];

    // Use current time as seed for random generator
    srand(time(0));

    //initializing the array with random numbers
    for(int i = 0; i < 100; i++) {
        arr[i] = rand();
    }

    printf("Sorted Array : - \n");
    SelectionSort(arr, 100);
    for(int i = 0; i < 100; i++) {
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

//returns the maximum element index
int getMaxIndex(int arr[], int start, int end) {
    int maxIndex = start;
    for(int i = start; i < end; i++) {
        if(arr[maxIndex] < arr[i]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

//Selection Sort
void SelectionSort(int arr[], int size) {

    for(int i = 0; i < size; i++) {
        int maxIndex = getMaxIndex(arr, i, size);
        if(arr[i] < arr[maxIndex])
            swap(&arr[i], &arr[maxIndex]);
    }
}