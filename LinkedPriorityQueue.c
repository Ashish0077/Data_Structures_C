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
};
typedef struct LinkedPriorityQueue Queue;

//function prototypes
Queue createQueue();
Element* createElement(int data, int priority);
void insert(Queue* addressOfQueue, int data, int priority);
void display(Queue queue);
void delete(Queue* addressOfQueue);

//main function starts here
int main (void) {

    //test code
    Queue queue = createQueue();
    insert(&queue, 1, 1);
    display(queue);
    insert(&queue, 2, 3);
    display(queue);
    insert(&queue, 3, 2);
    display(queue);
    insert(&queue, 4, 0);
    display(queue);

    for(int i = 0; i < 4; i++) {
        delete(&queue);
        display(queue);
    }

    return 0;
}

/*
    This function creates a new Queue a returns it
*/
Queue createQueue() {
    Queue queue; 
    queue.front = NULL;
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
    acoording to the priority
*/
void insert(Queue* addressOfQueue, int data, int priority) {
    Queue queue = *addressOfQueue;
    Element* newElement = createElement(data, priority);
    if(queue.front == NULL) {
        queue.front = newElement;
    } else if(queue.front->priority < priority) {
        newElement->next = queue.front;
        queue.front = newElement;
    } else {
        Element* list = queue.front;
        while(list->next != NULL && list->next->priority > priority)
        {
            list = list->next;
        }
        newElement->next = list->next;
        list->next = newElement;
    }
    *addressOfQueue = queue;
}

void display(Queue queue) {
    if(queue.front == NULL) {
        printf("EMPTY\n");
        return;
    }
    printf("Data\tPriority\n");
    while(queue.front != NULL) {
        printf("%d\t%d\n", queue.front->data, queue.front->priority);
        queue.front = queue.front->next;
    }
    printf("\n\n");
}

void delete(Queue* addressOfQueue) {
    Queue queue = *addressOfQueue;
    if(queue.front == NULL) {
        printf("Queue is Empty.\n");
    } else {
        Element* deletedElement = queue.front;
        queue.front = queue.front->next;
        free(deletedElement);
    }
    *addressOfQueue = queue;
}