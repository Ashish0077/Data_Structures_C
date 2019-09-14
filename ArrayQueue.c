/*
    *This file contains an implementation of an integer only queue using static array
    *constant size stack
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//size of the queue
#define SIZE 10

struct ArrayQueue {
    int front;
    int rear;
    int data[SIZE];
};

typedef struct ArrayQueue Queue;

int main (void) {

    return 0;
}