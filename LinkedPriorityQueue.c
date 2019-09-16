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
Element* createElement(int data, int priority);
void insert(Queue* addressOfQueue, int data, int priority);

//main function starts here
int main (void) {

    //test code
    Queue queue = createQueue();
    for(int i = 0; i < 5; i++) {
        insert(&queue, i, i+1);
    }

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

/*
    This function creates a new Element
    initializes data and priority
    and returns it
*/
Element* createElement(int data, int priority) {
    Element* newElement = (Element*) malloc(sizeof(Element));
    newElement->data = data;
    newElement->priority = priority;
    newElement->next = NULL;
    return newElement; 
}

/*
    this function is used to insert elements in the Queue
*/
void insert(Queue* addressOfQueue, int data, int priority) {
    Element* newElement = createElement(data, priority);
    Queue queue = *addressOfQueue;
    if(queue.front == NULL && queue.rear == NULL) {
        queue.front = newElement;
        queue.rear = newElement;
    } else {
        queue.rear->next = newElement;
        queue.rear = newElement;
    }

    *addressOfQueue = queue;
}