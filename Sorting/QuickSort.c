/*
    this file contains basic implementation of Quick Sort Algorithm
    assuming pivot element is the last the element
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

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
    quickSort(arr, 0, 9);
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

int partition(int arr[], int startPoint, int endPoint) {
    int pivot = arr[endPoint];
    int i = (endPoint - 1);

    for(int j = startPoint; i < endPoint; i++) {
        if(arr[j] <= pivot) {
            printf("Swapping");
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[endPoint]);

    return i + 1;
}