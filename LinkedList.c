/*
    Singly LinkedList implementation for integer type data
    
    head -> [data][next] -> [data][next] -> [data][next] -> null
*/

//header files
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

//Structure for the Node of LinkedList
struct node {
    int data;
    struct node* next;
};
typedef struct node NODE;

//function prototypes
NODE* createNode();

//main function starts here
int main (void) {

    //Test Code
    NODE* head = createNode();

    return 0;
}

/*
    This function allocates memory for newNode
    takes data input and initializes next to null
    and returns the address to the newNode
*/
NODE* createNode () {
    NODE* newNode = (NODE*) malloc(sizeof(NODE));
    newNode->next = NULL;
    printf("Enter Data : ");
    scanf("%d", &newNode->data);
    return newNode;
}