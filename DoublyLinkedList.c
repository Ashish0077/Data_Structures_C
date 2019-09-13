/*
    Doubly LinkedList implementation for integer type data

    NULL <- [prev][data][next] <-> [prev][data][next] <-> [prev][data][next] <-> null
*/

//header files
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Structure for the Node of DoublyLinkedList
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

typedef struct Node NODE;

//Function prototypes
NODE* createNode();
NODE* getNode(NODE* head, int position);
void printList(NODE* head);

//main function starts here
int main (void) {

    //Test Case
    NODE* head = createNode();

    return 0;
}

/*
    This function allocates memory for newNode
    takes data input and initializes next to null
    and returns the address to the newNode
*/
NODE* createNode() {
    NODE* newNode = (NODE*) malloc(sizeof(NODE));
    newNode->next = NULL;
    newNode->prev = NULL;
    printf("Enter Data : ");
    scanf("%d", &newNode->data);
    return newNode;
}

/*
    This function returns the node which is at the given position
*/
NODE* getNode(NODE* head, int position) {
    NODE* list = head;
    int counter =  1;
    while(counter != position) {
        list = list->next;
    }
    return list;
}

/*
    This function will print the DoublyLinkedList
*/
void printList(NODE* head) {
    NODE* list = head;
    printf("\nLIST : null <- ");
    while(true) {
        printf("%d <-> ", list->data);
        list = list->next;
        if(list == NULL) {
            printf("\b\b\b\b-> null\n");
            break;
        }
    }
    printf("\n\n");
}