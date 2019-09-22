/*
    This file contains implementation of Selection Sort Algorithm
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>

//function prototypes

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

    return 0;
}