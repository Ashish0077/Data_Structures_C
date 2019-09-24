/*
    This file contains a basic implementation of merge sort
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

//main function starts here
int main(void) {
    
    //test code
    int arr[10];
    srand(time(0)); //seeding the random with time

    //initializing the array with random numbers
    for(int i = 0; i < 10; i++) {
        arr[i] = rand();
    }

    return 0;
}