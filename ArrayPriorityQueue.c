/*
    This file contains basic implementation of Array based Priority Queue
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 10

//this structure represents a element of the Queue which is associated with a priority
struct element {
    int data;
    int priority;
};

typedef struct element Element; 

struct ArrayPriorityQueue
{
    int rear;
    int front;
    Element data[SIZE];
};

//main function starts here
int main (void) {

    return 0;
}