/*
    This file contains basic implementation of LinkedList based Priority Queue
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//This structure represents single element of the queue
struct node {
    int data;
    int priority;
    struct node* next;
};
typedef struct node Element;

//This structure represents the Queue
struct LinkedPriorityQueue {
    Element* front;
    Element* rear;   
};
typedef struct LinkedPriorityQueue Queue;

//main function starts here
int main (void) {

    return 0;
}