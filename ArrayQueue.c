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

//Function prototypes
Queue createQueue();
void enqueue(Queue* addressOfQueue, int element);
void displayQueue(Queue queue);

//main function starts here
int main (void) {

    //test code
    Queue queue = createQueue();
    for(int i = 0; i < 4; i++) {
        enqueue(&queue, i);
    }

    displayQueue(queue);
    
    return 0;
}

/*
    this function is used to create new Queues
    it initializes the front and rear to -1 and then returns the newly created queue
*/
Queue createQueue() {
    Queue queue = {-1, -1};
    return queue;
}

/*
    this function is used to insert elements in the queue
    it increments the rear;
*/
void enqueue(Queue* addressOfQueue, int element) {
    Queue queue = *addressOfQueue;
    if(queue.front == queue.rear && queue.front == -1) {
        queue.front = 0;
        queue.rear = 0;
        queue.data[queue.rear] = element;
    } else {
        queue.rear++;
        queue.data[queue.rear] = element;
    }

    *addressOfQueue = queue;
}

/*
    This function simply prints the queue
*/
void displayQueue(Queue queue) {
    printf("Queue : { ");
    for(int i = queue.front; i <= queue.rear; i++) {
        printf("%d, ", queue.data[i]);
    }
    printf("\b\b }\n");
}