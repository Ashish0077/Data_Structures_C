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

//function prototypes
Queue createQueue();

//main function starts here
int main (void) {

    //test code
    Queue queue = createQueue();

    return 0;
}

/*
    This function creates a new Queue a returns it
*/
Queue createQueue() {
    Queue queue; 
    queue.front = NULL;
    queue.rear = NULL;
    return queue;
}