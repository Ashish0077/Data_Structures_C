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
int dequeue(Queue* addressOfQueue);
void displayQueue(Queue queue);

//main function starts here
int main (void) {

    //test code
    Queue queue = createQueue();
    for(int i = 0; i < 11; i++) {
        enqueue(&queue, i);
    }

    displayQueue(queue);

    for(int i = 0; i < 5; i++) {
        dequeue(&queue);
    }

    displayQueue(queue);

    for(int i = 0; i < 6; i++) {
        dequeue(&queue);
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
*/
void enqueue(Queue* addressOfQueue, int element) {
    Queue queue = *addressOfQueue;
    if(queue.front == queue.rear && queue.front == -1) {
        queue.front = 0;
        queue.rear = 0;
        queue.data[queue.rear] = element;
    } else {
        queue.rear++;
        if(queue.rear == SIZE) {
            printf("OVERFLOW, QUEUE IS FULL\n");
            return;
        }
        queue.data[queue.rear] = element;
    }

    *addressOfQueue = queue;
}

/*
    This function simply prints the queue
*/
void displayQueue(Queue queue) {
    if(queue.front == -1) {
        printf("QUEUE IS EMPTY\n");
        return;
    }
    printf("Queue : { ");
    for(int i = queue.front; i <= queue.rear; i++) {
        printf("%d, ", queue.data[i]);
    }
    printf("\b\b }\n");
}
/*
    This function is used to delete elements from the queue
*/
int dequeue(Queue* addressOfQueue) {
    Queue queue = *addressOfQueue;
    if(queue.front == queue.rear) {
        if(queue.front == -1) {
            printf("Underflow, Queue is empty\n");
            return 0;
        }
        else {
            int removed = queue.data[queue.front];
            printf("Element %d, is removed from the queue\n", removed);
            queue.front = -1;
            queue.rear = -1;
            *addressOfQueue = queue;
            return removed;
        }
    }
    else {
        int removed = queue.data[queue.front];
        queue.front++;
        printf("Element %d, is removed from the queue\n", removed);
        *addressOfQueue = queue;
        return removed;
    }
}