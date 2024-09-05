// Fitness function for GWO
double fitness(Node* wolf, int target) {
    return abs(wolf->data - target);
}


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
            } 
else if (fitness_values[i] < fitness_values[wolves[i] == beta ? i : 0]) {
                delta = beta;
                beta = wolves[i];
            } 
else if (fitness_values[i] < fitness_values[wolves[i] == delta ? i : 0]) {
                delta = wolves[i];
           }
}
