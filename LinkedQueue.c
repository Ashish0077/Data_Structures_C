/*
    *This file contains an implementation of an integer only queue uaing linked list
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Structure for the node of linkedlist
struct node {
    int data;
    struct node* next;
};

//Structure for LinkedQueue
struct LinkedQueue {
  struct node* front;
  struct node* rear;  
};

typedef struct node Node;
typedef struct LinkedQueue Queue;

//function prototypes
Queue createQueue();
Node* createNewElement(int element);
void enqueue(Queue* queue, int element);
void display(Queue queue);
int dequeue(Queue* addressOfQueue);

//main function starts here
int main (void) {

    //test code
    Queue queue = createQueue();
    for(int i = 0; i < 5; i++) {
        enqueue(&queue, i+2);
    }
    display(queue);

    for(int i = 0; i < 6; i++) {
        dequeue(&queue);
        display(queue);
    }
    return 0;
}

/*
    This function is used to create new Node for the linked list
*/
Node* createNewElement(int element) {
    Node* newElement = (Node*) malloc(sizeof(Node));
    newElement->next = NULL;
    newElement->data = element;
    return newElement;
}

/*
    This function is used to create Queue
*/
Queue createQueue() {
    int element;
    printf("Enter data : ");
    scanf("%d", &element);
    Node* newElement = createNewElement(element);
    Queue queue;
    queue.front = newElement;
    queue.rear = newElement;
    return queue;
}

/*
    This function is used to insert elements in the queue
*/
void enqueue(Queue* addressOfQueue, int element) {
    Node* newElement = createNewElement(element);
    (*addressOfQueue).rear->next = newElement;
    (*addressOfQueue).rear = newElement;
}

/*
    This function is used to display Queue on the screen
*/
void display(Queue queue) {
    if(queue.front == NULL) {
        return;
    }
    Node* list = queue.front;
    printf("{ ");
    while(list != NULL) {
        printf("%d, ", list->data);
        list = list->next;
    }
    printf("\b\b }\n");
}

/*
    this function is used to delete elements from the Queue
*/
int dequeue(Queue* addressOfQueue) {
    if((*addressOfQueue).front == NULL) {
        printf("Underflow\n"); 
        return -1;
    }
    Node* deletedElement = (*addressOfQueue).front;
    (*addressOfQueue).front = deletedElement->next;
    if((*addressOfQueue).front == NULL) {
        (*addressOfQueue).rear = NULL;
    }
    printf("Element %d, is removed from Queue\n", deletedElement->data);
    int n = deletedElement->data;
    free(deletedElement);
    return n;
}