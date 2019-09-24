/*
    this file contains basic implementation of Quick Sort Algorithm
    assuming pivot element is the last the element
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void swap(int *a, int *b);
void quickSort(int arr[], int startPoint, int endPoint);
int partition(int arr[], int startPoint, int endPoint);

//Main function starts here
int main (void) {
    int arr[10];
    //seeding random wih time
    srand(time(0));
    for(int i = 0; i < 10; i++) {
        arr[i] = i;
    }
    return 0;
}

/*
    swapping function
*/
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int arr[], int startPoint, int endPoint) {
    int p;
    if(startPoint < endPoint) {
        p = partition(arr, startPoint, endPoint);
        quickSort(arr, startPoint, p);
        quickSort(arr, p + 1, endPoint);
    }
}



