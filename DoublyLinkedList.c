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
void insertNode(NODE** addressOfHead, int position);
int getListSize(NODE* head);
void deleteNode(NODE** addressOfHead, int position);

//main function starts here
int main (void) {

    //Test Case
    NODE* head = createNode();
    for(int i = 0; i < 4; i++) {
        insertNode(&head, getListSize(head));
    }
    printList(head);
    printf("[INSERT] Node at position 3\n");
    insertNode(&head, 3);
    printList(head);
    printf("[INSERT] Node at position 1\n");
    insertNode(&head, 1);
    printList(head);
    deleteNode(&head, 2);
    deleteNode(&head, 1);
    printList(head);
    printList(head);

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

/*
    This function will delete node at any given location
*/
void deleteNode(NODE** addressOfHead, int position) {
    NODE* list = *addressOfHead;
    if(position == 1){
        *addressOfHead = list->next;
        (*addressOfHead)->prev = NULL;
        list->next = NULL;
        list->prev = NULL;
        free(list);
    } else {
        NODE* loc = getNode(list, position);
        (loc->prev)->next = loc->next;
        loc->next = NULL;
        loc->prev = NULL;
        free(loc);
    }

    printf("[DELETED] Node at Position : %d\n", position);
}

/*
    This function will insert node at any given location
*/
void insertNode(NODE** addressOfHead, int position) {

    NODE* loc;
    NODE* newNode = createNode();

    if(position == getListSize(*addressOfHead)) {
        loc = getNode(*addressOfHead, position);
        loc->next = newNode;
    } else if(position ==  1) {
        NODE* chead = *addressOfHead;
        newNode->next = chead;
        chead->prev = newNode;
        *addressOfHead = newNode;
    } else {
        loc = getNode(*addressOfHead, position - 1);
        NODE* loc2 = loc->next;
        loc2->prev = newNode;
        newNode->next = loc2;
        loc->next = newNode;
        newNode->prev = loc;
    }
}

/*
    This function will returns the number of nodes in the list
*/
int getListSize(NODE* head) {

    NODE* list = head;
    int counter = 1;

    while(list->next != NULL) {
        list = list->next;
        counter++;
    }

    return counter;
}