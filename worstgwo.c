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

// Function to check if a value is unique
int isUnique(int value, int* unique_values, int size) {
    for (int i = 0; i < size; i++) {
        if (unique_values[i] == value) {
            return 0; // Value is not unique
        }
    }
    return 1; // Value is unique
}

// Function to dynamically fill the linked list with unique random data
void fillLinkedList(Node** head, int size, int min, int max) {
    srand(time(NULL)); // Seed random number generator

    // Ensure that the range can provide enough unique values
    if (max - min + 1 < size) {
        printf("Error: The range is too small to generate %d unique values.\n", size);
        return;
    }

    int* unique_values = (int*) malloc(size * sizeof(int));
    int unique_count = 0;

    Node* current = *head;
    while (unique_count < size) {
        int data = min + rand() % (max - min + 1); // Generate random data within the range [min, max]
        if (isUnique(data, unique_values, unique_count)) { // Check for uniqueness
            unique_values[unique_count] = data; // Store the unique value
            unique_count++;
            
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

    free(unique_values); // Free memory allocated for tracking unique values
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

// Fitness function for GWO
double fitness(Node* wolf, int target) {
    return abs(wolf->data - target);
}

// GWO search function
void gwoSearch(Node* head, int target, int size) {
    int n_wolves = 3;
    int max_iterations = size;
    double a = 2, b = 2; // GWO parameters

    // Initialize wolves with random positions in the linked list
    Node* wolves[n_wolves];
    for (int i = 0; i < n_wolves; i++) {
        wolves[i] = head;
        for (int j = 0; j < rand() % 10; j++) {
            if (wolves[i]->east != NULL) {
                wolves[i] = wolves[i]->east;
            }
        }
    }

    for (int iter = 0; iter < max_iterations; iter++) {
        // Encircle: calculate fitness of each wolf
        double fitness_values[n_wolves];
        for (int i = 0; i < n_wolves; i++) {
            fitness_values[i] = fitness(wolves[i], target);
        }

        // Hunt: identify the three best wolves
        Node* alpha, *beta, *delta;
        alpha = beta = delta = NULL;
        for (int i = 0; i < n_wolves; i++) {
            if (fitness_values[i] < fitness_values[wolves[i] == alpha ? i : 0]) {
                delta = beta;
                beta = alpha;
                alpha = wolves[i];
            } else if (fitness_values[i] < fitness_values[wolves[i] == beta ? i : 0]) {
                delta = beta;
                beta = wolves[i];
            } else if (fitness_values[i] < fitness_values[wolves[i] == delta ? i : 0]) {
                delta = wolves[i];
            }
        }

        // Update positions of all wolves
        for (int i = 0; i < n_wolves; i++) {
            if (wolves[i] == alpha) {
                wolves[i] = alpha;
            } else if (wolves[i] == beta) {
                wolves[i] = beta;
            } else if (wolves[i] == delta) {
                wolves[i] = delta;
            } else {
                wolves[i] = wolves[i]->east;
            }

            // Move wolf in a random direction
            int direction = rand() % 4;
            switch (direction) {
                case 0:
                    if (wolves[i]->east != NULL) {
                        wolves[i] = wolves[i]->east;
                    }
                    break;
                case 1:
                    if (wolves[i]->west != NULL) {
                        wolves[i] = wolves[i]->west;
                    }
                    break;
                case 2:
                    if (wolves[i]->north != NULL) {
                        wolves[i] = wolves[i]->north;
                    }
                    break;
                case 3:
                    if (wolves[i]->east != NULL && rand() % 2 == 0) {
                        wolves[i] = wolves[i]->east;
                    } else if (wolves[i]->west != NULL) {
                        wolves[i] = wolves[i]->west;
                    } else if (wolves[i]->north != NULL) {
                        wolves[i] = wolves[i]->north;
                    }
                    break;
            }
        }

        // Check if any wolf has found the target
        for (int i = 0; i < n_wolves; i++) {
            if (wolves[i]->data == target) {
                Node* current = head;
                int item_no = 1;
                while (current != wolves[i]) {
                    current = current->east;
                    item_no++;
                }
                printf("Target %d found at iteration %d, item no %d!\n", target, iter, item_no);
                return;
            }
        }
    }
    printf("Target %d not found after %d iterations.\n", target, max_iterations);
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
    fillLinkedList(&head, size, min, max);
    printLinkedList(head);

    // Find the last element of the linked list
    Node* current = head;
    while (current->east != NULL) {
        current = current->east;
    }
    int target = current->data;  // Assign the last element's value as the target
    printf("The target is the last element with value: %d\n", target);

    gwoSearch(head, target, size);

    return 0;
}
