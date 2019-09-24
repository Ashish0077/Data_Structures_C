/*
    This file contains a basic implementation of merge sort
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

void mergeSort(int arr[], int startPoint, int endPoint);
void merge(int arr[], int startPoint, int midPoint, int endPoint);

//main function starts here
int main(void) {
    
    //test code
    int arr[10];
    int size = 10;
    srand(time(0)); //seeding the random with time

    //initializing the array with random numbers
    for(int i = 0; i < size; i++) {
        arr[i] = 10 - i;
    }
    printf("Array => ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    mergeSort(arr, 0, size - 1);
    printf("\nSorted Array => ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }printf("\n");

    return 0;
}

void mergeSort(int arr[], int startPoint, int endPoint) {
    
    int midPoint;
    if(startPoint < endPoint) {
        midPoint = (startPoint + endPoint) / 2;
        mergeSort(arr, startPoint, midPoint);
        mergeSort(arr, midPoint + 1, endPoint);
        merge(arr, startPoint, midPoint, endPoint);
    }
}

void merge(int arr[], int startPoint, int midPoint, int endPoint) {

    int aux[endPoint - startPoint + 1];
    int s = startPoint;
    int s2 = midPoint + 1;

    //sorting here
    int k = 0;
    while(s <= midPoint && s2 <= endPoint) {
        if(arr[s] <= arr[s2]) {
            aux[k] = arr[s];
            s++;
        } else {
            aux[k] = arr[s2];
            s2++;
        }
        k++;
    }

    //merging the left over array
    while(s <= midPoint) {
        aux[k] = arr[s];
        s++;
        k++;
    }

    //merging the left over array
    while(s2 <= endPoint) {
        aux[k] = arr[s2];
        s2++;
        k++;
    }

    //copying the array back 
    for(int i = startPoint; i <= endPoint; i++) {
        arr[i] = aux[i - startPoint];
    }
 }