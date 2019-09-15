/*
    This file contains basic implementation of Array based Priority Queue
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//size of the Queue
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
    int maxPriorityIndex;
    Element data[SIZE];
};

typedef struct ArrayPriorityQueue Queue;

//Function prototypes
Queue createQueue();
void insert(Queue* addressOfQueue, int data, int priority);
void display(Queue queue);
Element getMaxPriorityElement(Queue queue);

//main function starts here
int main (void) {

    Queue queue = createQueue();
    for(int i = 0; i < 5; i++) {
        insert(&queue, i + 1, i);
    }

    display(queue);
    printf("%d\n", getMaxPriorityElement(queue).data);

    return 0;
}

Queue createQueue() {
    Queue queue;
    queue.front = -1;
    queue.rear = -1;
    queue.maxPriorityIndex = -1;
    return queue;
}

void insert(Queue* addressOfQueue, int data, int priority) {
    Queue queue = (*addressOfQueue);
    Element element;
    element.data = data;
    element.priority = priority;
    if(queue.front == queue.rear && queue.front == -1) {
        queue.front++;
        queue.rear++;
        queue.data[queue.rear] = element;
    } else {
        queue.rear++;
        queue.data[queue.rear] = element;
    }
    if(queue.data[queue.maxPriorityIndex].priority < priority) {
        queue.maxPriorityIndex = queue.rear;
    }
    *addressOfQueue = queue;
}

void display(Queue queue) {
    printf("DATA\tPRIORITY\n");
    for(int i = queue.front; i <= queue.rear; i++) {
        printf("%d\t%d\n", queue.data[i].data, queue.data[i].priority);
    }
}

Element getMaxPriorityElement(Queue queue) {
    return queue.data[queue.maxPriorityIndex];
}