#include <stdio.h>
#include <stdlib.h>
typedef struct node {   //Structure of Linked list
    int data;
    struct node *east;
    struct node *west;
    struct node *north;
} Node;
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->east = newNode->west = newNode->north = NULL;
    return newNode;
}
// Function to dynamically fill the linked list with random data
void fillLinkedList(Node** head, int size) {
    srand(time(NULL)); // seed random number generator
    Node* current = *head;
    for (int i = 0; i < size; i++) {
        int data = rand() % 100; // generate random data between 0 and 99
        Node* newNode = createNode(data);
        if (current == NULL) {
            *head = newNode;
            current = *head;
        } else {
            current->east = newNode;
            current = current->east;
        }
    }
}
// Function to print the linked list
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d---> ", current->data);
        current = current->east;
    }
    printf("NULL\n");
}
int main() {
    Node* head = NULL;
    fillLinkedList(&head, 1000); // fill the linked list with 20 random nodes
    printLinkedList(head); // print the linked list
    return 0;
}
