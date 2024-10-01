#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct node {
    int data;
    struct node* east;
    struct node* west;
    struct node* north;
} Node;
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->east = newNode->west = newNode->north = NULL;
    return newNode;
}
// Function to dynamically fill the linked list with random data
void fillLinkedList(Node** head, int size, int min, int max) {
    srand(time(NULL)); // seed random number generator
    Node* current = *head;
    for (int i = 0; i < size; i++) {
        int data = min + rand() % (max - min + 1); 
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
    int size, min, max;
    printf("Enter the number of data items to generate: ");
    scanf("%d", &size);
    printf("Enter the minimum value of the range: ");
    scanf("%d", &min);
    printf("Enter the maximum value of the range: ");
    scanf("%d", &max);

    Node* head = NULL;
    fillLinkedList(&head, size, min, max); // fill the linked list with random nodes within the specified range
    printLinkedList(head); // print the linked list
    return 0;
}
