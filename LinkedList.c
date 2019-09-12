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
NODE* getNode();
void insertNode(NODE** addressOfHead, int position);
void deleteNode(NODE** addressOfHead, int position);
int getListSize(NODE* head);
void printList(NODE* head);

//main function starts here
int main (void) {

    //Test Code
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
NODE* createNode () {
    NODE* newNode = (NODE*) malloc(sizeof(NODE));
    newNode->next = NULL;
    printf("Enter Data : ");
    scanf("%d", &newNode->data);
    return newNode;
}

/*
    This function returns a node at the given position
*/
NODE* getNode(NODE* head, int position) {
    NODE* list = head;
    int counter = 1;
    while (counter != position) {
        list = list->next;
        if(list == NULL) {
            printf("Reached List End, No Such position");
            return NULL;
        }
        counter++;
    }
    return list;
}

/*
    This function will insert node at any given location
*/
void insertNode(NODE** addressOfHead, int position) {

    NODE* newNode = createNode(); //create a new node
    NODE* list;

    if(position == getListSize(*addressOfHead)) {
        list = getNode(*addressOfHead, position); //getting the node at the position
        list->next = newNode; //making next of the fetched node equals to the new node
    } else if(position == 1) {
        NODE* cHead = *addressOfHead;
        newNode->next = cHead;
        *addressOfHead = newNode;
    }
    else {
        list = getNode(*addressOfHead, position - 1); //getting the node just before the position
        newNode->next = list->next; //setting the new node next to the the node at the position (position-1 + 1 = position)
        list->next = newNode;
    }

}

/*
    This function will delete node at any given location
*/
void deleteNode (NODE** addressOfHead, int pos) {

    NODE* list = *addressOfHead;
    if (pos == 1) {
        *addressOfHead = list->next;
        free(list);
    }
    else {
        NODE* loc = getNode(list, pos-1);
        list = getNode(list, pos);
        loc->next = list->next;
        free(list);
    }

    printf("[DELETED] Node at Position : %d\n", pos);
}

/*
    This function will returns the number of nodes in the list
*/
int getListSize(NODE* head) {
    NODE* list = head;
    int counter = 1; //counting from 1
    while(list->next != NULL) {
        list = list->next;
        counter++;
    }

    return counter;
}

/*
    This function will print the LinkedList
*/
void printList (NODE* head) {
    
    NODE* list = head;
    printf("\nLIST : ");
    while(true) {
        printf("%d -> ", list->data);
        list = list->next;
        if(list == NULL) {
            printf("null\n");
            break;
        }
    }
    printf("\n");
}