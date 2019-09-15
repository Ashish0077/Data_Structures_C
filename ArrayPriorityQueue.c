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

//this structure represents the ArrayPriorityQueue
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
void priorityReset(Queue* addressOfqueue);
Element getMaxPriorityElement(Queue queue);
Element delete(Queue* addressOfQueue);

//main function starts here
int main (void) {

    Queue queue = createQueue();
    for(int i = 0; i < 5; i++) {
        insert(&queue, i + 1, i);
        display(queue);
    }
    for(int i = 0; i < 10; i++) {
        delete(&queue);
        display(queue);
    }

    return 0;
}

//this fucntion is used to create new Queue
Queue createQueue() {
    Queue queue;
    queue.front = -1;
    queue.rear = -1;
    queue.maxPriorityIndex = -1;
    return queue;
}

/*
    this function is used to insert elements in the queue
*/
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

/*
    display function
*/
void display(Queue queue) {
    if(queue.front == queue.rear && queue.front == -1) {
        printf("Nothing to display\n");
        return;
    }
    printf("\n\nDATA\tPRIORITY\n");
    for(int i = queue.front; i <= queue.rear; i++) {
        printf("%d\t%d\n", queue.data[i].data, queue.data[i].priority);
    }
}

/*
    this function returns the maxPriorityElement
*/
Element getMaxPriorityElement(Queue queue) {
    return queue.data[queue.maxPriorityIndex];
}

Element delete(Queue* addressOfQueue) {
    Queue queue = *addressOfQueue;
    Element removedElement = queue.data[queue.maxPriorityIndex];
    if(queue.front == queue.rear && queue.front == -1) {
        printf("UNDERFLOW, Queue is empty.\n");
        return removedElement;
    }
    queue.data[queue.maxPriorityIndex].data = 0;
    queue.data[queue.maxPriorityIndex].priority = 0;

    if(queue.rear == queue.maxPriorityIndex) {
        queue.rear--;
    } else {
        queue.data[queue.maxPriorityIndex] = queue.data[queue.rear];
        queue.rear--;
    }
    priorityReset(&queue);
    if(queue.rear == -1) {
        queue.maxPriorityIndex = -1;
        queue.front = -1;
    }
    *addressOfQueue = queue;
    return removedElement;

}
/*
    this function sets queue's maxPriorityIndex to the element's index whose priority is max
*/
void priorityReset(Queue* addressOfQueue) {
    Queue queue = *addressOfQueue;
    for(int i = queue.front; i <= queue.rear; i++) {
        if(queue.data[queue.maxPriorityIndex].priority < queue.data[i].priority) {
            queue.maxPriorityIndex = i;
        }
    }
    *addressOfQueue = queue;
}