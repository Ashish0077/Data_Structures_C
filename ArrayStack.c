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
void push(Stack stack, int element);
void pop();

//main function starts here
int main (void) {

    //Test Case
    Stack stack;
    for(int i = 0; i < 10; i++) {
        push(stack, i);
    }
    return 0;
}

/*
    This function is used to insert elements in the stack
*/
void push(Stack stack, int element){
    if(stack.top == SIZE) {
        printf("OVERFLOW, stack is full\n");
        return;
    }
    stack.top++;
    stack.data[stack.top] = element;
    printf("Element %d is pushed into the stack\n", element);
}