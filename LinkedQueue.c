/*
    *This file contains an implementation of an integer only queue uaing linked list
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
    int data;
    struct node* next;
};

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

Node* createNewElement(int element) {
    Node* newElement = (Node*) malloc(sizeof(Node));
    newElement->next = NULL;
    newElement->data = element;
    return newElement;
}

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


void enqueue(Queue* addressOfQueue, int element) {
    Node* newElement = createNewElement(element);
    (*addressOfQueue).rear->next = newElement;
    (*addressOfQueue).rear = newElement;
}

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

int dequeue(Queue* addressOfQueue) {
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