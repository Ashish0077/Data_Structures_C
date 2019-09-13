/*
    *This file contains an implementation of an integer only stack using static array
    *constant size stack
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//size of the stack
#define SIZE 10

struct ArrayStack {
    int top;
    int data[SIZE];
};

typedef struct ArrayStack Stack;

//Function Prototypes
void push(Stack* stack, int element);
int pop(Stack* stack);
bool isEmpty(Stack* stack);
bool isFull(Stack* stack);

//main function starts here
int main (void) {

    //Test Case
    Stack stack = {-1};
    for(int i = 0; i < 11; i++) {
        push(&stack, i);
    }

    for(int i = 0; i < 11; i++) {
        pop(&stack);
    }
    return 0;
}

/*
    This function is used to insert elements in the stack
*/
void push(Stack* stack, int element){
    if(isFull(stack)) {
        printf("OVERFLOW, stack is full\n");
        return;
    }

    (*stack).top++;
    (*stack).data[(*stack).top] = element;
    printf("Element %d is pushed into the stack\n", (*stack).data[(*stack).top]);
}

/*
    This function is used to pop out elements from the stack
*/
int pop(Stack* stack) {
    if(isEmpty(stack)) {
        printf("UNDERFLOW, stack is empty\n");
        return -1;
    }
    
    int popedElement = (*stack).data[(*stack).top];
    printf("Element %d, is poped out of the stack\n", popedElement);
    (*stack).top--;
}

bool isEmpty(Stack* stack) {
    if((*stack).top == -1) {
        return true;
    }

    return false;
}

bool isFull(Stack* stack) {
    if((*stack).top == SIZE - 1) {
        return true;
    }
    
    return false;
}