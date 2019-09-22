/*
    This file contains implementation of Insertion Sort Algorithms
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

void swap(int* a, int* b);

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

//This function is used to swap two values (pass by reference)
void swap (int* a, int* b)  {
    int temp = *a;
    *a = *b;
    *b = temp;
}