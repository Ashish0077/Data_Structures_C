/*
    This File Contains very basic implementation of linear search
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void LinearSearch(int element,int arr[], int size);

int main (void) {
    int arr[] = {0, 1, 9, 6, 2, 4, 3};

    int e;
    printf("Enter the Element You want to search : ");
    scanf("%d", &e);

    LinearSearch(e, arr, sizeof(arr)/sizeof(arr[0]));

    return 0;
}

void LinearSearch(int element, int arr[], int size) {
    
    bool flag = false;
    for(int i = 0; i < size; i++) {
        if(arr[i] == element) {
            printf("Element Found at index : %d\n", i);
            flag = true;
            break;
        }
    }
    if(!flag) {
        printf("Element not found\n");
    }
}