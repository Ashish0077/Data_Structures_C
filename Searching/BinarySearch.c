/*
    This file contains basic implementation of Binary Search
    (Only Condition for binary search is that the data should be sorted)
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void BinarySearch(int element,int arr[], int size);

int main (void) {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; //sorted array

    int e;
    printf("Enter the Element You want to search : ");
    scanf("%d", &e);

    BinarySearch(e, arr, sizeof(arr)/sizeof(arr[0]));

    return 0;
}

void BinarySearch(int element, int arr[], int size) {
    int start = 0; 
    int end = size;
    int middle = (start + end) / 2;

    while(start <= end & element != arr[middle]) {
        if(element < arr[middle]) {
            end = middle;
            middle = (start + end) / 2;
        } else if (element > arr[middle]) {
            start = middle;
            middle = (start + end) / 2;
        } 
    }

    if (arr[middle] == element) {
        printf("Element Found At index : %d\n", middle);
       
    } else {
        printf("Element not found\n");
    }
}