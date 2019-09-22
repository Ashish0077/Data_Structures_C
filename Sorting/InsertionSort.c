/*
    This file contains implementation of Insertion Sort Algorithms
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>


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

    return 0;
}