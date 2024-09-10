
// Fitness function for GWO
double fitness(Node* wolf, int target) {
    return abs(wolf->data - target);
}

// GWO search function
void gwoSearch(Node* head, int target) {
    int n_wolves = 5; // number of grey wolves
    int max_iterations = 100;
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
                wolves[i] = alpha - (int)a * (alpha->data - target);
            } else if (wolves[i] == beta) {
                wolves[i] = beta - (int)a * (beta->data - target) + (int)b * (alpha->data - beta->data);
            } else if (wolves[i] == delta) {
                wolves[i] = delta - (int)a * (delta->data - target) + (int)b * (beta->data - delta->data);
            } else {
                wolves[i] = wolves[i] - (int)a * (wolves[i]->data - target) + (int)b * (alpha->data - wolves[i]->data);
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
                printf("Target %d found at iteration %d!\n", target, iter);
                return;
            }
        }
    }

    printf("Target %d not found after %d iterations.\n", target, max_iterations);
}

int main() {
    Node* head = NULL;
    fillLinkedList(&head, 1000); // fill the linked list with 20 random nodes
    printLinkedList(head); // print the linked list

    int target = 42; // target value to search for
    gwoSearch(head, target); // perform GWO search

    return 0;
}
