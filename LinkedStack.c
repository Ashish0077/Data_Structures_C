/*
    *This file contains an implementation of an integer only stack using LinkedList
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Structure for the LinkedStack
struct LinkedStack {
    int data;
    struct LinkedStack* next;
};

typedef struct LinkedStack Stack;

//Function prototype
void push(Stack** stack, int element);
int pop(Stack** stack);
bool isEmpty(Stack* stack);
//void display(Stack* top);

//main function starts here
int main(void) {

    //test case
    Stack* stack = NULL;
    for(int i = 0; i < 10; i++) {
        push(&stack, i);
        //display(stack);    
    }

    for(int i = 0; i < 11; i++) {
        pop(&stack);
        //display(stack);
    }

    return 0;
}

void push(Stack** stack, int element) {
    printf("Element %d, is pushed into the stack\n", element);
    
    if(isEmpty(*stack)) {
        *stack = (Stack*) malloc(sizeof(Stack));
        (*stack)->data = element;
        (*stack)->next = NULL;
    } else {
        Stack* newElement = (Stack*) malloc(sizeof(Stack));
        newElement->data = element;
        newElement->next = *stack;
        *stack = newElement;
    }

}

int pop(Stack** stack) {
    if(isEmpty(*stack)) {
        printf("UNDERFLOW, stack is empty\n");
        return -1;
    } else {
        Stack* poped = *stack;
        *stack = (*stack)->next;
        int popedElement = poped->data;
        printf("Element %d, is poped out of the stack\n", popedElement);
        free(poped);
        return popedElement;
    }
}

bool isEmpty(Stack* stack) {
    if(stack == NULL) {
        return true;
    }
    return false;
}

/*
void display(Stack* top) {
    Stack* copy = top;
    printf("\n\n\t \t");
    while(copy != NULL){
        printf("\n|\t %d \t|", copy->data);
        copy = copy->next;
    }
    printf("\n\n");
}
*/