/*
    This file contains implementation of Bubble Sort
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

//Main Function starts here
int main (void) {
    
    int arr[1000];

    // Use current time as seed for random generator
    srand(time(0));

    //initializing the array with random numbers
    for(int i = 0; i < 1000; i++) {
        arr[i] = rand();
    }
    return 0;
}