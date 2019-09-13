/*
    *This file contains an implementation of an integer only stack using static array
    *constant size stack
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//size of the stack
#define SIZE 10

struct Stack {
    int top;
    int data[SIZE];
};

//Function Prototypes
void push();
void pop();

int main (void) {

    return 0;
}