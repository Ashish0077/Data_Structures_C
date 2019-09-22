/*
    This file contains implementation of Bubble Sort
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

void BubbleSort(int arr[], int size);
void swap(int* a, int *b);

//Main Function starts here
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
    BubbleSort(arr, 100);
    for(int i = 0; i < 100; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}

//basic bubble sort algorithm
void BubbleSort(int arr[], int size) {

    bool sorted;
    do {
        sorted = true;;
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size - i; j++) {
                if(arr[j] < arr[j + 1]) {
                    swap(&arr[j], &arr[j+1]);
                    sorted = false;
                }
            }
        }
    }while(!sorted);
}

//This function is used to swap two values (pass by reference)
void swap (int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}